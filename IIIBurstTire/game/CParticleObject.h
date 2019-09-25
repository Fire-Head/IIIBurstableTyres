#pragma once
#include "types.h"
#include "..\address.h"
#include "CPlaceable.h"
#include "CParticle.h"
#include "CRGBA.h"

#define MAX_PARTICLEOBJECTS 100

enum eParticleObjectType
{
	POBJECT_PAVEMENT_STEAM = 0,
	POBJECT_PAVEMENT_STEAM_SLOWMOTION,
	POBJECT_WALL_STEAM,
	POBJECT_WALL_STEAM_SLOWMOTION,
	POBJECT_DARK_SMOKE,
	POBJECT_FIRE_HYDRANT,
	POBJECT_CAR_WATER_SPLASH,
	POBJECT_PED_WATER_SPLASH,
	POBJECT_SPLASHES_AROUND,
	POBJECT_SMALL_FIRE,
	POBJECT_BIG_FIRE,
	POBJECT_DRY_ICE,
	POBJECT_DRY_ICE_SLOWMOTION,
	POBJECT_FIRE_TRAIL,
	POBJECT_SMOKE_TRAIL,
	POBJECT_FIREBALL_AND_SMOKE,
	POBJECT_ROCKET_TRAIL,
	POBJECT_EXPLOSION_ONCE,
	POBJECT_CATALINAS_GUNFLASH,
	POBJECT_CATALINAS_SHOTGUNFLASH,
};

enum eParticleObjectState
{
	PARTICLEOBJECTSTATE_INITIALISED = 0,
	PARTICLEOBJECTSTATE_UPDATE_CLOSE,
	PARTICLEOBJECTSTATE_UPDATE_FAR,
	PARTICLEOBJECTSTATE_FREE,
};

class CParticleObject : public CPlaceable
{
public:
	CParticleObject *m_pNext;
	CParticleObject *m_pPrev;
	CParticle *m_pParticle;
	Int32 m_nRemoveTimer;
	Int32 m_Type;
	//eParticleObjectType m_Type;
	//tParticleType m_ParticleType;
	Int32 m_ParticleType;
	UInt8 m_nNumEffectCycles;
	UInt8 m_nSkinFrames;
	UInt16 m_nFrameCounter;
	UInt16 m_nState;
	char _pad0[2];
	CVector m_vecTarget;
	Float m_fRandVal;
	Float m_fSize;
	CRGBA m_Color;
	UInt8 m_bRemove;
	UInt8 m_nCreationChance;
	char _pad1[2];
  
	static CParticleObject *&pCloseListHead;
	static CParticleObject *&pFarListHead;
	static CParticleObject *&pUnusedListHead;
	
	static void Initialise();
	static void UpdateAll();
	
	static CParticleObject* AddObject(unsigned short Type, CVector const& vecPos, CVector const& vecTarget, float fSize, unsigned int nLifeTime, RwRGBA const& Color, unsigned char bCanRemove);
};

VALIDATE_SIZE(CParticleObject, 0x88);

//extern CParticleObject (&gPObjectArray)[MAX_PARTICLEOBJECTS];
extern CParticleObject (&gPObjectArray)[MAX_PARTICLEOBJECTS];