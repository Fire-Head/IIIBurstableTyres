#pragma once
#include "..\address.h"
#include "CVector.h"
#include "RenderWare.h"
#include "CEntity.h"
#include "CPlaceable.h"
#include "CCam.h"

enum eCamMode
{
  MODE_NONE = 0,
  MODE_TOPDOWN = 1,
  MODE_GTACLASSIC = 2,
  MODE_BEHINDCAR = 3,
  MODE_FOLLOWPED = 4,
  MODE_AIMING = 5,
  MODE_DEBUG = 6,
  MODE_SNIPER = 7,
  MODE_ROCKETLAUNCHER = 8,
  MODE_MODELVIEW = 9,
  MODE_BILL = 10,
  MODE_SYPHON = 11,
  MODE_CIRCLE = 12,
  MODE_CHEESYZOOM = 13,
  MODE_WHEELCAM = 14,
  MODE_FIXED = 15,
  MODE_1STPERSON = 16,
  MODE_FLYBY = 17,
  MODE_CAM_ON_A_STRING = 18,
  MODE_REACTION = 19,
  MODE_FOLLOW_PED_WITH_BIND = 20,
  MODE_CHRIS = 21,
  MODE_BEHINDBOAT = 22,
  MODE_PLAYER_FALLEN_WATER = 23,
  MODE_CAM_ON_TRAIN_ROOF = 24,
  MODE_CAM_RUNNING_SIDE_TRAIN = 25,
  MODE_BLOOD_ON_THE_TRACKS = 26,
  MODE_IM_THE_PASSENGER_WOOWOO = 27,
  MODE_SYPHON_CRIM_IN_FRONT = 28,
  MODE_PED_DEAD_BABY = 29,
  MODE_PILLOWS_PAPS = 30,
  MODE_LOOK_AT_CARS = 31,
  MODE_ARRESTCAM_ONE = 32,
  MODE_ARRESTCAM_TWO = 33,
  MODE_M16_1STPERSON = 34,
  MODE_SPECIAL_FIXED_FOR_SYPHON = 35,
  MODE_FIGHT_CAM = 36,
  MODE_TOP_DOWN_PED = 37,
  MODE_SNIPER_RUNABOUT = 38,
  MODE_ROCKETLAUNCHER_RUNABOUT = 39,
  MODE_1STPERSON_RUNABOUT = 40,
  MODE_M16_1STPERSON_RUNABOUT = 41,
  MODE_FIGHT_CAM_RUNABOUT = 42,
  MODE_EDITOR = 43,
  MODE_HELICANNON_1STPERSON = 44,
};


#pragma pack(push, 1)
struct struct_4732E0
{
  int field_0[800];
};
#pragma pack(pop)

struct struct_4732C0
{
  float f[14];
};

