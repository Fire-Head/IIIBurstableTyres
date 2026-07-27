#pragma once
#include "CMatrix.h"
#include "..\address.h"

#pragma pack(push, 4)
class CPlaceable
{
protected:
	DUMMY(CPlaceable);

public:
    //void *vmt;
    CMatrix m_sCoords;
	
	CPlaceable()
	{
		((void (__thiscall *)(CPlaceable *))AddressByVersion(0x49F9A0, 0x49FA90, 0x49FA20))(this);
	}
	
	void SetHeading(float heading)
	{
		((void (__thiscall *)(CPlaceable *, float))AddressByVersion(0x49FA00, 0x49FAF0, 0x49FA80))(this, heading);
	}
	
	CVector &GetForward(void) { return m_sCoords.GetForward(); }
	
    virtual ~CPlaceable() { }  //~CPlaceable();
};
#pragma pack(pop)