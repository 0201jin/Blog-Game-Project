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
	DrawFactory->AddSprite(new SpriteSheet(ResourceMgr->GetTexture("character"), {512, 512}, {0, 0}, {288, 240}, {0, 0}));
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
