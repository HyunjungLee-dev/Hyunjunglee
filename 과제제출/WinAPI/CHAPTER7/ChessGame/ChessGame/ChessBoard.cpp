#include "ChessBoard.h"



ChessBoard::ChessBoard()
{
}

void ChessBoard::SetPos(int x, int y)
{
	int index = 0;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (i % 2 == 0 && j % 2 == 0 || j % 2 != 0 && i % 2 != 0)
			{
				ChessBrd.push_back(AddBlock(BOARDBLOCK_LIGHT));
			}
			else
			{
				ChessBrd.push_back(AddBlock(BOARDBLOCK_DARK));
			}
			ChessBrd[index]->SetPos(x+j * IMG_WIDTH
				, y+i * IMG_HEIGHT);
			index++;
		}
	}
}


void ChessBoard::Draw(HDC hdc)
{
	for (vector<Block*>::iterator it = ChessBrd.begin(); it != ChessBrd.end(); it++)
	{
		(*it)->Draw(hdc);

	}
}

Block* ChessBoard::AddBlock(BOARDBLOCK Type)
{
	switch (Type)
	{
	case BOARDBLOCK_LIGHT:
		return new Light;
		break;
	case BOARDBLOCK_DARK:
		return new Dark;
		break;
	default:
		break;
	}
}

void ChessBoard::ClearBlock()
{
	for (vector<Block*>::iterator it = ChessBrd.begin(); it != ChessBrd.end(); it++)
	{
		delete (*it);

	}
	ChessBrd.clear();
}


ChessBoard::~ChessBoard()
{
	ClearBlock();
}
