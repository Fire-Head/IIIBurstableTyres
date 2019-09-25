#pragma once
#include "CVector.h"

class CColLine
{
public:
	CVector m_vStart;
	float m_fStartSize;
	CVector m_vEnd;
	float m_fEndSize;
	
	CColLine(CVector const &start, CVector const &end) 
	{
		m_vStart = start;
		m_vEnd = end;
	}
	
	CColLine &operator=(const CColLine &right)
	{
		m_vStart = right.m_vStart;
		m_fStartSize = right.m_fStartSize;
		m_vEnd = right.m_vEnd;
		m_fEndSize = right.m_fEndSize;
		return *this;
	}
};
