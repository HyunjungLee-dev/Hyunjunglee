#include "BitmapManager.h"

BitmapManager* BitmapManager::_Singleton = NULL;

BitmapManager::BitmapManager()
{
}

void BitmapManager::Init(HWND hWnd,int x, int y)
{

	HDC hdc = GetDC(hWnd);
	m_BackBuffer.Init(hdc,x,y);
	BufferDC = m_BackBuffer.GetMemDC();
	ImgLoad();
	ReleaseDC(hWnd, hdc);
}

void BitmapManager::ImgLoad()
{
	TCHAR buf[256];
	int num = 0;

	for (int i = IMG_START; i < IMG_END; i++)
	{
		Imglist.push_back(new Bitmap);
		if (i >= IMG_BLOCK_CLICK && i <= IMG_BLOCK8)
		{
			wsprintf(buf, L"Res//block_%d.bmp", num);
			num++;
			Imglist.at(i)->ImgLoad(BufferDC, buf);
		}
	}


	Imglist.at(IMG_BACK)->ImgLoad(BufferDC, L"Res//back.bmp");
	Imglist.at(IMG_BLOCK)->ImgLoad(BufferDC, L"Res//block.bmp");
	Imglist.at(IMG_FLAG)->ImgLoad(BufferDC, L"Res//flag.bmp");
	Imglist.at(IMG_MINE)->ImgLoad(BufferDC, L"Res//mine.bmp");

}


void BitmapManager::Clear()
{
	for (vector<Bitmap*>::iterator it = Imglist.begin(); it != Imglist.end(); it++)
	{
		(*it)->Release();
		delete (*it);

	}
	Imglist.clear();
}

BitmapManager::~BitmapManager()
{
}
