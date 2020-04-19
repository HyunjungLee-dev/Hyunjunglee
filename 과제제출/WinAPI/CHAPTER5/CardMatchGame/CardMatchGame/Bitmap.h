#pragma once
#include"Mecro.h"
class Bitmap
{
private:
	HDC MemDC;
	HBITMAP  m_myBitmap, m_oldBitmap;
	SIZE m_size;
public:
	void Init(HDC hdc, HINSTANCE hInst, int ResID);
	void Draw(HDC hdc, int x, int y, float sx, float sy);
	void Draw(HDC hdc, int x, int y);

	SIZE Getsize() { return m_size; }
	Bitmap();
	~Bitmap();
};

