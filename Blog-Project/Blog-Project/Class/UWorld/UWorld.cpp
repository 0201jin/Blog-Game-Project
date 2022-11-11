#include "UWorld.h"

UWorld::UWorld()
{
}

UWorld::~UWorld()
{
	delete(DrawFactory);
	for (vector<Actor*>::iterator iter = vWorldActors.begin(); iter != vWorldActors.end(); iter++)
	{
		vWorldActors.erase(iter);
	}
}

void UWorld::init()
{
	DrawFactory = new UDrawFactory;
}

void UWorld::Render(float _deltaTime)
{
	DrawFactory->Render(_deltaTime);
}

void UWorld::Update(float _deltaTime)
{
	for (vector<Actor*>::iterator iter = vWorldActors.begin(); iter != vWorldActors.end(); iter++)
	{
		(*iter)->Update(_deltaTime);
	}
}

void UWorld::AddWorldActor(Actor* _actor)
{
	_actor->init();
	vWorldActors.push_back(_actor);
	DrawFactory->AddSprite(_actor->GetSprite());
}

void UWorld::DelWorldActor(Actor* _actor)
{
	for (vector<Actor*>::iterator iter = vWorldActors.begin(); iter != vWorldActors.end(); iter++)
	{
		vWorldActors.erase(iter);
	}
}
