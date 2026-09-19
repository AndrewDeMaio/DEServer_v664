"""The mysql command line, wrapped: what deploy_db.py and create_account.py share.

The password never goes on a command line (where `ps` shows it). It is written
to a private temporary option file that the mysql client reads and that is
removed when the script ends.
"""
import atexit
import getpass
import os
import subprocess
import sys
import tempfile

DEFAULT_HOST = "127.0.0.1"
DEFAULT_PORT = 3306
DEFAULT_USER = "elcastle"       # the account the servers' conf files use
DEFAULT_DB = "DARKEDEN"


def add_connection_args(ap):
    g = ap.add_argument_group("connection")
    g.add_argument("--host", default=os.environ.get("DE_DB_HOST", DEFAULT_HOST))
    g.add_argument("--port", type=int, default=int(os.environ.get("DE_DB_PORT", DEFAULT_PORT)))
    g.add_argument("--user", default=os.environ.get("DE_DB_USER", DEFAULT_USER))
    g.add_argument("--password", default=None,
                   help="database password; otherwise $DE_DB_PASSWORD, otherwise asked for")
    g.add_argument("--db", default=os.environ.get("DE_DB_NAME", DEFAULT_DB),
                   help="database name (default %s)" % DEFAULT_DB)


class MySQL:
    def __init__(self, args):
        password = args.password
        if password is None:
            password = os.environ.get("DE_DB_PASSWORD")
        if password is None:
            password = getpass.getpass("password for %s@%s: " % (args.user, args.host))
        self.db = args.db

        fd, self._cnf = tempfile.mkstemp(prefix="dedb_", suffix=".cnf")
        atexit.register(self._cleanup)
        with os.fdopen(fd, "w") as f:       # mkstemp creates it 0600
            f.write("[client]\nhost=%s\nport=%d\nuser=%s\npassword=\"%s\"\n" % (
                args.host, args.port, args.user,
                password.replace("\\", "\\\\").replace('"', '\\"')))
        self._base = ["mysql", "--defaults-extra-file=" + self._cnf]

    def _cleanup(self):
        try:
            os.remove(self._cnf)
        except OSError:
            pass

    def query(self, sql, db=None, check=True):
        """Run SQL given on stdin, return the rows as lists of strings."""
        cmd = self._base + ["-N", "-B", "--default-character-set=utf8mb4"]
        if db is not False:
            cmd.append(db or self.db)
        p = subprocess.run(cmd, input=sql.encode("utf-8"), capture_output=True)
        if p.returncode:
            if check:
                sys.exit("mysql failed: " + p.stderr.decode("utf-8", "replace").strip())
            return None
        return [line.split("\t") for line in p.stdout.decode("utf-8", "replace").splitlines()]

    def scalar(self, sql, db=None):
        rows = self.query(sql, db)
        return rows[0][0] if rows else None

    def feed(self, body, db=None):
        """Pipe a .sql file's bytes through the client, untouched.

        The client runs as latin1: a single-byte character set, so it scans the
        file byte by byte and CP949 Korean passes through unparsed. It must NOT
        be `binary`: the client cannot read its own DELIMITER command under it
        ("DELIMITER must be followed by a 'delimiter' character"), so every
        BEGIN ... END body would be cut at its first semicolon.

        What the SERVER makes of the bytes is the file's own business: the
        skeleton dump says `SET NAMES binary`, and a migration opens with the
        SET NAMES that fits its text.
        Returns (ok, stderr text).
        """
        cmd = self._base + ["--default-character-set=latin1"]
        if db is not False:
            cmd.append(db or self.db)
        p = subprocess.run(cmd, input=body, capture_output=True)
        return p.returncode == 0, p.stderr.decode("utf-8", "replace").strip()


def quote(s):
    """A SQL string literal for a value we did not write ourselves."""
    return "'" + s.replace("\\", "\\\\").replace("'", "''") + "'"
