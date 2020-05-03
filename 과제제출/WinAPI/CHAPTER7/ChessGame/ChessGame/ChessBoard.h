#pragma once
#include"Block.h"

class ChessBoard : public Block
{
private:
	vector<Block*> ChessBrd;
public:
	Block* AddBlock(BOARDBLOCK Type);
	void ClearBlock();

	virtual void SetPos(int x, int y);
	virtual void Draw(HDC hdc);
	ChessBoard();
	~ChessBoard();
};

