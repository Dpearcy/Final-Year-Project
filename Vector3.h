#ifndef VECTOR_H_INCLUDED // Header guard - prevents file being included more than once (would cause errors)
#define VECTOR_H_INCLUDED
#include <cmath> //// needed for the some of the maths calutions.
#include <fstream> 
#include <vector> //// used to store the  spheres in the world so the more can be added if needed.
#include <iostream> 
using std::cout;
using std::endl;
using std::vector;
class CVector3 //// The class that stores the X Y Z postions in the world space.
{
private:
	/////
public:
	float X, Y, Z;
//	~CVector3() { X = NULL, Y = NULL, Z = NULL; }
	void setX(float tmp) { X = tmp; }//// This is used for seting the X in the ray cast loop.
	void setY(float tmp) { Y = tmp; }//// This is used for seting the Y in the ray cast loop.
	void setZ(float tmp) { Z = tmp; }//// This is used for seting the Z in the ray cast loop.
	float GetX(); //// This  used to get X postions  as the value  in X  should be private as this  improves secuity in the class. 
	float GetY();//// This  used to get Y postions  as the value  in Y  should be private as this  improves secuity in the class. 
	float GetZ();//// This  used to get Z postions  as the value  in Z  should be private as this  improves secuity in the class.
	CVector3() : X(float(0)), Y(float(0)), Z(float(0)) {}//// This used for the times when the vector 3 is made and has no value. 
	CVector3(float xx) : X(xx), Y(xx), Z(xx) {}//// This used for the times  when the vector 3 is made  and only has one value.
	CVector3(float xx, float yy, float zz) : X(xx), Y(yy), Z(zz) {}//// This is most  used of making the vector 3 class.
	CVector3 operator - (CVector3* T) { return CVector3(X - T->X, Y - T->Y, Z - T->Z); }//// This is used to take away one vector 3 from anthor vector 3. 
	 CVector3 operator * (float T) const{ return CVector3(X * T, Y * T, Z * T); }//// This is used to times two vector 3  together. 
	CVector3 operator ^ (CVector3 T)  {return CVector3( X * T.X, Y * T.Y, Z * T.Z); }//// this the times as the  * operator is already used.
	CVector3 operator = (float T) { this->X = T, this->Y = T, this->Z = T; return *this; }//// This  asigns  a single value to a  vector 3.
	CVector3 operator + (float T) { return CVector3( this->X + T, this->Y + T, this->Z + T); }//// This  adds the single value by a vector 3.
	CVector3 operator + (CVector3 &V) {return CVector3 (this->X + V.X, this->Y + V.Y, this->Z + V.Z); }//// This adds two vector 3 together.
	CVector3 operator + (CVector3 &V) const { return CVector3(this->X + V.X, this->Y + V.Y, this->Z + V.Z); }//// This adds two vector 3 together.
	CVector3 Normalise(const CVector3& v);///// This normalizes(sets the  length to 1)  the given vector.
	 float Dot(const CVector3& v1)const { return X * v1.X + Y * v1.Y + Z * v1.Z; }//// does the dot product(gets the direction from two points)  with the base vector and one given vector 3.
	float DotD(const CVector3* v1, const CVector3& v2);//// does the dot product(gets the direction from two points)  from two given vector 3.
	 CVector3 Cross(const CVector3& v1, const CVector3& v2);//// not used yet.
	 CVector3 CrossN( CVector3& v1, CVector3& v2);//// not used yet.
	CVector3 NormaliZe();//// This normalizes (sets the length to 1) the base vector.
	CVector3 Negtivefly(); //// David's version of inverse  function. 
	friend CVector3 operator * (float& F, CVector3&V) { return CVector3(V.X * F, V.Y * F, V.Z * F); }
    COLORREF operator =  (CVector3* V )/*()*/ { return RGB(V->X, V->Y, V->Z); }
	CVector3 operator =  (COLORREF)/*()*/ { return RGB(this->X, this->Y, this->Z); }
	//// Testing for maths and displaying 
	float length2() { return X * X + Y * Y + Z * Z; } ////Gets the length ofthe vector and  squries it used for normialztion.
	friend std::ostream & operator << (std::ostream &os, const CVector3 &V)//// used to display the world(the ray  traced world). 
	{
		os << "[" << V.X << " " << V.Y << " " << V.Z << "]";
		return os;
	}
	///// tmp
	CVector3 operator - (const CVector3 &v) const { return CVector3(X - v.X, Y - v.Y, Z - v.Z); }//// This takes one vector 3 from an another
	//CVector3 operator + (const CVector3 &v) const { return CVector3(X + v.X, Y + v.Y, Z + v.Z); }
	//CVector3 operator + (const float &T) const { this->X + T, this->Y + T, this->Z + T; return *this; }
	CVector3& operator += (const CVector3 &v) { X += v.X, Y += v.Y, Z += v.Z; return *this; }//// This adds the vector 3 on to the current values of ogranial vector 3. 
	//CVector3& operator *= (const CVector3 &v) { X *= v.X, Y *= v.Y, Z *= v.Z; return *this; }
	CVector3 operator - () const { return CVector3(-X, -Y, -Z); }///// This netgutes the X Y znd Z  valuse used the refeclotion in a object.
	
};
#endif //// VECTOR.H