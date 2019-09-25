#pragma once
#include <windows.h>
#include "CVector.h"
#include "RenderWare.h"
#include "..\address.h"


class CMatrix
{
public:
    CVector right;  // x
    unsigned int flags;
    CVector up;     // y
    unsigned int pad1;
    CVector at;     // z
    unsigned int pad2;
    CVector pos;
    unsigned int pad3;
    RwMatrix *m_pAttachMatrix;
    unsigned __int8 m_bAttachMatrixTemporary; //  bool m_bLinkedMatrix;
	
	
	CVector &GetTranslate()
	{
		return pos;
	}
	
	CVector &GetRight()
	{
		return right;
	}
	
	//
	CMatrix()
	{
		m_pAttachMatrix = NULL;
		m_bAttachMatrixTemporary = false;
	};
	
	
	~CMatrix(); 
	
	void Attach(RwMatrix *matrix, bool temporary);
};

extern CMatrix Invert(CMatrix const& in);