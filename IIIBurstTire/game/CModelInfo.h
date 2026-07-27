#pragma once
#include "..\address.h"
#include "CBaseModelInfo.h"

class CModelInfo
{
public:
	static CBaseModelInfo **ms_modelInfoPtrs;
	static CBaseModelInfo* GetModelInfo(char const *name, int* index);
};