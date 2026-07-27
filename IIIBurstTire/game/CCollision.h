#pragma once
#include "..\address.h"
#include "CColModel.h"
#include "CColLine.h"
#include "CColPoint.h"
#include "CMatrix.h"


class CCollision
{
public:
	static Bool ProcessLineOfSight(CColLine const& line, CMatrix const& matrix, CColModel& model, CColPoint& point, float& dist, Bool unk);
	static bool ProcessLineSphere(CColLine const& colLine, CColSphere const& colSphere, CColPoint& colPoint, float& maxTouchDistance);
	static void CalculateTrianglePlanes(CColModel* colModel);
	static bool TestLineTriangle(CColLine const& line, CompressedVector const* varticies, CColTriangle const& triagle, CColTrianglePlane const& triaglePlane);
	
	
};