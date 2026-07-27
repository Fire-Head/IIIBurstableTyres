#pragma once

#include "..\address.h"
#include "CPool.h"
#include "CPed.h"
#include "CPlayerPed.h"
#include "CObject.h"
#include "CCutsceneHead.h"

class CPools
{
public:
	static CPool<CPed, CPlayerPed> *&ms_pPedPool;
	static CPool<CObject, CCutsceneHead> *&ms_pObjectPool;
};