//////////////////////////////////////////////////////////////////////////////
// Filename    : PCItemInfo.h
// Written By  : elca
// Description :
// ������ �ϳ��� ���� ������ ������ �ִ� ��Ŷ�̴�.
// ��ǥ�����, ����Ʈ�� ���� ������ ������ ���� �ʴ�.
// �κ��丮�� ���õ� ���� �������� ��ӵǾ� ���ȴ�.
//////////////////////////////////////////////////////////////////////////////

#ifndef __SLAYER_ITEM_INFO_H__
#define __SLAYER_ITEM_INFO_H__

#include <algorithm>

#include "Types.h"
#include "Exception.h"
#include "SocketInputStream.h"
#include "SocketOutputStream.h"
#include "SubItemInfo.h"
#include "Assert.h"

//////////////////////////////////////////////////////////////////////////////
// class PCItemInfo
//////////////////////////////////////////////////////////////////////////////

class PCItemInfo 
{
public:
	PCItemInfo() throw();
	virtual ~PCItemInfo() throw();

public:
	void read (SocketInputStream & iStream) throw (ProtocolException, Error);
	void write (SocketOutputStream & oStream) const throw (ProtocolException, Error);

	string toString() const throw();

public:
	void setObjectID(ObjectID_t ObjectID) throw() { m_ObjectID = ObjectID; }
	ObjectID_t getObjectID() const throw() { return m_ObjectID; }

	void setItemClass (BYTE IClass) throw() { m_IClass = IClass; }
	BYTE getItemClass () const throw() { return m_IClass; }

	void setItemType (ItemType_t ItemType) throw() { m_ItemType = ItemType; }
	ItemType_t getItemType() const throw() { return m_ItemType; }

	void addOptionType(OptionType_t OptionType) throw() { m_OptionType.push_back( OptionType ); }
	void setOptionType(const list<OptionType_t>& OptionType) throw() { m_OptionType = OptionType; }
	int getOptionTypeSize() const throw() { return m_OptionType.size(); }
	const list<OptionType_t>& getOptionType() const throw() { return m_OptionType; }
	OptionType_t popOptionType() throw() 
	{ 
		if (m_OptionType.empty()) return 0;
		OptionType_t optionType = m_OptionType.front(); 
		m_OptionType.pop_front(); 
		return optionType; 
	}
	
	void setSilver(Silver_t amount) throw() { m_Silver = amount; }
	Silver_t getSilver() const throw() { return m_Silver; }

	void setGrade(Grade_t grade) throw() { m_Grade = grade; }
	Grade_t getGrade() const throw() { return m_Grade; }

	void setDurability(Durability_t Durability) throw() { m_Durability = Durability; }
	Durability_t getDurability() const throw() { return m_Durability; }

	void setEnchantLevel(EnchantLevel_t level) throw() { m_EnchantLevel = level; }
	EnchantLevel_t getEnchantLevel() throw() { return m_EnchantLevel; }

	void setItemNum(ItemNum_t ItemNum) throw() { m_ItemNum = ItemNum; }
	ItemNum_t getItemNum() const throw() { return m_ItemNum; }

	void setMainColor(WORD MainColor) throw() { m_MainColor = MainColor; }
	WORD getMainColor() const throw() { return m_MainColor; }

	BYTE getListNum() const throw() { return m_ListNum; }
	void setListNum(BYTE ListNum) throw() { m_ListNum = ListNum; }

	void addListElement(SubItemInfo* pSubItemInfo) throw() 
	{ 
		m_SubItemInfoList.push_back(pSubItemInfo); 
		m_ListNum++;
	}

	void clearList() throw() { m_SubItemInfoList.clear(); m_ListNum = 0; }

	SubItemInfo* popFrontListElement() throw() 
	{ 
		SubItemInfo* TempSubItemInfo = m_SubItemInfoList.front(); 
		m_SubItemInfoList.pop_front(); 
		return TempSubItemInfo; 
	}
	//1208 wlzzi
	void setAddedInfo1(BYTE idx) throw() { m_AddedInfo1 = idx; }
	BYTE getAddedInfo1() const throw() { return m_AddedInfo1; }
	void setAddedInfo2(BYTE idx) throw() { m_AddedInfo2 = idx; }
	BYTE getAddedInfo2() const throw() { return m_AddedInfo2; }
	
public:
	uint getSize() const throw()
	{
		return szObjectID +
			szBYTE +
			szItemType + 
			szBYTE + m_OptionType.size() +
			szDurability +
			szSilver + 
			szGrade +
			szEnchantLevel +
			szItemNum +
			szWORD +
			szBYTE +
			SubItemInfo::getMaxSize()*m_ListNum
			// Was "+ szBYTE * 2" for m_AddedInfo1/m_AddedInfo2, which write()
			// no longer emits (__PET_VISION_AMPLE is __OFF client-side).
			// Now +szBYTE for the m_CashItem byte write() does emit
			// (__INTERNATIONAL_PREMIUM_SYSTEM is __ON client-side).
			+ szBYTE
#ifdef VERSION_THIRD_ENCHANT_1
		+ szBYTE + m_ThirdOptionType.size() +
			szBYTE
#endif
		// mix-option block no longer written (__PET_MIXINGFORGE __OFF)
		;
	}

