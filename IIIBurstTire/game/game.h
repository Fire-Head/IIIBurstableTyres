#pragma once

#include "types.h"
#include "CVector.h"
#include "CVector2D.h"
#include "CRGBA.h"
#include "CEntity.h"
#include "CMatrix.h"
#include "CParticle.h"
#include "CParticleObject.h"
#include "CGeneral.h"
#include "CTxdStore.h"
#include "CTimer.h"
#include "CColModel.h"
#include "CBaseModelInfo.h"
#include "CPed.h"
#include "CCopPed.h"
#include "CAutomobile.h"
#include "CBoat.h"
#include "CObject.h"
#include "CFileMgr.h"
#include "cDMAudio.h"
#include "CModelInfo.h"
#include "CSprite.h"
#include "CWorld.h"
#include "CCamera.h"
#include "CShadows.h"
#include "CTempColModels.h"
#include "CPtrNode.h"
#include "CPtrList.h"
#include "CCollision.h"
#include "cAudioManager.h"
#include "cSampleManager.h"
#include "CGlass.h"
#include "CTimeCycle.h"
#include "CAnimManager.h"
#include "CPools.h"
#include "CCarCtrl.h"
#include "CDarkel.h"
#include "eModelID.h"


#define RsGlobal (*(RsGlobalType *)ADDR_RSGLOBAL)
#define PsGlobal (*(PsGlobalType *)ADDR_PSGLOBAL)
#define PSGLOBAL(var) (((PsGlobalType *)(RsGlobal.ps))->var)

static   CVector operator*(CMatrix const& matrix, CVector const& vector)
{
	return ((CVector (__cdecl *)(CMatrix  const&, CVector  const&))AddressByVersion(0x4BA4D0, 0x4BA5C0, 0x4BA550))(matrix, vector);
}

static CAnimBlendAssociation *RpAnimBlendClumpGetAssociation(RpClump *pClump, unsigned int AnimId)
{
	return ((CAnimBlendAssociation *(__cdecl *)(RpClump *, unsigned int))AddressByVersion(0x4055C0, 0x4055C0, 0x4055C0))(pClump, AnimId);
}

static   CPlayerPed *(__cdecl *FindPlayerPed)() = (CPlayerPed *(__cdecl *)())FUNC_FINDPLAYERPED;
static   CVehicle *(__cdecl *FindPlayerVehicle)() = (CVehicle *(__cdecl *)())FUNC_FINDPLAYERVEHICLE;