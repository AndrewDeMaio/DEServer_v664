#!/usr/local/bin/python2.2

import os, sys, MySQLdb;            
#from DBConfig import getDBConn;


###DB 접속##########################################################
DBhost = 'localhost'
DBuser = 'wnepd'
DBpass = 'dkarfk'
DBname = 'chworld'
DBport = 3306

DBhost2 = '222.122.137.65'
DBuser2 = 'cronman'
DBpass2 = 'tnstn100'
DBname2 = 'DARKEDEN'
DBport2 = 4958



conn_local = MySQLdb.connect(DBhost, DBuser, DBpass, DBname, DBport)
conn = MySQLdb.connect(DBhost2, DBuser2, DBpass2, DBname2, DBport2)
#conn_local = getDBConn('MOLD','SLAVE','DARKEDEN');
cursor = conn_local.cursor();
cursor2 = conn.cursor();
query = "select ClassID, ItemClass as TblName from ItemClasstmp;"
cursor2.execute(query);


###파일 출력#######################################################
outFile = open('Del_Items.sql','w')
outFile2 = open('except_Items.sql','w')
outFile2.write("===========삭제되지 않은 Row==========\n")


i = 0

for list in cursor2.fetchall() :
	ItemClass = list[0]
	TblName = list[1]
#print str(list)+'\t'+str(ItemClass)+'\t'+str(TblName)
	query = "select ID,ItemID, OwnerID from TimeLimitItems where ItemClass = %s and LimitDateTime < now()"%(ItemClass)
	cursor.execute(query);
	for ItmID in cursor.fetchall() :
		Itemid = ItmID[1]
		id = ItmID[0]
		Owner = ItmID[2]
		query = "Select ItemID, OwnerID from %s where ItemID = %s"%(TblName,Itemid);
		cursor.execute(query);
		for obj in cursor.fetchall() :
			own = obj[1]
			if own == Owner :
				if str(obj) == "()" :
					continue;
				else:
					query2 = "delete from %s where ItemID=%s and OwnerID='%s ';"%(TblName,Itemid,Owner); 
					outFile.write(query2+"\n")
					#cursor.execute(query2);
					
					query3 = "delete from TimeLimitItems where ID=%s and ItemID=%s and OwnerID='%s ';"%(id,Itemid,Owner);
					outFile.write(query3+"\n")
					#cursor.execute(query3);
					
					i = i + 1
				if i == 200 :
					outFile2.write("======================================")
					sys.exit();
			else :
				outFile2.write("삭제되지 않은 ItemID : "+ItemId+"\t테이블명 : "+TblName+"\n")
					

