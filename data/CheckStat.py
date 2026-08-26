#!/usr/local/bin/python2.2

import MySQLdb

conn = MySQLdb.connect('localhost','elcastle','zkqtpf','DARKEDEN')
cursor = conn.cursor()
cursor2 = conn.cursor()
#cursor.execute("set collation_connection = 'euckr_korean_ci'")
#cursor.execute("set character_set_results = 'euckr'")
#cursor.execute("set character_set_client = 'euckr'")
cursor.execute("truncate table LevelCheck")

Servers = ['TRAN','WALA','MOLD','HIST']
#Domains = [['Blade','Sword','Gun','Heal','Enchant'],[''],['']]
#Races = ['Slayer','Vampire','Ousters']
Domains = [[''],[''],['Blade','Sword','Gun','Heal','Enchant']]
Races = ['Ousters','Vampire','Slayer']

type = 0
for sv in Servers :
	for i in range(len(Races)) :
		for domain in Domains[i] :
			race = Races[i]
			for lv in range(10) :
				query = " select t1.Name, t2.chkDate, t2." + domain + "Level from " + race + "ExpStatus t1 , " + race + "ExpStatus t2 "
				query += " where t1.Name = t2.Name and t1.DBServer = t2.DBServer and t1.DBServer = '" + sv + "' "
				query += " and t1.chkDate = t2.chkDate - interval 1 day "
				query += " and t1." + domain + "Level <> t2." + domain + "Level "
				query += " and t1." + domain + "Level = 139 + " + str(lv) + " limit 10"
#				print query
				cursor.execute(query)
				for data in cursor.fetchall() :
#					print data[0] + "\t" + data[1] + "\t" + str(data[2])
					query2 = "select min(chkDate) from " + race + "ExpStatus where DBServer = '" + sv + "' and Name = '" + data[0]
					query2 += "' and " + domain + "Level > " + str(data[2]) 
					cursor2.execute(query2)
					for data2 in cursor2.fetchall() :
						query3 = "insert into LevelCheck values ('" + sv + "','" + race + "','" + str(data[0]) + "'," + str(data[2]) + ",'" + str(data[1]) + "','" + str(data2[0]) + "')";
						cursor.execute(query3)
#					print query2
	
conn.close
