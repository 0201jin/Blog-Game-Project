#include "InGame.h"

void InGame::Init()
{
	__super::Init();
	world = new UWorld();
	world->init();

	Character* character = new Character();
	world->AddWorldActor(character);
	world->SetPlayer(character);

	Monster* monster = new Monster();
	monster->SetLoctaion({300, 300});
	world->AddWorldActor(monster);
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
