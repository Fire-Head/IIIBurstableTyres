#pragma once
#include <windows.h>
#include "CPlaceable.h"
#include "RenderWare.h"
#include "CRect.h"

class CEntity;
struct CReference
{
	CReference *m_pNext;
	CEntity **m_ppEntity;
};

#define SL_BUILDINGCENTER 0
#define SL_BUILDINGEDGE 1
#define SL_OBJECTCENTER 2
#define SL_OBJECTEDGE 3
#define SL_VEHICLECENTER 4
#define SL_VEHICLEEDGE 5
#define SL_PEDCENTER 6
#define SL_PEDEDGE 7
#define SL_DUMMYCENTER 8
#define SL_DUMMYEDGE 9

enum eEntityStatus
{
	STATUS_PLAYER = 0x0,
	STATUS_PLAYER_PLAYBACKFROMBUFFER = 0x1,
	STATUS_SIMPLE = 0x2,
	STATUS_PHYSICS = 0x3,
	STATUS_ABANDONED = 0x4,
	STATUS_WRECKED = 0x5,
	STATUS_TRAIN_MOVING = 0x6,
	STATUS_TRAIN_NOT_MOVING = 0x7,
	STATUS_HELI = 0x8,
	STATUS_PLANE = 0x9,
	STATUS_PLAYER_REMOTE = 0xA,
	STATUS_PLAYER_DISABLED = 0xB,
};

enum eEntityType
{
	ENTITY_TYPE_NOTHING = 0x0,
	ENTITY_TYPE_BUILDING = 0x1,
	ENTITY_TYPE_VEHICLE = 0x2,
	ENTITY_TYPE_PED = 0x3,
	ENTITY_TYPE_OBJECT = 0x4,
	ENTITY_TYPE_DUMMY = 0x5,
	ENTITY_TYPE_NOTINPOOLS = 0x6,
};


class CEntity : public CPlaceable
{
protected:
	DUMMYB(CEntity, CPlaceable);
public:

	union
	{
		RwObject *m_pRwObject;
		RpAtomic *m_pRwAtomic;
		RpClump  *m_pRwClump;
	};
	
    //RwObject *m_pRwObject;
    union {
	
		struct {
			/*
			char m_nFlags;
			char m_nTypeStatus;
			char m_ExplosionFlag; //2,   14 car      /0x52
			char m_DamageFlag; //15                 //0x53
			char field_54;
			char field_55;
			*/
			char m_Flags;
			char m_Flags1;
			char m_Flags2;
			char m_Flags3;
			char m_Flags4;
			char m_Flags5;
		};
	
		struct {
			unsigned char m_nType : 3;
			unsigned char m_nState : 5;
			
			//unsigned char m_nFlags1;
			unsigned char m_bUsesCollision : 1;
			unsigned char m_bCollisionProcessed : 1;
			unsigned char m_bIsStatic : 1;
			unsigned char m_bHasCollidedThisFrame : 1;
			unsigned char m_bHeavyCollision : 1;
			unsigned char m_bIsStuck : 1;
			unsigned char m_bIsInSafePosition : 1;
			unsigned char m_bHasContacted : 1;
			
			//unsigned char m_nFlags2;
			unsigned char m_bControlPostponed : 1;
			unsigned char m_bExplosionProof : 1;
			unsigned char m_bIsVisible : 1;
			unsigned char m_bIsOnGround : 1;
			unsigned char m_bRequiresScorchedLights : 1;
			unsigned char m_bHasBlip : 1;
			unsigned char m_bIsBIGBuilding : 1;
			unsigned char m_bRenderDamaged : 1;
			
			//unsigned char m_nFlags3;
			unsigned char m_bBulletProof : 1;
			unsigned char m_bFireProof : 1;
			unsigned char m_bCollisionProof : 1;
			unsigned char m_bMeleeProof : 1;
			unsigned char m_bOnlyDamagedByPlayer : 1;
			unsigned char b3_20 : 1;
			unsigned char m_bIsCullzoneVisible : 1;
			unsigned char n_bIsTreadableVisible : 1;
			
			//unsigned char m_nFlags4;
			unsigned char m_bDestroyWhenNextProcessed /*m_bRemoveFromWorld*/ : 1;
			unsigned char m_bHasCollidedWithBuilding/*m_bHasHitWall*/ : 2;
			unsigned char m_bIsBeingRendered : 1;
			unsigned char b4_8 : 1;
			unsigned char m_bIsSubway : 1;
			unsigned char m_bDrawLast : 1;
			unsigned char b4_40 : 1;
			unsigned char m_bIsInactivePickup : 1;
			
			//unsigned char m_nFlags5;
			unsigned char b5_1 : 1;
			unsigned char b5_2 : 2;
		};
	};
	
    char field_unk[2];
    unsigned short m_nScanCode;
    unsigned short m_nRandomSeed;
    short m_nModelIndex;
    short m_nLevel;
	//char m_nBuildingIsland;
    //char field_5F;
    CReference *m_pReference;
	
	CEntity();
	virtual ~CEntity();
};

VALIDATE_SIZE(CEntity, 0x64);