#include "_precl.h"
#include <math.h>
#include <vector>

int wsavedEax;
#define STOREREGS()  __asm mov wsavedEax, eax __asm pushad __asm mov eax, wsavedEax
#define RESTOREREGS() __asm mov wsavedEax, eax __asm popad __asm mov eax, wsavedEax
#define STACK_REGS_SIZE 32

const UInt32 kPoppedTireCollisionSfxID = 371;
const UInt32 kTireBlownSfxID = 369;
const UInt32 kFlatTyreSfxID = 370;
const Char kBannedVehs[] = "122";

class CSettings
{
public:
	UInt32 m_nPoppedTireCollisionSfxID;		// 371, Original = 34
	UInt32 m_nTireBlownSfxID;				// 369, Original = 35
	UInt32 m_nFlatTyreSfxID;				// 370, Original = 36

	Bool m_bRandomTireBurstByPeds;			//RandomTireBurstForPeds;
	Int32 m_anWeaponsChanceForPeds[24];

	std::vector<Int32> m_vecVehicleBlackList;

	CSettings()
	{
		CIniReader Ini("");
		
		char *pGameVersion = Ini.ReadString("MAIN", "Version", "auto");
		for ( Int n = 1; n < ARRLEN(aGameVer); n++)
		{
			if (!strcmp(pGameVersion, aGameVer[n]) && strcmp(pGameVersion, "auto"))
			{
				bAutoVersionCheck = false;
				nVersion = n;
				break;
			}
		}
		if (!strcmp(pGameVersion, "auto"))
		{
			bAutoVersionCheck = true;
			nVersion = -1;
		}
		
		m_nPoppedTireCollisionSfxID = Ini.ReadInteger("MAIN", "nPoppedTireCollisionSfxID", kPoppedTireCollisionSfxID);
		m_nTireBlownSfxID = Ini.ReadInteger("MAIN", "nTireBlownSfxID", kTireBlownSfxID);
		m_nFlatTyreSfxID = Ini.ReadInteger("MAIN", "nFlatTyreSfxID", kFlatTyreSfxID);
		m_bRandomTireBurstByPeds = Ini.ReadBoolean("MAIN", "bUseRandomBurstForPeds", true);
		
		m_anWeaponsChanceForPeds[WEAPONTYPE_COLT45]      = Ini.ReadInteger("CHANCETABLE", "COLT45", 10);
		m_anWeaponsChanceForPeds[WEAPONTYPE_UZI]         = Ini.ReadInteger("CHANCETABLE", "UZI", 15);
		m_anWeaponsChanceForPeds[WEAPONTYPE_UZI_DRIVEBY] = m_anWeaponsChanceForPeds[WEAPONTYPE_UZI];
		m_anWeaponsChanceForPeds[WEAPONTYPE_SHOTGUN]     = Ini.ReadInteger("CHANCETABLE", "SHOTGUN", 25);
		m_anWeaponsChanceForPeds[WEAPONTYPE_HELICANNON]  = m_anWeaponsChanceForPeds[WEAPONTYPE_SHOTGUN];
		m_anWeaponsChanceForPeds[WEAPONTYPE_AK47]        = Ini.ReadInteger("CHANCETABLE", "AK47", 15);
		m_anWeaponsChanceForPeds[WEAPONTYPE_M16]         = Ini.ReadInteger("CHANCETABLE", "M16", 15);
		
		std::vector<cppext::String>vehsList = cppext::String(Ini.ReadString("MAIN", "BannedVehicles", kBannedVehs)).Split(",");
		
		if ( vehsList.size() > 0 )
		{
			for ( auto i = vehsList.begin(); i != vehsList.end(); ++i )
				m_vecVehicleBlackList.push_back((*i).Trim().ToInt());
		}
	}
	
	Bool IsVehicleBanned(Int32 index)
	{
		if ( m_vecVehicleBlackList.size() > 0 )
		{
			for ( Int i = 0; i < m_vecVehicleBlackList.size(); i++ )//for ( auto i = m_vecVehicleBlackList.begin(); i != m_vecVehicleBlackList.end(); ++i )
			{
				if ( m_vecVehicleBlackList[i] == index )
					return true;
			}
		}

		return false;
	}
	
}settings;

CVector vecFirePos(0.0f, 0.0f, 0.0f);

Bool __cdecl CAN_BURST_CAR_TYRES_Func(CAutomobile *This)
{
	return true;
}

typedef Bool ( __cdecl *tCAN_BURST_CAR_TYRESCB)(CAutomobile *This);
tCAN_BURST_CAR_TYRESCB CAN_BURST_CAR_TYRESCB = CAN_BURST_CAR_TYRES_Func;

//SET_CAN_BURST_CAR_TYRES = 0x53F,
//IS_CAR_TYRE_BURST = 0x496, ?
//BURST_CAR_TYRE = 0x4FE,
Bool CAN_BURST_CAR_TYRES(CAutomobile *This)
{
	return CAN_BURST_CAR_TYRESCB(This);
}

Bool __cdecl CheckTyres(CAutomobile *Auto, CColPoint *Point)
{
	UInt8 nVehicleComponent = Point->m_nPieceTypeB;
	if ( nVehicleComponent >= 13 && nVehicleComponent <= 16 )
	{
		Auto->BurstTyre(nVehicleComponent);
	
		for ( Int32 i = 0; i < 4; i++ )
		{
			CVector direction = 0.05f * Point->m_vecNormal;
			CParticle::AddParticle(PARTICLE_BULLETHIT_SMOKE, Point->m_vecPosition, direction, NULL, 0.0f, 0, 0, 0, 0);
		}
		
		return true;
	}

	return false;
}

