#include "CCollision.h"

Bool CCollision::ProcessLineOfSight(CColLine const& line, CMatrix const& matrix, CColModel& model, CColPoint& point, float& dist, Bool unk)
{
	return ((Bool (__cdecl *)(CColLine const&, CMatrix const&, CColModel&, CColPoint&, float&, Bool))AddressByVersion(0x40F910, 0x40F910, 0x40F910))(line, matrix, model, point, dist, unk);
}

bool CCollision::TestLineTriangle(CColLine const& line, CompressedVector const* varticies, CColTriangle const& triagle, CColTrianglePlane const& triaglePlane)
{
	return ((bool (__cdecl *)(CColLine const&, CompressedVector const*, CColTriangle const&, CColTrianglePlane const&))AddressByVersion(0x40EC10, 0x40EC10, 0x40EC10))(line, varticies, triagle, triaglePlane);
}

void CCollision::CalculateTrianglePlanes(CColModel* colModel)
{
	((void (__cdecl *)(CColModel*))AddressByVersion(0x40B960, 0x40B960, 0x40B960))(colModel);
}

bool CCollision::ProcessLineSphere(CColLine const& colLine, CColSphere const& colSphere, CColPoint& colPoint, float& maxTouchDistance)
{
	return ((bool (__cdecl *)(CColLine const&, CColSphere const&, CColPoint&, float&))AddressByVersion(0x40DE80, 0x40DE80, 0x40DE80))(colLine, colSphere, colPoint, maxTouchDistance);
}