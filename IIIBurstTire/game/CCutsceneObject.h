#pragma once
#include "CObject.h"
#include "..\address.h"

class CCutsceneObject : public CObject
{
protected:
	DUMMYB(CCutsceneObject, CObject);
public:
};

VALIDATE_SIZE(CCutsceneObject, 0x198);