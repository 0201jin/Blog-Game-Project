#pragma once
#include "../Mgr/UState.h"

class MainState : public UState
{
public:
	virtual void Init();

	virtual void Update(float _deltaTime);
	virtual void Redner(float _deltaTime);
};

