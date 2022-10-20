#include "MainState.h"
#include <iostream>

void MainState::Init()
{
	std::cout << "MainState!" << std::endl;
}

void MainState::Update(float _deltaTime)
{
	std::cout << "MainState Update!" << std::endl;
}

void MainState::Redner(float _deltaTime)
{
	std::cout << "MainState Render!" << std::endl;
}
