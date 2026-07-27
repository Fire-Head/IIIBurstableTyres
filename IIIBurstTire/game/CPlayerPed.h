#pragma once
#include "..\address.h"
#include "CVector.h"
#include "CPed.h"


struct CCrimeBeingQd
{
  unsigned __int32 m_nCrimeType;
  unsigned __int32 m_nCrimeId;
  unsigned __int32 m_nStartTime;
  CVector m_vecCoors;
  unsigned __int8 m_bAlreadyReported;
  unsigned __int8 m_bPoliceDontReallyCare;
};

#pragma pack(push, 1)
struct CWanted
{
  int m_nChaosLevel;
  int m_nLastTimeWantedDecreased;
  int m_nLastTimeWantedLevelChanged;
  float m_fMultiplier;
  char m_nCopsInPursuit;
  char m_nMaxCopsInPursuit;
  char m_nMaxCopCarsInPursuit;
  char m_nCopsBeatingSuspect;
  __int16 m_nChanceOnRoadBlock;
  char m_Flags;
  char _pad0;
  int m_nWantedLevel;
  CCrimeBeingQd m_asCrimesBeingQd[16];
  class CCopPed *m_apCopsInPursuit[10];
};
#pragma pack(pop)


class CPlayerPed : public CPed
{
protected:
	DUMMYB(CPlayerPed, CPed);
public:
	CWanted *m_pWanted;
	DWORD field_540;
	DWORD field_544;
	float m_fTimeCanRun;
	float m_fSprintEnergy;
	float m_fSprintControlCounter;
	char m_nChosenWeapon;
	char field_555;
	char field_556;
	char _pad0;
	DWORD field_558;
	DWORD field_55C;
	DWORD field_560;
	char field_564;
	BYTE _pad1[3];
	DWORD field_568;
	DWORD field_56C;
	DWORD field_570;
	DWORD field_574;
	DWORD field_578;
	char m_bAdrenaline;
	char field_57D;
	char _pad2[2];
	int m_nAdrenalineEndTime;
	char field_584;
	char field_585;
	char _pad3[2];
	CVector field_588[6];
	DWORD field_5D0;
	DWORD field_5D4;
	DWORD field_5D8;
	DWORD field_5DC;
	DWORD field_5E0;
	DWORD field_5E4;
	DWORD field_5E8;
	DWORD field_5EC;
};

VALIDATE_SIZE(CPlayerPed, 0x5F0);