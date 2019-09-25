#include "CMatrix.h"

CMatrix::~CMatrix()
{
	((void (__thiscall *)(CMatrix *))AddressByVersion(0x4B8DB0, 0x4B8EA0, 0x4B8E30))(this);
}

CMatrix Invert(CMatrix const& in)
{
	return ((CMatrix (__cdecl *)(CMatrix const&))AddressByVersion(0x4B9BF0, 0x4B9CE0, 0x4B9C70))(in);
}

void CMatrix::Attach(RwMatrix *matrix, bool temporary)
{
	((void (__thiscall *)(CMatrix *, RwMatrix *, bool))AddressByVersion(0x4B8DD0, 0x4B8EC0, 0x4B8E50))(this, matrix, temporary);
}