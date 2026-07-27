#pragma once
#include "CCutsceneObject.h"
#include "RenderWare.h"
#include "..\address.h"

class CCutsceneHead : public CCutsceneObject
{
protected:
	DUMMYB(CCutsceneHead, CCutsceneObject);
public:
	RwFrame *m_pSHeadFrame;
};

VALIDATE_SIZE(CCutsceneHead, 0x19C);