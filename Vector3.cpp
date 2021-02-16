#include "stdafx.h"
#include "Vector3.h"
////  most of code got from the week 5  lab materials  code CVector3cut.h file made by Laurent Noel
float CVector3::GetX() { return X; }
float CVector3::GetY() { return Y; }
float CVector3::GetZ() { return Z; }

const float kfEpsilon = 0.5e-6f;    // For 32-bit floats
// Return unit length vector in the same direction as given one
inline bool IsZero(const float x);
inline float InvSqrt(const float x);

CVector3 CVector3::NormaliZe()
{
	
	float nor2 = length2();
	if (nor2 > 0) {
		float invNor = 1 / sqrt(nor2);
		X *= invNor, Y *= invNor, Z *= invNor;
	}
	return *this; 
}
CVector3 CVector3::Negtivefly()
{
	return CVector3(-this->GetX(), -this->GetY(), -this->GetZ());
}
CVector3 CVector3::Normalise(const CVector3& v)
{

	float lengthSq = v.X*v.X + v.Y*v.Y + v.Z*v.Z;
	return CVector3(0.0f, 0.0f, 0.0f);
	 //Ensure vector is not zero length (use BaseMath.h float approx. fn with default epsilon)
	if (IsZero(lengthSq))
	{
		return CVector3(0.0f, 0.0f, 0.0f);
	}
	else
	{
		float invLength = InvSqrt(lengthSq);
		return CVector3(v.X * invLength, v.Y * invLength, v.Z * invLength);
	}
}
// Test if a float value is approximately 0. Epsilon value is the range around zero that
 //is considered equal to zero. Default value requires zero to 6 decimal places
inline bool IsZero(const float x)
{
	return fabsf(x) < kfEpsilon;
}
 //1 / Sqrt
inline float InvSqrt(const float x)
{
	return 1.0f / sqrtf(x);
}
// Dot product of two given vectors (order not important) - non-member version
 /*float CVector3::Dot(const CVector3& v1, const CVector3& v2)
{
	return v1.X*v2.X+ v1.Y*v2.Y + v1.Z*v2.Z;
}*/
 float CVector3::DotD(const CVector3* v1, const CVector3& v2)
 {
	 return v1->X*v2.X + v1->Y*v2.Y + v1->Z*v2.Z;
 }
// Cross product of two given vectors (order is important) - non-member version
inline CVector3 CVector3::Cross(const CVector3& v1, const CVector3& v2)
{
	return CVector3(v1.Y*v2.Z - v1.Z*v2.Y, v1.Z*v2.X - v1.X*v2.Z, v1.X*v2.Y - v1.Y*v2.X);
}
CVector3 CVector3::CrossN( CVector3& v1, CVector3& v2)
{
	return CVector3(v1.Y*v2.Z - v1.Z*v2.Y, v1.Z*v2.X - v1.X*v2.Z, v1.X*v2.Y - v1.Y*v2.X);
}