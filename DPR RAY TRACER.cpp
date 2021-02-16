#include "stdafx.h"
#include "DPR RAY TRACER.h"

CRay_IN::CRay_IN(ID3D11DeviceContext* d, CModelTrangle* trangle, int number)
{
	//Device = d;
	current_Trangle = trangle;
	number_of_Trangles = number;
}
CRay_IN::CRay_IN()
{
	//Device = NULL;
	current_Trangle = NULL;
	number_of_Trangles = NULL;
}
CRay_IN::~CRay_IN()
{
	//if (Device) Device->Release();
	//if (Ray_IN) Ray_IN->Release();
	if (current_Trangle) delete(current_Trangle);
}
 void CRay_IN::CreateComputeShader()
{
	// ID3D11Device * tmp;
	// tmp->CreateComputeShader(Ray_IN->)
	 //if (tmp) tmp->Release();
 }
 CVector3 CRay_IN::RunTrace(CVector3 &rayOrigin, const CVector3 &rayDirection,  std::vector<CModelSphere> &ModelsSpheres, std::vector<CModelTrangle> &Triangles, const int& Depth)/// SRay_Start* STart, CRay* MathsStuff,  const int& Depth, CVector3*Color)
 {
	 //// The ray is worked out here. 
	 FinalColor = new CVector3(0);
	 SufaceColor = 0.0f;/// This is the ground color and the  background.
	CModel* model = NULL;
	 out = 0.0f;
	 Tnear = INFINITY;
	 for (int i = 0;i < ModelsSpheres.size(); i++)
	 {
		 float T0 = INFINITY, T1 = INFINITY;
			 if (ModelsSpheres[i].intersection(rayOrigin, rayDirection, T0,T1))
			 {
				 if (T0 < 0) T0 = T1;
				 if (T0 < Tnear)
				 {
					 Tnear = T0;
					 model = &ModelsSpheres[i];
				 }
			 }
	 }
	 //float T, U, V;
	// if (Triangles[0].intersection(rayOrigin, rayDirection, T, V, U))
	//{
		 //if (T0 < 0) T0 = T1;
	//	 SufaceColor = (0, 0, 0);//U, V, 1 - U - V);

	//	 model = &Triangles[0];


	// }
	 if (!model) 
	 {
		 return SufaceColor = (0.0f, 0.0f, 0.0f);
	 };//// if no model  was hit by the ray then  return  with black color. 
	 CVector3 Pointofinter = rayOrigin + rayDirection * Tnear;
	 CVector3 Normalatinters = Pointofinter - model->MOdelCoords();
	 Normalatinters.NormaliZe();//// This normailzes the point at the point of the intersection with the model. 
	//float bias = 1e-4;
	  bool insidetheModel = false;//// This is used to check if the ray is inside the model.
	 if (rayDirection.Dot(Normalatinters) > 0) Normalatinters = -Normalatinters, insidetheModel = true;
	 if ((model->ReturnTransparencyFactor() > 0 || model->ReturnReftectionFactor() > 0) && Depth < MAX_RAY_DEPTH)
	 {
			 SRay_Start* REFlection = new SRay_Start(CVector3(Pointofinter+Normalatinters * bias),rayDirection- Normalatinters * 2 * rayDirection.Dot(Normalatinters));
			 REFlection->Direction->NormaliZe();
			 REFLECTION = RunTrace(*REFlection->Origin, *REFlection->Direction, ModelsSpheres,Triangles,Depth + 1);
			 REFRECTION = 0.0f;
			 if (model->ReturnTransparency())
			 {
				 /// testing
				 facingratio = -rayDirection.Dot(Normalatinters);
				 // change the mix value to tweak the effect
				 fresneleffect = mix(pow(1 - facingratio, 3), 1, 0.1);
				 ior = 1.1;
				 eta = (insidetheModel) ? ior : 1 / ior; // are we inside or outside the surface?
				 cosi = -Normalatinters.Dot(rayDirection);
				  k = 1 - eta * eta * (1 - cosi * cosi);
				 refrdir = rayDirection * eta + Normalatinters * (eta *  cosi - sqrt(k));
				 refrdir.NormaliZe();
				 SRay_Start* REFlectionTRANsparacny = new SRay_Start(CVector3(Pointofinter - Normalatinters * bias), refrdir);
				 REFlectionTRANsparacny->Direction->NormaliZe();
				 REFLECTION =  RunTrace(*REFlectionTRANsparacny->Origin,*REFlectionTRANsparacny->Direction, ModelsSpheres,Triangles,Depth + 1);
				 TrensparencyColor = model->ReturnTransparencyFactor();
				 // the result is a mix of reflection and refraction (if the sphere is transparent)
				 SufaceColor = (REFLECTION * fresneleffect + REFRECTION * (1 - fresneleffect) ^ TrensparencyColor) ^ model->MOdelSUrFaceColor();
				 delete(REFlectionTRANsparacny);
				 //delete(&refrdir);
				 //delete(&TrensparencyColor);
			 }
			 delete(REFlection);
		 }
		  else
		  {
			  for (int i = 0; i < ModelsSpheres.size(); i++)
			  {
				  colour = ModelsSpheres[i].Emissioncolor();
				  if (colour.GetX() > 0)
				  {
					  transmission = CVector3(1.0f);
					 CVector3 LightDirection = *ModelsSpheres[i].MOdelCoords() - Pointofinter;
					 LightDirection.NormaliZe();
					 for (int J = 0; J < ModelsSpheres.size(); J++)
					 {
						 if (i != J)
						 {

							 float T0, T1;
							 if (ModelsSpheres[J].intersection(Pointofinter + Normalatinters, LightDirection,T0, T1))
							 {
								 transmission = 0.0f;
								 break;
							 }
						 }
					 }
					 SufaceColor += model->MOdelSUrFaceColor()^ transmission /**std::Max_Value(float(0), Normalatinters.DotD(&Normalatinters, LightDirection))*/^ ModelsSpheres[i].Emissioncolor();

				  }
			  }
		  }
	 return SufaceColor +model->Emissioncolor(); 
 }