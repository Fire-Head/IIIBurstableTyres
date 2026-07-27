#pragma once
#include "..\address.h"
#include "CVector.h"
#include "CEntity.h"
#include "CColPoint.h"
#include "CStoredCollPoly.h"

class CWorld
{
public:
	static char& bIncludeDeadPeds;
	static char& bIncludeCarTyres;
	static unsigned short& ms_nCurrentScanCode;
	static CEntity *&pIgnoreEntity;
	static float FindGroundZFor3DCoord(float x, float y, float z, bool* bOut);
	
	static void Add(CEntity* pEntity);
	static void Remove(CEntity* pEntity);
	static bool ProcessVerticalLine(CVector const& pos, float a2, CColPoint& point, CEntity*& entity, bool a5, bool a6, bool a7, bool a8, bool a9, bool a10, CStoredCollPoly* a11);
	static bool ProcessLineOfSight(CVector  const& origin, CVector  const& target, CColPoint &colPoint, CEntity *&colEntity, bool buildings, bool vehicles, bool peds, bool objects, bool dummies, bool seeThrough, bool cameraObjects);
	static bool CameraToIgnoreThisObject(CEntity* entity);
	static void FindObjectsInRange(CVector const& point, float radius, bool b2D, short* outCount, short maxCount, CEntity** outEntities, bool buildings, bool vehicles, bool peds, bool objects, bool dummies);
	static CEntity* TestSphereAgainstWorld(CVector a1, float a2, CEntity* a3, bool a4, bool a5, bool a6, bool a7, bool a8, bool a9);
};