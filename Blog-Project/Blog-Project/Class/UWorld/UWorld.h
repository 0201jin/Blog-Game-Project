#pragma once
#include <vector>
#include "../UClass/UClass.h"

class UWorld : public UClass
{
public:
	virtual void init();
	virtual void Render(float _deltaTime);
	virtual void Update(float _deltaTime);

protected:
	vector<UClass*> vWorldActors;
};

