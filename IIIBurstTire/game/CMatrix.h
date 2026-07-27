#pragma once
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
	
	CVector &GetPosition(void) { return pos; }
	CVector &GetRight(void) { return right; }
	CVector &GetForward(void) { return up; }
	CVector &GetUp(void) { return at; }
	
	//
	CMatrix()
	{
		m_pAttachMatrix = NULL;
		m_bAttachMatrixTemporary = false;
	};
	
	
	~CMatrix(); 
	
	void Attach(RwMatrix *matrix, bool temporary);
	void SetRotate(float x, float y, float z);
};

extern CMatrix Invert(CMatrix const& in);
extern void Invert(CMatrix const& in, CMatrix&out);
extern CVector Multiply3x3(CMatrix const& m, CVector const& v);