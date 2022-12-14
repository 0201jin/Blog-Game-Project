#pragma once
#include "../Class/UWorld/UWorld.h"
#include "../Mgr/UState.h"

#include "../Class/Actor/Character/Character.h"
#include "../Class/UClass/PlayerController/PlayerController.h"
#include "../Class/Actor/Monster/Monster.h"

class InGame : public UState
{
public:
	virtual void Init();
	virtual void Update(float _deltaTime);
	virtual void Render(float _deltaTime);

protected:
	UWorld* world;
};

