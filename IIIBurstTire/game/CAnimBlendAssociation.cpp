#include "CAnimBlendAssociation.h"

void CAnimBlendAssociation::SetDeleteCallback(void (*callback)(CAnimBlendAssociation *, void *), void* entity)
{
	((void (__thiscall *)(CAnimBlendAssociation*, void*, void*))AddressByVersion(0x401800, 0x401800, 0x401800))(this, callback, entity);
}

void CAnimBlendAssociation::SetFinishCallback(void (*callback)(CAnimBlendAssociation *, void *), void* entity)
{
	((void (__thiscall *)(CAnimBlendAssociation*, void*, void*))AddressByVersion(0x401820, 0x401820, 0x401820))(this, callback, entity);
}
