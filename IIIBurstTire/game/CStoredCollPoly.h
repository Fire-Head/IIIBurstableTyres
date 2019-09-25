#pragma once
#include "CVector.h"

#pragma pack(push, 1)
struct CStoredCollPoly
{
  CVector m_aMeshVertices[3];
  char m_bIsActual;
  char _pad0[3];
};
#pragma pack(pop)