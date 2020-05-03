#include "BitmapManager.h"

BitmapManager* BitmapManager::_Singleton = NULL;

BitmapManager::BitmapManager()
{

}

void BitmapManager::Init(HWND hWnd)
{
	TCHAR buf[256];
	HDC hdc = GetDC(hWnd);
	int piece = 0, brdblock = 0;
	for (int i = IMG_START; i < IMG_END; i++)
	{

		if (piece < IMG_BPIECE)
		{
			m_pPiece.push_back(new Bitmap);
			wsprintf(buf, L"Chess//block_b_0%d.bmp", piece);
			m_pPiece[piece]->Init(hdc, buf);
			piece++;
		}
		else if (piece < IMG_BPIECE + IMG_WPIECE)
		{
			m_pPiece.push_back(new Bitmap);
			wsprintf(buf, L"Chess//block_w_0%d.bmp", piece- IMG_BPIECE);
			m_pPiece[piece]->Init(hdc, buf);
			piece++;
		}
		else if (brdblock < IMG_BRDBLOCK)
		{
			m_pBrdBlock.push_back(new Bitmap);
			wsprintf(buf, L"Chess//block0%d.bmp", brdblock);
			m_pBrdBlock[brdblock]->Init(hdc, buf);
			brdblock++;
		}

	}

	ReleaseDC(hWnd, hdc);
}

void BitmapManager::Clear(vector<Bitmap*> bit)
{
	for (vector<Bitmap*>::iterator it = bit.begin(); it != bit.end(); it++)
	{
		delete (*it);

	}
	bit.clear();
}


BitmapManager::~BitmapManager()
{
	Clear(m_pPiece);
	Clear(m_pBrdBlock);

}
