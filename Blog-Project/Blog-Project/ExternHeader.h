#pragma once
#pragma comment(lib,"D2D1.lib")

#include <d2d1.h>
#include <d2d1_1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <wincodec.h>

using namespace std;

extern ID2D1HwndRenderTarget* D2DRenderTarget;
extern ID2D1SolidColorBrush* pBlackBrush;
extern ID2D1DeviceContext* DeviceContext;
extern HWND Hwnd;