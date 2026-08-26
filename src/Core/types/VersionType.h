//////////////////////////////////////////////////////////////////////
//
// FileName		:	VersionType.h
// Description	:	���� ������ ���� ���� ���뿡 �ð� ó���ؾ���.
//
//////////////////////////////////////////////////////////////////////

// 20071001 ��ų ���� ���׷� ���� & ��ų
#define	VERSION_SKILL_1
// 20071001 Third ��æƮ �ý���
#define VERSION_THIRD_ENCHANT_1
// Stays DEFINED. The contribution feature itself is fine server-side; only its
// SERIALIZATION diverges from the client, which guards every ContributePoint
// read with #if __CONTENTS(__CONTRIBUTE_SYSTEM) (__OFF here).
//
// Undefining this looked tempting -- one switch instead of many edits -- but
// the guards are not symmetric: ActionGiveItem.cpp calls get/setContributePoint()
// unguarded, so the build breaks. The fix belongs in the PC*Info write()/getSize()
// methods, which is where the wire format actually lives.
#define __CONTRIBUTION_SYSTEM__ // �⿩�� �ý���

// Controls only whether m_ContributePoint goes ON THE WIRE, separate from the
// feature above. Left UNDEFINED: the client guards its ContributePoint reads
// with #if __CONTENTS(__CONTRIBUTE_SYSTEM), which is __OFF for
// __DESIGNED_INTERNATION, so sending the field desyncs every character payload.
//
// To re-enable, define this AND set __CONTRIBUTE_SYSTEM __ON in the client's
// ContentsFilter.h -- the two must always move together.
//#define __CONTRIBUTION_POINT_ON_WIRE__
#define __MENEGROTH_DOUNGEON_SYSTEM__


