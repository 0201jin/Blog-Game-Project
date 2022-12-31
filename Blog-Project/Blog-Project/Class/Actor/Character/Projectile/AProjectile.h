#pragma once
#include "../../Actor.h"

class AProjectile : public Actor
{
public:
	virtual void init();
	virtual void Render(float _deltaTime);
	virtual void Update(float _deltaTime);

	void SetDirection(D2D_VECTOR_2F _Direction) { Direction = _Direction; }

protected:
	D2D_VECTOR_2F Direction;

	float fLifeTime = 0;
};

