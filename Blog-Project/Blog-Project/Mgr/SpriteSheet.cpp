#include "SpriteSheet.h"

SpriteSheet::SpriteSheet()
{
}

SpriteSheet::SpriteSheet(ID2D1Bitmap* _bmp, D2D_VECTOR_2F _Size, D2D_VECTOR_2F _Location, D2D_VECTOR_2F _ImageSize, D2D_VECTOR_2F _ImageLocation)
{
	bmp = _bmp;

	Size = _Size;
	Location = _Location;

	if (_ImageSize.x == -1)
		fImageWidth = bmp->GetSize().width;
	else
		fImageWidth = _ImageSize.x;

	if (_ImageSize.y == -1)
		fImageHeight = bmp->GetSize().height;
	else
		fImageHeight = _ImageSize.y;

	fImageX = _ImageLocation.x;
	fImageY = _ImageLocation.y;
}

SpriteSheet::SpriteSheet(ID2D1Bitmap* _bmp, D2D_VECTOR_2F _Size, D2D_VECTOR_2F _FrameSize, vector<int> _vLineMaxFrame, float _fOneFrameTime)
{
	bmp = _bmp;

	Location = { 0, 0 };

	vLineMaxFrame = _vLineMaxFrame;
	fOneFrameTime = _fOneFrameTime;

	Size = _Size;

	fImageWidth = _FrameSize.x;
	fImageHeight = _FrameSize.y;

	iRenderType = 1;
}

SpriteSheet::~SpriteSheet()
{
}

void SpriteSheet::Draw()
{
	D2DRenderTarget->DrawBitmap(bmp, D2D1::RectF(Location.x, Location.y, Location.x + Size.x, Location.y + Size.y),
		1, D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
		D2D1::RectF(
			fImageX,
			fImageY,
			fImageX + fImageWidth,
			fImageY + fImageHeight));
}

void SpriteSheet::Draw(float _deltaTime)
{
	if (iMaxFrame > 0)
	{
		int iX = iFrame % iMaxFrame;

		fImageX = iX * fImageWidth;
		fImageY = iAction * fImageHeight;
		
		D2DRenderTarget->DrawBitmap(bmp, D2D1::RectF(Location.x, Location.y, Location.x + Size.x, Location.y + Size.y),
			1, D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR,
			D2D1::RectF(
				fImageX,
				fImageY,
				fImageX + fImageWidth,
				fImageY + fImageHeight));

		fFrameTime += _deltaTime;
		iFrame = fFrameTime / fOneFrameTime;
		iFrame %= iMaxFrame;
	}
}
