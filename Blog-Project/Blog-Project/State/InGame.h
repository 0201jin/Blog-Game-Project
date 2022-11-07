#pragma once
#include "../Class/UWorld/UWorld.h"
#include "../Mgr/UState.h"

class InGame : public UState
{
public:
	virtual void Init();
	virtual void Update(float _deltaTime);
	virtual void Redner(float _deltaTime);

protected:
	UWorld* world;
};

