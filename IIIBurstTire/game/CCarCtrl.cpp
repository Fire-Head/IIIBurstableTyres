#include "CCarCtrl.h"

void CCarCtrl::SwitchVehicleToRealPhysics(CVehicle* pVehicle)
{
	((void (__cdecl *)(CVehicle*))AddressByVersion(0x41F7F0, 0x41F7F0, 0x41F7F0))(pVehicle);
}
