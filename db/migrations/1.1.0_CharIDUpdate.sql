-- 1.1.0_CharIDUpdate.sql
--
-- CharID becomes the identity of a character, and a deleted character gives
-- its name back.
--
-- Until now a character WAS its Name: Name was the primary key of Slayer,
-- Vampire and Ousters, and everything a character owns points at it by name
-- (OwnerID). A name a player typed makes a poor key.
--
-- Slayer is the registry. Character creation inserts a Slayer row for EVERY
-- race (its Race column says which), then the Vampire or the Ousters row. So
-- Slayer.CharID, the AUTO_INCREMENT, is the one place an id is issued, and a
-- Vampire or Ousters row carries the CharID of its Slayer row.
--
-- PART 1 - the race tables
--   * Slayer.CharID is copied into the Vampire and Ousters rows of the same
--     name. The server never wrote those columns, so characters made since the
--     column was added still hold 0.
--   * Slayer, Vampire, Ousters: CharID moves to the first column and becomes
--     the PRIMARY KEY. Name stays UNIQUE: the server looks characters up by
--     name, and two live characters must never share one.
--   * Vampire.CharID and Ousters.CharID become FOREIGN KEYs to Slayer.CharID
--     (ON DELETE CASCADE: removing the registry row removes the race row).
--   * BEFORE INSERT triggers on Vampire and Ousters take the CharID from the
--     Slayer row the server has just inserted; the server's INSERTs are unchanged.
--   * OwnerCharID is brought back in step with OwnerID in every table that has
--     both (the trg_*_cid_* triggers only saw rows written after they existed).
--
-- PART 2 - deleted characters: INACTIVE + CharID
--   Deleting a character keeps it: the rows stay, Active = 'INACTIVE'. What has
--   to end is the dead character answering to its name, because the server
--   still finds a character's rows by name in well over a thousand statements,
--   and a new character of that name would inherit the dead one's skills,
--   guild, friends and mail.
--
--   So a deleted character is RETIRED: it stops being known by a name and is
--   known by its CharID alone. Its key in every name-keyed column becomes
--   `~<CharID>` (`~15`), which no player can type (names are a-z A-Z 0-9 and
--   Korean), and the name it had is kept in Slayer.RetiredName. There is no
--   counter and no mangled name to parse: the CharID is the link.
--
--     CALL sp_RetireCharacter('Anna');   -- CLDeletePCHandler, after its purges
--     CALL sp_RestoreCharacter(15);      -- undo it, if the name is still free
--
--   This replaces the `[D_001]Anna` renaming freeInactiveCharName used to do
--   inside CLCreatePCHandler, and the deleteNum counter it kept (the column
--   stays, unused). Characters deleted before this migration are retired by it.
--
--   Which columns hold a character's name:
--     * `OwnerID` in every table that also has `OwnerCharID`   (found at run time)
--     * the (table, column) pairs listed in `CharacterNameRef` (add a row when a
--       new name-keyed table appears; pairs that do not exist are skipped)
--   Logs and histories are left alone on purpose; they record who it was.
--
-- Safe to run again: every step looks first and skips what is done. MySQL
-- commits each ALTER on its own, so a run that stopped half way is finished by
-- running the file again.
--
-- Run through db/deploy_db.py, which selects the database and records the
-- version. By hand:  mysql --default-character-set=latin1 DARKEDEN < this file
-- (not `binary`: the mysql client cannot parse DELIMITER under it)

-- This file is plain ASCII. The routines below remember the character set they
-- were created under, so it is stated rather than inherited from the caller.
SET NAMES utf8mb4;

DELIMITER ;;

-- ---------------------------------------------------------------------------
-- The name-keyed columns that are not called OwnerID.
-- ---------------------------------------------------------------------------
CREATE TABLE IF NOT EXISTS `CharacterNameRef` (
  `TableName`  varchar(64)  NOT NULL,
  `ColumnName` varchar(64)  NOT NULL,
  `Note`       varchar(120) NOT NULL DEFAULT '',
  PRIMARY KEY (`TableName`, `ColumnName`)
) ENGINE=InnoDB DEFAULT CHARSET=ascii COLLATE=ascii_bin
  COMMENT='columns other than OwnerID that hold a character name; read by sp_RenameCharacterKeys';;

