#pragma once
#include <windows.h>
#include "..\address.h"
#include "CVector.h"
#include "RenderWare.h"
#include "cParticleSystemMgr.h"

enum tParticleType
{
  PARTICLE_SPARK = 0x0,
  PARTICLE_SPARK_SMALL = 0x1,
  PARTICLE_WHEEL_DIRT = 0x2,
  PARTICLE_WHEEL_WATER = 0x3,
  PARTICLE_BLOOD = 0x4,
  PARTICLE_BLOOD_SMALL = 0x5,
  PARTICLE_BLOOD_SPURT = 0x6,
  PARTICLE_DEBRIS = 0x7,
  PARTICLE_DEBRIS2 = 0x8,
  PARTICLE_WATER = 0x9,
  PARTICLE_FLAME = 0xA,
  PARTICLE_FIREBALL = 0xB,
  PARTICLE_GUNFLASH = 0xC,
  PARTICLE_GUNFLASH_NOANIM = 0xD,
  PARTICLE_GUNSMOKE = 0xE,
  PARTICLE_GUNSMOKE2 = 0xF,
  PARTICLE_SMOKE = 0x10,
  PARTICLE_SMOKE_SLOWMOTION = 0x11,
  PARTICLE_GARAGEPAINT_SPRAY = 0x12,
  PARTICLE_SHARD = 0x13,
  PARTICLE_SPLASH = 0x14,
  PARTICLE_CARFLAME = 0x15,
  PARTICLE_STEAM = 0x16,
  PARTICLE_STEAM2 = 0x17,
  PARTICLE_STEAM_NY = 0x18,
  PARTICLE_STEAM_NY_SLOWMOTION = 0x19,
  PARTICLE_ENGINE_STEAM = 0x1A,
  PARTICLE_RAINDROP = 0x1B,
  PARTICLE_RAINDROP_SMALL = 0x1C,
  PARTICLE_RAIN_SPLASH = 0x1D,
  PARTICLE_RAIN_SPLASH_BIGGROW = 0x1E,
  PARTICLE_RAIN_SPLASHUP = 0x1F,
  PARTICLE_WATERSPRAY = 0x20,
  PARTICLE_EXPLOSION_MEDIUM = 0x21,
  PARTICLE_EXPLOSION_LARGE = 0x22,
  PARTICLE_EXPLOSION_MFAST = 0x23,
  PARTICLE_EXPLOSION_LFAST = 0x24,
  PARTICLE_CAR_SPLASH = 0x25,
  PARTICLE_BOAT_SPLASH = 0x26,
  PARTICLE_BOAT_THRUSTJET = 0x27,
  PARTICLE_BOAT_WAKE = 0x28,
  PARTICLE_WATER_HYDRANT = 0x29,
  PARTICLE_WATER_CANNON = 0x2A,
  PARTICLE_EXTINGUISH_STEAM = 0x2B,
  PARTICLE_PED_SPLASH = 0x2C,
  PARTICLE_PEDFOOT_DUST = 0x2D,
  PARTICLE_HELI_DUST = 0x2E,
  PARTICLE_HELI_ATTACK = 0x2F,
  PARTICLE_ENGINE_SMOKE = 0x30,
  PARTICLE_ENGINE_SMOKE2 = 0x31,
  PARTICLE_CARFLAME_SMOKE = 0x32,
  PARTICLE_FIREBALL_SMOKE = 0x33,
  PARTICLE_PAINT_SMOKE = 0x34,
  PARTICLE_TREE_LEAVES = 0x35,
  PARTICLE_CARCOLLISION_DUST = 0x36,
  PARTICLE_CAR_DEBRIS = 0x37,
  PARTICLE_HELI_DEBRIS = 0x38,
  PARTICLE_EXHAUST_FUMES = 0x39,
  PARTICLE_RUBBER_SMOKE = 0x3A,
  PARTICLE_BURNINGRUBBER_SMOKE = 0x3B,
  PARTICLE_BULLETHIT_SMOKE = 0x3C,
  PARTICLE_GUNSHELL_FIRST = 0x3D,
  PARTICLE_GUNSHELL = 0x3E,
  PARTICLE_GUNSHELL_BUMP1 = 0x3F,
  PARTICLE_GUNSHELL_BUMP2 = 0x40,
  PARTICLE_TEST = 0x41,
  PARTICLE_BIRD_FRONT = 0x42,
  PARTICLE_RAINDROP_2D = 0x43,
  MAX_PARTICLES,
};

class CEntity;

class CParticle
{
public:
	CVector   m_vecPosition;
	CVector   m_vecVelocity; //m_vecTarget
	CVector   m_vecScreenPosition;
	Int32     m_nTimeWhenWillBeDestroyed;
	Int32     m_nTimeWhenColorWillBeChanged;
	Float     m_fZGround;
	CVector   m_vecParticleMovementOffset;
	Int16     m_nCurrentZRotation;
	UInt16     m_nZRotationTimer;
	Float     m_fCurrentZRadius;
	UInt16     m_nZRadiusTimer;
	char _pad0[2];
	Float     m_fSize;
	Float     m_fExpansionRate;
	UInt16     m_nFadeToBlackTimer;
	UInt16     m_nFadeAlphaTimer;
	UInt8     m_nColorIntensity;
	UInt8     m_nAlpha;
	UInt16    m_nCurrentFrame;
	Int16     m_nAnimationSpeedTimer;
	Int16     m_nRotationStep;
	Int16     m_nRotation;
	RwRGBA    m_Color;
	char _pad1[2];
	CParticle *m_pNext;
	
	static void ReloadConfig();
	static void Initialise();
	static void Shutdown();
	static CParticle* AddParticle(tParticleType type, CVector const& vecPos, CVector const& vecDir, CEntity* pEntity, float fSize, int nRotationSpeed, int nRotation, int nCurFrame, int nLifeSpan);
	static CParticle* AddParticle(tParticleType type, CVector const& vecPos, CVector const& vecDir, CEntity* pEntity, float fSize, RwRGBA const& color, int nRotationSpeed, int nRotation, int nCurFrame, int nLifeSpan);
	static void Update();
	static void Render();
	static void RemovePSystem(tParticleType type);
	static void RemoveParticle(CParticle* pParticle, CParticle* pPrevParticle, tParticleSystemData* pPSystemData);
	
	static CParticle *&m_pUnusedListHead;
};