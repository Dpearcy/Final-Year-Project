#include "stdafx.h"
#include "CModelSphere.h"
bool CModelSphere::ReturnTransparency()
{
	return Transparency;
}
void CModelSphere::SetTransparencyFactor(float factor)
{
	if (Transparency) transparencyFactor = factor;
	else exit(0);
}
void CModelSphere::SetReftectionFactor(float factor)
{
	if (Reflection) RftectionFactor = factor;
	else exit(0);
}
CModelSphere::CModelSphere(CVector3* Croods, CVector3* ColoUr, float r, CVector3* emissioncol, bool seethough, bool shiny)
{
	ModelCenter = Croods;
	SurfaceColor = ColoUr;
	raduis = r;
	raduis2 = raduis * raduis;
	Transparency = seethough;
	Reflection = shiny;
	emissionColor = emissioncol;

}

bool CModelSphere::intersection(const CVector3 &orgin, const CVector3 &dir, float& t0, float& t1)
{
	// float t = InModel(RAY, T);
	l = *ModelCenter - orgin;/// the distence to the orgin of the ray. 
	float tca = l.Dot(dir); //// works out if the oject is in frount of the ray orgin by dot product.
	if (tca < 0) return false; ///// if the output is less then  0 then the ojbect is behind the ray.
	float d2 = l.Dot(l) - tca * tca; //// 
	if (d2 > raduis2) return false;
	float thc = sqrt(raduis2 - d2);
	t0 = tca - thc;
	t1 = tca + thc;

	return true;
}

float CModelSphere::ReturnTransparencyFactor()
{
	return transparencyFactor;
}
float CModelSphere::ReturnReftectionFactor()
{
	return RftectionFactor;
}