INSERT IGNORE INTO `CharacterNameRef` (`TableName`, `ColumnName`, `Note`) VALUES
  ('GuildMember',             'Name',              'guild membership'),
  ('FriendList',              'Name',              'whose friend list'),
  ('FriendList',              'FriendName',        'the friend on it'),
  ('FriendWaitList',          'Name',              'pending friend requests'),
  ('FriendWaitList',          'FriendName',        'pending friend requests'),
  ('FriendGlobalOption',      'Name',              'friend settings'),
  ('Messages',                'Sender',            'mail'),
  ('Messages',                'Receiver',          'mail'),
  ('CoupleInfo',              'FemalePartnerName', 'couples'),
  ('CoupleInfo',              'MalePartnerName',   'couples'),
  ('RedistributeAttr50Count', 'Name',              'stat redistribution allowance'),
  ('ResetAttributeCount',     'Name',              'stat reset allowance'),
  ('EventLevelUp',            'Name',              'level-up event progress'),
  ('EventNewbie',             'Name',              'newbie event'),
  ('GMGhost',                 'Name',              'GM ghost flag'),
  ('EnemyErase',              'EnemyName',         'who is on somebody''s enemy list'),
  ('GoodsListObject',         'Name',              'item mall deliveries');;

-- ---------------------------------------------------------------------------
-- Re-key everything a character owns from one name to another.
-- The race tables themselves are the caller's business (order matters there).
-- ---------------------------------------------------------------------------
DROP PROCEDURE IF EXISTS `sp_RenameCharacterKeys`;;

CREATE PROCEDURE `sp_RenameCharacterKeys`(
    IN pOld VARCHAR(32) CHARACTER SET latin1,
    IN pNew VARCHAR(32) CHARACTER SET latin1)
    SQL SECURITY INVOKER
BEGIN
    DECLARE vDone   INT DEFAULT 0;
    DECLARE vTable  VARCHAR(64);
    DECLARE vColumn VARCHAR(64);

    DECLARE curKeys CURSOR FOR
        SELECT c.TABLE_NAME, c.COLUMN_NAME
          FROM information_schema.COLUMNS c
          JOIN information_schema.TABLES t
            ON t.TABLE_SCHEMA = c.TABLE_SCHEMA AND t.TABLE_NAME = c.TABLE_NAME
         WHERE c.TABLE_SCHEMA = DATABASE()
           AND t.TABLE_TYPE = 'BASE TABLE'
           AND c.COLUMN_NAME = 'OwnerID'
           AND EXISTS (SELECT 1 FROM information_schema.COLUMNS o
                        WHERE o.TABLE_SCHEMA = c.TABLE_SCHEMA
                          AND o.TABLE_NAME = c.TABLE_NAME
                          AND o.COLUMN_NAME = 'OwnerCharID')
        UNION
        SELECT c.TABLE_NAME, c.COLUMN_NAME
          FROM `CharacterNameRef` r
          JOIN information_schema.COLUMNS c
            ON c.TABLE_SCHEMA = DATABASE()
           AND CAST(c.TABLE_NAME  AS BINARY) = CAST(r.TableName  AS BINARY)
           AND CAST(c.COLUMN_NAME AS BINARY) = CAST(r.ColumnName AS BINARY)
          JOIN information_schema.TABLES t
            ON t.TABLE_SCHEMA = c.TABLE_SCHEMA AND t.TABLE_NAME = c.TABLE_NAME
           AND t.TABLE_TYPE = 'BASE TABLE';

    DECLARE CONTINUE HANDLER FOR NOT FOUND SET vDone = 1;

    IF pOld IS NULL OR pOld = '' OR pNew IS NULL OR pNew = '' THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'sp_RenameCharacterKeys: empty name';
    END IF;

    -- latin1 like the columns, so the comparison needs no conversion, uses the
    -- index, and CP949 Korean bytes pass through untouched
    SET @rck_old = pOld, @rck_new = pNew;

    OPEN curKeys;
    key_loop: LOOP
        FETCH curKeys INTO vTable, vColumn;
        IF vDone = 1 THEN
            LEAVE key_loop;
        END IF;

        SET @rck_sql = CONCAT('UPDATE `', vTable, '` SET `', vColumn, '` = ? WHERE `', vColumn, '` = ?');
        PREPARE rck_stmt FROM @rck_sql;
        EXECUTE rck_stmt USING @rck_new, @rck_old;
        DEALLOCATE PREPARE rck_stmt;
    END LOOP;
    CLOSE curKeys;
END;;

