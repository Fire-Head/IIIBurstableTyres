#pragma once
#include "CPhysical.h"
#include "CEntity.h"
#include "CMatrix.h"
#include "..\address.h"

class CObject : public CPhysical
{
protected:
	DUMMYB(CObject, CPhysical);
public:
	CMatrix m_sMatrix;
	Float m_fUprootLimit;
	Int8 m_nObjectType;
	Int8 m_Flags;
	Int8 field_176;
	char _pad0[1];
	Float m_fCollisionDamageMultiplier;
	Int8 m_nCollisionDamageEffectFlags;
	Int8 m_nSpecialCollisionResponseCase;
	Bool m_bCameraAvoidObject;
	char _pad1[5];
	Int32 m_nTempObjectTimer;
	Int16 m_nRefModelIndex;
	char _pad2[2];
	CEntity *m_pRoad;
	CEntity *field_190;
	UInt8 m_nCarColor[2];
	char _pad3[2];
	
	void *CObject::operator new(unsigned int size);
	void *CObject::operator new(unsigned int size, int a2);
	void CObject::operator delete(void *object);
};

VALIDATE_SIZE(CObject, 0x198);