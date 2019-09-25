#pragma once
#include <windows.h>
#include "CPhysical.h"
#include "CVehicle.h"
#include "CWeapon.h"
#include "CVector2D.h"
#include "CFire.h"
#include "RenderWare.h"
#include "..\address.h"
#include "CStoredCollPoly.h"
#include "CAnimBlendAssociation.h"

enum eMoveState
{
  PEDMOVE_NONE = 0x0,
  PEDMOVE_STILL = 0x1,
  PEDMOVE_WALK = 0x2,
  PEDMOVE_JOG = 0x3,
  PEDMOVE_RUN = 0x4,
  PEDMOVE_SPRINT = 0x5,
  PEDMOVE_THROWN = 0x6,
};

typedef int AnimationId;

enum eObjective
{
  OBJECTIVE_FALSE = 0x0,
  OBJECTIVE_WAIT_ON_FOOT = 0x1,
  OBJECTIVE_FLEE_ON_FOOT_TILL_SAFE = 0x2,
  OBJECTIVE_GUARD_SPOT = 0x3,
  OBJECTIVE_GUARD_AREA = 0x4,
  OBJECTIVE_WAIT_IN_CAR = 0x5,
  OBJECTIVE_WAIT_IN_CAR_THEN_GETOUT = 0x6,
  OBJECTIVE_KILL_CHAR_ON_FOOT = 0x7,
  OBJECTIVE_KILL_CHAR_ANY_MEANS = 0x8,
  OBJECTIVE_FLEE_CHAR_ON_FOOT_TILL_SAFE = 0x9,
  OBJECTIVE_FLEE_CHAR_ON_FOOT_ALWAYS = 0xA,
  OBJECTIVE_GOTO_CHAR_ON_FOOT = 0xB,
  OBJECTIVE_FOLLOW_CHAR_IN_FORMATION = 0xC,
  OBJECTIVE_LEAVE_CAR = 0xD,
  OBJECTIVE_ENTER_CAR_AS_PASSENGER = 0xE,
  OBJECTIVE_ENTER_CAR_AS_DRIVER = 0xF,
  OBJECTIVE_FOLLOW_CAR_IN_CAR = 0x10,
  OBJECTIVE_FIRE_AT_OBJ_FROM_VEHICLE = 0x11,
  OBJECTIVE_DESTROY_OBJ = 0x12,
  OBJECTIVE_DESTROY_CAR = 0x13,
  OBJECTIVE_GOTO_AREA_ANY_MEANS = 0x14,
  OBJECTIVE_GOTO_AREA_ON_FOOT = 0x15,
  OBJECTIVE_RUN_TO_AREA = 0x16,
  OBJECTIVE_GOTO_AREA_IN_CAR = 0x17,
  OBJECTIVE_FOLLOW_CAR_ON_FOOT_WOFFSET = 0x18,
  OBJECTIVE_GUARD_ATTACK = 0x19,
  OBJECTIVE_SET_LEADER = 0x1A,
  OBJECTIVE_FOLLOW_ROUTE = 0x1B,
  OBJECTIVE_SOLICIT = 0x1C,
  OBJECTIVE_TAKE_TAXI = 0x1D,
  OBJECTIVE_CATCH_TRAIN = 0x1E,
  OBJECTIVE_BUY_ICECREAM = 0x1F,
  OBJECTIVE_STEAL_ANY_CAR = 0x20,
  OBJECTIVE_MUG_CHAR = 0x21,
  OBJECTIVE_FLEE_CAR = 0x22,
};


struct LimbMovementInfo
{
  float maxYaw;
  float minYaw;
  float yawD;
  float maxPitch;
  float minPitch;
  float pitchD;
};
struct LimbOrientation
{
  float yaw;
  float pitch;
};


#pragma pack(push, 1)
struct struct_4C50C0
{
  DWORD field_0;
  DWORD field_4;
};
#pragma pack(pop)


class CPedIK
{
public:
	void *m_pPed;
	LimbOrientation m_torsoOrien;
	LimbOrientation field_C;
	float m_fSlopePitch;
	float m_fSlopePitchLimitMult;
	float m_fSlopeRoll;
	float m_fBodyRoll;
	unsigned __int32 m_nFlags;
	
