#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include "Memory.h"
#include "Offsets.h"
#include "Vector3.h"

class Entity
{
public:
	DWORD gBaseEntity(int);
	DWORD gGlowPointer();
	int gTeam(int);
	int gGlowIndex(int);
	bool gIsDead(int);
	bool gIsDormant(int);
	bool gbSpotted(int);
	void gBonePosition(int, float*, int);


private:
};

extern Entity* gEntity;

#endif