#pragma once

#ifndef LOCAL_H
#define LOCAL_H

#include "Memory.h"
#include "Offsets.h"
#include "Vector3.h"

class Local
{
public:
	DWORD gPlayerBase();
	DWORD gAnglePointer();
	int gTeam();
	int gCrosshairID();
	int gfFlags();
	int gShotsFired();
	int gWepID();
	bool gIsDead();
	bool gIsScoped();
	float gViewOrigin();
	void gVelocity(float* Buffer);
	void gAngles(float* Angles);
	void sAngles(float* Angles);
	void gPosition(float* Buffer);
	void WPMShoot();
	void MouseShoot();

private:
};

extern Local* gLocal;

#endif