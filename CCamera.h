#ifndef CAMERA_H_INCLUDED // Header guard - prevents file being included more than once (would cause errors)
#define CAMERA_H_INCLUDED
#include "Vector3.h"
#define M_PI 3.141592653589793 
class CCamera
{
private:
	CVector3 Ogrin;
	CVector3 direction;
	float Fov;
	float G__ViewportWidth;
	float G_ViewportHeight;
	float invWidth;
	float invHeight;
	float  aspectratio;
	float Angle;
	float Scale;
public:
	CCamera(float hight, float width, float fov);
	CVector3 GETORgin() { return Ogrin; }
	CVector3 GETDIrection() { return direction; }
	void SEtOrgin(CVector3* Value) { Ogrin = *Value; }
	void SEtDirection(CVector3* Value) { direction = *Value; }
	float Getfov() { return Fov; }
	float GEtViewportWidth(){ return G__ViewportWidth; }
	float GEtviewportHeight() { return G_ViewportHeight; }
	float GETinvWidth() { return invWidth; }
	float GETinvHeight() { return invHeight; }
	float GETaspectratio() { return aspectratio; }
	float GETangle() { return Angle; }
	float GETscale() { return Scale; }
};



#endif //// Camera.h
