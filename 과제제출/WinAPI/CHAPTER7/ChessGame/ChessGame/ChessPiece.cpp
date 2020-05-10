#include "ChessPiece.h"



ChessPiece::ChessPiece()
{
}

void ChessPiece::Init(int x, int y, COLOR color)	
{
	SetImgColor(color);
	SetPieceListPos(x, y);
}


void ChessPiece::SetPieceListPos(int x, int y)
{
	int index = 0;

	for (int i = 0; i < 8; i++) // y
	{
		for (int j = 0; j < 8; j++) // x
		{
			if (m_ePieceColor == COLOR_W)
			{
				if (i == 6) 
				{
					ChessPieceList.push_back(AddPiece(PIECETYPE_PAWN));
					SetColor(index);
					ChessPieceList[index]->SetPos((j + x)* IMG_WIDTH
						, (i + y) * IMG_HEIGHT);
					index++;
				}
				else if (i == 7)
				{
					if (j == 0 || j == 7) 
						ChessPieceList.push_back(AddPiece(PIECETYPE_ROOK));
					else if (j == 1 || j == 6) 
						ChessPieceList.push_back(AddPiece(PIECETYPE_KNIGHT));
					else if (j == 2 || j == 5) 
						ChessPieceList.push_back(AddPiece(PIECETYPE_BISHOP));
					else if (j == 3) 
						ChessPieceList.push_back(AddPiece(PIECETYPE_QUEEN));
					else 
					{
						ChessPieceList.push_back(AddPiece(PIECETYPE_KING));
					}
					SetColor(index);
					ChessPieceList[index]->SetPos((j + x)* IMG_WIDTH
						, (i + y) * IMG_HEIGHT);
					index++;
				}
			}
			else if (m_ePieceColor == COLOR_B)
			{
				if (i == 1) 
				{
					ChessPieceList.push_back(AddPiece(PIECETYPE_PAWN));
					SetColor(index);
					ChessPieceList[index]->SetPos((j + x)* IMG_WIDTH
						, (i + y) * IMG_HEIGHT);
					index++;
				}
				else if (i == 0)
				{
					if (j == 0 || j == 7) 
						ChessPieceList.push_back(AddPiece(PIECETYPE_ROOK));
					else if (j == 1 || j == 6) 
						ChessPieceList.push_back(AddPiece(PIECETYPE_KNIGHT));
					else if (j == 2 || j == 5) 
						ChessPieceList.push_back(AddPiece(PIECETYPE_BISHOP));
					else if (j == 3) 
						ChessPieceList.push_back(AddPiece(PIECETYPE_QUEEN));
					else 
					{
						ChessPieceList.push_back(AddPiece(PIECETYPE_KING));
					}
					SetColor(index);
					ChessPieceList[index]->SetPos((j + x)* IMG_WIDTH
						, (i + y) * IMG_HEIGHT);
					index++;
				}
			}
		}
	}
}

void ChessPiece::SetAllMovable(bool b)
{
	for (vector<Piece*>::iterator it = ChessPieceList.begin(); it != ChessPieceList.end(); it++)
	{
		(*it)->SetMovable(b);
	}
}

void ChessPiece::SetColor(int index)	//개별 피스의 색상 
{
	ChessPieceList[index]->SetImgColor(m_ePieceColor);
}

Piece* ChessPiece::SetMoveRange(POINT point, vector<Piece*> v)
{
	for (vector<Piece*>::iterator it = ChessPieceList.begin(); it != ChessPieceList.end(); it++)
	{
		if (PtInRect(&(*it)->GetRect(), point))//
		{
			(*it)->SetMoveRange(v);
			return (*it);
		}
	}
}

void ChessPiece::PieceListDraw(HDC hdc)
{
for (vector<Piece*>::iterator it = ChessPieceList.begin(); it != ChessPieceList.end(); it++)
{
	(*it)->Draw(hdc);
}
}

POINT ChessPiece::GetPiecePos(int index)
{
	return ChessPieceList[index]->GetPos();
}


Piece* ChessPiece::AddPiece(PIECETYPE Type)
{
	switch (Type)
	{
	case PIECETYPE_PAWN:
		return new Pawn;
		break;
	case PIECETYPE_KNIGHT:
		return new Knight;
		break;
	case PIECETYPE_BISHOP:
		return new Bishop;
		break;
	case PIECETYPE_ROOK:
		return new Rook;
		break;
	case PIECETYPE_QUEEN:
		return new Queen;
		break;
	case PIECETYPE_KING:
		return new King;
		break;
	default:
		break;
	}
}