	static RwMatrix* CPedIK::GetWorldMatrix(RwFrame* frame, RwMatrix* matrix)
	{
		return ((RwMatrix* (__cdecl *)(RwFrame*, RwMatrix*))AddressByVersion(0x4ED060, 0x4ED110, 0x4ED0A0))(frame, matrix);
	}
};

enum ePedStates
{
  PED_NONE = 0x0,
  PED_IDLE = 0x1,
  PED_LOOK_ENTITY = 0x2,
  PED_LOOK_HEADING = 0x3,
  PED_WANDER_RANGE = 0x4,
  PED_WANDER_PATH = 0x5,
  PED_SEEK_POS = 0x6,
  PED_SEEK_ENTITY = 0x7,
  PED_FLEE_POS = 0x8,
  PED_FLEE_ENTITY = 0x9,
  PED_PURSUE = 0xA,
  PED_FOLLOW_PATH = 0xB,
  PED_SNIPER_MODE = 0xC,
  PED_ROCKET_MODE = 0xD,
  PED_DUMMY = 0xE,
  PED_PAUSE = 0xF,
  PED_ATTACK = 0x10,
  PED_FIGHT = 0x11,
  PED_FACE_PHONE = 0x12,
  PED_MAKE_CALL = 0x13,
  PED_CHAT = 0x14,
  PED_MUG = 0x15,
  PED_AIMGUN = 0x16,
  PED_AI_CONTROL = 0x17,
  PED_SEEK_CAR = 0x18,
  PED_SEEK_INBOAT = 0x19,
  PED_FOLLOW_ROUTE = 0x1A,
  PED_C_P_R = 0x1B,
  PED_SOLICIT = 0x1C,
  PED_BUY_ICECREAM = 0x1D,
  PED_INVESTIGATE = 0x1E,
  PED_STEP_AWAY = 0x1F,
  PED_ON_FIRE = 0x20,
  PED_HANG_OUT = 0x21,
  PED_NO_AI = 0x22,
  PED_JUMP = 0x23,
  PED_FALL = 0x24,
  PED_GETUP = 0x25,
  PED_STAGGER = 0x26,
  PED_DIVE_AWAY = 0x27,
  PED_NO_ST = 0x28,
  PED_ENTER_TRAIN = 0x29,
  PED_EXIT_TRAIN = 0x2A,
  PED_ARREST_PLYR = 0x2B,
  PED_DRIVING = 0x2C,
  PED_PASSENGER = 0x2D,
  PED_TAXI_PASSNGR = 0x2E,
  PED_OPEN_DOOR = 0x2F,
  PED_DIE = 0x30,
  PED_DEAD = 0x31,
  PED_CARJACK = 0x32,
  PED_DRAG_FM_CAR = 0x33,
  PED_ENTER_CAR = 0x34,
  PED_STEAL_CAR = 0x35,
  PED_EXIT_CAR = 0x36,
  PED_HANDS_UP = 0x37,
  PED_ARRESTED = 0x38,
};




enum eFormation
{
  FORMATION_NONE = 0x0,
  FORMATION_BEHIND = 0x1,
  FORMATION_BACKLEFT = 0x2,
  FORMATION_BACKRIGHT = 0x3,
  FORMATION_FRONTLEFT = 0x4,
  FORMATION_FRONTRIGHT = 0x5,
  FORMATION_LEFT = 0x6,
  FORMATION_RIGHT = 0x7,
  FORMATION_FRONT = 0x8,
};

