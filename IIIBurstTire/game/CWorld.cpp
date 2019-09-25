#include "CWorld.h"

char& CWorld::bIncludeDeadPeds = *(char *)AddressByVersion(0x95CD8F, 0x95CF47, 0x96D087);
char& CWorld::bIncludeCarTyres = *(char*)AddressByVersion(0x95CDAA, 0x95CF63, 0x96D0A3);
unsigned short& CWorld::ms_nCurrentScanCode = *(unsigned short *)AddressByVersion(0x95CC64, 0x95CE1C, 0x96CF5C);
CEntity *&CWorld::pIgnoreEntity = *(CEntity **)AddressByVersion(0x8F6494, 0x8F664C, 0x90678C);

bool CWorld::CameraToIgnoreThisObject(CEntity* entity)
{
	return ((bool (__cdecl *)(CEntity*))AddressByVersion(0X4B5C30, 0X4B5D20, 0X4B5CB0))(entity);
}

bool CWorld::ProcessLineOfSight(CVector  const& origin, CVector  const& target, CColPoint &colPoint, CEntity *&colEntity, bool buildings, bool vehicles, bool peds,  bool objects, bool dummies, bool seeThrough, bool cameraObjects)
{
	return ((bool (__cdecl *)(CVector  const&, CVector  const&, CColPoint &, CEntity *&, bool, bool, bool, bool, bool, bool, bool))AddressByVersion(0x4AF970, 0x4AFA60, 0x4AF9F0))(origin, target, colPoint, colEntity, buildings, vehicles, peds, objects, dummies, seeThrough, cameraObjects);
}

// Converted from static bool __cdecl CWorld::ProcessVerticalLine(CVector const &pos, float a2, CColPoint &point, CEntity *&entity, bool a5, bool a6, bool a7, bool a8, bool a9, bool a10, CStoredCollPoly *a11) 0x4B0DE0
bool CWorld::ProcessVerticalLine(CVector const& pos, float a2, CColPoint& point, CEntity*& entity, bool a5, bool a6, bool a7, bool a8, bool a9, bool a10, CStoredCollPoly* a11)
{
	return ((bool (__cdecl *)(CVector const&, float, CColPoint&, CEntity*&, bool, bool, bool, bool, bool, bool, CStoredCollPoly*))AddressByVersion(0x4B0DE0, 0x4B0ED0, 0x4B0E60))(pos, a2, point, entity, a5, a6, a7, a8, a9, a10, a11);
}

// Converted from static float __cdecl CWorld::FindGroundZFor3DCoord(float x, float y, float z, bool *bOut) 0x4B3AE0
float CWorld::FindGroundZFor3DCoord(float x, float y, float z, bool* bOut)
{
	return ((float (__cdecl *)(float, float, float, bool*))AddressByVersion(0x4B3AE0, 0x4B3BD0, 0x4B3B60))(x, y, z, bOut);
}
