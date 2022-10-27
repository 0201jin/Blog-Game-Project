#include "UDrawFactory.h"

UDrawFactory::UDrawFactory()
{
}

UDrawFactory::~UDrawFactory()
{
	for (vector<SpriteSheet*>::iterator it = vSpriteSheet.begin(); it != vSpriteSheet.end(); it++)
	{
		delete(*it);
	}
}

void UDrawFactory::Render(float _deltaTime)
{
	for (vector<SpriteSheet*>::iterator it = vSpriteSheet.begin(); it != vSpriteSheet.end(); it++)
	{
		(*it)->Draw();
	}
}

void UDrawFactory::AddSprite(SpriteSheet* _sprite)
{
	if (_sprite)
		vSpriteSheet.push_back(_sprite);
}
