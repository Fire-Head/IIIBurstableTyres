#include "cAudioManager.h"

cAudioManager &AudioManager = *(cAudioManager*)0x880FC0;

// Converted from float __thiscall cAudioManager::GetDistanceSquared(CVector const &vec) 0x569750
float cAudioManager::GetDistanceSquared(CVector const& vec)
{
	return ((float (__thiscall *)(cAudioManager*, CVector const&))AddressByVersion(0x569750, 0X569AA0, 0X5699A0))(this, vec);
}

// Converted from void __thiscall cAudioManager::CalculateDistance(unsigned char &a1, float a2) 0x5697A0
void cAudioManager::CalculateDistance(unsigned char& a1, float a2)
{
	((void (__thiscall *)(cAudioManager*, unsigned char&, float))AddressByVersion(0x5697A0, 0X569AF0, 0X5699F0))(this, a1, a2);
}

// Converted from bool __thiscall cAudioManager::ComputeVolume(unsigned char a1, float a2, float a3) 0x57ABB0
unsigned char cAudioManager::ComputeVolume(unsigned char a1, float a2, float a3)
{
	return ((unsigned char (__thiscall *)(cAudioManager*, unsigned char, float, float))AddressByVersion(0x57ABB0, 0X57AF00, 0X57AE00))(this, a1, a2, a3);
}

// Converted from int __thiscall cAudioManager::RandomDisplacement(unsigned int a1) 0x57AF90
int cAudioManager::RandomDisplacement(unsigned int a1)
{
	return ((int (__thiscall *)(cAudioManager*, unsigned int))AddressByVersion(0x57AF90, 0X57B2E0, 0X57B1E0))(this, a1);
}

// Converted from void __thiscall cAudioManager::AddSampleToRequestedQueue() 0x57B070
void cAudioManager::AddSampleToRequestedQueue()
{
	((void (__thiscall *)(cAudioManager*))AddressByVersion(0x57B070, 0X57B3C0, 0X57B2C0))(this);
}

void cAudioManager::ProcessLoopingScriptObject(unsigned char a1)
{
	((void (__thiscall *)(cAudioManager*, unsigned char))0x576770)(this, a1);
}