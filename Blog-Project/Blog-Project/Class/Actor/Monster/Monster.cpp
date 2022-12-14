#include "Monster.h"
#include "../../../Mgr/UResourceMgr.h"
#include "../../UWorld/UWorld.h"

#include <iostream>

void Monster::init()
{
	Spritesheet = new SpriteSheet(UResourceMgr::GetInst()->GetTexture("monster"), { 128, 128 }, { 32, 32 }, { 4, 6, 7, 3, 5 });
	Spritesheet->SetRenderType(1);
	Spritesheet->SetAction(0);
}

void Monster::Render(float _deltaTime)
{
}

void Monster::Update(float _deltaTime)
{
	D2D_VECTOR_2F Direction = { Location.x - GetWorld()->GetPlayer()->GetLocation().x,  Location.y - GetWorld()->GetPlayer()->GetLocation().y };
	double R = atan2(Direction.y, Direction.x);

	Location.x -= cos(R);
	Location.y -= sin(R);
	Spritesheet->SetLocation(Location);
}