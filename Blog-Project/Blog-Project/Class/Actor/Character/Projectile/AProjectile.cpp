#include "AProjectile.h"
#include "../../../../Mgr/UResourceMgr.h"
#include "../../../UWorld/UWorld.h"
#include "../../Monster/Monster.h"

void AProjectile::init()
{
	Spritesheet = new SpriteSheet(UResourceMgr::GetInst()->GetTexture("projectile"), { 40, 32 }, { 32, 32 }, { 5 }, 0.1);
	Spritesheet->SetRenderType(1);
	Spritesheet->SetAction(0);

	type = 3;
}

void AProjectile::Render(float _deltaTime)
{
}

void AProjectile::Update(float _deltaTime)
{
	Location.x += Direction.x * _deltaTime * 100;
	Location.y += Direction.y * _deltaTime * 100;
	Spritesheet->SetLocation(Location);

	for (int i = 0; i < GetWorld()->GetWorldActors().size(); ++i)
	{
		if (GetWorld()->GetWorldActors()[i]->GetType() == 2)
		{
			double Distance = sqrt(pow((Location.x - (GetWorld()->GetWorldActors()[i]->GetLocation().x + 64)), 2) + pow((Location.y - (GetWorld()->GetWorldActors()[i]->GetLocation().y + 64)), 2));
			if (Distance <= 64)
			{
				GetWorld()->GetWorldActors()[i]->Attacked();

				GetWorld()->DelWorldActor(this);
				delete(this);
				return;
			}
		}
	}

	fLifeTime += _deltaTime;

	if (fLifeTime > 3)
	{
		GetWorld()->DelWorldActor(this);
		delete(this);
	}
}
