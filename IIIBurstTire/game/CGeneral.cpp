#include "CGeneral.h"

// Converted from static float __cdecl CGeneral::GetRandomNumberInRange(float min, float max) 0x054A520
float CGeneral::GetRandomNumberInRange(float min, float max)
{
	return ((float (__cdecl *)(float, float))AddressByVersion(0x54A520, 0x54A720, 0x54A6D0))(min, max);
}

// Converted from static int __cdecl CGeneral::GetRandomNumberInRange(int min, int max) 0x54A4C0
int CGeneral::GetRandomNumberInRange(int min, int max)
{
	return ((int (__cdecl *)(int, int))AddressByVersion(0x54A4C0, 0x54A6C0, 0x54A670))(min, max);
}

int CGeneral::GetRandomNumber()
{
	return ((int (__cdecl *)())AddressByVersion(0x54A4B0, 0x54A6B0, 0x54A660))();
}