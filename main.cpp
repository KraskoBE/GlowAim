#include "Entity.h"
#include "Local.h"
#include "Memory.h"
#include "Offsets.h"
#include "Variables.h"
#include "Vector3.h"

#include <iostream>
#include <thread>
#include <math.h>

#define RADPI  57.2957795f;

int index = -1;

using namespace std;

void ReadData();
void Aim();
void Glow();
void ConsoleInfo();

float GetDistance(float *from, float* to);
float Distance2D(float* x, float* y);
void CalcAngle(float *src, float *dst, float *angles, float dist);
void GetFov(float *pAimAngles, float *pLocalAngles, float *pFov);
void DrawGlow(int PlayerNumber, GlowRGBA color);
void ClampAngle(float* angle);
float AngleDistance(float next, float cur);


int main()
{
	Team.g = 1.0f;
	Enemy.r = 0.5019607843137255f;
	Enemy.b = 0.5019607843137255f;

	SetConsoleTitle("Aim & Glow by Block4o");
	cout << "Waiting for CS:GO\n";
	while (!gMemory->Process("csgo.exe"))
	{
		Sleep(500);
	}
	
	DWORD tClientDLL = gMemory->Module("client.dll", tClientDLL);
	DWORD tEngineDLL = gMemory->Module("engine.dll", tEngineDLL);

	gOffsets->sClientDLL(tClientDLL);
	gOffsets->sEngineDLL(tEngineDLL);


	cout << "CS:GO Found\n\n";
	cout << "Glow: " << bGlow << " (F6)\n";
	cout << "Aim: " << bAim << " (F7)\n";
	cout << "Aimbone: " << iAimBone << " (F8) 3=Chest | 10=Head\n";

	thread first(ReadData);
	thread second(Aim);
	thread third(Glow);

	first.join();
	second.join();
	third.join();

	return 0;
}

void ReadData()
{
	while (true)
	{
		/*DWORD tClientDLL = gMemory->Module("client.dll", tClientDLL);
		DWORD tEngineDLL = gMemory->Module("engine.dll", tEngineDLL);

		gOffsets->sClientDLL(tClientDLL);
		gOffsets->sEngineDLL(tEngineDLL);*/

		int gameState = gMemory->Read<int>(gLocal->gAnglePointer() + 0xE8);

		if (GetAsyncKeyState(VK_F6))
		{
			bGlow = !bGlow;
			ConsoleInfo();
			Sleep(300);
		}

		if (GetAsyncKeyState(VK_F7))
		{
			bAim = !bAim;
			ConsoleInfo();
			Sleep(300);
		}

		if (GetAsyncKeyState(VK_F8))
		{
			if (iAimBone == 3) iAimBone = 10;
			else if (iAimBone == 10) iAimBone = 3;
			Sleep(300);
			ConsoleInfo();
		}

		
		Sleep(100);
	}
}

void ConsoleInfo()
{
	system("cls");
	cout << "Waiting for CS:GO\n";
	cout << "CS:GO Found\n\n";
	cout << "Glow: " << bGlow << " (F6)\n";
	cout << "Aim: " << bAim << " (F7)\n"; 
	cout << "Aimbone: " << iAimBone << " (F8) 3=Chest | 10=Head\n";
}

void Glow()
{
	while (true)
	{
		int gameState = gMemory->Read<int>(gLocal->gAnglePointer() + 0xE8);
		if (bGlow && gameState == 6)
		{
			for(int i = 0; i < 63; i++)
			{
				if (!gEntity->gIsDead(i) && !gEntity->gIsDormant(i))
				{
					if (gEntity->gTeam(i) == gLocal->gTeam() && bGlowTeam)
					{
						DrawGlow(i, Team);
					}

					if (gEntity->gTeam(i) != gLocal->gTeam() && bGlowEnemy)
					{
						DrawGlow(i, Enemy);
					}
				}
			}
		}

		Sleep(1);
	}
}