static int jmp_0x558AF7 = AddressByVersion(0x558AF7, 0x558C27, 0x558BD7);
static int jmp_0x558948 = AddressByVersion(0x558948, 0x558A78, 0x558A28);
static int jmp_0x5589F8 = AddressByVersion(0x5589F8, 0x558B28, 0x558AD8);
void NAK BulletInfoPatch()
{
	__asm
	{
		cmp     al, 2
		jnz     _BIP_ELSE
	}

	__asm
	{
		STOREREGS()
		
		lea     eax, [esp+STACK_REGS_SIZE+0B8h+-98h]
		push    eax
		
		mov     eax, dword ptr [esp+STACK_REGS_SIZE+0B8h+4h+-70h]
		push    eax
		
		call    CheckTyres
		add     esp, 8
		
		RESTOREREGS()
		
		test    al, al
		
		jz      _BIP_CHECK_FAIL
		jmp     _BIP_CHECK_OK
	}
	
_BIP_CHECK_OK:
	VARJMP(jmp_0x558AF7);

_BIP_CHECK_FAIL:
	VARJMP(jmp_0x558948);
		
_BIP_ELSE:
	__asm
	{
		mov     eax, [esp+0B8h-70h]
		mov     al, [eax+50h]
		and     al, 7
	}
	VARJMP(jmp_0x5589F8);
}

static int jmp_0x560127 = AddressByVersion(0x560127, 0x560257, 0x560207);
static int jmp_0x55FF65 = AddressByVersion(0x55FF65, 0x560095, 0x560045);
void NAK DoBulletImpactPatch()
{
	__asm
	{
		mov     eax, dword ptr [esp+138h+14h]
		fld     dword ptr [eax+0h]
		fstp    vecFirePos.x
		
		mov     eax, dword ptr [esp+138h+14h]
		fld     dword ptr [eax+4h]
		fstp    vecFirePos.y
		
		mov     eax, dword ptr [esp+138h+14h]
		fld     dword ptr [eax+8h]
		fstp    vecFirePos.z
	}

	__asm
	{
		STOREREGS()
		
		mov     eax, dword ptr [esp+STACK_REGS_SIZE+138h+14h]
		push    eax
		
		mov     eax, dword ptr  [esp+STACK_REGS_SIZE+138h+4h+8h]
		push    eax
		
		call    CheckTyres
		add     esp, 8
		
		RESTOREREGS()
		
		test    al, al
		
		jz      _DBIP_CHECK_FAIL
		jmp     _DBIP_CHECK_OK
	}
	
_DBIP_CHECK_OK:
	__asm sub     esp, 24h
	VARJMP(jmp_0x560127);
		
_DBIP_CHECK_FAIL:
	__asm
	{
		mov     eax, [esp+138h+-118h]
		fild    dword ptr [eax+14h]
		push    eax
		fstp    [esp+13Ch+-13Ch]
	}
	VARJMP(jmp_0x55FF65);
}

static int jmp_0x55FF85 = AddressByVersion(0x55FF85, 0x5600B5, 0x560065);
void NAK DoBulletImpactPatch2()
{
	__asm
	{
		mov     vecFirePos.x, 0
		mov     vecFirePos.y, 0
		mov     vecFirePos.z, 0
	}
	
	__asm
	{
		xor     edi, edi
		fldz
		fldz
	}
	VARJMP(jmp_0x55FF85);
}

static int jmp_0x561735 = AddressByVersion(0x561735, 0x561865, 0x561815);
static int jmp_0x561244 = AddressByVersion(0x561244, 0x561374, 0x561324);
void NAK FireShotgunPatch() 
{
	__asm
	{
		STOREREGS()
		
		lea     eax, [esp+STACK_REGS_SIZE+200h+-1A0h]
		push    eax
		
		mov     eax, dword ptr [esp+STACK_REGS_SIZE+200h+4h+-178h]
		push    eax
		
		call    CheckTyres
		add     esp, 8
		
		RESTOREREGS()
		
		test    al, al
		
		jz      _FSP_CHECK_FAIL
		jmp     _FSP_CHECK_OK

	}

_FSP_CHECK_OK:
	//__asm add     esp, 24h
	VARJMP(jmp_0x561735);
	
_FSP_CHECK_FAIL:
	__asm
	{
		mov     eax, [esp+200h+-1F8h]
		fild    dword ptr [eax+14h]
		push    eax
		fstp    [esp+204h+-208h+4]
	}
	VARJMP(jmp_0x561244);

}

Bool __cdecl _ProcessLineOfSightPatch(CVector const& origin, CVector const& target, CColPoint &colPoint, CEntity *&colEntity, eWeaponType weapon, CEntity *unk, Bool buildings, Bool vehicles, Bool peds, Bool objects, Bool dummies, Bool seeThrough, Bool cameraObjects)
{
	CWorld::bIncludeCarTyres = true;
	Bool r = CWorld::ProcessLineOfSight(origin, target, colPoint, colEntity, buildings, vehicles, peds, objects, dummies, seeThrough, cameraObjects);
	CWorld::bIncludeCarTyres = false;
	return r;
}

