#pragma once
#include"Bitmap.h"
#include"Singleton.h"


class BitmapManager : public Singleton< BitmapManager>
{
	vector<Bitmap*> m_pPiece;
	vector<Bitmap*> m_pBrdBlock;


public:
	void Init(HWND hWnd);
	void Clear(vector<Bitmap*> bit);

	Bitmap* GetPieceImg(PIECE Btype) { return m_pPiece[Btype]; }
	Bitmap* GetBrdBImg(BOARDBLOCK Btype) { return m_pBrdBlock[Btype]; }
	BitmapManager();
	~BitmapManager();
};

