#pragma once
#include"Mecro.h"
class Bitmap
{
private:
	HDC MemDC;
	HBITMAP m_BitMap;
	HBITMAP m_OldBitMap;
	SIZE m_size;
public:
	void Init(HDC hdc,int x, int y);
	void ImgLoad(HDC hdc, LPCWSTR FileName);
	void Draw(HDC hdc,int nX, int nY);
	void Draw(HDC hdc, int nX, int nY, int w, int h);
	inline SIZE GetSize() { return m_size; }
	HDC GetMemDC() { return MemDC; }
	void Release();
	Bitmap();
	~Bitmap();
};

