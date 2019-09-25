#pragma once
#include "..\address.h"
#include "RenderWare.h"
#include "CVector.h"

struct AnimBlendFrameData
{
  char m_nFlags;
  char _pad[3];
  CVector m_vecOffset;
  RwFrame *m_pRwFrame;
};

enum CallbackType
{
  FinishCallbackType = 0x1,
  DeleteCallbackType = 0x2,
};

#pragma pack(push, 1)
struct CAnimBlendSequence
{
  void *vtable;
  DWORD field_4;
  char m_cName[24];
  int m_nKeyFrames;
  DWORD m_keyFrames;
  DWORD field_28;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct CAnimBlendNode
{
  float m_fTheta0;
  float m_fTheta1;
  int m_nEndKeyFrameId;
  int m_nStartKeyFrameId;
  float m_fTimeDelta;
  CAnimBlendSequence *m_pAnimBlendSequence;
  DWORD field_18;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct CAnimBlendHierarchy
{
  char m_cName[24];
  CAnimBlendSequence *m_pSequences;
  __int16 m_nNumSequences;
  __int16 m_nLoadCompressed;
  float m_fTotalTime;
  DWORD field_24;
};
#pragma pack(pop)

class CAnimBlendAssociation
{
protected:
	DUMMY(CAnimBlendAssociation);
public:
	//void *vtable;
	DWORD field_4;
	DWORD field_8;
	int m_nAnimBlendNodeCount;
	CAnimBlendNode *m_pAnimBlendNodeArray; //CAnimBlendNode *
	CAnimBlendHierarchy *m_pAnimBlendHierarchy; //CAnimBlendHierarchy *
	float m_fBlendAmount;
	float m_fBlendDelta;
	float m_fCurrentTime;
	float m_fSpeed;
	float m_fTimeStep;
	int m_nAnimID;
	int m_Flags;
	int m_eCallbackType; //CallbackType
	void *m_pCallbackFunc;
	void *m_pCallbackData;

	CAnimBlendAssociation();
	virtual ~CAnimBlendAssociation(); //__vecDelDtor
};