-- ---------------------------------------------------------------------------
-- Retire a character: keep it, INACTIVE, known only by its CharID.
-- ---------------------------------------------------------------------------
DROP PROCEDURE IF EXISTS `sp_RetireCharacter`;;

CREATE PROCEDURE `sp_RetireCharacter`(IN pName VARCHAR(32) CHARACTER SET latin1)
    SQL SECURITY INVOKER
BEGIN
    DECLARE vCharID INT UNSIGNED DEFAULT NULL;
    DECLARE vTomb   VARCHAR(32) CHARACTER SET latin1;
    DECLARE vWas    VARCHAR(32) CHARACTER SET latin1;

    DECLARE EXIT HANDLER FOR SQLEXCEPTION
    BEGIN
        ROLLBACK;
        RESIGNAL;
    END;

    SET vCharID = (SELECT CharID FROM Slayer WHERE Name = pName);

    IF vCharID IS NULL THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'sp_RetireCharacter: no character of that name';
    END IF;
    IF LEFT(pName, 1) = '~' THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'sp_RetireCharacter: already retired';
    END IF;

    SET vTomb = CONCAT('~', vCharID);

    -- a name the old renaming scheme already mangled: `[D_001]Anna` was Anna
    SET vWas = IF(pName REGEXP '^\\[D_[0-9A-Fa-f]+\\].', SUBSTRING(pName, LOCATE(']', pName) + 1), pName);

    START TRANSACTION;

    -- The registry first: the trg_*_cid_* triggers on the owned tables look the
    -- new OwnerID up in Slayer, and must find this same CharID under it.
    UPDATE Slayer  SET RetiredName = vWas, Name = vTomb, Active = 'INACTIVE' WHERE CharID = vCharID;
    UPDATE Vampire SET Name = vTomb, Active = 'INACTIVE' WHERE CharID = vCharID;
    UPDATE Ousters SET Name = vTomb, Active = 'INACTIVE' WHERE CharID = vCharID;

    CALL sp_RenameCharacterKeys(pName, vTomb);

    COMMIT;
END;;

-- ---------------------------------------------------------------------------
-- Bring a retired character back under the name it had.
-- ---------------------------------------------------------------------------
DROP PROCEDURE IF EXISTS `sp_RestoreCharacter`;;

CREATE PROCEDURE `sp_RestoreCharacter`(IN pCharID INT UNSIGNED)
    SQL SECURITY INVOKER
BEGIN
    DECLARE vTomb   VARCHAR(32) CHARACTER SET latin1 DEFAULT NULL;
    DECLARE vWas    VARCHAR(32) CHARACTER SET latin1 DEFAULT NULL;
    DECLARE vPlayer VARCHAR(32) CHARACTER SET latin1 DEFAULT NULL;
    DECLARE vSlot   VARCHAR(8)  CHARACTER SET latin1 DEFAULT NULL;
    DECLARE vCount  INT DEFAULT 0;

    DECLARE EXIT HANDLER FOR SQLEXCEPTION
    BEGIN
        ROLLBACK;
        RESIGNAL;
    END;

    SELECT Name, RetiredName, PlayerID, Slot INTO vTomb, vWas, vPlayer, vSlot
      FROM Slayer WHERE CharID = pCharID;

    IF vTomb IS NULL THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'sp_RestoreCharacter: no such CharID';
    END IF;
    IF vWas IS NULL THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'sp_RestoreCharacter: that character is not retired';
    END IF;

    SELECT COUNT(*) INTO vCount FROM Slayer WHERE Name = vWas;
    IF vCount > 0 THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'sp_RestoreCharacter: its name has been taken by another character';
    END IF;

    SELECT COUNT(*) INTO vCount FROM Slayer WHERE PlayerID = vPlayer AND Slot = vSlot AND Active = 'ACTIVE';
    IF vCount > 0 THEN
        SIGNAL SQLSTATE '45000' SET MESSAGE_TEXT = 'sp_RestoreCharacter: the account has a live character in that slot';
    END IF;

    START TRANSACTION;

    UPDATE Slayer  SET Name = vWas, RetiredName = NULL, Active = 'ACTIVE' WHERE CharID = pCharID;
    UPDATE Vampire SET Name = vWas, Active = 'ACTIVE' WHERE CharID = pCharID;
    UPDATE Ousters SET Name = vWas, Active = 'ACTIVE' WHERE CharID = pCharID;

    CALL sp_RenameCharacterKeys(vTomb, vWas);

    COMMIT;
