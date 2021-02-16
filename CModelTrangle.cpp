#include "stdafx.h"
#include "CModelTrangle.h"
const float  kEpsilon = 1e-8;
CMash::CMash(CVector3 &p1, CVector3 &p2, CVector3 &p3, CVector3 &Color)
{
	Point1 = &p1;
	Point2 = &p2;
	Point3 = &p3;
	TRangleSufaceColor = &Color;
}
CModelTrangle::CModelTrangle(CVector3 &p1, CVector3 &p2, CVector3 &p3, CVector3 &Color, float number)
{
	PM_Mash.push_back(CMash(p1, p2,  p3, Color));
	NumberOfTrangles = number;//// This tells you how many trangles are in the .X file (placeholder).
}
CVector3 Cross(CVector3* P, CVector3* P2)
{
	return(P->GetY()* P2->GetZ() - P2->GetY() *  P->GetZ(), P->GetZ()* P2->GetX() - P2->GetZ() *  P->GetX(), P->GetX()* P2->GetY() - P2->GetX() *  P->GetY());
}
bool CMash::intersection(const CVector3 &orgin, const CVector3 &dir, float&t, float& v, float& u)
{
	//// work in process./FastMinimum Storage RayTriangle	Intersection
	////    Tomas Moller									Ben Trumbore
	////	Prosolvia Clarus AB								Program of Computer Graphics
	////	Chalmers University of Technology				Cornell University
	////	Email tompaclarusse								Email wbtgraphicscornell
	////	A ray R(t) with origin O and normalized direction D is dened as
	////	R(t) = o + tD.
	////	A point T (u,v) on a triangle is given by 
	////	T(U,v) = (1 - u-v) V0 + uV1 + uV2
	////	intersection for triangle  =
	////	O + tD = (1 - u-v) V0 + uV1 + uV2
	////	[-D, V1 - V), V2- V0 ] [t u v] = O - v0.
	CVector3 raydir = dir;
	CVector3 RayOrgin = orgin;
	CVector3 vertex0 = *Point1;//inTriangle->vertex0;
	CVector3 vertex1 = *Point2;///inTriangle->vertex1;
	CVector3 vertex2 = *Point3;// inTriangle->vertex2;
	CVector3 edge1, edge2, edge3, C, vP0, vP1, vP2;
	float per, Point_of_Hit;
	edge1 = vertex1 - vertex0;
	edge2 = vertex2 - vertex0;
	edge3 = vertex1 - vertex2;
	//// getting the normals forthe points in the trangle 
	//RayOrgin + Normal.Z;
	//(1.0f - U - V) *vertex0 + U.X + u.y;
	//[(-raydir, vertex1 - V), vertex2 - vertex0] [Normal * U * V] = 0 - vertex0;
	//Normal_Vertex1.NormaliZe();
	//// negtivefly(not a world) one of the normals.
	//Normal_Vertex1.Negtivefly();
	//// work out if the ray is pariall with the  normal if yes  continune, no  return false.
	// gets the normal from the trangle.


	// no need to normalize
	CVector3 N = edge1.CrossN(edge1, edge2); // N 
	float denom = N.Dot(N);

	// Step 1: finding P

	// check if ray and plane are parallel ?
	float NdotRayDirection = N.Dot(raydir);
	if (fabs(NdotRayDirection) < kEpsilon) // almost 0 
		return false; // they are parallel so they don't intersect 
					  
	// wort out d parameter using equation 2
	float d = N.Dot(vertex0);

	// work out t (equation 3)
	t = (N.Dot(RayOrgin) + d) / NdotRayDirection;
	// check if the triangle is in behind the ray
	if (t < 0) return false; // the triangle is behind 

	// work out the intersection point using equation 1
	CVector3 P = RayOrgin + t * raydir;

	// Step 2: inside-outside test
	//Vec3f C; // vector perpendicular to triangle's plane 

			 // edge 0
	//Vec3f edge0 = v1 - v0;
	vP0 = P - vertex0;
	C = edge1.CrossN(edge1, vP0);
	if (N.Dot(C) < 0) return false; // P is on the right side 

										   // edge 1

	vP1 = P - vertex1;
	C = edge2.CrossN(edge2, vP1);
	if ((u = N.Dot(C)) < 0)  return false; // P is on the right side 

												  // edge 2
	vP2 = P - vertex2;
	C = edge3.CrossN(edge3, vP2);
	if ((v = N.Dot(C)) < 0) return false; // P is on the right side; 

	u /= denom;
	v /= denom;
	return true;
}
bool CModelTrangle::intersection(const CVector3 &orgin, const CVector3 &dir, float&t, float& v, float& u)
{
	//// work in process./FastMinimum Storage RayTriangle	Intersection
	////    Tomas Moller									Ben Trumbore
	////	Prosolvia Clarus AB								Program of Computer Graphics
	////	Chalmers University of Technology				Cornell University
	////	Email tompaclarusse								Email wbtgraphicscornell
	////	A ray R(t) with origin O and normalized direction D is dened as
	////	R(t) = o + tD.
	////	A point T (u,v) on a triangle is given by 
	////	T(U,v) = (1 - u-v) V0 + uV1 + uV2
	////	intersection for triangle  =
	////	O + tD = (1 - u-v) V0 + uV1 + uV2
	////	[-D, V1 - V), V2- V0 ] [t u v] = O - v0.
	U = *PM_Mash[0].Point2 - *PM_Mash[0].Point1;
	V = *PM_Mash[0].Point3 - *PM_Mash[0].Point1;
	x = U.GetY()* V.GetZ() - U.GetZ() * V.GetY();
	y = U.GetZ() * V.GetX() - U.GetX() * U.GetZ();
	z = U.GetX() * V.GetY() - U.GetY() * V.GetX();
	 Normal = (x, y, z);
	//PM_Mash[0].intersection(orgin, dir, t, v, u);
	CVector3 raydir = dir;
	CVector3 RayOrgin = orgin;
	///const float EPSILON = 0.0000001;
//	const float ONE = 0.1;
	CVector3 vertex0 = *PM_Mash[0].Point1;//inTriangle->vertex0;
	CVector3 vertex1 = *PM_Mash[0].Point2;///inTriangle->vertex1;
	CVector3 vertex2 = *PM_Mash[0].Point3;// inTriangle->vertex2;
	CVector3 edge1, edge2, edge3, C, vP0, vP1, vP2;
	float per, Point_of_Hit;
	edge1 = vertex1 - vertex0;
	edge2 = vertex2 - vertex0;
	edge3 = vertex1 - vertex2;
	//// getting the normals forthe points in the trangle 
	//RayOrgin + Normal.Z;
	//(1.0f - U - V) *vertex0 + U.X + u.y;
	//[(-raydir, vertex1 - V), vertex2 - vertex0] [Normal * U * V] = 0 - vertex0;

	//Normal_Vertex1.NormaliZe();
	//// negtivefly(not a world) one of the normals.
	//Normal_Vertex1.Negtivefly();
	//// work out if the ray is pariall with the  normal if yes  continune, no  return false.
	// gets the normal from the trangle.


	// no need to normalize
	CVector3 N = edge1.CrossN(edge1,edge2); // N 
	float denom = N.Dot(N);

	// Step 1: finding P

	// check if ray and plane are parallel ?
	float NdotRayDirection = N.Dot(raydir);
	if (fabs(NdotRayDirection) < kEpsilon) // almost 0 
		return false; // they are parallel so they don't intersect ! 

					  // compute d parameter using equation 2
	float d = N.Dot(vertex0);

	// compute t (equation 3)
	t = (N.Dot(RayOrgin) + d) / NdotRayDirection;
	// check if the triangle is in behind the ray
	if (t < 0) return false; // the triangle is behind 

							 // compute the intersection point using equation 1
	CVector3 P = RayOrgin + t * raydir;

	// Step 2: inside-outside test
	//Vec3f C; // vector perpendicular to triangle's plane 

			 // edge 0
	//Vec3f edge0 = v1 - v0;
	 vP0 = P - vertex0;
	C = edge1.CrossN(edge1, vP0);
	if (N.Dot(C) < 0) return false; // P is on the right side 

										   // edge 1
	
	vP1 = P - vertex1;
	C = edge2.CrossN(edge2, vP1);
	if ((u = N.Dot(C)) < 0)  return false; // P is on the right side 

												  // edge 2
	 vP2 = P - vertex2;
	C = edge3.CrossN(edge3,vP2);
	if ((v = N.Dot(C)) < 0) return false; // P is on the right side; 

	u /= denom;
	v /= denom;
	return true;
}

	
	 // this ray hits the triangle 

	//haftway = edge2.CrossN(raydir,edge2);
	//a = edge1.Dot(h);


	
