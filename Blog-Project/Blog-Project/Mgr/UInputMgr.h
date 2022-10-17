#pragma once
#pragma comment(lib, "dinput8.lib") 
#pragma comment(lib, "dxguid.lib")

#include <dinput.h>
#include <d2d1.h>
#include <d2d1helper.h>

using namespace std;

enum class ButtonEnum
{
	Left,
	Right,
	Wheel
};

class UInputMgr
{
public:
	UInputMgr();
	~UInputMgr();

	static UInputMgr* GetInst()
	{
		if (Inst == nullptr)
			Inst = new UInputMgr;

		return Inst;
	}

	bool Init(HINSTANCE _hInst, HWND _hWnd, float _width, float _height);
	bool Frame();

	void GetMouseMove(float& _X, float& _Y);

private:
	bool ReadMouse();
	void ProcessInput();

private:
	IDirectInput8* DirectInput = nullptr;
	IDirectInputDevice8* KeyBoard = nullptr;
	IDirectInputDevice8* Mouse = nullptr;

	BYTE keyBoardState[256] = { 0, };
	bool bCheckKeyBoardState[256] = { false, };
	DIMOUSESTATE MouseState;
	BYTE PrevKey;

	float ScreenWidth = 0;
	float ScreenHeight = 0;
	float MouseX = 0;
	float MouseY = 0;
	float MouseMoveX = 0;
	float MouseMoveY = 0;
	float CharacterX = 0;
	float CharacterY = 0;

	static UInputMgr* Inst;
};
