#include "Offsets.h"

Offsets* gOffsets = new Offsets();

DWORD Offsets::gClientDLL()
{
	return ClientDLL;
}

DWORD Offsets::gEngineDLL()
{
	return EngineDLL;
}

DWORD Offsets::gLocalPlayer()
{
	return LocalPlayer;
}

DWORD Offsets::gEntityList()
{
	return EntityList;
}

DWORD Offsets::gFlashDuration()
{
	return FlashDuration;
}

DWORD Offsets::gRadarBase()
{
	return RadarBase;
}

DWORD Offsets::gEnginePtr()
{
	return EnginePtr;
}

DWORD Offsets::gViewAngles()
{
	return ViewAngles;
}

DWORD Offsets::gCrosshairIndex()
{
	return CrosshairIndex;
}

DWORD Offsets::gGlowObjectBase()
{
	return GlowObjectBase;
}

DWORD Offsets::gAttack()
{
	return Attack;
}

DWORD Offsets::gJump()
{
	return Jump;
}

DWORD Offsets::gViewMatrix1()
{
	return ViewMatrix1;
}

DWORD Offsets::gViewMatrix2()
{
	return ViewMatrix2;
}

DWORD Offsets::gViewMatrix3()
{
	return ViewMatrix3;
}

DWORD Offsets::gHealth()
{
	return Health;
}

DWORD Offsets::gDwEntitySize()
{
	return DwEntitySize;
}

DWORD Offsets::gbDormant()
{
	return bDormant;
}

DWORD Offsets::gbSpotted()
{
	return bSpotted;
}

DWORD Offsets::gTeamNum()
{
	return TeamNum;
}

DWORD Offsets::gShotsFired()
{
	return ShotsFired;
}

DWORD Offsets::gFlags()
{
	return Flags;
}

DWORD Offsets::gGlowIndex()
{
	return GlowIndex;
}

DWORD Offsets::gDwBoneMatrix()
{
	return DwBoneMatrix;
}

DWORD Offsets::gVecViewOrigin()
{
	return VecViewOrigin;
}

DWORD Offsets::gVecOrigin()
{
	return VecOrigin;
}

DWORD Offsets::gLifeState()
{
	return LifeState;
}

DWORD Offsets::gVecPunch()
{
	return VecPunch;
}

DWORD Offsets::gVecVelocity()
{
	return VecVelocity;
}

DWORD Offsets::ghActiveWeapon()
{
	return hActiveWeapon;
}

DWORD Offsets::gdwActiveWeaponID()
{
	return dwActiveWeaponID;
}

DWORD Offsets::gbIsScoped()
{
	return bIsScoped;
}
//--------------------SET FUNCTIONS------------------SET FUNCTIONS-------
void Offsets::sClientDLL(DWORD nClientDLL)
{
	ClientDLL = nClientDLL;
}

void Offsets::sEngineDLL(DWORD nEngineDLL)
{
	EngineDLL = nEngineDLL;
}