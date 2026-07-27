#include "CGlass.h"

int CGlass::CalcAlphaWithNormal(CVector* pPos)
{
	return ((int (__cdecl *)(CVector*))AddressByVersion(0x503C90, 0x503D70, 0x503D00))(pPos);
}
