#pragma once
#include "..\address.h"
#include "CPed.h"


enum eCopType
{
  COPTYPE_COP = 0x0,
  COPTYPE_SWAT = 0x1,
  COPTYPE_FBI = 0x2,
  COPTYPE_ARMY = 0x3,
};


class CCopPed : public CPed
{
public:
	UInt16 field_53C;
	char _pad0[2];
	Float m_fDistanceToPlayer;
	Bool field_544;
	Bool field_545;
	Bool field_546;
	Bool field_547;
	Bool field_548;
	Bool m_b1;
	char _pad1[2];
	Int32 _unk0;
	eCopType m_CopType;
	SInt8 field_554;
	char _pad2[3];

	void ClearPursuit()
	{
		((void (__thiscall *)(CCopPed*))AddressByVersion(0x4C28C0, 0x4C2960, 0x4C28F0))(this);
	}
};