#pragma once
#include "../framework.h"
#include "../Mgr/UInputMgr.h"
#include "../Mgr/UStateMgr.h"

class Main
{
public:
	Main(HWND _hwnd, HINSTANCE _hInst);
	~Main();

	void Update(float _deltaTime);
	void Render(float _deltaTime);

protected:
	UInputMgr* InputMgr;
	UStateMgr* StateMgr;

	HWND hWnd;
	HINSTANCE hInst;
};

