#pragma once
#include "..\address.h"

enum eWeaponType;
class CPed;

class CDarkel
{
public:
	static void RegisterKillByPlayer(CPed* pPed, eWeaponType Weapon, bool bHeadShotted);
	static void RegisterKillNotByPlayer(CPed* pPed, eWeaponType Weapon);
};