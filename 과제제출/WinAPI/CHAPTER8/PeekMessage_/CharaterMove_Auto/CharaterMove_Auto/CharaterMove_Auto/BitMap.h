#pragma once
#include<windows.h>
#include"Singleton.h"

enum IMG
{
	IMG_NONE,
	IMG_BACKGROUND,
	IMG_CHARACTER,
	IMG_END
};


class BitMap : public Singleton <BitMap>
{
private:
	HDC MemDC[IMG_END];
	HBITMAP m_pBitMap[IMG_END];
	HBITMAP m_pBitOld[IMG_END];
	SIZE m_size[IMG_END];
public:
	BitMap();
	void Init(HDC hdc);
	void ImgLoad(LPCWSTR FileName, IMG img);
	void Draw(int nX, int nY, int nFX, int nFH);
	void Draw();
	void Draw(HDC hdc);
	~BitMap();
};

