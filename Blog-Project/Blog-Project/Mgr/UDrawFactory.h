#pragma once
#include <vector>
#include "SpriteSheet.h"

using namespace std;

class UDrawFactory
{
public:
	UDrawFactory();
	~UDrawFactory();

	void Render(float _deltaTime);

	void AddSprite(SpriteSheet* _sprite);
	void DelSprite(SpriteSheet* _sprite);

protected:
	vector<SpriteSheet*> vSpriteSheet;
};