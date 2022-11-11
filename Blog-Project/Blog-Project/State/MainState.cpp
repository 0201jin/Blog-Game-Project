#include "MainState.h"
#include <iostream>
#include "../Mgr/UStateMgr.h"
#include "InGame.h"

MainState::MainState()
{
}

MainState::~MainState()
{
}

void MainState::Init()
{
	__super::Init();
	std::cout << "MainState!" << std::endl;
}

void MainState::Update(float _deltaTime)
{
	__super::Update(_deltaTime);

	if (InputMgr->GetPressAnyKey())
	{
		UStateMgr::GetInst()->SetState(new InGame);
	}
}

void MainState::Render(float _deltaTime)
{
}
