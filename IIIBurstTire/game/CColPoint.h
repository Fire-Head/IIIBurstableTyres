#pragma once
#include "..\address.h"
#include "CVector.h"

class CColPoint
{
public:
	CVector m_vecPosition;
	float field_C;
	CVector m_vecNormal;
	float field_1C;
	char m_nSurfaceTypeA;
	char m_nPieceTypeA;
	char m_nSurfaceTypeB;
	char m_nPieceTypeB;
	float m_fDepth;
	
	CColPoint &operator=(CColPoint &right)
	{
		m_vecPosition = right.m_vecPosition;
		m_vecNormal = right.m_vecNormal;
		m_nSurfaceTypeA = right.m_nSurfaceTypeA;
		m_nPieceTypeA = right.m_nPieceTypeA;
		m_nSurfaceTypeB = right.m_nSurfaceTypeB;
		m_nPieceTypeB  = right.m_nPieceTypeB;
		return *this;
	}
};