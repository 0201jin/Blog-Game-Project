#pragma once
#include "../UClass.h"
#include "../../../Mgr/UInputMgr.h"

class PlayerController : public UClass
{
public:
	virtual void init();
	virtual void Render(float _deltaTime);
	virtual void Update(float _deltaTime);

	D2D_VECTOR_2F GetVector()
	{
		return Vector;
	}

protected:
	UInputMgr* InputMgr;

	D2D_VECTOR_2F Vector;
};

