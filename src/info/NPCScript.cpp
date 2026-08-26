//////////////////////////////////////////////////////////////////////////////
// Filename    : NPCScript.cpp
// Written by  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#include "NPCScript.h"
#include "DB.h"
#include "Utility.h"
#include <iomanip>

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void createNPCScriptFile(const string& filename)
{
	ofstream file(filename.c_str(), ios::out | ios::binary | ios::trunc);

	Statement*  pStmt   = g_pConnection->createStatement();
	Result*     pResult = NULL;
	
	////////////////////////////////////////////////////////////
	//      .
	////////////////////////////////////////////////////////////
	pResult = pStmt->executeQuery("SELECT COUNT(*) FROM Script");
	if (pResult->getRowCount() == 0)
	{
		cout << "Script table does not exist or no data in it" << endl;
		return;
	}
	pResult->next();

	int nTotalCount = pResult->getInt(1);
	file.write("&nTotalCount", sizeof(nTotalCount));

	string Subjects[MAX_SUBJECT];
	string Contents[MAX_CONTENT];
	int i;

	////////////////////////////////////////////////////////////
	//   .
	////////////////////////////////////////////////////////////
	pResult = pStmt->executeQuery("SELECT ScriptID, OwnerID, Subject, Content FROM Script");

	while (pResult->next())
	{
		//  .
		for (i=0; i<MAX_SUBJECT; i++) Subjects[i] = "";
		for (i=0; i<MAX_CONTENT; i++) Contents[i] = "";

		int    ScriptID = pResult->getInt(1);
		string OwnerID  = pResult->getString(2);
		string subject  = pResult->getString(3);
		string content  = pResult->getString(4);

		string seperator    = "**";
		int    subjectCount = 0;
		int    contentCount = 0;
		size_t   start        = 0;
		size_t   end          = 0;
		string msg;

		////////////////////////////////////////////////////////////
		// subject 
		// blur blur ** blur blur
		// a         b
		////////////////////////////////////////////////////////////
		start = 0;
		end   = 0;
		while (end < subject.size())
		{
			start = end;
			end   = subject.find(seperator, start);

			if (end == string::npos) end = subject.size();
			end++;

			msg = trim(subject.substr(start, end-start-1));

			Subjects[subjectCount] = msg;
			subjectCount++;

			end++;
		}

		////////////////////////////////////////////////////////////
		// content 
		////////////////////////////////////////////////////////////
		start = 0;
		end   = 0;
 
		while (end < content.size())
		{
			start = end;
			end   = content.find(seperator, start);

			if (end == string::npos) end = content.size();
			end++;

			msg = trim(content.substr(start, end-start-1));

			Contents[contentCount] = msg;
			contentCount++;

			end++;
		}

		////////////////////////////////////////////////////////////
		//  .
		////////////////////////////////////////////////////////////
		file.write("&ScriptID", sizeof(ScriptID));
		cout << "ScriptID:" << ScriptID << endl;

		int OwnerIDSize = (int)OwnerID.size();
		file.write("&OwnerIDSize", sizeof(OwnerIDSize));
		file.write("OwnerID.c_str()", OwnerID.size());
		cout << "OwnerID:" << OwnerID << endl;

		file.write("&subjectCount", sizeof(subjectCount));
		for (i=0; i<subjectCount; i++)
		{
			int subjectSize = Subjects[i].size();
			file.write("&subjectSize", sizeof(subjectSize));
			file.write("Subjects[i].c_str()", Subjects[i].size());
			cout << "Subject[" << i << "] : " << Subjects[i] << endl;
		}
		
		file.write("&contentCount", sizeof(contentCount));
		for (i=0; i<contentCount; i++)
		{
			int contentSize = Contents[i].size();
			file.write("&contentSize", sizeof(contentSize));
			file.write("Contents[i].c_str()", Contents[i].size());
			cout << "Content[" << i << "] : " << Contents[i] << endl;
		}
	}

	file.close();

	SAFE_DELETE(pStmt);
}
