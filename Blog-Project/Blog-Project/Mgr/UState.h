#pragma once
#include <iostream>

#include "../Mgr/UInputMgr.h"

using namespace std;

class UState
{
public:
	UState();
	~UState();

	virtual void Init();

	virtual void Update(float _deltaTime);
	virtual void Render(float _deltaTime);

protected:
	UInputMgr* InputMgr;
};

