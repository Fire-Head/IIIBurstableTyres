#include "CDarkel.h"

void CDarkel::RegisterKillByPlayer(CPed* pPed, eWeaponType Weapon, bool bHeadShotted)
{
	((void (__cdecl *)(CPed*, eWeaponType, bool))AddressByVersion(0x420F60, 0x420F60, 0x420F60))(pPed, Weapon, bHeadShotted);
}

void CDarkel::RegisterKillNotByPlayer(CPed* pPed, eWeaponType Weapon)
{
	((void (__cdecl *)(CPed*, eWeaponType))AddressByVersion(0x421060, 0x421060, 0x421060))(pPed, Weapon);
}
