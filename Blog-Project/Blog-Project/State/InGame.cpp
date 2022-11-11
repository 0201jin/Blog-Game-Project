#include "InGame.h"

void InGame::Init()
{
	__super::Init();
	world = new UWorld();
	world->init();
	world->AddWorldActor(new Character());
	cout << "InGame State!" << endl;
}

void InGame::Update(float _deltaTime)
{
	__super::Update(_deltaTime);
	world->Update(_deltaTime);
}

void InGame::Render(float _deltaTime)
{
	world->Render(_deltaTime);
}
