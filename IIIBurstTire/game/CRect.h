#pragma once
#include "..\address.h"

class CRect
{
public:
	union{	
		struct{
			float x1;
			float y2;
			float x2;
			float y1;
		};
		
		struct{
			float left;
			float bottom;
			float right;
			float top;
		};
	};
	CRect();
	CRect(float x1, float y1, float x2, float y2);
};