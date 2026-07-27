#include "CAnimManager.h"

CAnimBlendAssociation* CAnimManager::BlendAnimation(RpClump *pClump, AssocGroupId groupId, AnimationId animId, float fBlendDelta)
{
	return ((CAnimBlendAssociation* (__cdecl *)(RpClump *, AssocGroupId, AnimationId, float))AddressByVersion(0x403710, 0x403710, 0x403710))(pClump, groupId, animId, fBlendDelta);
}

void CAnimManager::AddAnimation(RpClump* clump, AssocGroupId grounID, AnimationId animID)
{
	((void (__cdecl *)(RpClump*, AssocGroupId, AnimationId))AddressByVersion(0x403620, 0x403620, 0x403620))(clump, grounID, animID);
}
