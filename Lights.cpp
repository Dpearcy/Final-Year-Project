#include "stdafx.h"
#include "Lights.h"

CLIGHTS::CLIGHTS(CVector3* pos, CVector3* Dir, CVector3* Col, bool turnOn, bool Effects)
{
	lightpos = pos;
	LightDirection = Dir;
	LightColor = Col;
	flash = turnOn;
	OtherEffects = Effects;
}
void CLIGHTS::flashValues()
{
	//// furtue idea.
}
void CLIGHTS::OtherEFFectsValues()
{
	//// furture idea.
}