#pragma once
#include <Windows.h>
#include "..\address.h"
#include "CVehicle.h"
#include "CVector.h"
#include "CColPoint.h"
#include "RenderWare.h"

enum ePanels;

class CDamageManager
{
public:
	float m_fWheelDamageEffect;
	unsigned __int8 m_nEngineStatus;
	unsigned __int8 m_anWheelsStatus[4];
	unsigned __int8 m_anDoorsStatus[6];
	char _pad0[1];
	unsigned __int32 m_nLightsStatus;
	unsigned __int32 m_nPanelsStatus;
	DWORD field_18;
	
	int GetWheelStatus(int a1);
	void SetWheelStatus(int wheel, unsigned int status);
	void SetEngineStatus(unsigned int status);
	bool ProgressWheelDamage(unsigned char wheel);
};

class CDoor
{
public:
	float m_fOpenAngle;
	float m_fClosedAngle;
	char m_nDirn;
	char m_nAxis;
	char m_nState;
	char _padding0;
	float m_fAngle;
	float m_fPrevAngle;
	float m_fAngVel;
	CVector m_vecPos;
};


struct tTransmissionGear
{
  Float m_fMaxVelocity;
  Float m_fChangeUpVelocity;
  Float m_fChangeDownVelocity;
};

#pragma pack(push, 1)
struct cTransmission
{
  tTransmissionGear m_aGears[6];
  UInt8 m_nDriveType;
  UInt8 m_nEngineType;
  UInt8 m_nNumberOfGears;
  UInt8 m_nHandlingFlags;
  Float m_fEngineAcceleration;
  Float m_fMaxVelocity;
  Float m_fMaxSpeed;
  Float m_fMinGearVelocity;
  Float m_fCurrentSpeed;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct tHandlingData
{
  Int m_nVehicleId;
  Float m_fMass;
  Float field_8;
  Float m_fTurnMass;
  CVector m_vecDimensions;
  CVector m_vecCentreOfMass;
  UInt8 m_nPercentSubmerged;
  char _pad0[3];
  Float m_fBuoyancyConstant;
  Float m_fTractionMultiplier;
  cTransmission m_TransmissionData;
  Float m_fBrakeDeceleration;
  Float m_fBrakeBias;
  Bool m_bABS;
  char _pad1[3];
  Float m_fSteeringLock;
  Float m_fTractionLoss;
  Float m_fTractionBias;
  char _unk0[4];
  Float m_fSuspensionForceLevel;
  Float m_fSuspensionDampingLevel;
  Float m_fSuspensionUpperLimit;
  Float m_fSuspensionLowerLimit;
  Float m_fSuspensionBiasBetweenFrontAndRear;
  Float m_fCollisionDamageMultiplier;
  UInt8 m_nHandlingFlags;
  char _pad2[3];
  Float m_fSeatOffsetDistance;
  UInt32 m_nMonetaryValue;
  UInt8 m_nFrontLights;
  UInt8 m_nRearLights;
  char _pad3[2];
};
#pragma pack(pop)

class CObject;
class CAutomobile : public CVehicle
{
protected:
	DUMMYB(CAutomobile, CVehicle);
public:
	CDamageManager m_sCarDamage;
	CDoor m_sCarDoor[6];
	RwFrame *m_aCarNodes[20];
	CColPoint m_sWheelColPoint[4];
	Float m_afWheelSuspDist[4];
	Float m_afWheelSuspDistSoft[4];
	Float m_afWheelContactRate[4];
	Float field_49C;
	Bool field_4A0[4];
	Bool m_abWheelContactWithPed[4];
	Float m_afWheelTotalRot[4];
	Float m_afWheelRot[4];
	Float m_afWheelAngleStep[4];
	UInt8 _unk0;
	UInt8 m_nFlagsA;
	UInt8 m_nFlagsB;
	char _pad0[1];
	int field_4DC;
	UInt16 m_nMiscComponentAngle;
	UInt16 field_4E2;
	Int32 m_nBusDoorTimerEnd;
	Int32 m_nBusDoorTimerStart;
	Float m_afWheelOffsetZ[2][4];
	Float m_fHeightAboveRoad;
	Float m_fImprovedHandling;
	Float field_514;
	Float field_518[6];
	Float m_fBurnTimer;
	CEntity *m_apReferVehicle[4];
	CVector field_544[4];
	CEntity *_m_pDamageEntity;
	Float field_578;
	Float field_57C;
	Float m_fDoomHorizontalRotation;
	Float m_fDoomVerticalRotation;
	Float field_588_RotateY;
	int _unk1;
	UInt8 m_nNumContactWheels;
	UInt8 m_nWheelsOnGround;
	UInt8 m_nPrevWheelsOnGround;
	char _pad1[1];
	Float m_fSkidMarkDensity;
	Int32 m_anTireFriction[4];
	
	CAutomobile(int a1, unsigned char a2);
	virtual ~CAutomobile();
	bool SetUpWheelColModel(class CColModel* wheelCol);
	void BurstTyre(unsigned char tyreComponentId);
};

VALIDATE_SIZE(CAutomobile, 0x5A8);