#include "Character.h"
#include "../../../Mgr/UResourceMgr.h"
#include "../../UWorld/UWorld.h"
#include "Projectile/AProjectile.h"

void Character::init()
{
	Controller = new PlayerController();
	Controller->init();

	Spritesheet = new SpriteSheet(UResourceMgr::GetInst()->GetTexture("character"), {128, 128}, {48, 48}, {6, 6, 4, 0, 3});
	Spritesheet->SetRenderType(1);
	Spritesheet->SetAction(0);
	
	type = 1;
}

void Character::Render(float _deltaTime)
{
}

void Character::Update(float _deltaTime)
{
	Controller->Update(_deltaTime);

	Location.x += Controller->GetVector().x;
	Location.y += Controller->GetVector().y;
	Spritesheet->SetLocation(Location);

	if (Controller->GetLeftButtonClick())
	{
		D2D_VECTOR_2F Direction = { (Location.x + 64) - Controller->GetMousePos().x, (Location.y + 64) - Controller->GetMousePos().y };
		double R = atan2(Direction.y, Direction.x);

		AProjectile* projectile = new AProjectile();
		projectile->SetLoctaion({ Location.x + 64, Location.y + 64});
		projectile->SetDirection({ (float)-cos(R), (float)-sin(R)});

		GetWorld()->AddWorldActor(projectile);
	}
}

void Character::Attacked()
{
	iHealth -= 5;

	if (iHealth <= 0)
	{
		GetWorld()->DelWorldActor(this);
		GetWorld()->SetPlayer(nullptr);
		delete(Controller);
		delete(this);
	}
}
