#include "UState.h"

UState::UState()
{
}

UState::~UState()
{
}

void UState::Init()
{
	InputMgr = UInputMgr::GetInst();
}

void UState::Update(float _deltaTime)
{
	InputMgr->Frame();
}

void UState::Redner(float _deltaTime)
{
}
