#pragma once
#include "../framework.h"
#include "../Mgr/UInputMgr.h"
#include "../Mgr/UStateMgr.h"
#include "../Mgr/UResourceMgr.h"

class Main
{
public:
	Main(HWND _hwnd, HINSTANCE _hInst);
	~Main();

	void Update(float _deltaTime);
	void Render(float _deltaTime);

private:
	HRESULT CreateDevice();

protected:
	UInputMgr* InputMgr;
	UStateMgr* StateMgr;
	UResourceMgr* ResourceMgr;

	HWND hWnd;
	HINSTANCE hInst;

	ID2D1Factory* D2DFactory;
};

