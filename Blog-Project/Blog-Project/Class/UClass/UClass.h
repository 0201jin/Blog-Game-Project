#pragma once
#include <d2d1.h>
#include <iostream>

using namespace std;

class UClass
{
public:
	virtual void init();
	virtual void Render(float _deltaTime);
	virtual void Update(float _deltaTime);
};