Bool __fastcall __SetUpWheelColModel(CAutomobile *This, int edx0, CColModel *wheelCol)
{
	CVehicleModelInfo *vehModel = (CVehicleModelInfo *)CModelInfo::ms_modelInfoPtrs[This->m_nModelIndex];
	
	if ( This->m_eVehicleType != VEHICLETYPE_CAR )
		return false;

	wheelCol->m_BoundSphere.sphere.center.x = vehModel->m_pColModel->m_BoundSphere.sphere.center.x;
	wheelCol->m_BoundSphere.sphere.center.y = vehModel->m_pColModel->m_BoundSphere.sphere.center.y;
	wheelCol->m_BoundSphere.sphere.center.z = vehModel->m_pColModel->m_BoundSphere.sphere.center.z;
	wheelCol->m_BoundSphere.sphere.radius = vehModel->m_pColModel->m_BoundSphere.sphere.radius;
	wheelCol->m_BoundSphere.material = vehModel->m_pColModel->m_BoundSphere.material;
	wheelCol->m_BoundSphere.flag = vehModel->m_pColModel->m_BoundSphere.flag;
	wheelCol->m_BoundBox = vehModel->m_pColModel->m_BoundBox;
	
	CMatrix transform;
	
	float scale = 0.5f * vehModel->m_fWheelScale;
	
	transform.Attach(&This->m_aCarNodes[4]->modelling, false); // CAR_WHEEL_LF
	wheelCol->m_pSpheres[0].Set(scale, transform.pos, 23, 13);

	transform.Attach(&This->m_aCarNodes[6]->modelling, false); // CAR_WHEEL_LB
	wheelCol->m_pSpheres[1].Set(scale, transform.pos, 23, 15);

	transform.Attach(&This->m_aCarNodes[1]->modelling, false); // CAR_WHEEL_RF 
	wheelCol->m_pSpheres[2].Set(scale, transform.pos, 23, 14);

	transform.Attach(&This->m_aCarNodes[3]->modelling, false); // CAR_WHEEL_RB
	wheelCol->m_pSpheres[3].Set(scale, transform.pos, 23, 16);

	if ( This->m_aCarNodes[5] && This->m_aCarNodes[2] )
	{
		transform.Attach(&This->m_aCarNodes[5]->modelling, false); // CAR_WHEEL_LM
		wheelCol->m_pSpheres[4].Set(scale, transform.pos, 23, 15);

		transform.Attach(&This->m_aCarNodes[2]->modelling, false); // CAR_WHEEL_RM
		wheelCol->m_pSpheres[5].Set(scale, transform.pos, 23, 16);

		wheelCol->m_nNumSpheres = 6;
	}
	else
		wheelCol->m_nNumSpheres = 4;

	return true;
}

CColModel * __cdecl GetPedColModel_Func(CPed *pPed)
{
	if ( pPed->UseGroundColModel() )
		return &CTempColModels::ms_colModelPedGroundHit;
	else
		return ((CPedModelInfo *)CModelInfo::ms_modelInfoPtrs[pPed->m_nModelIndex])->m_pHitColModel;
}

typedef CColModel *( __cdecl *t_GetPedColModel_FuncCB)(CPed *pPed);
t_GetPedColModel_FuncCB GetPedColModelCB = GetPedColModel_Func;

CColModel *__cdecl GetPedColModel(CPed *pPed)
{
	return GetPedColModelCB(pPed);	
}

Bool __cdecl _ProcessLineOfSightSectorList_Func(CPtrList &ptrList, CColLine const &colLine, CColPoint &outColPoint, float &maxTouchDistance, CEntity *&outEntity, Bool doSeeThroughCheck, Bool doIgnoreCameraCheck)
{
	Bool bDeadPeds = false;
	float newTouchDist = maxTouchDistance;

	Bool bCarTyres = false;
	CColPoint wheelPoint;
	CColModel wheel;
	CColSphere aSpheres[6];
	
	if ( ptrList.m_pNode && CWorld::bIncludeDeadPeds && ptrList.m_pNode->pEntity->m_nType == 3 )
		bDeadPeds = true;

	if ( ptrList.m_pNode && CWorld::bIncludeCarTyres && ptrList.m_pNode->pEntity->m_nType == 2 )
	{
		bCarTyres = true;
		wheel.m_nNumTriangles = 0;
		wheel.m_pSpheres = aSpheres;
		wheel.m_nNumBoxes = 0;
		wheel.m_nNumSpheres = 6;
		wheel.m_nNumLines = 0;
	}
	
	//for ( CPtrNode *node = ptrList.m_pNode; node; node = node->pNext )
	CPtrNode *node = ptrList.m_pNode;
	while ( node )
	{
		CEntity *entity = node->pEntity;
		UInt32 scanCode = node->pEntity->m_nScanCode;
		node = node->pNext;

		if ( scanCode != CWorld::ms_nCurrentScanCode
			&& entity != CWorld::pIgnoreEntity
			&& (entity->m_bUsesCollision || bDeadPeds) )
		{
			if ( !doIgnoreCameraCheck || !CWorld::CameraToIgnoreThisObject(entity) )
			{
				CColModel *model = NULL;
				
				entity->m_nScanCode = CWorld::ms_nCurrentScanCode;
				
				float newTouchDist2 = newTouchDist;
				
				if ( entity->m_nType == 3 )
				{
					if ( entity->m_bUsesCollision || bDeadPeds && ((CPed *)entity)->m_nPedState == 49 )
					{
						model = GetPedColModel((CPed *)entity);
						/*
						if ( ((CPed *)entity)->UseGroundColModel() )
							model = &CTempColModels::ms_colModelPedGroundHit;
						else
							model = ((CPedModelInfo *)CModelInfo::ms_modelInfoPtrs[entity->m_nModelIndex])->m_pHitColModel;
						*/
					}
					else
						model = NULL;
				}
				else if ( entity->m_bUsesCollision )
				{
					model = ((CBaseModelInfo *)CModelInfo::ms_modelInfoPtrs[entity->m_nModelIndex])->m_pColModel;
				}

				if ( model && CCollision::ProcessLineOfSight(colLine, entity->m_sCoords, *model, outColPoint, newTouchDist, doSeeThroughCheck) )
					outEntity = entity;
				
				if ( bCarTyres && ((CAutomobile *)entity)->SetUpWheelColModel(&wheel)
					&& CCollision::ProcessLineOfSight(colLine, entity->m_sCoords, wheel, wheelPoint, newTouchDist2, false) )
				{
					if ( newTouchDist2 < newTouchDist )
					{
						newTouchDist = newTouchDist2;
						outColPoint = wheelPoint;
						outEntity = entity;
					}
					else
					{
						float fLineDot = DotProduct(colLine.m_vEnd - colLine.m_vStart, entity->m_sCoords.right);
						float fPointDot = DotProduct(outColPoint.m_vecPosition - entity->m_sCoords.pos, entity->m_sCoords.right);

						if ( ( fLineDot < -0.85f && fPointDot > 0.0f ) || ( fLineDot > 0.85f && fPointDot < 0.0f ) )
						{
							newTouchDist = newTouchDist2;
							outColPoint = wheelPoint;
							outEntity = entity;
						}
						
						/*
						if ( fLineDist < 0.0f && fPointDist > 0.0f || fLineDist > 0.0f && fPointDist < 0.0f )
						{
							CVector vec = colLine.m_vEnd - colLine.m_vStart;
							if ( fabs(fLineDist) / vec.Magnitude() > 0.5f )
							{
								newTouchDist = newTouchDist2;
								outColPoint = wheelPoint;
								outEntity = entity;
							}
						}
						*/
					}
				}
			}
		}
	}

	wheel.m_pSpheres = NULL;
	
	if ( newTouchDist < maxTouchDistance )
	{
		maxTouchDistance = newTouchDist;
		return true;
	}
	return false;
}

