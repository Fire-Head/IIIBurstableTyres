#pragma once
#include <math.h> 
#include "RenderWare.h"
#include "CVector2D.h"
#include "..\address.h"
#include "types.h"

#define SQR(x) ( x * x )

class CVector
{
public:
    float x, y, z;

    CVector();
	CVector(float _x, float _y, float _z);
	
	CVector(CVector &refVector) : x(refVector.x), y(refVector.y), z(refVector.z)
	{
		;
	}
	
	CVector(const CVector &refVector) : x(refVector.x), y(refVector.y), z(refVector.z)
	{
		;
	}
	
	CVector(CVector2D &refVector, float _z = 0.0f) : x(refVector.x), y(refVector.y), z(_z)
	{
		;
	}
	
	CVector(const CVector &refVector, float _z) : x(refVector.x), y(refVector.y), z(_z)
	{
		;
	}
	
	CVector(float _v) : x(_v), y(_v), z(_v)
	{
		;
	}
	
	operator RwV3d (void) const {
		RwV3d vecRw = { this->x, this->y, this->z };
		return vecRw;
	}
	
	operator RwV3d *(void)
	{
		return (RwV3d *)this;
	}
	
	operator RwV3d &(void)
	{
		return *((RwV3d *)this);
	}
	
	/*
	operator const RwV3d * const(void) const {
		RwV3d vecRw = { this->x, this->y, this->z };
		return &vecRw;
	}
	*/
	void Normalise();
	float NormaliseAndMag();
	void Normalise2D();
	float Magnitude();
	float MagnitudeSqr() const
	{
		return SQR(x) + SQR(y) + SQR(z);
	}
	
	Float Magnitude2DSqr() const
	{
		return SQR(x) + SQR(y);
	}
	
	Float Magnitude2D() const
	{
		return sqrt(Magnitude2DSqr());
	}
	
	
	// operator =
	inline CVector const& operator = (CVector const &refRight)
	{
		x = refRight.x;
		y = refRight.y;
		z = refRight.z;
		return *this;
	}
	
	inline CVector const& operator = (Float fRight)
	{
		x = fRight;
		y = fRight;
		z = fRight;
		return *this;
	}
	
	// operator +=
	inline CVector const& operator += (CVector const &refRight)
	{
		x += refRight.x;
		y += refRight.y;
		z += refRight.z;
		return *this;
	}
	
	inline CVector const& operator += (Float fRight)
	{
		x += fRight;
		y += fRight;
		z += fRight;
		return *this;
	}
	
	// operator -=
	inline CVector const& operator -= (CVector const &refRight)
	{
		x -= refRight.x;
		y -= refRight.y;
		z -= refRight.z;
		return *this;
	}
	
	inline CVector const& operator -= (Float fRight)
	{
		x -= fRight;
		y -= fRight;
		z -= fRight;
		return *this;
	}
	
	// operator *=
	inline CVector const& operator *= (CVector const &refRight)
	{
		x *= refRight.x;
		y *= refRight.y;
		z *= refRight.z;
		return *this;
	}
	
	inline CVector const& operator *= (Float fRight)
	{
		x *= fRight;
		y *= fRight;
		z *= fRight;
		return *this;
	}
	
	// operator /=
	inline CVector const& operator /= (CVector const &refRight)
	{
		x /= refRight.x;
		y /= refRight.y;
		z /= refRight.z;
		return *this;
	}
	
	inline CVector const& operator /= (Float fRight)
	{
		x /= fRight;
		y /= fRight;
		z /= fRight;
		return *this;
	}
	
	
	inline CVector operator - () const
    {
        return CVector(-x, -y, -z);
    }
	
	float Heading(void) const { return atan2f(-x, y); }
};

extern CVector CrossProduct(const CVector& first, const CVector& second);

inline float
CrossProduct2D(const CVector2D &v1, const CVector2D &v2)
{
	return v1.x*v2.y - v1.y*v2.x;
}

//extern CVector operator*(CMatrix const& matrix, CVector const& vector);

Float DotProduct(CVector const &refA, CVector const &refB);

// operator +
extern CVector operator + (CVector const &refLeft, CVector const &refRight);
extern CVector operator + (CVector const &refLeft, Float fRight);
extern CVector operator + (Float fLeft, CVector const &refRight);

// operator -
extern CVector operator - (CVector const &refLeft, CVector const &refRight);
extern CVector operator - (CVector const &refLeft, Float fRight);
extern CVector operator - (Float fLeft, CVector const &refRight);
 
// operator *
extern CVector operator * (CVector const &refLeft, CVector const &refRight);
extern CVector operator * (CVector const &refLeft, Float fRight);
extern CVector operator * (Float fLeft, CVector const &refRight);
 
// operator /
extern CVector operator / (CVector const &refLeft, CVector const &refRight);
extern CVector operator / (CVector const &refLeft, Float fRight);
extern CVector operator / (Float fLeft, CVector const &refRight);