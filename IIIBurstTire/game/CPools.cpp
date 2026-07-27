#include "CPools.h"

CPool<CPed, CPlayerPed> *&CPools::ms_pPedPool = *(CPool<CPed, CPlayerPed> **)AddressByVersion(0x8F2C60, 0x8F2D14, 0x902E54);

CPool<CObject, CCutsceneHead> *&CPools::ms_pObjectPool = *(CPool<CObject, CCutsceneHead> **)AddressByVersion(0x880E28, 0x880DD8, 0x890F18);
