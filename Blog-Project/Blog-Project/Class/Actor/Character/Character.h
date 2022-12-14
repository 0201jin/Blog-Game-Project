#pragma once
#include "../Actor.h"
#include "../../UClass/PlayerController/PlayerController.h"

class Character : public Actor
{
public:
	virtual void init();
	virtual void Render(float _deltaTime);
	virtual void Update(float _deltaTime);

	PlayerController* GetPlayerController() { return Controller; }

protected:
	PlayerController* Controller;
};

