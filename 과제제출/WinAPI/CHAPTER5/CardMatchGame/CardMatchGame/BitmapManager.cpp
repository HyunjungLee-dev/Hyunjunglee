#include "BitmapManager.h"

BitmapManager* BitmapManager::_Singleton = NULL;

BitmapManager::BitmapManager()
{

}

void BitmapManager::Init(HWND hWnd, HINSTANCE hInst)
{
	HDC hdc = GetDC(hWnd);
	for (int i = IMG_TYP_START; i < IMG_TYP_CARDEND; i++)
	{
		m_pBitmap.push_back(new Bitmap);
		m_pBitmap[i]->Init(hdc, hInst, i + 101);
	}
	ReleaseDC(hWnd, hdc);
}


BitmapManager::~BitmapManager()
{
	//vector<Bitmap*>().swap(m_pBitmap); ���ÿ��� ������ vector ������ �Ҵ� �޸� ���� ����
	for (vector<Bitmap*>::iterator it = m_pBitmap.begin(); it != m_pBitmap.end(); it++)
	{
		delete (*it);

	}
	m_pBitmap.clear();

}
