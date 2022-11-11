#pragma once
#include "../Class/UWorld/UWorld.h"
#include "../Mgr/UState.h"

#include "../Class/Actor/Character/Character.h"

class InGame : public UState
{
public:
	virtual void Init();
	virtual void Update(float _deltaTime);
	virtual void Render(float _deltaTime);

protected:
	UWorld* world;
};

