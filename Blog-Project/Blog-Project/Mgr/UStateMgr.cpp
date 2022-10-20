#include "UStateMgr.h"

UStateMgr* UStateMgr::Inst = nullptr;

UStateMgr::UStateMgr()
{
}

UStateMgr::~UStateMgr()
{
}

void UStateMgr::SetState(UState* _state)
{
	if (m_State != nullptr)
		delete(m_State);

	m_State = _state;
	m_State->Init();
}

void UStateMgr::Update(float _deltaTime)
{
	if (m_State != nullptr)
		m_State->Update(_deltaTime);
}

void UStateMgr::Render(float _deltaTime)
{
	if (m_State != nullptr)
		m_State->Redner(_deltaTime);
}