//#pragma pack(push, 1)
class CCamera : public CPlaceable
{
protected:
	DUMMYB(CCamera, CPlaceable);
public:
	char m_bAboveGroundTrainNodesLoaded;
	char m_bBelowGroundTrainNodesLoaded;
	char m_bCamDirectlyBehind;
	char m_bCamDirectlyInFront;
	char m_bCameraJustRestored;
	char m_bCutsceneFinished;
	char m_bCullZoneChecksOn;
	char m_bFirstPersonBeingUsed;
	char field_54;
	char field_55;
	char m_bInATunnelAndABigVehicle;
	char field_57;
	char field_58;
	char field_59;
	char field_5A;
	char field_5B;
	char m_bJustInitalised;
	char m_bJust_Switched;
	char m_bLookingAtPlayer;
	char m_bLookingAtVector;
	char m_bMoveCamToAvoidGeom;
	char m_bObbeCinematicPedCamOn;
	char m_bObbeCinematicCarCamOn;
	char m_bRestoreByJumpCut;
	char m_bUseNearClipScript;
	char field_65;
	char field_66;
	char field_67;
	char field_68;
	char m_bUseSpecialFovTrain;
	char m_bUseTransitionBeta;
	char field_6B;
	char field_6C;
	char field_6D;
	char field_6E;
	char m_bWantsToSwitchWidescreenOff;
	char m_bWideScreenOn;
	char m_b1rstPersonRunCloseToAWall;
	char m_bHeadBob;
	char m_bVehicleSuspenHigh;
	char field_74;
	char m_bDebugCamPCOn;
	char m_nActiveCam;
	char _pad0;
	int m_nCamShakeStart;
	int field_7C;
	int field_80;
	int field_84;
	char field_88;
	char field_89;
	char _pad1[2];
	int field_8C;
	int field_90;
	int m_nTimeTransitionStart;
	int field_98;
	unsigned int m_nBlurBlue;
	unsigned int m_nBlurGreen;
	unsigned int m_nBlurRed;
	int m_nBlurType;
	int field_AC;
	int m_nWorkOutSpeedThisNumFrames;
	int m_nNumFramesSoFar;
	int m_nCurrentTrainCamNode;
	unsigned int m_nMotionBlur;
	unsigned int m_nMotionBlurAddAlpha;
	int field_C4;
	int field_C8;
	int field_CC;
	float field_D0;
	float field_D4;
	float field_D8;
	float field_DC;
	float field_E0;
	float field_E4;
	float field_E8;
	float field_EC;
	float field_F0;
	float field_F4;
	float field_F8;
	float field_FC;
	float field_100;
	float field_104;
	float field_108;
	float field_10C;
	float field_110;
	float field_114;
	float field_118;
	float field_11C;
	float field_120;
	float field_124;
	float field_128;
	float field_12C;
	float m_fFovForTrain;
	float m_fFOV_Wide_Screen;
	float m_fNearClipScript;
	float field_13C;
	float field_140;
	float field_144;
	float field_148;
	float field_14C;
	float field_150;
	float field_154;
	float field_158;
	float m_fOrientation;
	float _m_fCameraModeID;
	float field_164;
	float field_168;
	float field_16C;
	float field_170;
	float field_174;
	float field_178;
	float field_17C;
	float field_180;
	float field_184;
	float field_188;
	float field_18C;
	float field_190;
	float field_194;
	float field_198;
	float field_19C;
	float field_1A0;
	CCam m_aCams[3];
  int field_690;
  int field_694;
  __int16 field_698;
  char field_align1[10];
  __int16 m_nPlayerWeaponMode;
  char _pad7[2];
  float m_fPlayerWeaponDuration;
  __int16 m_nPlayerWeaponMaxZoom;
  __int16 m_nPlayerWeaponMinZoom;
	CVector m_vecPreviousCameraPosition;
    CVector m_vecRealPreviousCameraPosition;
    CVector m_vecAimingTargetCoors;
    CVector m_vecFixedModeVector;
    CVector m_vecFixedModeSource;
    CVector m_vecFixedModeUpOffSet;
    CVector m_vecCutSceneOffset;
    CVector m_vecStartingSourceForInterPol;
    CVector m_vecStartingTargetForInterPol;
    CVector m_vecStartingUpForInterPol;
    CVector m_vecSourceSpeedAtStartInter;
    CVector m_vecTargetSpeedAtStartInter;
    CVector m_vecUpSpeedAtStartInter;
    CVector m_vecSourceWhenInterPol;
    CVector m_vecTargetWhenInterPol;
	CVector field_764;
	CVector field_770;
	CVector field_77C;
	CVector field_788;
	CVector field_794;
	RwCamera *m_pRwCamera;
	CEntity *m_pTargetEntity;
	struct_4732E0 m_aPathArray[4];
	struct_4732C0 m_aTrainCamNodes[800];
	char field_align2[152];
	CVector field_E940;
	CVector field_E94C;
	CVector field_E958;
	CVector field_E964;
	CVector field_E970;
	CVector field_E97C;
	CVector field_E988;
	int field_E994;
	float m_fFadeAlpha;
	DWORD field_E99C;
	float field_E9A0;
	float field_E9A4;
	float field_E9A8;
	float field_E9AC;
	float field_E9B0;
	float field_E9B4;
	float field_E9B8;
	unsigned int field_E9BC;
	__int16 field_E9C0;
	char _pad3[2];
	int field_E9C4;
	__int16 field_E9C8;
	__int16 field_E9CA;
	__int16 field_E9CC;
	char _pad4[2];
	int field_E9D0;
	int field_E9D4;
	
	static char &m_bUseMouse3rdPerson;
};
//#pragma pack(pop)

extern CCamera& TheCamera;
