#include "PlayerController.h"

void PlayerController::init()
{
	InputMgr = UInputMgr::GetInst();
}

void PlayerController::Render(float _deltaTime)
{
}

void PlayerController::Update(float _deltaTime)
{
	Vector = {0, 0};

	if (InputMgr->GetKeyInput(DIK_A))
	{
		Vector.x -= 100 * _deltaTime;
	}
	if (InputMgr->GetKeyInput(DIK_D))
	{
		Vector.x += 100 * _deltaTime;
	}
	if (InputMgr->GetKeyInput(DIK_W))
	{
		Vector.y -= 100 * _deltaTime;
	}
	if (InputMgr->GetKeyInput(DIK_S))
	{
		Vector.y += 100 * _deltaTime;
	}
}
