//////////////////////////////////////////////////////////////////////////////
// Filename    : NPCShopTemplate.h
// Written by  : excel96
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __NPCSHOPTEMPLATE_H__
#define __NPCSHOPTEMPLATE_H__

#include "Types.h"

//////////////////////////////////////////////////////////////////////////////
// NPC  
// 
// int numberOfNPC; //   NPC 
// {
//     int currentNPCID;
//     int numberOfShopTemplate
//     {
//         int eachShopTemplateID
//     } // 
//     int DescriptionLength;
//     string Description;
// } // 
//
//
// SHOPTEMPLATE  
// DWORD numberOfShopTemplate; //    
// {
//     uint ID;
//     BYTE rackType;
//     int  itemClass;
//     WORD minItemType;
//     WORD maxItemType;
//     BYTE minOptionLevel;
//     BYTE maxOptionLevel;
// } // 
//////////////////////////////////////////////////////////////////////////////

void createNPCShopTemplateFile(string npc_filename, string shop_filename);

#endif

