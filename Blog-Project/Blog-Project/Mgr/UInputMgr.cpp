#include "UInputMgr.h"

UInputMgr* UInputMgr::Inst = nullptr;

UInputMgr::UInputMgr()
{
}

UInputMgr::~UInputMgr()
{
}

bool UInputMgr::Init(HINSTANCE _hInst, HWND _hWnd, float _width, float _height)
{
	ScreenWidth = _width;
	ScreenHeight = _height;

	DirectInput8Create(_hInst, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&DirectInput, nullptr);
	DirectInput->CreateDevice(GUID_SysKeyboard, &KeyBoard, nullptr);
	KeyBoard->SetDataFormat(&c_dfDIKeyboard);
	KeyBoard->SetCooperativeLevel(_hWnd, DISCL_FOREGROUND | DISCL_EXCLUSIVE);
	KeyBoard->Acquire();
	DirectInput->CreateDevice(GUID_SysMouse, &Mouse, nullptr);
	Mouse->SetDataFormat(&c_dfDIMouse);
	Mouse->Acquire();

	return true;
}

bool UInputMgr::Frame()
{
	ReadMouse();

	ProcessInput();

	return true;
}

void UInputMgr::GetMouseMove(float& _X, float& _Y)
{
	_X = MouseMoveX;
	_Y = MouseMoveY;
}

bool UInputMgr::ReadMouse()
{
	HRESULT m_hr = Mouse->GetDeviceState(sizeof(DIMOUSESTATE), (LPVOID)&MouseState);

	if (FAILED(m_hr))
	{
		if ((m_hr == DIERR_INPUTLOST) || (m_hr == DIERR_NOTACQUIRED))
		{
			Mouse->Acquire();
		}
		else
		{
			return false;
		}
	}

	return true;
}

void UInputMgr::ProcessInput()
{
	MouseX += MouseState.lX;
	MouseY += MouseState.lY;

	MouseMoveX = MouseState.lX;
	MouseMoveY = MouseState.lY;

	if (MouseX < 0)
	{
		MouseX = 0;
		MouseMoveX = 0;
	}
	else if (MouseX > ScreenWidth)
	{
		MouseX = ScreenWidth;
		MouseMoveX = 0;
	}

	if (MouseY < 0)
	{
		MouseY = 0;
		MouseMoveY = 0;
	}
	else if (MouseY > ScreenHeight)
	{
		MouseY = ScreenHeight;
		MouseMoveY = 0;
	}
}