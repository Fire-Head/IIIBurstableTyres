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
};