typedef Bool ( __cdecl *t_ProcessLineOfSightSectorListCB)(CPtrList &ptrList, CColLine const &colLine, CColPoint &outColPoint, float &maxTouchDistance, CEntity *&outEntity, Bool doSeeThroughCheck, Bool doIgnoreCameraCheck);
t_ProcessLineOfSightSectorListCB _ProcessLineOfSightSectorListCB = _ProcessLineOfSightSectorList_Func;

Bool __cdecl _ProcessLineOfSightSectorList(CPtrList &ptrList, CColLine const &colLine, CColPoint &outColPoint, float &maxTouchDistance, CEntity *&outEntity, Bool doSeeThroughCheck, Bool doIgnoreCameraCheck)
{
	return _ProcessLineOfSightSectorListCB(ptrList, colLine, outColPoint, maxTouchDistance, outEntity, doSeeThroughCheck, doIgnoreCameraCheck);	
}

void __cdecl _PreRender(CAutomobile *This, int i/*edx0*/)
{
	if ( This->m_sCarDamage.GetWheelStatus(i) == 1 && This->m_afWheelSuspDistSoft[i] < 1.0f )
	{
		Float fSpeed = This->m_vecVelocity.MagnitudeSqr();	
		if ( fSpeed > 0.01f )
		{
			Int32 nSurface = This->m_sWheelColPoint[i].m_nSurfaceTypeB;
			if ( nSurface != 2 && nSurface != 4 && nSurface != 18 && nSurface != 33 && nSurface != 19 )
			{
				Float fWheelProduct = DotProduct(This->m_sWheelColPoint[i].m_vecNormal, This->m_vecVelocity);

				CVector result = This->m_vecVelocity - CVector(fWheelProduct * This->m_sWheelColPoint[i].m_vecNormal);

				if ( i != 0 && i != 1 ) // 0.15f - PC
					result = result + (0.15f * This->m_sCoords.right);
				else
					result = result - (0.15f * This->m_sCoords.right);
				
				result = 0.25f * result;
				
				//int nSpeed = int(This->m_vecVelocity.Magnitude() * 10);
				//for ( int n = 0; n < nSpeed; n++)
				//for ( int n = 0; n < 500; n++)
				//{
				CParticle::AddParticle(PARTICLE_SPARK_SMALL, This->m_sWheelColPoint[i].m_vecPosition, result, 0, 0.0f, 0, 0, 0, 0);
				if ( fSpeed > 0.04f )
				{
					CParticle::AddParticle(PARTICLE_SPARK_SMALL, This->m_sWheelColPoint[i].m_vecPosition, result, 0, 0.0f, 0, 0, 0, 0);
				}
				if ( fSpeed > 0.16f )
				{
					CParticle::AddParticle(PARTICLE_SPARK_SMALL, This->m_sWheelColPoint[i].m_vecPosition, result, 0, 0.0f, 0, 0, 0, 0);
					CParticle::AddParticle(PARTICLE_SPARK_SMALL, This->m_sWheelColPoint[i].m_vecPosition, result, 0, 0.0f, 0, 0, 0, 0);
				}
				//}
			}
		}
	}
}

static int jmp_0x536552 = AddressByVersion(0x536552, 0x536792, 0x536722);
void NAK PreRenderPatch()
{
	__asm
	{
		STOREREGS()
		
		push     esi
		push     ebp
		call     _PreRender
		add      esp, 8
		
		RESTOREREGS()
	}
	
	__asm
	{
		inc     esi
		add     dword ptr [esp+708h+-6F4h], 28h
	}
	VARJMP(jmp_0x536552);
}

Int32 _FindTyreNearestPoint(CVehicle *This, float x, float y)
{	
	Float fUp =    ( (x - This->m_sCoords.pos.x) * This->m_sCoords.up.x )    + ( (y - This->m_sCoords.pos.y) * This->m_sCoords.up.y );
	Float fRight = ( (x - This->m_sCoords.pos.x) * This->m_sCoords.right.x ) + ( (y - This->m_sCoords.pos.y) * This->m_sCoords.right.y );

	if ( fUp <= 0.0f )
	{
		if ( fRight < 0.0f || fRight == 0.0f )
			return 2;
		else
			return 3;
	}
	else if ( fRight < 0.0f || fRight == 0.0f )
		return 0;
	else
		return 1;
}

