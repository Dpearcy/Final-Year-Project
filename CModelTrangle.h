#ifndef CMODELTRANGLE_H_INCLUDED // Header guard - prevents file being included more than once (would cause errors)
#define CMODELTRANGLE_H_INCLUDED
#include "CModel.h"
class CMash
{
public:
	CVector3* Point1;//// This is top of the trangle. or //// This tells you where the top of the trangle is  the world space.
	CVector3* Point2;//// This is bottom left of the trangle. or //// This tells you where the bottom left of the trangle is  the world space.
	CVector3* Point3;//// This is bottom right of the trangle. or //// This tells you where the bottom right of the trangle is  the world space.
	CVector3* TRangleSufaceColor;//// This is the color of the trangle. or //// This tells you color the trangle will be(given by the texture file).
	bool intersection(const CVector3 &orgin, const CVector3 &dir, float&t, float& v, float& u);////// Works  out if the ray is in the trangle.
	CMash(CVector3 &p1, CVector3 &p2, CVector3 &p3, CVector3 &Color);
};
class CModelTrangle : public CModel
{
	//// I could use box technique that nivda use in the RTX GPU but on the CPU  that help profroamce.
private:
	std::vector<CMash> PM_Mash;
	CMash* PM_TRangle;
	float NumberOfTrangles;//// This tells you how many trangles are in the .X file (placeholder).
	CVector3 U;
	CVector3 V;
	float x;
	float y;
	float z;
	CVector3 Normal;
public:

	CModelTrangle(CVector3 &p1, CVector3 &p2, CVector3 &p3, CVector3 &Color, float number); //// the constor for class
	CVector3 MOdelSUrFaceColor(int& i) { PM_TRangle = &PM_Mash[i]; return *PM_TRangle->TRangleSufaceColor; } //// returns the color of the trangle color.
	bool intersection(const CVector3 &orgin, const CVector3 &dir, float&t, float& v, float& u); ////// Works  out if the ray is in the trangle.
};
#endif /// CModelTrangle.h
