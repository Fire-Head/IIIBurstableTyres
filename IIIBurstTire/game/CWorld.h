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
	
	static bool ProcessVerticalLine(CVector const& pos, float a2, CColPoint& point, CEntity*& entity, bool a5, bool a6, bool a7, bool a8, bool a9, bool a10, CStoredCollPoly* a11);
	static bool ProcessLineOfSight(CVector  const& origin, CVector  const& target, CColPoint &colPoint, CEntity *&colEntity, bool buildings, bool vehicles, bool peds, bool objects, bool dummies, bool seeThrough, bool cameraObjects);
	static bool CameraToIgnoreThisObject(CEntity* entity);
};