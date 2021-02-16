#ifndef CMODEL_H_INCLUDED // Header guard - prevents file being included more than once (would cause errors)
#define CMODEL_H_INCLUDED
#include "Vector3.h"

class CModel //// The base class for polymohism ( only becuase why not and to prove to me I can do it)
{
private:
	CVector3* ModelCenter;
	CVector3* SurfaceColor;
	float raduis2;
	bool Transparency;
public:
	virtual bool ReturnTransparency();
	virtual void SetTransparencyFactor(float  factor);
	virtual void SetReftectionFactor(float factor);
	virtual float ReturnTransparencyFactor();
	virtual float ReturnReftectionFactor();
	virtual bool intersection(const CVector3 &orgin, const CVector3 &dir, float& t0, float& t1);
	virtual CVector3* MOdelCoords() const; 
	virtual CVector3 MOdelSUrFaceColor();
	virtual float raduisSqured();
	virtual CVector3 Emissioncolor();
};
#endif //// CModel.h