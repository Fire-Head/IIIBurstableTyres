#pragma once
#include "..\address.h"
#include "CVector2D.h"
#include "CVector.h"
#include "CVehicle.h"

class CBoat : public CVehicle
{
protected:
	DUMMYB(CBoat, CVehicle);
public:
	Float field_288;
	Float field_28C;
	Float field_290;
	Float field_294;
	Float field_298;
	Float field_29C;
	Float field_2A0;
	Float field_2A4;
	Float m_fMovingHiRotation;
	Int32 _unk0;
	RwFrame *m_aBoatNodes[4];
	UInt8 m_nBoatFlags;
	Bool field_2C1;
	char _pad0[2];
	Float field_2C4;
	Int32 _unk1;
	Float field_2CC;
	CEntity *field_2D0;
	Bool _unk2;
	char _pad1[3];
	Float m_fAccelerate;
	Float m_fBrake;
	Float m_fSteeringLeftRight;
	UInt8 m_nPadID;
	char _pad2[3];
	Int32 _unk3;
	Float m_fTurnForceZ;
	CVector m_vecMoveForce;
	Float field_2FC;
	Int16 field_300;
	UInt16 m_nNumWakePoints;
	CVector2D m_avec2dWakePoints[32];
	Float m_afWakePointLifeTime[32];
  
	virtual ~CBoat() { }
};