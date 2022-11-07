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
	virtual void Redner(float _deltaTime);

protected:
	UInputMgr* InputMgr;
};

