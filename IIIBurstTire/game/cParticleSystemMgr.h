#pragma once
#include "types.h"
#include "..\address.h"
#include "CRGBA.h"
#include "RenderWare.h"

#define MAX_PARTICLE 68

#pragma pack(push, 1)
struct tParticleSystemData
{
  Char m_aName[20];
  char _unk0[4];
  Float m_fCreateRange;
  Float m_fDefaultInitialRadius;
  Float m_fExpansionRate;
  UInt16 m_nInitialAngle;
  UInt16 m_nAngleChangeAmount;
  UInt16 m_nAngleChangeTime;
  UInt16 m_nRadiusChangeTime;
  Float m_fInitialZRadius;
  Float m_fZRadiusChangeAmount;
  UInt16 m_nFadetoBlack_FadeTime;
  SInt16 m_nFadetoBlack_FadeAmount;
  UInt8 m_nFadetoBlack_InitialIntensity;
  UInt8 m_nFadeAlpha_InitialIntensity;
  UInt16 m_nFadeAlpha_FadeTime;
  UInt16 m_nFadeAlpha_FadeAmount;
  UInt16 m_nStartAnimationFrame;
  UInt16 m_nFinalAnimationFrame;
  UInt16 m_nAnimationSpeed;
  UInt16 m_nRotationSpeed;
  char _pad0[2];
  Float m_fGravitationalAcceleration;
  Int32 m_nDrag_FrictionDecceleration;
  Int32 m_nDefaultLifeSpanOfParticle;
  Float m_fPositionRandomError;
  Float m_fVelocityRandomError;
  Float m_fExpansionRateError;
  Int32 m_nRotationRateError;
  UInt32 m_nLifeSpanErrorShape;
  Float m_fTrailLengthMultiplier;
  Int32 Flags;
  CRGBA m_RenderColouring;
  UInt8 m_InitialColorVariation;
  CRGBA m_FadeDestinationColor;
  char _pad1[3];
  UInt32 m_ColorFadeTime;
  RwRaster **m_ppRaster;
  void *m_pNextParticle;
};
#pragma pack(pop)

class cParticleSystemMgr
{
public:
	tParticleSystemData m_aParticles[68];
};

extern cParticleSystemMgr &mod_ParticleSystemManager;
