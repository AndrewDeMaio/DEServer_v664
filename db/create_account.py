#!/usr/bin/env python3
"""Create a game account that can log in.

    ./create_account.py <account> <password>

An account is one row of `Player`. Everything but the id and the password keeps
the column default, which is exactly what the accounts in use look like:
Access ALLOW, LogOn LOGOFF, no pay restrictions.

The password is stored the way the login server compares it,
    CONCAT('*', UPPER(SHA1(UNHEX(SHA1(password)))))
(MySQL 4.1's PASSWORD(), which MySQL 8 no longer has; see CLLoginHandler). It is
hashed here, so the plain text never reaches the database or a command line.

The rules are the game's own, so an account made here is one the client can
actually type and the server will actually accept:
  * account   4-10 characters, letters and digits   (the client's login box
    takes 10; PlayerTypes.h minIDLength/maxIDLength)
  * password  6-12 characters, printable, no spaces, none of ' " ; and not
    containing "1=1" (the login handler throws those away as SQL injection)

After the INSERT the script runs the login server's own lookup against the new
row and fails loudly if it would not log in.

Connection: --host/--port/--user/--password/--db or $DE_DB_*; see deploy_db.py.
Note that --password is the DATABASE password; the account's password is the
second positional argument.
"""
import argparse
import hashlib
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from dbconn import MySQL, add_connection_args, quote  # noqa: E402


def game_hash(password):
    inner = hashlib.sha1(password.encode("ascii")).digest()
    return "*" + hashlib.sha1(inner).hexdigest().upper()


def check_account(name):
    if not re.match(r"^[A-Za-z0-9]{4,10}$", name):
        sys.exit("account: 4 to 10 letters and digits, nothing else")


def check_password(pw):
    if not 6 <= len(pw) <= 12:
        sys.exit("password: 6 to 12 characters (the client's box takes 12)")
    if not all(33 <= ord(c) <= 126 for c in pw):
        sys.exit("password: printable ASCII only, no spaces")
    if any(c in pw for c in "'\";") or "1=1" in pw:
        sys.exit("password: the login server rejects ' \" ; and \"1=1\" as SQL injection")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("account")
    ap.add_argument("account_password", metavar="password")
    ap.add_argument("--admin", action="store_true",
                    help="set Player.Admin to 'Y' (the column's own default; this script writes 'N' otherwise)")
    add_connection_args(ap)
    a = ap.parse_args()

    check_account(a.account)
    check_password(a.account_password)
    my = MySQL(a)

    if int(my.scalar("SELECT COUNT(*) FROM information_schema.TABLES WHERE TABLE_SCHEMA = %s "
                     "AND TABLE_NAME = 'Player'" % quote(a.db), db=False)) == 0:
        sys.exit("`%s` has no Player table; deploy the database first (deploy_db.py)" % a.db)

    # PlayerID compares case-insensitively (latin1_swedish_ci), so Bob blocks bob
    if int(my.scalar("SELECT COUNT(*) FROM Player WHERE PlayerID = %s" % quote(a.account))) > 0:
        sys.exit("account %r already exists" % a.account)

    my.query("INSERT INTO Player (PlayerID, Password, creation_date, Admin) VALUES (%s, %s, CURDATE(), %s)"
             % (quote(a.account), quote(game_hash(a.account_password)), quote("Y" if a.admin else "N")))

    # The login server's lookup, word for word, with the password as a hex
    # literal so nothing in it needs escaping.
    rows = my.query(
        "SELECT PlayerID, LogOn, Access FROM Player WHERE PlayerID = %s "
        "AND Password = CONCAT('*', UPPER(SHA1(UNHEX(SHA1(0x%s)))))"
        % (quote(a.account), a.account_password.encode("ascii").hex()))
    if len(rows) != 1:
        sys.exit("the row was written but the login server's password check does not match it; "
                 "this is a bug in create_account.py, the account will not log in")
    _, logon, access = rows[0]
    if access != "ALLOW" or logon != "LOGOFF":
        sys.exit("the account exists but would be refused: Access=%s LogOn=%s" % (access, logon))

    print("account %s created in `%s` (Access ALLOW, LogOn LOGOFF, Admin %s); it can log in"
          % (a.account, a.db, "Y" if a.admin else "N"))


main()
