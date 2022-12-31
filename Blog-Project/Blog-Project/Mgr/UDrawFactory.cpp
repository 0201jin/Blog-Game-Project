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
	for (int i = 0; i < vSpriteSheet.size(); ++i)
	{
		switch (vSpriteSheet[i]->GetRenderType())
		{
		case 0:
			vSpriteSheet[i]->Draw();
			break;

		case 1:
			vSpriteSheet[i]->Draw(_deltaTime);
			break;
		}
	}
}

void UDrawFactory::AddSprite(SpriteSheet* _sprite)
{
	if (_sprite)
		vSpriteSheet.push_back(_sprite);
}

void UDrawFactory::DelSprite(SpriteSheet* _sprite)
{
	for (vector<SpriteSheet*>::iterator it = vSpriteSheet.begin(); it != vSpriteSheet.end(); it++)
	{
		if ((*it) == _sprite)
		{
			vSpriteSheet.erase(it);
			delete(_sprite);
			return;
		}
	}
}
