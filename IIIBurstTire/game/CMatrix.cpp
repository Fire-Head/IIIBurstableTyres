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

void CMatrix::SetRotate(float x, float y, float z)
{
	((void (__thiscall *)(CMatrix *, float, float, float))AddressByVersion(0x4B93A0, 0x4B9490, 0x4B9420))(this, x, y, z);
}


void Invert(CMatrix const& in, CMatrix&out)
{
    //return ((CMatrix const&(__cdecl *)(CMatrix const&, CMatrix&out))AddressByVersion(0x4B9C30, 0x4B9D20, 0x4B9CB0))(in, out);
    ((void (__cdecl *)(CMatrix const&, CMatrix&out))AddressByVersion(0x4B9C30, 0x4B9D20, 0x4B9CB0))(in, out);
}

CVector Multiply3x3(CMatrix const& m, CVector const& v)
{
	return ((CVector (__cdecl *)(CMatrix const&, CVector const&))AddressByVersion(0x4BA3D0, 0x4BA4C0, 0x4BA450))(m, v);
}