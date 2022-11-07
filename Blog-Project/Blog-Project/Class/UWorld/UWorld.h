#pragma once
#include <vector>
#include "../Actor/Actor.h"

#include "../../Mgr/UDrawFactory.h"

class UWorld : public UClass
{
public:
	UWorld();
	~UWorld();

	virtual void init();
	virtual void Render(float _deltaTime);
	virtual void Update(float _deltaTime);

public:
	void AddWorldActor(Actor* _actor);
	void DelWorldActor(Actor* _actor);

protected:
	vector<Actor*> vWorldActors;

	UDrawFactory* DrawFactory;
};

