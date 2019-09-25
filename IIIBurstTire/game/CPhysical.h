#pragma once
#include "CEntity.h"
#include "CPlaceable.h"
#include "CVector.h"
#include "CColPoint.h"
#include "..\address.h"

//#pragma pack(push, 4)
class CPhysical : public CEntity
{
protected:
	DUMMYB(CPhysical, CEntity);
public:
	Int m_nAudioIndex;
	Float field_68;
	CEntity *field_6C;
	CEntity *field_70;
	Int m_nLastCollisionTime;
	CVector m_vecVelocity; //m_vecMoveSpeed
	CVector m_vecAngularVelocity;
	CVector m_vecAcceleration;
	CVector m_vecAngularAcceleration;
	CVector m_vecForce;
	CVector m_vecTorque;
	Float m_fMass;
	Float m_fTurnMass;
	Float m_fForceMultiplier;
	Float m_fAirResistance;
	Float m_fElasticity;
	Float m_fBuoyancyConstant;
	CVector m_vecCentreOfMass;
	/*CEntryInfoList **/void *m_pCollisionList;
	/*CPtrNode **/void *m_pMovingList;
	char field_EC;
	UInt8 field_ED;
	UInt8 m_nNumEntitiesCollided;
	UInt8 m_nContactSurface;
	CEntity *m_apCollidedEntities[6];
	Float m_fTotSpeed;
	Float m_fCollisionPower;
	CEntity *m_pPhysColling;
	CVector m_vecCollisionPower;
	UInt16 m_nComponentCol;
	UInt8 m_MoveFlags;
	UInt8 m_nLastCollType;
	Int8 m_nZoneLevel;
	char _pad0[3];
	
	CPhysical();
	virtual ~CPhysical();

	void ApplyMoveForce(float fX, float fY, float fZ)
	{
		((void (__thiscall *)(CPhysical*, float, float, float))AddressByVersion(0x4959A0, 0x495A60, 0x4959F0))(this, fX, fY, fZ);
	}
};
//#pragma pack(pop)

VALIDATE_SIZE(CPhysical, 0x128);