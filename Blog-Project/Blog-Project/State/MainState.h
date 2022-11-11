#pragma once
#include "../Mgr/UState.h"

class MainState : public UState
{
public:
	MainState();
	~MainState();

	virtual void Init();

	virtual void Update(float _deltaTime);
	virtual void Render(float _deltaTime);
};