Int32 _GetVehicleAppearance(CVehicle *This)
{
	return 0;
	/*
	Int32 flags = this->pHandling->flags & 0xF0000;

	if ( flags == 0 )
		return 1;

	if ( v1 == 0x10000 )
		return 2;

	if ( v1 == 0x20000 )
		return 3;

	if ( v1 == 0x40000 )
		return 5;

	if ( v1 == 0x80000 )
		return 4;

	return 0;
	*/
}

int _cwrand()
{
	return ((int (__cdecl *)())AddressByVersion(0x5A41D0, 0X5A4490, 0X5A5170))();
}

Bool _Using1stPersonWeaponMode()
{
	UInt16 mode = TheCamera.m_nPlayerWeaponMode;
	return mode == MODE_SNIPER 
		|| mode == MODE_M16_1STPERSON 
		|| mode == MODE_ROCKETLAUNCHER 
		|| mode == MODE_HELICANNON_1STPERSON;
}

void __cdecl _InflictDamage(CVehicle *This, CEntity *damager, eWeaponType wep)
{
	if ( damager && damager->m_nType == 3 )
	{
		if ( This->m_eVehicleType == VEHICLETYPE_CAR )
		{
			Int32 nTyreChance;

			
			switch ( wep )
			{
				case WEAPONTYPE_COLT45:
					nTyreChance = settings.m_anWeaponsChanceForPeds[wep];
					break;

				case WEAPONTYPE_UZI:
				case WEAPONTYPE_UZI_DRIVEBY:
					if ( !((CPed *)damager)->IsPlayer() )
						nTyreChance = settings.m_anWeaponsChanceForPeds[wep];
					break;

				case WEAPONTYPE_SHOTGUN:
				case WEAPONTYPE_HELICANNON:
					nTyreChance = settings.m_anWeaponsChanceForPeds[wep];
					break;

				case WEAPONTYPE_AK47:
				case WEAPONTYPE_M16:
					if ( !((CPed *)damager)->IsPlayer() )
						nTyreChance = settings.m_anWeaponsChanceForPeds[wep];
					break;

				default:
					nTyreChance = 0;
					break;
			}
		
/*			
			switch ( wep )
			{
				case WEAPONTYPE_COLT45:
					nTyreChance = 10;
					break;

				case WEAPONTYPE_UZI:
				case WEAPONTYPE_UZI_DRIVEBY:
					if ( !((CPed *)damager)->IsPlayer() )
						nTyreChance = 15;
					break;

				case WEAPONTYPE_SHOTGUN:
				case WEAPONTYPE_HELICANNON:
					nTyreChance = 25;
					break;

				case WEAPONTYPE_AK47:
				case WEAPONTYPE_M16:
					if ( !((CPed *)damager)->IsPlayer() )
						nTyreChance = 15;
					break;

				default:
					nTyreChance = 0;
					break;
			}
*/		
			if ( !((CPed *)damager)->IsPlayer() && ( !CCamera::m_bUseMouse3rdPerson || !_Using1stPersonWeaponMode() ) )
			{
				if ( nTyreChance )
				{
					if ( CAN_BURST_CAR_TYRES((CAutomobile *)This) )
					{
						if ( nTyreChance > (_cwrand() & 127) )
						{
							if ( This->m_eVehicleType == VEHICLETYPE_CAR )
								((CAutomobile *)This)->BurstTyre(_FindTyreNearestPoint(This, vecFirePos.x, vecFirePos.y) + 13);
						}
					}
				}
			}
		}
	}
	
}

static int jmp_0x551A16 = AddressByVersion(0x551A16, 0x551B56, 0x551B06);
void NAK InflictDamageHook()
{
	__asm
	{
		STOREREGS()
		
		mov     eax, [esp+STACK_REGS_SIZE+1Ch+8h]
		push    eax
		
		mov     eax, [esp+STACK_REGS_SIZE+1Ch+4h+4h]
		push    eax
		
		push    esi
		
		call    _InflictDamage
		add     esp, 0Ch
		
		RESTOREREGS()
	}
	
	__asm fld     dword ptr [esi+200h]
	VARJMP(jmp_0x551A16);
}

Bool __cdecl CanBurstTyresBTIP(CAutomobile *This)
{
	if ( !settings.IsVehicleBanned(This->m_nModelIndex) && CAN_BURST_CAR_TYRES(This) )
		return true;
	else
		return false;
}

static int jmp_0x53C0EC = AddressByVersion(0x53C0EC, 0x53C32C, 0x53C2DC);
static int jmp_0x53C230 = AddressByVersion(0x53C230, 0x53C470, 0x53C420);
void NAK BurstTyreIgnorePatch()
{
	__asm
	{
		sub     esp, 18h
		mov     edx, [esp+24h+4h]
		
		STOREREGS()
		
		push    ebp
		call    CanBurstTyresBTIP
		add     esp, 4
		
		RESTOREREGS()

		test    al, al			//cmp     al, 1//test    al, al				//cmp     eax, 1
		
		jz	    short BTIP_EXIT
		
	}

	VARJMP(jmp_0x53C0EC);
	
BTIP_EXIT:
	VARJMP(jmp_0x53C230);
}

///////////////////////////////////////////////////////////////////////////////////////////////

void __cdecl PlayBurstSFX2(CVehicle *veh)
{
	DMAudio.PlayOneShot(veh->m_nAudioIndex, 147, 0.0f);
}

static int jmp_0x53C137 = AddressByVersion(0x53C137, 0x53C377, 0x53C327);
void NAK BurstTyrePatch()
{
	__asm
	{
		STOREREGS()
		
		push    ebp
		call    PlayBurstSFX2
		add     esp, 4
		
		RESTOREREGS()
	}
	
	__asm
	{
		mov     dl, [ebp+50h]
		shr     dl, 3
	}
	VARJMP(jmp_0x53C137);
}

