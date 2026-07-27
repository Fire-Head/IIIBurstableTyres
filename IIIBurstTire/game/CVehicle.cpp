#include "CVehicle.h"

void CVehicle::ProcessOpenDoor(unsigned int arg0, unsigned int arg1, float arg2)
{
	((void (__thiscall *)(CVehicle *, unsigned int, unsigned int, float))FUNCVMT(23))(this, arg0, arg1, arg2);
}

bool CVehicle::IsUpsideDown()
{
	return ((bool (__thiscall *)(CVehicle*))AddressByVersion(0x552230, 0x552370, 0x552320))(this);
}