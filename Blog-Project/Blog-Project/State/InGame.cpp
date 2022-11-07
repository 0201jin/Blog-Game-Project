#include "InGame.h"

void InGame::Init()
{
	__super::Init();
	world = new UWorld();
	world->init();
	cout << "InGame State!" << endl;
}

void InGame::Update(float _deltaTime)
{
	__super::Update(_deltaTime);
	world->Update(_deltaTime);
}

void InGame::Redner(float _deltaTime)
{
	world->Render(_deltaTime);
}
