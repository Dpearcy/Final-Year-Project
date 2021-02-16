#include "stdafx.h"
#include "CCamera.h"

inline float deg2rad(const float &deg)
{
	return deg * M_PI / 180;
}
CCamera::CCamera(float hight, float width, float fov)
{
	G_ViewportHeight = hight;
	G__ViewportWidth = width;
	aspectratio = G__ViewportWidth / float(G_ViewportHeight);
	Fov = fov;
	Angle = tan(M_PI * 0.5 * Fov / 180.);
	Scale = tan(deg2rad(Fov * 0.5));

}