#include "UResourceMgr.h"

UResourceMgr* UResourceMgr::Inst = nullptr;

UResourceMgr::UResourceMgr()
{
	ID2D1Bitmap* Texture;
	LoadTexture(Texture, "Asset/characters/player.png");
	mTexture["character"] = Texture;

	ID2D1Bitmap* MonsterTexture;
	LoadTexture(MonsterTexture, "Asset/characters/slime.png");
	mTexture["monster"] = MonsterTexture;

	ID2D1Bitmap* ProjectileTexture;
	LoadTexture(ProjectileTexture, "Asset/Thunder Projectile 1/Thunder projectile1 w blur.png");
	mTexture["projectile"] = ProjectileTexture;
}

UResourceMgr::~UResourceMgr()
{
}

void UResourceMgr::LoadTexture(ID2D1Bitmap*& Texture, string Path)
{
	IWICImagingFactory* wicFactory = nullptr;
	HRESULT hr = CoCreateInstance(
		CLSID_WICImagingFactory,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_PPV_ARGS(&wicFactory)
	);

	if (SUCCEEDED(hr))
	{
		wstring LPath = wstring(Path.begin(), Path.end());
		IWICBitmapDecoder* wicDecoder = nullptr;
		hr = wicFactory->CreateDecoderFromFilename(LPath.c_str(), nullptr, GENERIC_READ,
			WICDecodeMetadataCacheOnLoad, &wicDecoder);

		if (SUCCEEDED(hr))
		{
			IWICBitmapFrameDecode* wicFrame = nullptr;
			wicDecoder->GetFrame(0, &wicFrame);

			IWICFormatConverter* wicConverter = nullptr;
			wicFactory->CreateFormatConverter(&wicConverter);

			wicConverter->Initialize(wicFrame, GUID_WICPixelFormat32bppPBGRA,
				WICBitmapDitherTypeNone, nullptr, 0.0, WICBitmapPaletteTypeCustom);

			D2DRenderTarget->CreateBitmapFromWicBitmap(wicConverter, nullptr, &Texture);

			wicDecoder->Release();
			wicConverter->Release();
			wicFrame->Release();
		}
	}

	wicFactory->Release();
}

ID2D1Bitmap* UResourceMgr::GetTexture(string _name)
{
	return mTexture[_name];
}
