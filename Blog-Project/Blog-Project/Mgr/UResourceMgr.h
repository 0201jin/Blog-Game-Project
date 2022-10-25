#pragma once
#include <unordered_map>
#include <map>
#include "../ExternHeader.h"

using namespace std;

class UResourceMgr
{
public:
	UResourceMgr();
	~UResourceMgr();

	void LoadTexture(ID2D1Bitmap*& Texture, string Path);

	ID2D1Bitmap* GetTexture(string _name);

protected:
	unordered_map<string, ID2D1Bitmap*> mTexture;

private:
	static UResourceMgr* Inst;

public:
	static UResourceMgr* GetInst()
	{
		if (Inst == nullptr)
			Inst = new UResourceMgr;
		return Inst;
	}
};

