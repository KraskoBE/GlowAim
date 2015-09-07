#pragma once
#include <Windows.h>

using namespace std;

#ifndef OFFSETS_H
#define OFFSETS_H

class Offsets
{
public:

	DWORD gClientDLL();
	DWORD gEngineDLL();

	DWORD gLocalPlayer();
	DWORD gEntityList();
	DWORD gFlashDuration();
	DWORD gRadarBase();
	DWORD gEnginePtr();
	DWORD gViewAngles();
	DWORD gCrosshairIndex();
	DWORD gGlowObjectBase();
	DWORD gAttack();
	DWORD gJump();
	DWORD gViewMatrix1();
	DWORD gViewMatrix2();
	DWORD gViewMatrix3();
	DWORD gHealth();
	DWORD gDwEntitySize();
	DWORD gbDormant();
	DWORD gbSpotted();
	DWORD gTeamNum();
	DWORD gShotsFired();
	DWORD gFlags();
	DWORD gGlowIndex();
	DWORD gDwBoneMatrix();
	DWORD gVecViewOrigin();
	DWORD gVecOrigin();
	DWORD gLifeState();
	DWORD gVecPunch();
	DWORD gVecVelocity();
	DWORD ghActiveWeapon();
	DWORD gdwActiveWeaponID();
	DWORD gbIsScoped();


	void sClientDLL(DWORD);
	void sEngineDLL(DWORD);

private:
	DWORD ClientDLL;
	DWORD EngineDLL;

	const DWORD LocalPlayer = 0xA8013C;
	const DWORD EntityList = 0x4A22534;
	const DWORD RadarBase = 0x4A571DC;
	const DWORD EnginePtr = 0x5D0224;
	const DWORD GlowObjectBase = 0x4B357D4;
	const DWORD Attack = 0x2E94458;
	const DWORD Jump = 0x4AB3528;
	const DWORD ViewMatrix1 = 0xE3060058;
	const DWORD	ViewMatrix2 = 0xE3060168;
	const DWORD	ViewMatrix3 = 0xE3060478;

	//constant
	const DWORD CrosshairIndex = 0x2410;
	const DWORD Health = 0xFC;
	const DWORD DwEntitySize = 0x10;
	const DWORD bDormant = 0xE9;
	const DWORD bSpotted = 0x935;
	const DWORD TeamNum = 0xF0;
	const DWORD ShotsFired = 0x1D60;
	const DWORD Flags = 0x100;
	const DWORD GlowIndex = 0x1DCC;
	const DWORD DwBoneMatrix = 0xA78;
	const DWORD VecViewOrigin = 0x104;
	const DWORD VecOrigin = 0x134;
	const DWORD LifeState = 0x25B;
	const DWORD VecPunch = 0x13E8;
	const DWORD VecVelocity = 0x110;
	const DWORD hActiveWeapon = 0x12C0;
	const DWORD dwActiveWeaponID = 0x1690;
	const DWORD bIsScoped = 0x1C00;
	const DWORD FlashDuration = 0x1DB4;
	const DWORD ViewAngles = 0x4CE0;

};

extern Offsets* gOffsets;

#endif