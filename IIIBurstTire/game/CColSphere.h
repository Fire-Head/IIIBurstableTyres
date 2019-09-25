#pragma once
#include "..\address.h"
#include "RenderWare.h"

class CColSphere
{
public:
	RwSphere sphere;
	char material;
	char flag;
	char lighting;
	char light;
	
	void Set(float radius, CVector const &center, unsigned char nMaterial, unsigned char nFlags)
	{
		sphere.radius = radius;
		sphere.center.x = center.x;
		sphere.center.y = center.y;
		sphere.center.z = center.z;
		material = nMaterial;
		flag = nFlags;
	}
};
