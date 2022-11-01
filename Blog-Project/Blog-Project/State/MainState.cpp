#include "MainState.h"
#include <iostream>

MainState::MainState()
{
}

MainState::~MainState()
{
	delete(DrawFactory);
}

void MainState::Init()
{
	std::cout << "MainState!" << std::endl;
	ResourceMgr = new UResourceMgr();

	DrawFactory = new UDrawFactory;

	SpriteSheet* sprite = new SpriteSheet(ResourceMgr->GetTexture("character"), { 512, 512 }, { 48, 48 }, { 6, 6, 4, 0, 3 });
	DrawFactory->AddSprite(sprite);
	sprite->SetAction(1);
}

void MainState::Update(float _deltaTime)
{
	std::cout << "MainState Update!" << std::endl;
}

void MainState::Redner(float _deltaTime)
{
	std::cout << "MainState Render!" << std::endl;
	DrawFactory->Render(_deltaTime);
}
