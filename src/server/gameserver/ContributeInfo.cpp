//////////////////////////////////////////////////////////////////////////////
// Filename    : ContributeInfo.cpp 
// Written by  : bigheart
// Description :
//////////////////////////////////////////////////////////////////////////////

#include "ContributeInfo.h"
#include "DB.h"

void ContributeInfo::load()
	throw(Error)
{
	Statement* pStmt;

	BEGIN_DB 
	{
		pStmt = g_pDatabaseManager->getConnection("DARKEDEN")->createStatement();

		Result* pResult = pStmt->executeQuery(
			"SELECT `Rank`, RankPoint FROM ContributeInfo ORDER BY `Rank` ASC"
			);
		int nCount = 0;
		while (pResult->next()) 
		{
			uint i = 0;
			int Rank, RankPoint;
			Rank = pResult->getInt(++i);
			RankPoint = pResult->getInt(++i);
			// m_ContributeRank is a fixed array of MAX_CONTRIBUTE_RANK; the original
			// loop indexed it with no bound, so a table with more rows than that
			// would overrun it.
			if (nCount >= MAX_CONTRIBUTE_RANK) break;

			m_ContributeRank[nCount].m_Rank = Rank;
			m_ContributeRank[nCount].m_RankPoint = RankPoint;			
			nCount++;
		}
		// ContributeInfo is empty in this database, so nCount is 0 and this used to
		// abort server start. Zero the unfilled entries and leave the contribute
		// feature inert rather than inventing rank thresholds.
		if(MAX_CONTRIBUTE_RANK != nCount)
		{
			filelog( "ContributeInfo.log", "expected %d contribute ranks, found %d - feature disabled",
				(int)MAX_CONTRIBUTE_RANK, nCount );
			for (int i = nCount; i < MAX_CONTRIBUTE_RANK; i++)
			{
				m_ContributeRank[i].m_Rank      = 0;
				m_ContributeRank[i].m_RankPoint = 0;
			}
		}

		SAFE_DELETE(pStmt);
	}
	END_DB(pStmt)
		
}

int ContributeInfo::getRank(int RankPoint)
{
	for(int i = 0; i < MAX_CONTRIBUTE_RANK; i++)
	{
		if(m_ContributeRank[i].m_RankPoint <= RankPoint)
			return m_ContributeRank[i].m_Rank;
		else
			continue;
	}	
	return 0;
}

ContributeInfo* g_pContributeInfo = NULL;