UInt8 __cdecl _VehicleOneShots(cAudioManager *This, float &fDistance)
{
	UInt32 SfxIndex = settings.m_nTireBlownSfxID; // const UInt32 SfxIndex = 369;
	static UInt8 TyreIndex = 91;
	
	This->m_QueueSample.m_nCurSampleIndex = SfxIndex;
	This->m_QueueSample.field_C = 0;
	This->m_QueueSample.m_nIndex = TyreIndex++;
	if ( TyreIndex > 94 )
		TyreIndex = 91;
	This->m_QueueSample.m_nSampleFreq = SampleManager.GetSampleBaseFrequency(SfxIndex);
	This->m_QueueSample.m_nSampleFreq += This->RandomDisplacement(2000);
	This->m_QueueSample.field_10 = 2;
	This->m_QueueSample.field_30 = 0.0f;
	This->m_QueueSample.field_34 = 60.0f;
	fDistance = 3600.0f;
	return This->m_aRandomTable[4] % 10 + 117;
}


UInt32 __cdecl _VehicleOneShots2(cAudioManager *This, float &fDistance, UInt16 &Index, cVehicleParams *vehParam)
{
	UInt32 SfxIndex = settings.m_nPoppedTireCollisionSfxID; // const UInt32 SfxIndex = 371;
	static UInt8 TyreIndex = 82;
	
	Float vol;
	if ( This->m_aAudioEntities[This->m_QueueSample.m_AudioEntity].m_anSfxId[Index] == 148 )
	{
		vol = min( ( 2 * ( 100.0f * This->m_aAudioEntities[This->m_QueueSample.m_AudioEntity].field_14[Index] ) ), 50.0f);
	}
		
	This->m_QueueSample.m_nCurSampleIndex = SfxIndex;
	This->m_QueueSample.field_C = 0;
	This->m_QueueSample.m_nIndex = TyreIndex++;
	if ( TyreIndex > 85 )
		TyreIndex = 82;
	This->m_QueueSample.m_nSampleFreq = SampleManager.GetSampleBaseFrequency(SfxIndex);
	This->m_QueueSample.m_nSampleFreq += This->RandomDisplacement(This->m_QueueSample.m_nSampleFreq >> 4);
	This->m_QueueSample.field_10 = 6;
	This->m_QueueSample.field_30 = 2.0f;
	This->m_QueueSample.field_34 = 35.0f;
	fDistance = 1225.0f;
	
	if ( vehParam->m_nVehicleAudioIndex == 41 )
		This->m_QueueSample.m_nSampleFreq *= 2;
			
		
	return (Int32)vol;
}

//static int jmp_0x56DBC0 = AddressByVersion(0x56DBC0, 0x56DF10, 0x56DE10);
static int jmp_0x56DBC0 = -1;
static int jmp_0x56DA6C = AddressByVersion(0x56DA6C, 0x56DDBC, 0x56DCBC);

void NAK ProcessVehicleOneShotsHook()
{
	__asm
	{
		movzx   eax, dx
		cmp     eax, 93h
		jz	short TYREBURSTSFX
		cmp     eax, 94h
		jz	short TYREBURSTSFX2
	}
	VARJMP(jmp_0x56DBC0);

TYREBURSTSFX:

	__asm
	{
		STOREREGS()
		
		lea     eax, [esp+STACK_REGS_SIZE+48h+-34h]
		push    eax
		push    ebp
		
		call    _VehicleOneShots
		add     esp, 8
		
		RESTOREREGS()
	}
	
	__asm
	{
		mov     bl, al
		fldz
	}
	
	VARJMP(jmp_0x56DA6C);
	
TYREBURSTSFX2:
	__asm
	{
		STOREREGS()
		
		push    [esp+STACK_REGS_SIZE+48h+4h] //vehparam
		
		lea     eax, [esp+STACK_REGS_SIZE+48h+4h-3Ch]
		push    eax          // index
		
		lea     eax, [esp+STACK_REGS_SIZE+48h+8h+-34h]
		push    eax          // fDistance
		
		push    ebp          // This
		
		call    _VehicleOneShots2
		add     esp, 10h
		
		RESTOREREGS()
	}
	
	__asm
	{
		mov     ebx, eax

		fldz
	}
	VARJMP(jmp_0x56DA6C);
}

Bool __fastcall _ProcessVehicleFlatTyre(cAudioManager *This, int edx0, cVehicleParams *vehicleParams)
{
	const Int32 SfxIndex = settings.m_nFlatTyreSfxID; // const Int32 SfxIndex = 370;
	
	if ( vehicleParams->m_fDistanceSquared >= 3600.0f )
		return false;
	
	if ( vehicleParams->m_pVehicle->m_eVehicleType != VEHICLETYPE_CAR )
		return true;

	Bool bTiresFucked = false;

	for ( Int32 i = 0; i < 4; i++ )
	{
		if ( ((CAutomobile *)vehicleParams->m_pVehicle)->m_sCarDamage.GetWheelStatus(i) == 1 && ((CAutomobile *)vehicleParams->m_pVehicle)->m_afWheelContactRate[i] > 0.0f )
		{
			bTiresFucked = true;
			break;
		}
	}
	
	if ( !bTiresFucked )
		return true;
	
	Float fRate = min(fabsf(vehicleParams->m_fSpeed) / (vehicleParams->m_pTransmission->m_fMaxVelocity * 0.3f), 1.0f);

	
	if ( fRate > 0.01f )
	{
		This->CalculateDistance(vehicleParams->field_4, vehicleParams->m_fDistanceSquared);
	
		This->m_QueueSample.m_nVolume = This->ComputeVolume(UInt8(fRate * 100.0f), 60.0f, This->m_QueueSample.m_fDistance);
		if ( This->m_QueueSample.m_nVolume )
		{
			This->m_QueueSample._oldVolume = UInt8(fRate * 100.0f);
			This->m_QueueSample.m_nIndex = 95;
			This->m_QueueSample.field_C = 0;
			This->m_QueueSample.field_D = 0;
			This->m_QueueSample.field_10 = 5;
			This->m_QueueSample.field_20 = 0;
			This->m_QueueSample.m_nCurSampleIndex = SfxIndex;
			This->m_QueueSample.m_nSampleFreq = UInt32( (fRate * 5500.0f) + 8000 );
			This->m_QueueSample.m_nLoopStartOffset = SampleManager.GetSampleLoopStartOffset(SfxIndex);
			This->m_QueueSample.field_38 = 0;
			This->m_QueueSample.field_34 = 60.0f;
			This->m_QueueSample.field_4A = 0;
			This->m_QueueSample.field_50 = 3;
			This->m_QueueSample.field_30 = 2.0f;
			This->m_QueueSample.m_nLoopEndOffset = SampleManager.GetSampleLoopEndOffset(SfxIndex);
			This->AddSampleToRequestedQueue();
		}
	}

	return true;
}

