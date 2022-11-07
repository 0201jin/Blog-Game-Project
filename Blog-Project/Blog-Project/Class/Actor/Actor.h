#pragma once
#include "../UClass/UClass.h"

class Actor : public UClass
{
public:
	virtual void init();
	virtual void Render(float _deltaTime);
	virtual void Update(float _deltaTime);
};

