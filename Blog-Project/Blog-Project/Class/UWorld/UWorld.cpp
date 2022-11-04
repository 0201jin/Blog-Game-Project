#include "UWorld.h"

void UWorld::init()
{
}

void UWorld::Render(float _deltaTime)
{
	for (vector<UClass*>::iterator iter = vWorldActors.begin(); iter != vWorldActors.end(); iter++)
	{
		(*iter)->Render(_deltaTime);
	}
}

void UWorld::Update(float _deltaTime)
{
	for (vector<UClass*>::iterator iter = vWorldActors.begin(); iter != vWorldActors.end(); iter++)
	{
		(*iter)->Update(_deltaTime);
	}
}