static int jmp_0x569CAA = AddressByVersion(0x569CAA, 0x569FFA, 0x569EFA);
void NAK ProcessVehicleHook2()
{
	__asm
	{
		lea     eax, [esp+20h+-20h]
		mov     ecx, ebp
		push    eax
		call    _ProcessVehicleFlatTyre
	}
	VARJMP(jmp_0x569CAA);
}

static int jmp_0x569C69 = AddressByVersion(0x569C69, 0x569FB9, 0x569EB9);
void NAK ProcessVehicleHook3()
{
	__asm
	{
		lea     eax, [esp+20h+-20h]
		mov     ecx, ebp
		push    eax
		call    _ProcessVehicleFlatTyre
	}
	VARJMP(jmp_0x569C69);
}

static int jmp_0x569C23 = AddressByVersion(0x569C23, 0x569F73, 0x569E73);
void NAK ProcessVehicleHook4()
{
	__asm
	{
		lea     eax, [esp+20h+-20h]
		mov     ecx, ebp
		push    eax
		call    _ProcessVehicleFlatTyre
		lea     eax, [esp+20h+-20h]
		mov     ecx, ebp
		push    eax
	}
	VARJMP(jmp_0x569C23);
}


float __cdecl _GetSpeedMag(CAutomobile *This)
{
	return This->m_vecVelocity.MagnitudeSqr();
}

float PCfSpeed = 0.04f;

void __cdecl _PlayOneShot(int a1, unsigned int a2, float a3)
{
	DMAudio.PlayOneShot((unsigned short)a1, a2, a3);
}

static int jmp_0x53488E = AddressByVersion(0x53488E, 0x534ACE, 0x534A5E);
void NAK _ProcessControl()
{
	__asm
	{
		STOREREGS()
		
		push    ebp
		call    _GetSpeedMag
		add     esp, 4h
		
		RESTOREREGS()
		
		fcomp   dword ptr [PCfSpeed]
		fnstsw  ax
		test    ah, 45h
		
		jnz     short loc_53488E
	}
	
	__asm
	{
		lea     ecx, [ebp+288h]
		push    esi
		call    CDamageManager::GetWheelStatus
		cmp     eax, 1
		jnz     short PlaySoundELSE

		push    [esp+518h+-49Ch]
		push    94h
		jmp     short PlaySoundNOTA
	}

PlaySoundELSE:
	__asm
	{
		push    [esp+518h+-49Ch]
		push    0Dh
	}
	
PlaySoundNOTA:
	__asm
	{
		mov     eax, [ebp+64h]
		push    eax
		
		mov     ecx, dword ptr [DMAudio]
		call    cDMAudio::PlayOneShot

		fld     [esp+518h+-49Ch]
		fcomp   [esp+518h+-4A4h]
		fnstsw  ax
		test    ah, 45h
		jnz     short loc_53488E
		mov     eax, [esp+518h+-49Ch]
		mov     [esp+518h+-4A4h], eax
	}
	VARJMP(jmp_0x53488E);
	
loc_53488E:
	VARJMP(jmp_0x53488E);
}

static char * _EGGVar;
void EGG(char *a)
{
	_EGGVar = a;
	__asm mov eax, eax
}

int __fastcall __GetWheelStatus1(CDamageManager *This, int edx0,int a2)
{
	if ( This->m_anWheelsStatus[a2] == 2 )
		return 1;
	else
		return 0;
}

void __fastcall __SetWheelStatus1(CDamageManager *This, int edx0, int a2, unsigned __int8 a3)
{
	This->ProgressWheelDamage(a2);
	/*
	if ( This->m_anWheelsStatus[a2] == 2 )
	{
		int adr = (int)This;
		adr -= 0x288;
		CAutomobile *aut = (CAutomobile *)adr;
		
		RpAtomic *pCurrentAtomic = 0;
		
		RwFrameForAllObjects(aut->m_aCarNodes[1], (RwObjectCallBack)0x52C690, &pCurrentAtomic);
		
		if ( pCurrentAtomic )
			pCurrentAtomic->object.object.flags = 0;
		
		RwFrameForAllObjects(aut->m_aCarNodes[3], (RwObjectCallBack)0x52C690, &pCurrentAtomic);
		
		if ( pCurrentAtomic )
			pCurrentAtomic->object.object.flags = 0;
		
		RwFrameForAllObjects(aut->m_aCarNodes[4], (RwObjectCallBack)0x52C690, &pCurrentAtomic);
		
		if ( pCurrentAtomic )
			pCurrentAtomic->object.object.flags = 0;
		
		RwFrameForAllObjects(aut->m_aCarNodes[6], (RwObjectCallBack)0x52C690, &pCurrentAtomic);
		
		if ( pCurrentAtomic )
			pCurrentAtomic->object.object.flags = 0;
		
	}
	*/
}

