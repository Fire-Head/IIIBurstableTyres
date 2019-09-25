#pragma once
#include "..\address.h"
#include "CColModel.h"
#include "RenderWare.h"
#include "CVector.h"

class CBaseModelInfo
{
public:
	void *vtable;
	char m_aName[24];
	CColModel *m_pColModel;
	void *m_p2dEffect;
	__int16 m_nObjectDataId;
	__int16 m_nRefCount;
	__int16 m_nTxdId;
	char m_nType;
	char m_nNum2dEffects;
	char field_2C;
	char _padding[3];

};

class CClumpModelInfo : public CBaseModelInfo
{
public:
  RpClump *m_pClump;
};

class CPedModelInfo : public CClumpModelInfo
{
public:
  int m_nAnimGroupId;
  int m_nPedtype;
  int m_nStatPedtype;
  int m_nCarsCanDriveMask;
  CColModel *m_pHitColModel;
};

class CVehicleModelInfo : public CClumpModelInfo
{
public:
  char m_nLastCarColorId[2];
  char m_aGameName[32];
  char __padding0[2];
  int m_nVehicleType;
  int m_nWheelModelIndex;
  float m_fWheelScale;
  int m_nNumDoors;
  int m_nHandlingId;
  int m_nClass;
  int m_nLvl;
  CVector m_vecDummyPos[10];
  int m_nComprules;
  float m_fBikeSteerAngle;
  void *m_pMaterialPrimary[26];
  void *m_pMaterialSecondary[26];
  char m_nPrimaryColorId[8];
  char m_nSecondaryColorId[8];
  char m_nNumColorVariations;
  char m_nLastColorVariation;
  char m_nCurrentColorId[2];
  void *m_pEnvironmentTex;
  void *m_pExtra[6];
  int m_nNumExtras;
};