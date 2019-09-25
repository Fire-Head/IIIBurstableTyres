#pragma once
#include "..\address.h"
#include "CVector.h"
#include "CColPoint.h"
#include "CColSphere.h"
#include "CColBox.h"
#include "eLevelName.h"
#include "CColLine.h"
#include "CompressedVector.h"
#include "CColTriangle.h"
#include "CColTrianglePlane.h"

class CColModel
{
public:
    CColSphere m_BoundSphere;
    CColBox m_BoundBox;
    unsigned short m_nNumSpheres;
    unsigned short m_nNumLines;
    unsigned short m_nNumBoxes;
    unsigned short m_nNumTriangles;
    eLevelName m_ColLevel;
    unsigned char m_nFlags;
    CColSphere *m_pSpheres;
    CColLine *m_pLines;
    CColBox *m_pBoxes;
    CompressedVector *m_pVertices;
    CColTriangle *m_pTriangles;
    CColTrianglePlane *m_pTrianglePlanes;
};
