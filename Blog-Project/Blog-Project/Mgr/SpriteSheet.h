#pragma once
#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <wincodec.h>
#include <vector>
#include "../ExternHeader.h"

class SpriteSheet
{
public:
	SpriteSheet();
	SpriteSheet(ID2D1Bitmap* _bmp,
		D2D_VECTOR_2F _Size, D2D_VECTOR_2F _Location,
		D2D_VECTOR_2F _ImageSize = { -1, -1 }, D2D_VECTOR_2F _ImageLocation = { 0, 0 });
	SpriteSheet(ID2D1Bitmap* _bmp, D2D_VECTOR_2F _Size, D2D_VECTOR_2F _FrameSize, vector<int> _vLineMaxFrame = {}, float _fOneFrameTime = 0.1);
	~SpriteSheet();

	void Draw();
	void Draw(float _deltaTime);

	void SetAction(int _action) 
	{ 
		iAction = _action;

		if (vLineMaxFrame.size() >= iAction)
		{
			iMaxFrame = vLineMaxFrame[iAction];
		}
	};
	
	int GetRenderType() { return iRenderType; }

private:
	int iRenderType = 0;

	ID2D1Bitmap* bmp;

	D2D_VECTOR_2F Location;
	D2D_VECTOR_2F Size;

	float fImageWidth = 0;
	float fImageHeight = 0;
	float fImageX = 0;
	float fImageY = 0;

	int iAction = 0;
	vector<int> vLineMaxFrame;

	int iFrame = 0;
	int iMaxFrame = 0;
	float fFrameTime = 0;
	float fOneFrameTime = 0;
};