void Aim()
{
	while (true)
	{
		float fov1;
		int gameState = gMemory->Read<int>(gLocal->gAnglePointer() + 0xE8);
		while (bAim && gameState == 6 && GetAsyncKeyState(VK_SHIFT))
		{
			fov1 = 5000;
			index = -1;
			for (int i = 1; i < 63; i++)
			{
				if (gEntity->gTeam(i) != gLocal->gTeam() && !gEntity->gIsDead(i) && gEntity->gTeam(i) !=0 && !gEntity->gIsDormant(i))
				{
					float myPos[3];
					gLocal->gPosition(myPos);

					float bonePos[3];
					gEntity->gBonePosition(i, bonePos, iAimBone);

					float distance_my_bone;
					distance_my_bone = GetDistance(myPos, bonePos);

					float calcedAngle[2];
					CalcAngle(myPos, bonePos, calcedAngle, distance_my_bone);
					ClampAngle(calcedAngle);

					float currentAngle[2];
					gLocal->gAngles(currentAngle);

					float fov[2];
					GetFov(calcedAngle, currentAngle, fov);

					if (GetDistance(calcedAngle,currentAngle)<fov1 && fov[1]<=60)
					{
						fov1 = GetDistance(calcedAngle, currentAngle);
						index = i;
					}

				}
			}
			cout << fov1 << endl;
			cout << index << endl;
			Sleep(50);
			int tempEnemy = gLocal->gCrosshairID();

			if (tempEnemy > 0 && tempEnemy < 64 && gEntity->gTeam(tempEnemy) != gLocal->gTeam() && gEntity->gTeam(tempEnemy) != 0 && !gEntity->gIsDead(tempEnemy))
				index = tempEnemy;

			while (GetAsyncKeyState(VK_SHIFT) && index != -1 && !gEntity->gIsDead(index))
			{
				float myPos[3];
				gLocal->gPosition(myPos);

				float bonePos[3];
				gEntity->gBonePosition(index, bonePos, iAimBone);

				float distance_my_bone;
				distance_my_bone = GetDistance(myPos, bonePos);

				float calcedAngle[2];
				CalcAngle(myPos, bonePos, calcedAngle, distance_my_bone);

				ClampAngle(calcedAngle);

				if (
					calcedAngle[0]<89.0f && calcedAngle[0]>-89.0f &&
					calcedAngle[1]<179.0f && calcedAngle[1]>-179.0f
					)
				{
					gLocal->sAngles(calcedAngle);
				}
				Sleep(1);
			}
		}
		Sleep(1);
	}

}


void CalcAngle(float *src, float *dst, float *angles, float dist)
{
	float delta[3] = { (src[0] - dst[0]), (src[1] - dst[1]), (src[2] - dst[2]) };
	float hyp = sqrt(delta[0] * delta[0] + delta[1] * delta[1]);
	dist = sqrt(delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2]);
	angles[0] = (float)(asinf(delta[2] / hyp) * 57.2957795f);
	angles[1] = (float)(atanf(delta[1] / delta[0]) * 57.2957795f);
	angles[2] = 0.0f;
	if (angles[0] > 180) angles[0] -= 360;
	if (angles[1] > 180) angles[1] -= 360;
	if (angles[0] < -180) angles[0] += 360;
	if (angles[1] < -180) angles[1] += 360;
	if (delta[0] >= 0.0) { angles[1] += 180.0f; }
}

void GetFov(float *pAimAngles, float *pLocalAngles, float *pFov)
{
	pFov[0] = (pAimAngles[0] - pLocalAngles[0]);
	pFov[1] = (pAimAngles[1] - pLocalAngles[1]);
	pFov[2] = (pAimAngles[2] - pLocalAngles[2]);
	if (pFov[0]>180) pFov[0] -= 360;
	if (pFov[1]>180) pFov[1] -= 360;
	if (pFov[0]<-180) pFov[0] += 360;
	if (pFov[1]<-180) pFov[1] += 360;
	if (pFov[0]<0) pFov[0] *= (-1);
	if (pFov[1]<0) pFov[1] *= (-1);
}

void DrawGlow(int PlayerNumber, GlowRGBA color)
{
	gMemory->Write<GlowRGBA>(gEntity->gGlowPointer() + ((gEntity->gGlowIndex(PlayerNumber) * 0x34) + 0x4), color);
	gMemory->Write<bool>(gEntity->gGlowPointer() + ((gEntity->gGlowIndex(PlayerNumber) * 0x34) + 0x24), 1);
	gMemory->Write<bool>(gEntity->gGlowPointer() + ((gEntity->gGlowIndex(PlayerNumber) * 0x34) + 0x25), 0);
}

float Distance2D(float* x, float* y)
{

	//atan2(sin(x-y), cos(x-y))
	//float distance = sqrtf((x[1] - x[0])*(x[1] - x[0]) + (y[1] - y[0])*(y[1] - y[0]));
	float distance = atan2(x[1] - y[1], cos(x[1] - y[1]));
	return distance;
}

void ClampAngle(float* qaAng)
{
	{
		if (qaAng[1] > 179.0f)
			qaAng[1] -= 359.0f;

		if (qaAng[1] < -359.0f)
			qaAng[1] += 359.0f;

		if (qaAng[0] > 89.0f)
			qaAng[0] = 89.0f;

		if (qaAng[0] < -89.0f)
			qaAng[0] = -89.0f;
	}
}

float AngleDistance(float next, float cur)
{
	float delta = next - cur;

	if (delta < -180)
		delta += 360;
	else if (delta > 180)
		delta -= 360;

	return delta;
}
float GetDistance(float* from, float* to)
{
	float angle[3];
	angle[0] = to[0] - from[0]; angle[1] = to[1] - from[1]; angle[2] = to[2] -
		from[2];
	return sqrt(angle[0] * angle[0] + angle[1] * angle[1] + angle[2] * angle[2]);
}