void ChessPiece::CheckAllPieceMovable(POINT point, vector<Piece*> v, POINT point2)
{
	vector<Piece*> temp;
	Piece* king = GetKingPiece();
	vector<POINT> kingRange = king->GetRange();
	bool btmp = false;


	for (vector<Piece*>::iterator it = ChessPieceList.begin(); it != ChessPieceList.end(); it++)
	{
		(*it)->SetMoveRange(v);
		vector<POINT> tmp = (*it)->GetMovableRange();
		for (vector<POINT>::iterator iter = tmp.begin(); iter != tmp.end(); iter++)
		{
			for (vector<POINT>::iterator kingp = kingRange.begin(); kingp != kingRange.end(); kingp++)
			{
				if (point2.x == (*kingp).x && point2.y == (*kingp).y)
				{
					btmp = true;
				}
				if ((*kingp).x == (*iter).x && (*kingp).y == (*iter).y)
				{
					if ( point.x == (*iter).x &&  point.y ==( *iter).y )
					{
					temp.push_back((*it));
					(*it)->SetMovable(true);
					break;
					}
			}
			}
		}
	}

	if (btmp)
	{
		for (vector<Piece*>::iterator iter = temp.begin(); iter != temp.end(); iter++)
		{
			vector<POINT> tmp = (*iter)->GetMovableRange();
			for (vector<POINT>::iterator it = tmp.begin(); it != tmp.end(); it++)
			{
				if (point2.x == (*it).x && point2.y == (*it).y)
				{
					(*iter)->SetMovable(true);
					break;
				}
				else
					(*iter)->SetMovable(false);
			}
		}
	}

}

bool ChessPiece::CheckAllPieceMovable()
{
	bool bHaveMovable;
	for (vector<Piece*>::iterator it = ChessPieceList.begin(); it != ChessPieceList.end(); it++)
	{

		if ((*it)->GetMovable() == true)
		{
			bHaveMovable = true;
			break;
		}
		else
			bHaveMovable = false;
	}
	return bHaveMovable;
}

bool ChessPiece::SearchPiecePos(POINT point)
{
	for (vector<Piece*>::iterator it = ChessPieceList.begin(); it != ChessPieceList.end(); it++)
	{
		if (PtInRect(&(*it)->GetRect(), point))
		{
			return true;
		}
	}
	return false;
}

void ChessPiece::UpgradePawn()
{
	PIECE piece;
	int end_y;
	POINT point;
	bool UpgradePawn = false;

	if (m_ePieceColor == COLOR_W)
	{
		piece = PIECE_W_PAWN;
		end_y = 0;
	}
	else
	{
		piece = PIECE_B_PAWN;
		end_y = IMG_HEIGHT * 7;
	}

	for (vector<Piece*>::iterator it = ChessPieceList.begin(); it != ChessPieceList.end(); it++)
	{
		if ((*it)->GetPieceType() == piece)
		{
			if ((*it)->GetPos().y == end_y)
			{
				point.x = (*it)->GetPos().x;
				point.y = (*it)->GetPos().y;
				ChessPieceList.erase(it);
				UpgradePawn = true;
				break;
			}
		}
	}
	if (UpgradePawn)
	{
		ChessPieceList.push_back(AddPiece(PIECETYPE_QUEEN));
		ChessPieceList.back()->SetImgColor(m_ePieceColor);
		ChessPieceList.back()->SetPos(point.x, point.y);
	}

}

Piece* ChessPiece::GetKingPiece()
{
	PIECE piece;
	if (m_ePieceColor == COLOR_W)
		piece = PIECE_W_KING;
	else
		piece = PIECE_B_KING;

	for (vector<Piece*>::iterator it = ChessPieceList.begin(); it != ChessPieceList.end(); it++)
	{
		if ((*it)->GetPieceType() == piece)
		{
			return (*it);
		}
	}
}


bool ChessPiece::SearchKing(POINT point)
{
	PIECE piece;
	if (m_ePieceColor == COLOR_W)
		 piece = PIECE_W_KING;
	else
		piece = PIECE_B_KING;

	for (vector<Piece*>::iterator it = ChessPieceList.begin(); it != ChessPieceList.end(); it++)
	{
		if ((*it)->GetPieceType() == piece)
		{
			if ((*it)->GetPos().x ==point.x && (*it)->GetPos().y == point.y)
			{
				return true;
			}
		}
	}
	return false;
}


void ChessPiece::ErasePiece(Piece* piece)
{
	RECT rcTemp = { 0 };
	for (vector<Piece*>::iterator it = ChessPieceList.begin(); it != ChessPieceList.end(); it++)
	{
		if (IntersectRect(&rcTemp,&(*it)->GetRect(), &piece->GetRect()))
		{
			ChessPieceList.erase(it);
			break;
		}
	}
}


void ChessPiece::ClearPiece()
{
	for (vector<Piece*>::iterator it = ChessPieceList.begin(); it != ChessPieceList.end(); it++)
	{
		delete (*it);

	}
	ChessPieceList.clear();
}


ChessPiece::~ChessPiece()
{
	ClearPiece();
}
