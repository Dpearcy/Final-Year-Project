#ifndef DPR_RAY_TRACER_H_INCLUDED // Header guard - prevents file being included more than once (would cause errors)
#define DPR_RAY_TRACER_H_INCLUDED
 
#include "Device .h"
#include "Vector3.h"
#include "CModelTrangle.h"
#include "CModelSphere.h"
#include "Lights.h"
#define MAX_RAY_DEPTH 5 
struct SRay_Start
{
	CVector3* Origin; //// This is the Origin Ponit the Ray Line.
	CVector3* Direction; //// This the direction of the ray facses.
	SRay_Start(const CVector3& O, const CVector3& D) { Origin = new CVector3(O); Direction = new CVector3(D); } //// The consturtor for the ray.
	~SRay_Start() { delete(Origin);	delete(Direction); } //// The desconsturtor. 

};
class CRay_IN
{
private:
	//ID3D11DeviceContext* Device;
	int m_Count = 0;
	//ID3D11ComputeShader* Ray_IN = NULL;
	CModelTrangle* current_Trangle;
	int number_of_Trangles;
	/// function pointers
	//bool(CModelTrangle::*trangle_PTR) (const CVector3& Rayorgin, const CVector3& RayDir, float& T0, float& T1, CVector3& ReturningColor) = &CModelTrangle::intersection ;
	float mix(const float &a, const float &b, const float &mix)
	{
		return b * mix + a * (1 - mix);
	}
	CVector3* FinalColor;
	CVector3 SufaceColor;/// This is the ground color and the  background.
	CVector3 out;
	CVector3 Normalatinters;
	float Tnear;
	float bias = 1e-4;
	CVector3 REFLECTION;
	CVector3 REFRECTION;
	float facingratio;
	float fresneleffect;
	float ior;
	float eta;
	float cosi;
	float k;
	CVector3 refrdir;
	CVector3 TrensparencyColor;
	CVector3 colour;
	CVector3 transmission;
	//CVector3 LightDirection;
public:
	CRay_IN(ID3D11DeviceContext* d, CModelTrangle* trangle, int number);
	CRay_IN();
	~CRay_IN();
	void CreateComputeShader();
	//// the Function that runs the tracing system to the work out the vactor 3 color
	CVector3 RunTrace(CVector3 &rayOrigin, const CVector3 &rayDirection, std::vector<CModelSphere> &ModelsSpheres,
		std::vector<CModelTrangle> &Triangles, const int& Depth);/// SRay_Start* STart, CRay* MathsStuff,  const int& Depth, CVector3*Color)
};


#endif ////DPR_RAY_TRACER.h header file 
