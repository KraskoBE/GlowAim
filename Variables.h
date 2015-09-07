#pragma once
#ifndef VARIABLES_H
#define VARIABLES_H

#include <Windows.h>

struct GlowRGBA
{
	float r = 0;
	float g = 0;
	float b = 0;
	float a = 0.8f;
}Team,Enemy,bomb;


//Glow
bool bGlow = false;
bool bGlowTeam = true;
bool bGlowEnemy = true;

//Trigger
bool bTrigger = false;
bool bInstant = false;
bool bScopedOnly = false;
bool bSniperMode = false;
bool bWPM = true;
int iDelay = 120;

//RCS
bool bRCS = false;
bool bFullComp = false;
int iPercentage = 70;
float fMultiplier = 1.4f;

//Aim
bool bAim = false;
int iSmooth = 25;
int iAimBone = 10;

//Misc
bool bBhop = false;
bool bFlash = false;
bool bRadar = false;

int gameState;
char stringGameState[20];

//Settings
DWORD dwGlowToggle = 0x74;

DWORD dwTriggerToggle = 0x75;
DWORD dwTriggerHold = 0x12;

DWORD dwBhopToggle = 0x76;
DWORD dwFlashToggle = 0x77;
DWORD dwRadarToggle = 0x78;

DWORD dwRCSToggle = 0x79;
DWORD dwAimHold = 0x10;

#endif