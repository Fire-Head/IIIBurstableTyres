#include "CParticleObject.h"

CParticleObject (&gPObjectArray)[MAX_PARTICLEOBJECTS] = *(CParticleObject(*)[MAX_PARTICLEOBJECTS])AddressByVersion(0x62A58C, 0x62A58C, 0x63A58C);

CParticleObject *&CParticleObject::pCloseListHead = *(CParticleObject **)AddressByVersion(0x8F4340, 0x8F43F4, 0x904534);
CParticleObject *&CParticleObject::pFarListHead = *(CParticleObject **)AddressByVersion(0x942F78, 0x943130, 0x953270);
CParticleObject *&CParticleObject::pUnusedListHead = *(CParticleObject **)AddressByVersion(0x94128C, 0x941444, 0x951584);

// Converted from static void __cdecl CParticleObject::Initialise() 0x42C760
void CParticleObject::Initialise()
{
	((void (__cdecl *)())AddressByVersion(0x4BC440, 0x4BC530, 0x4BC4C0))();
}

// Converted from static void __cdecl CParticleObject::UpdateAll() 0x4BCA30
void CParticleObject::UpdateAll()
{
	((void (__cdecl *)())AddressByVersion(0x4BCA30, 0x4BCB20, 0x4BCAB0))();
}

// Converted from static CParticleObject * __cdecl CParticleObject::AddObject(unsigned short Type, CVector const &vecPos, CVector const &vecTarget, float fSize, unsigned int nLifeTime, RwRGBA const &Color, unsigned char bCanRemove) 0x4BC5B0
CParticleObject* CParticleObject::AddObject(unsigned short Type, CVector const& vecPos, CVector const& vecTarget, float fSize, unsigned int nLifeTime, RwRGBA const& Color, unsigned char bCanRemove)
{
	return ((CParticleObject* (__cdecl *)(unsigned short, CVector const&, CVector const&, float, unsigned int, RwRGBA const&, unsigned char))AddressByVersion(0x4BC5B0, 0x4BC6A0, 0x4BC630))(Type, vecPos, vecTarget, fSize, nLifeTime, Color, bCanRemove);
}
