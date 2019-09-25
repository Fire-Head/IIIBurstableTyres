#pragma once
#include "..\address.h"
#include "CEntity.h"

class CPtrNode
{
public:
    CEntity *pEntity;
    CPtrNode *pPrev;
    CPtrNode *pNext;
};