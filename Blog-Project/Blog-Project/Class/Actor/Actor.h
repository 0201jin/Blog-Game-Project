#pragma once
#include "../UClass/UClass.h"
#include "../../Mgr/SpriteSheet.h"

class UWorld;
class Actor : public UClass
{
public:
	virtual void init();
	virtual void Render(float _deltaTime);
	virtual void Update(float _deltaTime);

	void SetLoctaion(D2D_VECTOR_2F _Lo)
	{
		Location = _Lo;
	}

	D2D_VECTOR_2F GetLocation()
	{
		return Location;
	}

	void SetScale(D2D_VECTOR_2F _Scale)
	{
		Scale = _Scale;
	}

	D2D_VECTOR_2F GetScale()
	{
		return Scale;
	}

	SpriteSheet* GetSprite()
	{
		return Spritesheet;
	}

	UWorld* GetWorld() { return world; }
	void SetWorld(UWorld* _world) { world = _world; }

protected:
	D2D_VECTOR_2F Location;
	D2D_VECTOR_2F Scale;
	SpriteSheet* Spritesheet;

	UWorld* world;
};

