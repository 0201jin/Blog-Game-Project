#include "Main.h"
#include "../State/MainState.h"

ID2D1HwndRenderTarget* D2DRenderTarget;
ID2D1SolidColorBrush* pBlackBrush;
ID2D1DeviceContext* DeviceContext;

Main::Main(HWND _hwnd, HINSTANCE _hInst)
{
	hWnd = _hwnd;
	hInst = _hInst;

	D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &D2DFactory);

	CreateDevice();

	ResourceMgr = UResourceMgr::GetInst();

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
	D2DRenderTarget->BeginDraw();
	D2DRenderTarget->Clear();

	StateMgr->Render(_deltaTime);

	D2DRenderTarget->EndDraw();
}

HRESULT Main::CreateDevice()
{
	HRESULT hr = S_OK;

	if (!D2DRenderTarget)
	{
		RECT rc;
		GetClientRect(hWnd, &rc);
		D2D1_SIZE_U size = D2D1::SizeU(rc.right - rc.left, rc.bottom - rc.top);

		hr = D2DFactory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(), D2D1::HwndRenderTargetProperties(hWnd, size), &D2DRenderTarget);

		D2DRenderTarget->QueryInterface(&DeviceContext);
	}

	return hr;
}
