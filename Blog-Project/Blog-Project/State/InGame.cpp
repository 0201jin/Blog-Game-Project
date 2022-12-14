#include "InGame.h"

void InGame::Init()
{
	__super::Init();
	world = new UWorld();
	world->init();

	Character* character = new Character();
	world->AddWorldActor(character);
	world->SetPlayer(character);

	world->AddWorldActor(new Monster());
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
