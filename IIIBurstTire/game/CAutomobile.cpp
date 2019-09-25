#include "CAutomobile.h"

void CDamageManager::SetWheelStatus(int wheel, unsigned int status)
{
	((void (__thiscall *)(CDamageManager*, int, unsigned int))AddressByVersion(0x545900, 0x545B00, 0x545AB0))(this, wheel, status);
}

void CDamageManager::SetEngineStatus(unsigned int status)
{
	((void (__thiscall *)(CDamageManager*, unsigned int))AddressByVersion(0x545940, 0x545B40, 0x545AF0))(this, status);
}
	
int CDamageManager::GetWheelStatus(int a1)
{
	return ((int (__thiscall *)(CDamageManager*, int))AddressByVersion(0x545910, 0X545B10, 0X545AC0))(this, a1);
}


// Converted from bool __thiscall CDamageManager::ProgressWheelDamage(unsigned char wheel) 0x545A40
bool CDamageManager::ProgressWheelDamage(unsigned char wheel)
{
	return ((bool (__thiscall *)(CDamageManager*, unsigned char))AddressByVersion(0x545A40, 0x545C40, 0x545BF0))(this, wheel);
}

bool CAutomobile::SetUpWheelColModel(class CColModel* wheelCol)
{
	return ((bool (__thiscall *)(CAutomobile *, class CColModel*))FUNCVMT(30))(this, wheelCol);
}
	
void CAutomobile::BurstTyre(unsigned char tyreComponentId)
{
	((void (__thiscall *)(CAutomobile *, unsigned char))FUNCVMT(31))(this, tyreComponentId);
}
