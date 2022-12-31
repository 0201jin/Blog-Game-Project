#pragma once
#include <vector>
#include "../Actor/Actor.h"

#include "../../Mgr/UDrawFactory.h"
#include "../UClass/PlayerController/PlayerController.h"

class UWorld : public UClass
{
public:
	UWorld();
	~UWorld();

	virtual void init();
	virtual void Render(float _deltaTime);
	virtual void Update(float _deltaTime);

public:
	Actor* AddWorldActor(Actor* _actor);
	void DelWorldActor(Actor* _actor);

	Actor* GetPlayer() { return Player; }
	void SetPlayer(Actor* _Player) { Player = _Player; }

	vector<Actor*> GetWorldActors() { return vWorldActors; }

protected:
	vector<Actor*> vWorldActors;

	UDrawFactory* DrawFactory;
	Actor* Player;
};

