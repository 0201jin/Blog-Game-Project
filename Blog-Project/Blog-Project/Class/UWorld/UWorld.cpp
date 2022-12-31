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
	for(int i = 0; i < vWorldActors.size(); ++i)
	{
		vWorldActors[i]->Update(_deltaTime);
	}
}

Actor* UWorld::AddWorldActor(Actor* _actor)
{
	_actor->init();
	vWorldActors.push_back(_actor);
	DrawFactory->AddSprite(_actor->GetSprite());
	_actor->SetWorld(this);

	return _actor;
}

void UWorld::DelWorldActor(Actor* _actor)
{
	for (vector<Actor*>::iterator iter = vWorldActors.begin(); iter != vWorldActors.end(); iter++)
	{
		if ((*iter) == _actor)
		{
			DrawFactory->DelSprite((*iter)->GetSprite());
			vWorldActors.erase(iter);
			return;
		}
	}
}
