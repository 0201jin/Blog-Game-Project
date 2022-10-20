#include "Main.h"
#include "../State/MainState.h"

Main::Main(HWND _hwnd, HINSTANCE _hInst)
{
	hWnd = _hwnd;
	hInst = _hInst;

	InputMgr = UInputMgr::GetInst();
	InputMgr->Init(_hInst, _hwnd, 1270, 720);

	StateMgr = UStateMgr::GetInst();
	StateMgr->SetState(new MainState);
}

Main::~Main()
{
}

void Main::Update(float _deltaTime)
{
	InputMgr->Frame();
	StateMgr->Update(_deltaTime);
}

void Main::Render(float _deltaTime)
{
	StateMgr->Render(_deltaTime);
}
