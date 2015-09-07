#include "Entity.h"

Entity* gEntity = new Entity();

DWORD Entity::gBaseEntity(int PlayerNumber)
{
	return gMemory->Read<DWORD>(gOffsets->gClientDLL() + gOffsets->gEntityList() + (gOffsets->gDwEntitySize() * PlayerNumber));
}

DWORD Entity::gGlowPointer()
{
	return gMemory->Read<DWORD>(gOffsets->gClientDLL() + gOffsets->gGlowObjectBase());
}

int Entity::gTeam(int PlayerNumber)
{
	return gMemory->Read<int>(gBaseEntity(PlayerNumber) + gOffsets->gTeamNum());
}

int Entity::gGlowIndex(int PlayerNumber)
{
	return gMemory->Read<int>(gBaseEntity(PlayerNumber) + gOffsets->gGlowIndex());
}

bool Entity::gIsDead(int PlayerNumber)
{
	/*int hp= gMemory->Read<int>(gBaseEntity(PlayerNumber) + gOffsets->gHealth());
	if (hp < 1) return true;
	else return false;*/
	return gMemory->Read<bool>(gBaseEntity(PlayerNumber) + gOffsets->gLifeState());

}

bool Entity::gIsDormant(int PlayerNumber)
{
	return gMemory->Read<bool>(gBaseEntity(PlayerNumber) + gOffsets->gbDormant());
}

void Entity::gBonePosition(int PlayerNumber, float* position, int bone)
{
	DWORD BaseEntity = gBaseEntity(PlayerNumber);
	if (BaseEntity)
	{
		DWORD BoneMatrix = gMemory->Read<DWORD>(BaseEntity + gOffsets->gDwBoneMatrix());
		if (BoneMatrix)
		{
			position[0] = gMemory->Read<float>(BoneMatrix + 0x30 * bone + 0x0C);
			position[1] = gMemory->Read<float>(BoneMatrix + 0x30 * bone + 0x1C);
			position[2] = gMemory->Read<float>(BoneMatrix + 0x30 * bone + 0x2C) ;
		}
	}
	
}

bool Entity::gbSpotted(int PlayerNumber)
{
	return gMemory->Read<bool>(gBaseEntity(PlayerNumber) + gOffsets->gbSpotted());
}