void __fastcall HealthCheatFix(CDamageManager *This, int edx0, unsigned int status)
{
	This->SetEngineStatus(status);

	for ( Int32 i = 0; i < 4; i++ )
		This->SetWheelStatus(i, 0);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved)
{
	if(reason == DLL_PROCESS_ATTACH)
	{
		EGG("You N'wah!");
		
		CPatch::SetChar(AddressByVersion(0x558609, 0x558739, 0x5586E9), 0); //CBulletInfo::Update
		CPatch::SetChar(AddressByVersion(0x562206, 0x562336, 0x5622E6), 0); //FireM16_1stPerson
		CPatch::SetChar(AddressByVersion(0x560E8C, 0x560FBC, 0x560F6C), 0); //FireShotgun
		CPatch::SetChar(AddressByVersion(0x55D8E8, 0x55DA18, 0x55D9C8), 0); //FireInstantHit

		CPatch::RedirectCall(AddressByVersion(0x560EB1, 0x560FE1, 0x560F91), _ProcessLineOfSightPatch); //FireShotgun
		CPatch::RedirectCall(AddressByVersion(0x562289, 0x5623B9, 0x562369), _ProcessLineOfSightPatch); //FireM16_1stPerson
		CPatch::RedirectCall(AddressByVersion(0x55D907, 0x55DA37, 0x55D9E7), _ProcessLineOfSightPatch); //FireInstantHit
		
		CPatch::RedirectJump(AddressByVersion(0x558940, 0x558A70, 0x558A20), BulletInfoPatch);
		CPatch::RedirectJump(AddressByVersion(0x55FF5A, 0x56008A, 0x56003A), DoBulletImpactPatch);
		CPatch::RedirectJump(AddressByVersion(0x55FF7F, 0x5600AF, 0x56005F), DoBulletImpactPatch2);
		CPatch::RedirectJump(AddressByVersion(0x561239, 0x561369, 0x561319), FireShotgunPatch);

		CPatch::RedirectJump(AddressByVersion(0x4B0C70, 0x4B0D60, 0x4B0CF0), _ProcessLineOfSightSectorList);
		CPatch::RedirectJump(AddressByVersion(0x53BF70, 0x53C1B0, 0x53C160), __SetUpWheelColModel);
		CPatch::RedirectJump(AddressByVersion(0x53654C, 0x53678C, 0x53671C), PreRenderPatch);
		
		if ( settings.m_bRandomTireBurstByPeds )
			CPatch::RedirectJump(AddressByVersion(0x551A10, 0x551B50, 0x551B00), InflictDamageHook);
		
		CPatch::RedirectJump(AddressByVersion(0x53C0E5, 0x53C325, 0x53C2D5), BurstTyreIgnorePatch);
		
		// sfx Patches
		CPatch::RedirectJump(AddressByVersion(0x53C131, 0x53C371, 0x53C321), BurstTyrePatch);

		//CPatch::RedirectJA(AddressByVersion(0x56CDB9, 0x56D109, 0x56D009), ProcessVehicleOneShotsHook);
		CPatch::JA(AddressByVersion(0x56CDB9, 0x56D109, 0x56D009), ProcessVehicleOneShotsHook, jmp_0x56DBC0);

		CPatch::RedirectJump(AddressByVersion(0x569BD1, 0x569F21, 0x569E21), ProcessVehicleHook3);
		CPatch::RedirectJump(AddressByVersion(0x569C1D, 0x569F6D, 0x569E6D), ProcessVehicleHook4);
		CPatch::RedirectJump(AddressByVersion(0x569B3A, 0x569E8A, 0x569D8A), ProcessVehicleHook2);

		CPatch::RedirectJump(AddressByVersion(0x534863, 0x534AA3, 0x534A33), _ProcessControl);

		//
		CPatch::RedirectCall(AddressByVersion(0x490ECD, 0x490F8D, 0x490F1D), HealthCheatFix);
#if 0		
		//test
		CPatch::RedirectCall(AddressByVersion(0x53C116, 0x53C356, 0x53C306), __GetWheelStatus1);
		CPatch::RedirectCall(AddressByVersion(0x53C12C, 0x53C36C, 0x53C31C), __SetWheelStatus1);
#endif
	
	}
	return TRUE;
}

namespace BurstableTyres
{
	void EXP Set_ProcessLineOfSightSectorList_CallBack(t_ProcessLineOfSightSectorListCB func)
	{
		_ProcessLineOfSightSectorListCB = func;
	}
	
	t_ProcessLineOfSightSectorListCB EXP Get_ProcessLineOfSightSectorList_CallBack()
	{
		return _ProcessLineOfSightSectorListCB;
	}
	
	void EXP Set_GetPedColModel_CallBack(t_GetPedColModel_FuncCB func)
	{
		GetPedColModelCB = func;
	}
	
	t_GetPedColModel_FuncCB EXP Get_GetPedColModel_CallBack()
	{
		return GetPedColModelCB;
	}
	
	void EXP Set_CAN_BURST_CAR_TYRES_CallBack(tCAN_BURST_CAR_TYRESCB func)
	{
		CAN_BURST_CAR_TYRESCB = func;
	}
	
	tCAN_BURST_CAR_TYRESCB EXP Get_CAN_BURST_CAR_TYRES_CallBack()
	{
		return CAN_BURST_CAR_TYRESCB;
	}
};