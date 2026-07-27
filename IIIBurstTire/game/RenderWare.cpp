#include "RenderWare.h"

RpHAnimHierarchy* RpSkinAtomicGetHAnimHierarchy(RpAtomic const* atomic)
{
	return ((RpHAnimHierarchy* (__cdecl *)(RpAtomic const*))AddressByVersion(0x5B1070, 0x5B1330, 0x5B4B80))(atomic);
}

RpSkin* RpSkinGeometryGetSkin(RpGeometry* geometry)
{
	return ((RpSkin* (__cdecl *)(RpGeometry*))AddressByVersion(0x5B1080, 0x5b1340, 0x5B4B90))(geometry);
}

RwBool RwIm3DRenderIndexedPrimitive(RwPrimitiveType primType, RwImVertexIndex* indices, RwInt32 numIndices)
{
	return ((RwBool (__cdecl *)(RwPrimitiveType, RwImVertexIndex*, RwInt32))AddressByVersion(0x5B6820, 0x5B6AE0, 0x5BB200))(primType, indices, numIndices);
}

RwBool RwIm3DEnd()
{
	return ((RwBool (__cdecl *)())AddressByVersion(0x5B67F0, 0x5B6AB0, 0x5BB1C0))();
}

void* RwIm3DTransform(RwIm3DVertex* pVerts, RwUInt32 numVerts, RwMatrix* ltm, RwUInt32 flags)
{
	return ((void* (__cdecl *)(RwIm3DVertex*, RwUInt32, RwMatrix*, RwUInt32))AddressByVersion(0x5B6720, 0x5B69E0, 0x5BB0D0))(pVerts, numVerts, ltm, flags);
}

RwBool RwRenderStateSet(RwRenderState state, void* value)
{
	//return ((RwBool (__cdecl *)(RwRenderState, void*))0x5A43C0)(state, value);
	return ((RwBool (__cdecl *)(RwRenderState, void*))AddressByVersion(0x5A43C0, 0x5A4680, 0x5A5360))(state, value);
}

RpClump* RpClumpForAllAtomics(RpClump* clump, RpAtomicCallBack callback, void* pData)
{
	return ((RpClump* (__cdecl *)(RpClump*, RpAtomicCallBack, void*))AddressByVersion(0x59EDD0, 0X59F090, 0X59EFC0))(clump, callback, pData);
}

RwV3d* RwV3dTransformPoints(RwV3d* pointsOut, RwV3d const* pointsIn, RwInt32 numPoints, RwMatrix const* matrix)
{
	return ((RwV3d* (__cdecl *)(RwV3d*, RwV3d const*, RwInt32, RwMatrix const*))AddressByVersion(0x5A37D0, 0x5A3A90, 0x5A4570))(pointsOut, pointsIn, numPoints, matrix);
}