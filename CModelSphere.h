#ifndef CMODELSPHERE_H_INCLUDED // Header guard - prevents file being included more than once (would cause errors)
#define CMODELSPHERE_H_INCLUDED
#include "CModel.h"
class CModelSphere /*This is for the spheres as raytracing is far easier with spheres.
I may remove the whole class as everybody uses spheres in ray tracing. and i want my version to be unique. */ : public CModel
{
private:
	CVector3* ModelCenter; //// The spheres center  in the world.
	CVector3* SurfaceColor;//// The color of  suface  of the sphere  
	CVector3* emissionColor; //// The color inside the sphere. 
	float raduis; //// The raduis of sphere.
	float raduis2; //// The raduis of sphere  squred.
	float transparencyFactor;//// How  transperent the sphere is.
	float RftectionFactor;//// How refective the sphere is.
	bool Transparency;//// Is the sphere even transperent at all. 
	bool Reflection;//// Is the sphere even refective at all.
	CVector3 l;
public:

	CModelSphere(CVector3* Croods, CVector3* ColoUr, float r, CVector3* emissioncol, bool seethough = false, bool shiny = false);//// The constor
	void SetTransparencyFactor(float  factor);//// this sets the transparency  value.
	void SetReftectionFactor(float factor);//// This sets the rafection value. 
	bool ReturnTransparency(); //// this returns the wherether the sphere is transparent or not.  
	float ReturnTransparencyFactor();//// this returns the  transparency  value.
	float ReturnReftectionFactor();//// This returns the rafection value.
	bool intersection(const CVector3 &orgin, const CVector3 &dir, float& t0, float& t1);//// finds out if the ray is in the sphere.
	CVector3* MOdelCoords() const { return ModelCenter; } //// returns the model center.
	CVector3 MOdelSUrFaceColor() { return *SurfaceColor; }//// returns te  color of the sphere suface.
	float raduisSqured() { return raduis2; } //// returns the raduis squied. 
	CVector3 Emissioncolor() { return *emissionColor; }//// returns the emission color.
};
#endif ////CMODELSPHERE.H
