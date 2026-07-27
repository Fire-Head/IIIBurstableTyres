#include "CModelInfo.h"

CBaseModelInfo **CModelInfo::ms_modelInfoPtrs = (CBaseModelInfo **)AddressByVersion(0x83D408, 0x83D408, 0x84D548);

CBaseModelInfo* CModelInfo::GetModelInfo(char const *name, int* index)
{
	return ((CBaseModelInfo* (__cdecl *)(char const*, int*))AddressByVersion(0x50B860, 0x50B950, 0x50B8E0))(name, index);
}