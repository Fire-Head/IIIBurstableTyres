#pragma once
#include <windows.h>
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
	
    virtual ~CPlaceable() { }  //~CPlaceable();
};
#pragma pack(pop)