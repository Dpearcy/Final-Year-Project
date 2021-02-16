#ifndef LIGHTS_H_INCLUDED // Header guard - prevents file being included more than once (would cause errors)
#define LIGHTS_H_INCLUDED
#include "Vector3.h"
class CLIGHTS
{
private:
  CVector3* lightpos; //// This tells you where the light is  world space.
  CVector3* LightDirection;//// This tells you where the light is facing in the world space.
  CVector3* LightColor;//// This tells you where the light color that will project into the world.
  bool flash;//// This is if the turn light will turn off and on.
  bool OtherEffects;//// This is if the light has other effects(e.g. going from point to spotlight or adding partils effects to light). 
  ////The flash and other effects are not used as the build dones one ray trace before display,
  //// these effects would appear at runtime and the ray tracer would need to run at realtime(DXR and very fast GPU needed)
public:
	CLIGHTS(CVector3* pos, CVector3* Dir, CVector3* Col, bool turnOn = false, bool Effects = false);/// constor for the class.
	 void flashValues();//// works out the turning on and off.
	 void OtherEFFectsValues();//// gets user entered othereffects and then works how  make it  run in real time (not used).
};
#endif /// Lights.h