END;;

-- ---------------------------------------------------------------------------
-- The one-off work.
-- ---------------------------------------------------------------------------
DROP PROCEDURE IF EXISTS `mig_1_1_0`;;

CREATE PROCEDURE `mig_1_1_0`()
BEGIN
    DECLARE vCount INT DEFAULT 0;
    DECLARE vDone  INT DEFAULT 0;
    DECLARE vTable VARCHAR(64);
    DECLARE vName  VARCHAR(32) CHARACTER SET latin1;

    -- every base table that carries both OwnerID and OwnerCharID
    DECLARE curOwner CURSOR FOR
        SELECT c.TABLE_NAME
          FROM information_schema.COLUMNS c
          JOIN information_schema.TABLES t
            ON t.TABLE_SCHEMA = c.TABLE_SCHEMA AND t.TABLE_NAME = c.TABLE_NAME
         WHERE c.TABLE_SCHEMA = DATABASE()
           AND c.COLUMN_NAME = 'OwnerCharID'
           AND t.TABLE_TYPE = 'BASE TABLE'
           AND EXISTS (SELECT 1 FROM information_schema.COLUMNS o
                        WHERE o.TABLE_SCHEMA = c.TABLE_SCHEMA
                          AND o.TABLE_NAME = c.TABLE_NAME
                          AND o.COLUMN_NAME = 'OwnerID')
         ORDER BY c.TABLE_NAME;

    DECLARE CONTINUE HANDLER FOR NOT FOUND SET vDone = 1;

    -- 1. every Vampire and Ousters row must have its Slayer registry row
    SELECT COUNT(*) INTO vCount FROM (
        SELECT v.Name FROM Vampire v LEFT JOIN Slayer s ON s.Name = v.Name WHERE s.Name IS NULL
        UNION ALL
        SELECT o.Name FROM Ousters o LEFT JOIN Slayer s ON s.Name = o.Name WHERE s.Name IS NULL
    ) orphans;

    IF vCount > 0 THEN
        SIGNAL SQLSTATE '45000'
            SET MESSAGE_TEXT = '1.1.0: Vampire/Ousters rows exist with no Slayer row of the same Name; give them a registry row first';
    END IF;

    UPDATE Vampire v JOIN Slayer s ON s.Name = v.Name SET v.CharID = s.CharID WHERE v.CharID <> s.CharID;
    UPDATE Ousters o JOIN Slayer s ON s.Name = o.Name SET o.CharID = s.CharID WHERE o.CharID <> s.CharID;

    -- 2. Slayer: CharID first, the primary key; Name unique; RetiredName
    SELECT COUNT(*) INTO vCount FROM information_schema.STATISTICS
     WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'Slayer'
       AND INDEX_NAME = 'PRIMARY' AND COLUMN_NAME = 'CharID';

    IF vCount = 0 THEN
        ALTER TABLE `Slayer`
            DROP PRIMARY KEY,
            DROP INDEX `CharID`,
            MODIFY `CharID` int unsigned NOT NULL AUTO_INCREMENT FIRST,
            ADD PRIMARY KEY (`CharID`),
            ADD UNIQUE KEY `UQ_Slayer_Name` (`Name`);
    END IF;

    SELECT COUNT(*) INTO vCount FROM information_schema.COLUMNS
     WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'Slayer' AND COLUMN_NAME = 'RetiredName';

    IF vCount = 0 THEN
        ALTER TABLE `Slayer`
            ADD COLUMN `RetiredName` varchar(32) DEFAULT NULL
                COMMENT 'the name this character had before it was deleted; NULL while it is alive'
                AFTER `Name`;
    END IF;

    -- 3. Vampire and Ousters: the same, and CharID references the registry.
    --    CharID keeps DEFAULT 0 because the server's INSERT does not name it;
    --    the BEFORE INSERT trigger below replaces the 0.
    SELECT COUNT(*) INTO vCount FROM information_schema.STATISTICS
     WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'Vampire'
       AND INDEX_NAME = 'PRIMARY' AND COLUMN_NAME = 'CharID';

    IF vCount = 0 THEN
        ALTER TABLE `Vampire`
            DROP PRIMARY KEY,
            MODIFY `CharID` int unsigned NOT NULL DEFAULT '0' FIRST,
            ADD PRIMARY KEY (`CharID`),
            ADD UNIQUE KEY `UQ_Vampire_Name` (`Name`),
            ADD CONSTRAINT `FK_Vampire_CharID` FOREIGN KEY (`CharID`)
                REFERENCES `Slayer` (`CharID`) ON DELETE CASCADE ON UPDATE CASCADE;
    END IF;

    SELECT COUNT(*) INTO vCount FROM information_schema.STATISTICS
     WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'Ousters'
       AND INDEX_NAME = 'PRIMARY' AND COLUMN_NAME = 'CharID';

    IF vCount = 0 THEN
        ALTER TABLE `Ousters`
            DROP PRIMARY KEY,
            MODIFY `CharID` int unsigned NOT NULL DEFAULT '0' FIRST,
            ADD PRIMARY KEY (`CharID`),
            ADD UNIQUE KEY `UQ_Ousters_Name` (`Name`),
            ADD CONSTRAINT `FK_Ousters_CharID` FOREIGN KEY (`CharID`)
                REFERENCES `Slayer` (`CharID`) ON DELETE CASCADE ON UPDATE CASCADE;
    END IF;

    -- 4. OwnerCharID back in step with OwnerID, table by table
    SET vDone = 0;
    OPEN curOwner;
    owner_loop: LOOP
        FETCH curOwner INTO vTable;
        IF vDone = 1 THEN
            LEAVE owner_loop;
        END IF;

        SET @mig_sql = CONCAT(
            'UPDATE `', vTable, '` o LEFT JOIN `Slayer` s ON s.`Name` = o.`OwnerID`',
            ' SET o.`OwnerCharID` = IFNULL(s.`CharID`, 0)',
            ' WHERE o.`OwnerCharID` <> IFNULL(s.`CharID`, 0)');
        PREPARE mig_stmt FROM @mig_sql;
        EXECUTE mig_stmt;
        DEALLOCATE PREPARE mig_stmt;
    END LOOP;
    CLOSE curOwner;

    -- 5. retire the characters that were deleted before retirement existed.
    --    One at a time, asking afresh each round: retiring rewrites the very
    --    rows a cursor over Slayer would be walking.
    dead_loop: LOOP
        SET vName = (SELECT Name FROM Slayer
                      WHERE Active = 'INACTIVE' AND RetiredName IS NULL AND LEFT(Name, 1) <> '~'
                      ORDER BY CharID LIMIT 1);
        IF vName IS NULL THEN
            LEAVE dead_loop;
        END IF;
        CALL sp_RetireCharacter(vName);
    END LOOP;

    -- 6. a world with no characters starts counting at 1
    SELECT COUNT(*) INTO vCount FROM Slayer;
    IF vCount = 0 THEN
        ALTER TABLE `Slayer` AUTO_INCREMENT = 1;
    END IF;
