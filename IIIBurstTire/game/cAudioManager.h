#pragma once
#include "..\address.h"
#include "types.h"
#include "CVector.h"

#pragma pack(push, 1)
struct cVehicleParams
{
	unsigned char field_4;
	char _pad[3];
	Float m_fDistanceSquared;
	class CVehicle *m_pVehicle;
	class cTransmission *m_pTransmission;
	UInt32 m_nVehicleAudioIndex;
	Float m_fSpeed;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct tSound
{
  UInt32 m_AudioEntity;
  UInt32 m_nIndex;
  UInt32 m_nCurSampleIndex;
  UInt8 field_C;
  Bool field_D;
  char tmp0[2];
  UInt32 field_10;
  UInt32 m_nSampleFreq;
  UInt8 m_nVolume;
  char tmp1[3];
  Float m_fDistance;
  UInt32 field_20;
  Int32 m_nLoopStartOffset;
  Int32 m_nLoopEndOffset;
  UInt8 _oldVolume;
  char tmp2[3];
  Float field_30;
  Float field_34;
  Bool field_38;
  char tmp3[3];
  CVector m_vecPosition;
  Bool m_bUseReverb;
  Bool field_49;
  Bool field_4A;
  UInt8 field_4B;
  Int32 field_4C;
  Bool field_50;
  char field_51;
  char tmp6[2];
  int field_54;
  UInt8 field_58;
  char tmp7[3];
};
#pragma pack(pop)


#pragma pack(push, 1)
struct tPedComment
{
  UInt32 m_nSampleIndex;
  int field_4;
  CVector vecPosition;
  Float m_fDistance;
  UInt8 m_nVolume;
  UInt8 field_19;
  char _pad0[2];
};
#pragma pack(pop)


#pragma pack(push, 1)
struct cAMCrime
{
  Int32 m_CrimeType;
  CVector m_vecPos;
  Int16 m_nSampleIndex;
  char _pad0[2];
};
#pragma pack(pop)


#pragma pack(push, 1)
struct cAudioCollision
{
  class CEntity *m_pPhysEntity;
  class CEntity *m_pPhysColling;
  UInt8 m_nSurfaceTypeA;
  UInt8 m_nSurfaceTypeB;
  char _pad0[2];
  Float m_fCollisionPower;
  Float m_fVelocity;
  CVector m_vecPosition;
  Float m_fDistance;
  UInt32 field_24;
};
#pragma pack(pop)


#pragma pack(push, 1)
struct cAudioCollisionManager
{
  cAudioCollision arr1[10];
  cAudioCollision arr2[10];
  UInt8 field_4A9C[10];
  UInt8 field_4AA6;
  char _pad0[1];
  cAudioCollision m_Queue;
};
#pragma pack(pop)


enum eAudioType
{
  AUDIOTYPE_PHYSICAL = 0x0,
  AUDIOTYPE_EXPLOSION = 0x1,
  AUDIOTYPE_FIRE = 0x2,
  AUDIOTYPE_WEATHER = 0x3,
  AUDIOTYPE_CRANE = 0x4,
  AUDIOTYPE_SCRIPTOBJECT = 0x5,
  AUDIOTYPE_BRIDGE = 0x6,
  AUDIOTYPE_COLLISION = 0x7,
  AUDIOTYPE_FRONTEND = 0x8,
  AUDIOTYPE_PROJECTILE = 0x9,
  AUDIOTYPE_GARAGE = 0xA,
  AUDIOTYPE_FIREHYDRANT = 0xB,
  AUDIOTYPE_WATERCANNON = 0xC,
  AUDIOTYPE_POLICERADIO = 0xD,
  MAX_AUDIOTYPES = 0xE,
};


#pragma pack(push, 1)
struct tAudioEntity
{
  eAudioType m_AudioType;
  void *m_Object;
  Bool m_bActive;
  UInt8 m_nStatus;
  UInt16 m_anSfxId[4];
  char _pad0[2];
  Float field_14[4];
  UInt8 field_24;
  char _pad1[3];
};
#pragma pack(pop)


#pragma pack(push, 1)
struct cPoliceRadioQueue
{
  Int32 aSampleIndeces[60];
  UInt8 field_F0;
  UInt8 field_F1;
  UInt8 nSample;
  char _pad0[1];
  cAMCrime aObjects[10];
};
#pragma pack(pop)



#pragma pack(push, 1)
struct cPedComments
{
  tPedComment arr[40];
  UInt8 m_aIndex[40];
  UInt8 field_488[2];
  UInt8 m_nBaseIndex;
  char field_48B;
};
#pragma pack(pop)


class cAudioManager
{
public:
	Bool m_bInitialised;
	char field_1;
	Bool field_2;
	UInt8 m_nActiveSamples;
	char field_4;
	Bool m_bReverb;
	char _pad0[2];
	Float field_8;
	Bool m_bResetTimers;
	char tmp0[3];
	UInt32 _ResetedTimer;
	tSound m_QueueSample;
	UInt8 field_70;
	char tmp1[3];
	tSound m_aSamples[54];
	BYTE field_13DC[54];
	BYTE field_1412[2];
	tSound m_aActiveSamples[27];
	tAudioEntity m_aAudioEntities[200];
	int field_1DC8[200];
	Int32 field_4028;
	CVector field_402C[5];
	Float field_4068[5];
	int m_aScriptObjectEntityIndex[40];
	int m_nScriptObjectEntityNum;
	cPedComments m_PedComments;
	Int32 m_hFire;
	Int32 m_hWaterCannon;
	Int32 m_hPoliceRadio;
	cPoliceRadioQueue m_PoliceQueue;
	Int32 m_hFrontEnd;
	Int32 m_hCollision;
	cAudioCollisionManager m_CollisionManager;
	Int32 m_hProjectile;
	Int32 m_hBridge;
	CVector m_vecMissionAudioLocation;
	Bool field_4AE4;
	char f4AE5[3];
	UInt32 m_nMissionAudioIndex;
	UInt8 m_nMissionAudioLoadingStatus;
	UInt8 _bLowVolume;
	Bool field_4AEE;
	char f4AEF[1];
	UInt32 field_4AF0;
	Bool field_4AF4;
	char f4AF5[3];
	UInt32 m_aRandomTable[5];
	UInt8 field_4B0C;
	Bool m_bUserPause;
	Bool m_bOldUserPause;
	char _pad8[1];
	UInt32 m_nJumboVolOffset;
	
	float GetDistanceSquared(CVector const& vec);
	void CalculateDistance(unsigned char& a1, float a2);
	unsigned char ComputeVolume(unsigned char a1, float a2, float a3);
	int RandomDisplacement(unsigned int a1);
	void ProcessLoopingScriptObject(unsigned char a1);
	void AddSampleToRequestedQueue();
};

extern cAudioManager &AudioManager;
