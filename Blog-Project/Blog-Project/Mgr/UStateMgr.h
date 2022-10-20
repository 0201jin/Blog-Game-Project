#pragma once
#include "UState.h"

class UStateMgr
{
public:
	UStateMgr();
	~UStateMgr();

	static UStateMgr* GetInst()
	{
		if (Inst == nullptr)
			Inst = new UStateMgr;

		return Inst;
	}

	void SetState(UState* _state);

	void Update(float _deltaTime);
	void Render(float _deltaTime);

protected:
	UState* m_State = nullptr;

	static UStateMgr* Inst;
};