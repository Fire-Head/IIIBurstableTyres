#include "CParticle.h"

CParticle *&CParticle::m_pUnusedListHead = *(CParticle **)AddressByVersion(0x8F3958, 0x8F3A0C, 0x903B4C);
	

// Converted from static void __cdecl CParticle::ReloadConfig() 0x50C430
void CParticle::ReloadConfig()
{
	((void (__cdecl *)())AddressByVersion(0x50C430, 0x50C520, 0x50C4B0))();
}

// Converted from static void __cdecl CParticle::Initialise() 0x50C570
void CParticle::Initialise()
{
	((void (__cdecl *)())AddressByVersion(0x50C570, 0x50C660, 0x50C5F0))();
}

// Converted from static void __cdecl CParticle::Shutdown() 0x50CF40
void CParticle::Shutdown()
{
	((void (__cdecl *)())AddressByVersion(0x50CF40, 0x50D030, 0x50CFC0))();
}

// Converted from static CParticle * __cdecl CParticle::AddParticle(tParticleType type, CVector const &vecPos, CVector const &vecDir, CEntity *pEntity, Float fSize, Int32 nRotationSpeed, Int32 nRotation, Int32 nCurFrame, Int32 nLifeSpan) 0x50D140
CParticle* CParticle::AddParticle(tParticleType type, CVector const& vecPos, CVector const& vecDir, CEntity* pEntity, float fSize, int nRotationSpeed, int nRotation, int nCurFrame, int nLifeSpan)
{
	return ((CParticle* (__cdecl *)(tParticleType, CVector const&, CVector const&, CEntity*, float, int, int, int, int))AddressByVersion(0x50D140, 0x50D330, 0x50D2C0))(type, vecPos, vecDir, pEntity, fSize, nRotationSpeed, nRotation, nCurFrame, nLifeSpan);
}

// Converted from static CParticle * __cdecl CParticle::AddParticle(tParticleType type, CVector const &vecPos, CVector const &vecDir, CEntity *pEntity, Float fSize, RwRGBA const &color, Int32 nRotationSpeed, Int32 nRotation, Int32 nCurFrame, Int32 nLifeSpan) 0x50D190
CParticle* CParticle::AddParticle(tParticleType type, CVector const& vecPos, CVector const& vecDir, CEntity* pEntity, float fSize, RwRGBA const& color, int nRotationSpeed, int nRotation, int nCurFrame, int nLifeSpan)
{
	return ((CParticle* (__cdecl *)(tParticleType, CVector const&, CVector const&, CEntity*, float, RwRGBA const&, int, int, int, int))AddressByVersion(0x50D190, 0x50D380, 0x50D310))(type, vecPos, vecDir, pEntity, fSize, color, nRotationSpeed, nRotation, nCurFrame, nLifeSpan);
}

// Converted from static void __cdecl CParticle::Update() 0x50DCF0
void CParticle::Update()
{
	((void (__cdecl *)())AddressByVersion(0x50DCF0, 0x50DEE0, 0x50DE70))();
}

// Converted from static void __cdecl CParticle::Render() 0x50EE20
void CParticle::Render()
{
	((void (__cdecl *)())AddressByVersion(0x50EE20, 0x50F010, 0x50EFA0))();
}

// Converted from static void __cdecl CParticle::RemovePSystem(tParticleType type) 0x50F6E0
void CParticle::RemovePSystem(tParticleType type)
{
	((void (__cdecl *)(tParticleType))AddressByVersion(0x50F6E0, 0x50F8D0, 0x50F860))(type);
}

// Converted from static void __cdecl CParticle::RemoveParticle(CParticle *pParticle, CParticle *pPrevParticle, tParticleSystemData *pPSystemData) 0x50F720
void CParticle::RemoveParticle(CParticle* pParticle, CParticle* pPrevParticle, tParticleSystemData* pPSystemData)
{
	((void (__cdecl *)(CParticle*, CParticle*, tParticleSystemData*))AddressByVersion(0x50F720, 0x50F910, 0x50F8A0))(pParticle, pPrevParticle, pPSystemData);
}

