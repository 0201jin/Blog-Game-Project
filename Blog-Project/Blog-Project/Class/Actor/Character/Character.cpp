#include "Character.h"
#include "../../../Mgr/UResourceMgr.h"

void Character::init()
{
	Controller = new PlayerController();
	Controller->init();

	Spritesheet = new SpriteSheet(UResourceMgr::GetInst()->GetTexture("character"), {128, 128}, {48, 48}, {6, 6, 4, 0, 3});
	Spritesheet->SetRenderType(1);
	Spritesheet->SetAction(0);
}

void Character::Render(float _deltaTime)
{
}

void Character::Update(float _deltaTime)
{
	Controller->Update(_deltaTime);

	Spritesheet->AddLocation(Controller->GetVector());
}