	static uint getMaxSize() throw()
	{
		return szObjectID +
			szBYTE +
			szItemType + 
			szBYTE + 255 +
			szDurability +
			szSilver + 
			szGrade +
			szEnchantLevel +
			szItemNum +
			szWORD +
			szBYTE +
			SubItemInfo::getMaxSize()*8
			//1208 wlzzi
			+ szBYTE * 2
#ifdef VERSION_THIRD_ENCHANT_1
		+ szBYTE + 255 +
			szBYTE
#endif
			//20090601 ksym555
			+ szBYTE + 10 * szOptionType;
	}

#ifdef VERSION_THIRD_ENCHANT_1
	void addThirdOptionType(OptionType_t OptionType) throw() { m_ThirdOptionType.push_back( OptionType ); }
	int getThirdOptionTypeSize() const throw() { return m_ThirdOptionType.size(); }
	const list<OptionType_t>& getThirdOptionType() const throw() { return m_ThirdOptionType; }
	OptionType_t popThirdOptionType() throw() 
	{ 
		if (m_ThirdOptionType.empty()) return 0;
		OptionType_t optionType = m_ThirdOptionType.front(); 
		m_ThirdOptionType.pop_front(); 
		return optionType; 
	}
	void setThirdOptionType(const list<OptionType_t>& optionType) throw() { m_ThirdOptionType = optionType; }
	BYTE getThirdEnchantType() const throw() { return m_ThirdEnchantType; }
	void setThirdEnchantType(BYTE ThirdEnchantType)throw() {m_ThirdEnchantType = ThirdEnchantType; }
	
	//20090601 ksym555
	void						setMixOptionType(const list<OptionType_t>& mixOptionType) throw() { m_MixOptionType = mixOptionType; }
	int							getMixOptionTypeSize() const throw() { return m_MixOptionType.size(); }
	const list<OptionType_t>&	getMixOptionType() const throw() { return m_MixOptionType; }
	OptionType_t				getMixFirstOptionType() const throw() { if (m_MixOptionType.empty()) return 0; return m_MixOptionType.front(); }
	void						removeMixOptionType(OptionType_t mixOptionType) throw() { std::list<OptionType_t>::iterator itr = std::find(m_MixOptionType.begin(), m_MixOptionType.end(), mixOptionType); if (itr!=m_MixOptionType.end()) m_MixOptionType.erase(itr); }
	void						addMixOptionType(OptionType_t mixOptionType) throw() { m_MixOptionType.push_back(mixOptionType); }

#endif
protected:
	ObjectID_t         m_ObjectID;         // item object id
	BYTE               m_IClass;           // item class
	ItemType_t         m_ItemType;         // item type
	list<OptionType_t> m_OptionType;       // item option type
#ifdef VERSION_THIRD_ENCHANT_1
	list<OptionType_t> m_ThirdOptionType;       // item option type
	BYTE			   m_ThirdEnchantType;			// Third Enchant type
#endif
	Durability_t       m_Durability;       // item durability
	Silver_t           m_Silver;           // silver coating amount
	Grade_t				m_Grade;			// ������ ���
	EnchantLevel_t     m_EnchantLevel;     // item enchant level
	ItemNum_t          m_ItemNum;          // number of item
	WORD               m_MainColor;        // item color
	BYTE               m_ListNum;          // number of sub item
	list<SubItemInfo*> m_SubItemInfoList;  // actual sub item info
	
	//1208 wlzzi - PetOption�� indexing���� �߰�
	//	- PetOption2�� �߰��Ǹ鼭 �ʿ��� ����. -_-;;
	//	- ������ Ŭ���� ���� �߰����� ������ ������ �ʿ��� �� �������� ����ϵ��� .. ���̹� �Ѵ�.
	BYTE			   m_AddedInfo1;
	BYTE			   m_AddedInfo2;
	
	//20090601 ksym555
	list<OptionType_t>	m_MixOptionType;
};

#endif