END;;

CALL `mig_1_1_0`();;

DROP PROCEDURE `mig_1_1_0`;;

-- ---------------------------------------------------------------------------
-- A Vampire or Ousters row takes the CharID of its Slayer registry row.
-- CLCreatePCHandler inserts the Slayer row first and does not name CharID in
-- the race INSERT, so it arrives here as 0.
-- ---------------------------------------------------------------------------
DROP TRIGGER IF EXISTS `trg_Vampire_charid_ins`;;

CREATE TRIGGER `trg_Vampire_charid_ins` BEFORE INSERT ON `Vampire` FOR EACH ROW
BEGIN
    IF NEW.CharID = 0 THEN
        SET NEW.CharID = IFNULL((SELECT CharID FROM Slayer WHERE Name = NEW.Name), 0);
    END IF;
    IF NEW.CharID = 0 THEN
        SIGNAL SQLSTATE '45000'
            SET MESSAGE_TEXT = 'Vampire row has no Slayer registry row of the same Name to take its CharID from';
    END IF;
END;;

DROP TRIGGER IF EXISTS `trg_Ousters_charid_ins`;;

CREATE TRIGGER `trg_Ousters_charid_ins` BEFORE INSERT ON `Ousters` FOR EACH ROW
BEGIN
    IF NEW.CharID = 0 THEN
        SET NEW.CharID = IFNULL((SELECT CharID FROM Slayer WHERE Name = NEW.Name), 0);
    END IF;
    IF NEW.CharID = 0 THEN
        SIGNAL SQLSTATE '45000'
            SET MESSAGE_TEXT = 'Ousters row has no Slayer registry row of the same Name to take its CharID from';
    END IF;
END;;

DELIMITER ;
