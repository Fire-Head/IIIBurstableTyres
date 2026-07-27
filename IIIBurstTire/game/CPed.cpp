#include "CPed.h"

void CPed::SetDie(int a, float b, float c)
{
	((void (__thiscall *)(CPed *, int, float, float))AddressByVersion(0x4D37D0, 0x4D3870, 0x4D3800))(this, a, b, c);
}

bool CPed::IsPedInControl()
{
	return ((bool (__thiscall *)(CPed*))AddressByVersion(0x4CE6C0, 0x4CE760, 0x4CE6F0))(this);
}

void CPed::SetObjective(eObjective objective, void* entity)
{
	((void (__thiscall *)(CPed*, eObjective, void*))AddressByVersion(0x4D83E0, 0x4D8480, 0x4D8410))(this, objective, entity);
}

void CPed::SetRadioStation()
{
	((void (__thiscall *)(CPed*))AddressByVersion(0x4D7BC0, 0x4D7C60, 0x4D7BF0))(this);
}

void CPed::ReactToAttack(CEntity* pAttackEntity)
{
	((void (__thiscall *)(CPed*, CEntity*))AddressByVersion(0x4DDEC0, 0x4DDF70, 0x4DDF00))(this, pAttackEntity);
}
void CPed::PedSetDraggedOutCarPositionCB(CAnimBlendAssociation* asoc, void* entity)
{
	((void (__cdecl *)(CAnimBlendAssociation*, void*))AddressByVersion(0x4E2920, 0x4E29D0, 0x4E2960))(asoc, entity);
}

void CPed::PedSetOutCarCB(CAnimBlendAssociation* asoc, void* entity)
{
	((void (__cdecl *)(CAnimBlendAssociation*, void*))AddressByVersion(0x4CE8F0, 0x4CE990, 0x4CE920))(asoc, entity);
}

void CPed::SetExitCar(CVehicle* pVehicle, unsigned int arg1)
{
	((void (__thiscall *)(CPed*, CVehicle*, unsigned int))AddressByVersion(0x4E1010, 0x4E10C0, 0x4E1050))(this, pVehicle, arg1);
}

void CPed::SetBeingDraggedFromCar(CVehicle* pVehicle, unsigned int nEnterType, bool arg2)
{
	((void (__thiscall *)(CPed*, CVehicle*, unsigned int, bool))AddressByVersion(0x4E0640, 0x4E06F0, 0x4E0680))(this, pVehicle, nEnterType, arg2);
}

void CPed::SetMoveState(eMoveState state)
{
	((void (__thiscall *)(CPed*, eMoveState))AddressByVersion(0x4C5A30, 0x4C5AD0, 0x4C5A60))(this, state);
}

void CPed::RestorePreviousObjective()
{
	((void (__thiscall *)(CPed*))AddressByVersion(0x4D9460, 0x4D9500, 0x4D9490))(this);
}

void CPed::RestorePreviousState()
{
	((void (__thiscall *)(CPed*))AddressByVersion(0x4C5E30, 0x4C5ED0, 0x4C5E60))(this);
}

bool CPed::SetWanderPath(signed char headDir)
{
	return ((bool (__thiscall *)(CPed*, signed char))AddressByVersion(0x4D2750, 0x4D27F0, 0x4D2780))(this, headDir);
}

void CPed::ClearAimFlag()
{
	((void (__thiscall *)(CPed*))AddressByVersion(0x4C6A50, 0x4C6AF0, 0x4C6A80))(this);
}

void CPed::ClearLookFlag()
{
	((void (__thiscall *)(CPed*))AddressByVersion(0x4C64F0, 0x4C6590, 0x4C6520))(this);
}

void CPed::SetIdle()
{
	((void (__thiscall *)(CPed*))AddressByVersion(0x4D0600, 0x4D06A0, 0x4D0630))(this);
}