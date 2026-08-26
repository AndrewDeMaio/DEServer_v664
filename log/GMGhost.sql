-- Per-character GM ghost mode, so that "*command ghost on|off" survives a logout.
--
-- Before this, CGConnectHandler::execute() force-applied EffectGhost to every
-- GOD character on every connect, so turning ghost off only lasted the session.
-- It now reads the saved value from here; a character with no row keeps the old
-- behaviour (GOD ghosts, everyone else does not).
--
-- Name matches Slayer.Name / Vampire.Name / Ousters.Name: varchar(10) latin1.

CREATE TABLE IF NOT EXISTS `GMGhost` (
  `Name`  varchar(10)       NOT NULL DEFAULT '',
  `Ghost` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`Name`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
