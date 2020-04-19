#pragma once
#include"Bitmap.h"
#include"Singleton.h"
#include"resource.h"



class BitmapManager : public Singleton< BitmapManager>
{
	vector<Bitmap*> m_pBitmap;
public:
	void Init(HWND hWnd, HINSTANCE hInst);
	Bitmap* GetImg(IMG_TYP type) { return m_pBitmap[type]; }
	BitmapManager();
	~BitmapManager();
};

