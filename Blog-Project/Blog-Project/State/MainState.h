#pragma once
#include "../Mgr/UState.h"

#include "../Mgr/UDrawFactory.h"
#include "../Mgr/UResourceMgr.h"

class MainState : public UState
{
public:
	MainState();
	~MainState();

	virtual void Init();

	virtual void Update(float _deltaTime);
	virtual void Redner(float _deltaTime);

protected:
	UDrawFactory* DrawFactory;
	UResourceMgr* ResourceMgr;
};