#pragma pack(push, 1)
struct CPathNode
{
  CVector m_vecPoint;
  unsigned int field_C;
  unsigned int field_10;
  unsigned __int16 field_14;
  unsigned __int16 field_16;
  unsigned __int16 field_18;
  unsigned __int8 m_bFlags;
  unsigned __int8 field_1B;
  unsigned __int8 m_bNumFloodFillGroups;
  unsigned __int8 field_1D;
  unsigned __int8 field_1E;
  unsigned __int8 field_1F;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct CAccident
{
  DWORD field_0;
  DWORD ___nNumOfMedics;
  DWORD field_8;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct CPedStats
{
  int m_nIndex;
  char m_aName[24];
  int m_fFleeDistance;
  float m_fHeadingChangeRate;
  char m_nFear;
  char m_nTemper;
  char m_nLawfullness;
  char m_nSexiness;
  int m_fAttackStrength;
  int m_fDefendWeakness;
  __int16 m_nFlags;
  __int16 _pad0;
};
#pragma pack(pop)


struct FightMoves
{
  UInt32 nAnimId;
  Float fStartFireTime;
  Float fEndFireTime;
  Float fComboFollowOnTime;
  Float fStrikeRadius;
  UInt8 nHitLevel;
  UInt8 nDamage;
  UInt8 Flags;
  char _pad0[1];
};

#pragma pack(push, 1)
struct tPedRoute
{
  Int16 field_0;
  char _pad0[2];
  CVector vecPosn;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct CPedType
{
  UInt32 Flags;
  Float field_4;
  Float field_8;
  Float field_C;
  Float field_10;
  Float field_14;
  UInt32 ThreatFlags;
  UInt32 AvoidFlags;
};
#pragma pack(pop)

enum ePedType
{
  PEDTYPE_PLAYER1 = 0x0,
  PEDTYPE_PLAYER2 = 0x1,
  PEDTYPE_PLAYER3 = 0x2,
  PEDTYPE_PLAYER4 = 0x3,
  PEDTYPE_CIVMALE = 0x4,
  PEDTYPE_CIVFEMALE = 0x5,
  PEDTYPE_COP = 0x6,
  PEDTYPE_GANG1 = 0x7,
  PEDTYPE_GANG2 = 0x8,
  PEDTYPE_GANG3 = 0x9,
  PEDTYPE_GANG4 = 0xA,
  PEDTYPE_GANG5 = 0xB,
  PEDTYPE_GANG6 = 0xC,
  PEDTYPE_GANG7 = 0xD,
  PEDTYPE_GANG8 = 0xE,
  PEDTYPE_GANG9 = 0xF,
  PEDTYPE_MEDIC = 0x10,
  PEDTYPE_FIRE = 0x11,
  PEDTYPE_CRIMINAL = 0x12,
  PEDTYPE_BUM = 0x13,
  PEDTYPE_PROSTITUTE = 0x14,
  PEDTYPE_SPECIAL = 0x15,
  PEDTYPE_DUMMY = 0x16,
};

class CPed : public CPhysical
{
protected:
	DUMMYB(CPed, CPhysical);

public:
CStoredCollPoly m_pCollPoly;
  Float m_fCollisionSpeed;
  UInt8 m_Flags0;
  UInt8 m_Flags1;
  UInt8 m_Flags2;
  UInt8 m_Flags3;
  UInt8 m_Flags4;
  UInt8 m_Flags5;
  UInt8 m_Flags6;
  UInt8 m_Flags7;
  UInt8 m_Flags8;
  char _pad0[3];
  UInt8 m_nReferenceType;
  char _pad1[3];
  UInt32 m_nObjective;
  UInt32 m_nPrevObjective;
  CEntity *m_pObjectiveEntity;
  CEntity *m_pTargetEntity;
  CVector m_vecObjective;
  CPed *m_pLeader;
  eFormation m_Formation;
  UInt32 m_FearFlags;
  CPed *m_pThreatPed;
  CVector2D m_vec2dThreat;
  UInt32 m_nEventType;
  CEntity *m_pEventEntity;
  Float m_fAngleToEvent;
  AnimBlendFrameData *m_apBodyParts[12];
  UInt32 m_nAnimGroupId;
  CAnimBlendAssociation *m_pVehicleAnimBlendAssoc;
  CVector2D m_vec2dAnimMoveDelta;
  CVector m_vecOffsetSeek;
  CPedIK m_PedIK;
  CVector2D m_vec2dState;
  Int32 m_nStateTimer;
  ePedStates m_nPedState;
  ePedStates m_LastState;
  eMoveState m_MoveState;
  eMoveState m_LastMoveState;
  eMoveState m_PrevMoveState;
  UInt32 m_nWaitState;
  Int32 m_nWaitStateTimer;
  CPathNode *m_pPathNodes[8];
  CVector2D field_260[10];
  UInt16 m_nPathNodes;
  UInt16 m_nCurPathNode;
  SInt8 m_nPathHeadDirection;
  char _pad2[3];
  CPathNode *m_pCurrentNode;
  CPathNode *m_pNextNode;
  Float m_fHealth;
  Float m_fArmour;
  Int16 m_nRouteLastPoint;
  Int16 m_nRoutePoints;
  Int16 m_nRoutePos;
  Int16 m_nRouteType;
  Int16 m_nRouteCurDir;
  char _pad3[2];
  CVector2D m_vec2dAnimMovingShift;
  Float m_fCurrentRotation;
  Float m_fAimingRotation;
  Float m_fHeadingChangeRate;
  UInt16 m_nEnterType;
  UInt16 m_nWalkAroundType;
  CEntity *m_pCurrentPhysSurface;
  CVector m_vecOffsetFromPhysSurface;
  CEntity *m_pCurrentSurface;
  CVector m_vecSeekPosn;
  CEntity *m_pAimingEntity;
  class CVehicle *m_pVehicle;
  Bool m_bInVehicle;
  char _pad4[3];
  Float field_318;
  Bool m_bHasPhone;
  char _pad5[1];
  Int16 m_nPhoneIndex;
  Int32 m_nLookingForPhone;
  Int32 m_nPhoneTalkTimer;
  CAccident *m_pLastAccident;
  UInt32 m_nPedType;
  CPedStats *m_pStats;
  CVector2D m_vec2DFleeFromPosn;
  CEntity *m_pFleeFrom;
  Int32 m_nFleeTimer;
  CEntity *m_pLastThreat;
  Int32 m_nLastThreatTimer;
  CEntity *m_pVehicleColliding;
  UInt8 field_350;
  char _pad6[3];
  Int32 field_354;
  void *m_pRange2D;
  CWeapon m_aWeapons[13];
  eWeaponType m_eSavedWeapon;
  UInt8 m_nActiveWeapon;
  UInt8 m_nLoadedWeapons;
  UInt8 field_49A;
  UInt8 m_nWeaponAccuracy;
  CPed *m_pThreatAttack;
  CVector m_vecHitLastPos;
  UInt32 m_nFightState;
  UInt8 field_4B0;
  UInt8 field_4B1;
  Bool field_4B2;
  char _pad7[1];
  CFire *m_pPedFire;
  CPed *m_pPedFight;
  Float m_fLookDirection;
  Int32 m_nWeaponModelID;
  Int32 m_nLeaveCarTimer;
  Int32 m_nGetUpTimer;
  Int32 m_nLookTimer;
  Int32 m_nStandardTimer;
  Int32 m_nAttackTimer;
  Int32 m_nShootTimer;
  Int32 m_nHitRecoverTimer;
  Int32 m_nObjectiveTimer;
  Int32 m_nDuckTimer;
  Int32 _m_nDuckAndCoverTimer;
  Int32 _m_nBloodyTimer;
  UInt8 m_nPanicCounter;
  Bool m_nDeadBleeding;
  Int8 m_nBodyPartBleeding;
  char _pad8[1];
  CPed *m_apNearByPeds[10];
  UInt16 m_nNumNearByPeds;
  UInt8 m_nLastWeaponDamage;
  char _pad9[1];
  Int32 m_nSayTimer;
  Int32 m_nTalkTimer;
  UInt16 m_nComment;
  UInt16 m_nLastComment;
  CVector m_vecGuardSeekPos;
  Float m_fGuardSeekAngle;
	
	CPed() { }
	virtual ~CPed();
	bool IsPlayer()
	{
		return ((bool (__thiscall *)(CPed *))AddressByVersion(0x4D48E0, 0x4D4980, 0x4D4910))(this);
	}
	
	bool UseGroundColModel()
	{
		return ((bool (__thiscall *)(CPed*))AddressByVersion(0x4CE730, 0x4CE7D0, 0x4CE760))(this);
	}
};

VALIDATE_SIZE(CPed, 0x53C);