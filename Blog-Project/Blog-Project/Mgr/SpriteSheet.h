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
	~SpriteSheet();

	void Draw();

private:
	ID2D1Bitmap* bmp;

	D2D_VECTOR_2F Location;
	D2D_VECTOR_2F Size;

	float fImageWidth = 0;
	float fImageHeight = 0;
	float fImageX = 0;
	float fImageY = 0;
};

