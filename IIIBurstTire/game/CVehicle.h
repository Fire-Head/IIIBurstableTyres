#pragma once
#include "CPhysical.h"
#include "CPed.h"
#include "CEntity.h"
#include "CStoredCollPoly.h"


enum eVehicleType
{
  VEHICLETYPE_CAR = 0x0,
  VEHICLETYPE_BOAT = 0x1,
  VEHICLETYPE_TRAIN = 0x2,
  VEHICLETYPE_HELI = 0x3,
  VEHICLETYPE_PLANE = 0x4,
  VEHICLETYPE_BIKE = 0x5,
};



#pragma pack(push, 1)
struct CAutoPilot
{
  Int32 m_nCurrentNode;
  Int32 m_nNextNode;
  Int32 m_nPrevNode;
  Int32 m_nCurrentSpeedScaleFactor;
  Int32 m_nNextSpeedScaleFactor;
  Int32 m_nCurrentCarLinkNode;
  Int32 m_nNextCarLinkNode;
  Int32 m_nPrevCarLinkNode;
  SInt32 m_snGettingNewCommandTimeStamp;
  SInt32 field_24;
  UInt8 m_nPrevDirectionScale;
  UInt8 m_nCurrentDirectionScale;
  UInt8 m_nNextDirectionScale;
  UInt8 m_nCurrentLanes;
  UInt8 m_nNextLanes;
  UInt8 m_nTrafficBehaviour;
  UInt8 m_nDriverBehaviour;
  UInt8 m_nSimpleAction;
  SInt32 m_snSimpleActionTime;
  Float m_fCurrentSpeed;
  UInt8 m_nMaxSpeed;
  UInt8 m_nSpeedLimitFlags;
  char _pad0[2];
  CVector m_vecTargetPoint;
  void *m_pIntermediateRouteList[8];
  UInt16 m_nRouteListStep;
  char _pad1[2];
};
#pragma pack(pop)


class CVehicle : public CPhysical
{   
protected:
	DUMMYB(CVehicle, CPhysical);
public:
    //
	void *m_VehicleType;
	CAutoPilot m_AutoPilot;
	CVehicle *m_pVehicleToRam;
	UInt8 m_anCarColorId[2];
	UInt8 m_anExtras[2];
	UInt16 m_nAlarmState;
	char _pad0[2];
	class CPed *pDriver;
	class CPed *pPassengers[8];
	UInt8 m_nNumPassengers;
	UInt8 m_nNumGettingIn;
	UInt8 m_nGettingInFlags;
	UInt8 m_nGettingOutFlags;
	UInt8 m_nMaxPassengers;
	char _pad1[3];
	Int32 field_1D0;
	CVector field_1D4;
	CEntity *m_pEntityWeAreOn;
	class CFire *m_pFire;
	Float m_fSteerAngle;
	Float m_fGasPedal;
	Float m_fBreakPedal;
	UInt8 m_nReferenceType;
	UInt8 m_Flags0;
	UInt8 m_Flags1;
	UInt8 m_Flags2;
	UInt8 m_Flags3;
	UInt8 m_nUsedForCover;
	UInt8 m_nAmmoInClip;
	UInt8 m_nPacMansCollected;
	Int8 field_1FC;
	char _pad2[1];
	Int16 field_1FE;
	Float m_nHealth;
	UInt8 m_nCurrentGear;
	char _pad3[3];
	Float field_208;
	SInt32 m_snGunFiringTime;
	SInt32 m_nTimeOfDeath;
	Int16 field_214;
	Int16 m_nExplosionTimer;
	CEntity *m_pLastDamEntity;
	Float field_21C;
	Float field_220;
	UInt32 m_nCarLockStatus;
	UInt8 m_nLastWeaponDamage;
	UInt8 m_nRadioStation;
	UInt8 field_22A;
	UInt8 field_22B;
	UInt8 m_nCarHornTimer;
	UInt8 _m_nHornType;
	Bool m_bSirenOrAlarm;
	UInt8 field_22F;
	CStoredCollPoly m_aCollPolys[2];
	Float m_fSteeringRatio;
	eVehicleType m_eVehicleType;
};
VALIDATE_SIZE(CVehicle, 0x288);