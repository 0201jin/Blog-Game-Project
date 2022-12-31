#pragma once
#include "../Actor.h"

class Monster : public Actor
{
public:
	virtual void init();
	virtual void Render(float _deltaTime);
	virtual void Update(float _deltaTime);

	virtual void Attacked();
};

