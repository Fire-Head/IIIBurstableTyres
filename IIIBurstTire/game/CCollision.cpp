#include "CCollision.h"

Bool CCollision::ProcessLineOfSight(CColLine const& line, CMatrix const& matrix, CColModel& model, CColPoint& point, float& dist, Bool unk)
{
	return ((Bool (__cdecl *)(CColLine const&, CMatrix const&, CColModel&, CColPoint&, float&, Bool))AddressByVersion(0x40F910, 0x40F910, 0x40F910))(line, matrix, model, point, dist, unk);
}
