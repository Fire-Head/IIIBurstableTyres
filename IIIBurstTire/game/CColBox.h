#pragma once
#include "..\address.h"
#include "RenderWare.h"


class CColBox
{
public:
	RwBBox m_Box;
	char material;
	char flag;
	char lighting;
	char light;
};

