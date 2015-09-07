#include "Local.h"

Local* gLocal = new Local();

DWORD Local::gPlayerBase()
{
	return gMemory->Read<DWORD>(gOffsets->gClientDLL() + gOffsets->gLocalPlayer());
}

DWORD Local::gAnglePointer()
{
	return gMemory->Read<DWORD>(gOffsets->gEngineDLL() + gOffsets->gEnginePtr());
}

int Local::gTeam()
{
	return gMemory->Read<int>(gPlayerBase() + gOffsets->gTeamNum());
}

int Local::gCrosshairID()
{
	return gMemory->Read<int>(gPlayerBase() + gOffsets->gCrosshairIndex()) - 1;
}

bool Local::gIsDead()
{
	return gMemory->Read<bool>(gPlayerBase() + gOffsets->gLifeState());
}

int Local::gfFlags()
{
	return gMemory->Read<int>(gPlayerBase() + gOffsets->gFlags());
}

int Local::gShotsFired()
{
	return gMemory->Read<int>(gPlayerBase() + gOffsets->gShotsFired());
}

void Local::gVelocity(float* Buffer)
{
	Buffer[0] = gMemory->Read<float>(gPlayerBase() + gOffsets->gVecVelocity());
	Buffer[1] = gMemory->Read<float>(gPlayerBase() + gOffsets->gVecVelocity() + sizeof(float));
	Buffer[2] = gMemory->Read<float>(gPlayerBase() + gOffsets->gVecVelocity() + 2 * sizeof(float));
}

void Local::gAngles(float* Angles)
{

	Angles[0] = gMemory->Read<float>(gAnglePointer() + gOffsets->gViewAngles() );
	Angles[1] = gMemory->Read<float>(gAnglePointer() + gOffsets->gViewAngles() + sizeof(float));
	//Angles[2] = gMemory->Read<float>(gAnglePointer() + gOffsets->gViewAngles() + 2* sizeof(float));

}

void Local::sAngles(float* Angles)
{
	gMemory->Write<float>(gAnglePointer() + gOffsets->gViewAngles(),Angles[0]);
	gMemory->Write<float>(gAnglePointer() + gOffsets->gViewAngles() + sizeof(float), Angles[1]);
	//gMemory->Write<float>(gAnglePointer() + gOffsets->gViewAngles() + 2 * sizeof(float), Angles[2]);
	
}

float Local::gViewOrigin()
{
	float tempVec = gMemory->Read<float>(gAnglePointer() + gOffsets->gVecViewOrigin() + sizeof(float));
	return tempVec;
}

void Local::gPosition(float* Buffer)
{
	Buffer[0] = gMemory->Read<float>(gPlayerBase() + gOffsets->gVecOrigin() + 0 * sizeof(float));
	Buffer[1] = gMemory->Read<float>(gPlayerBase() + gOffsets->gVecOrigin() + 1 * sizeof(float));
	Buffer[2] = gMemory->Read<float>(gPlayerBase() + gOffsets->gVecOrigin() + 2 * sizeof(float)) + 64;
}

void Local::WPMShoot()
{
	gMemory->Write<int>(gOffsets->gClientDLL() + gOffsets->gAttack(), 1);
	Sleep(20);
	gMemory->Write<int>(gOffsets->gClientDLL() + gOffsets->gAttack(), 0);
	Sleep(10);
}

void Local::MouseShoot()
{
	mouse_event(MOUSEEVENTF_LEFTDOWN, NULL, NULL, NULL, NULL);
	Sleep(20);
	mouse_event(MOUSEEVENTF_LEFTUP, NULL, NULL, NULL, NULL);
	Sleep(10);
}

bool Local::gIsScoped()
{
	return gMemory->Read<bool>(gPlayerBase() + gOffsets->gbIsScoped());
}

int Local::gWepID()
{
		DWORD ActiveWeapon = gMemory->Read<DWORD>(gPlayerBase() + gOffsets->ghActiveWeapon());
		DWORD entNum = ActiveWeapon & 0xFFF;
		DWORD WeaponID = gMemory->Read<DWORD>(gOffsets->gClientDLL() + gOffsets->gEntityList() + (entNum - 1) * gOffsets->gDwEntitySize());
		int myWeaponID = gMemory->Read<int>(WeaponID + gOffsets->gdwActiveWeaponID());
		return myWeaponID;
}