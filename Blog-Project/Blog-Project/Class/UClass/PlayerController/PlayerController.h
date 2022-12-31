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

	bool GetLeftButtonClick()
	{
		return bLeftButtonClick;
	}

	D2D_VECTOR_2F GetMousePos()
	{
		float x, y;
		InputMgr->GetMousePos(x, y);
		return { x, y };
	}

protected:
	UInputMgr* InputMgr;

	D2D_VECTOR_2F Vector;

	bool bLeftButtonClick = false;
};

