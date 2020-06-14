#pragma once
#include"Bitmap.h"
#include"Singleton.h"
class BitmapManager : public Singleton< BitmapManager>
{
private:
	Bitmap m_BackBuffer;
	vector<Bitmap*> Imglist;
	HDC BufferDC;
public:
	void Init(HWND hWnd,int x, int y);
	void ImgLoad();
	void Clear();

	HDC GetBufferDC() { return BufferDC; }
	Bitmap GetBackBuffer() { return m_BackBuffer; }
	Bitmap* GetImg(IMG index) { return Imglist.at(index); }
	BitmapManager();
	~BitmapManager();
};

