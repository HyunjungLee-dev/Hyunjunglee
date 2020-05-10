#include "Piece.h"



Piece::Piece()
{
}

/*Piece*/

void Piece::SetPos(int x, int y)
{
	pos.x = x;
	pos.y = y;
	m_PieceRect.left = x*0.5;
	m_PieceRect.top = y*0.5;
	m_PieceRect.right = m_PieceRect.left + m_pBitmap->GetSize().cx*0.5;
	m_PieceRect.bottom = m_PieceRect.top + m_pBitmap->GetSize().cy*0.5;
}


void Piece::Draw(HDC hdc)
{
	m_pBitmap->Draw(hdc, pos.x, pos.y);
}

void Piece::RangelengthWidth(vector<Piece*> v)
{
	/*가로세로*/

	for (int i = 1; i < 8; i++)
	{
		MoveRange.push_back(RangePoint(0, i * IMG_HEIGHT));
	}
	SetMovableRange(v);
	MoveRange.clear();

	for (int i = 1; i < 8; i++)
	{
		MoveRange.push_back(RangePoint(0, -i * IMG_HEIGHT));
	}
	SetMovableRange(v);
	MoveRange.clear();

	for (int i = 1; i < 8; i++)
	{
		MoveRange.push_back(RangePoint(i * IMG_WIDTH, 0));
	}
	SetMovableRange(v);
	MoveRange.clear();

	for (int i = 1; i < 8; i++)
	{
		MoveRange.push_back(RangePoint(-i * IMG_WIDTH, 0));
	}
	SetMovableRange(v);
	MoveRange.clear();

}

void Piece::RangediagonalLine(vector<Piece*> v)
{
	/*대각선*/
	for (int i = 1; i < 8; i++)
	{
		MoveRange.push_back(RangePoint(i* IMG_WIDTH, i * IMG_HEIGHT));
	}
	SetMovableRange(v);
	MoveRange.clear();

	for (int i = 1; i < 8; i++)
	{
		MoveRange.push_back(RangePoint(-i * IMG_WIDTH, i * IMG_HEIGHT));
	}
	SetMovableRange(v);
	MoveRange.clear();

	for (int i = 1; i < 8; i++)
	{
		MoveRange.push_back(RangePoint(i * IMG_WIDTH, -i * IMG_HEIGHT));
	}
	SetMovableRange(v);
	MoveRange.clear();


	for (int i = 1; i < 8; i++)
	{
		MoveRange.push_back(RangePoint(-i * IMG_WIDTH, -i * IMG_HEIGHT));
	}
	SetMovableRange(v);
	MoveRange.clear();


}

POINT Piece::RangePoint(int x, int y)
{
	POINT point;
	point.x = pos.x + x;
	point.y = pos.y + y;

	return point;
}

Piece::~Piece()
{
}


/*King*/

King::King()
{
}

void King::SetImgColor(COLOR color)
{
	m_eColor = color;
	if (m_eColor == COLOR_W)
		m_ePieceType = PIECE_W_KING;
	else
		m_ePieceType = PIECE_B_KING;
	m_pBitmap = BitmapManager::GetSingleton()->GetPieceImg(m_ePieceType);
}


void King::SetMoveRange(vector<Piece*> v)
{
	MovableRange.clear();
	MoveRange.clear();


	MoveRange.push_back(RangePoint(0, 1 * IMG_HEIGHT));
	MoveRange.push_back(RangePoint(1 * IMG_WIDTH, 0));
	MoveRange.push_back(RangePoint(1 * IMG_WIDTH, 1 * IMG_HEIGHT));
	MoveRange.push_back(RangePoint(-1 * IMG_WIDTH, 0));
	MoveRange.push_back(RangePoint(0, -1 * IMG_HEIGHT));
	MoveRange.push_back(RangePoint(-1 * IMG_WIDTH, -1 * IMG_HEIGHT));
	MoveRange.push_back(RangePoint(1 * IMG_WIDTH, -1 * IMG_HEIGHT));
	MoveRange.push_back(RangePoint(-1 * IMG_WIDTH, +1 * IMG_HEIGHT));

	SetMovableRange(v);
	UpdateKingRange(v);
}

void King::SetMovableRange(vector<Piece*> v)
{
	MovableRange.push_back(pos);

	bool bCheck = false;

	for (auto it = MoveRange.begin(); it != MoveRange.end(); it++)
	{
		if ((*it).x < 0 || (*it).x >= 1000 || (*it).y < 0 || (*it).y >= 1000)
			continue;
		for (auto iter = v.begin(); iter != v.end(); iter++)
		{
			if ((*iter)->GetPos().x == (*it).x && ((*iter)->GetPos().y == (*it).y))
			{
				if (m_eColor == COLOR_W)
				{
					if ((*iter)->GetColor() == COLOR_W)
					{
						bCheck = false;
						break;
					}
				}
				else
				{
					if ((*iter)->GetColor() == COLOR_B)
					{
						bCheck = false;
						break;
					}
				}
			}
			else
				bCheck = true;
		}
		if (bCheck == true)
			MovableRange.push_back((*it));
	}
}

void King::UpdateKingRange(vector<Piece*> v)
{
	COLOR piece;
	if (m_eColor == COLOR_W)
		piece = COLOR_B;
	else
		piece = COLOR_W;

	for (auto iter = v.begin(); iter != v.end(); iter++)
	{
		if ((*iter)->GetColor() == piece)
		{
			vector<POINT> point;
			point = (*iter)->GetMovableRange();
			for (auto it = point.begin(); it != point.end(); it++)
			{
				if (it == point.begin())
					continue;
				for (auto kingRange = MovableRange.begin(); kingRange != MovableRange.end(); kingRange++)
				{
					if ((*it).x == (*kingRange).x && (*it).y == (*kingRange).y)
					{
						MovableRange.erase(kingRange);
						break;
					}
				}
			}
		}
	}
}

/*Queen*/

Queen::Queen()
{
}

void Queen::SetImgColor(COLOR color)
{
	m_eColor = color;
	if (m_eColor == COLOR_W)
		m_ePieceType = PIECE_W_QUEEN;
	else
		m_ePieceType = PIECE_B_QUEEN;
	m_pBitmap = BitmapManager::GetSingleton()->GetPieceImg(m_ePieceType);
}


void Queen::SetMoveRange(vector<Piece*> v)
{
	MovableRange.clear();
	MoveRange.clear();




	/*가로세로*/

	this->RangelengthWidth(v);

	/*대각선*/
	this->RangediagonalLine(v);

}

void Queen::SetMovableRange(vector<Piece*> v)
{
	MovableRange.push_back(pos);
	BREAK bCheck;

	for (auto it = MoveRange.begin(); it != MoveRange.end(); it++)
	{
		for (auto iter = v.begin(); iter != v.end(); iter++)
		{
			if (((*iter)->GetPos().x == (*it).x && ((*iter)->GetPos().y == (*it).y)))
			{
				if (m_eColor == COLOR_W)
				{
					if ((*iter)->GetColor() == COLOR_W)
					{
						bCheck = BREAK_YES;
						break;
					}
					else if ((*iter)->GetColor() == COLOR_B)
					{
						bCheck = BREAK_YES_PUSH;
						break;
					}
				}
				else if (m_eColor == COLOR_B)
				{
					if ((*iter)->GetColor() == COLOR_W) 
					{
						bCheck = BREAK_YES_PUSH;
						break;
					}
					else if ((*iter)->GetColor() == COLOR_B)
					{
						bCheck = BREAK_YES;
						break;
					}
				}
			}
			else
				bCheck = BREAK_NO_PUSH;
		}
		if (bCheck == BREAK_NO_PUSH)
			MovableRange.push_back((*it));
		else if (bCheck == BREAK_YES_PUSH)
		{
			MovableRange.push_back((*it));
			break;
		}
		else
			break;
	}
}

/*Bishop*/

Bishop::Bishop()
{
}

void Bishop::SetImgColor(COLOR color)
{
	m_eColor = color;
	if (m_eColor == COLOR_W)
		m_ePieceType = PIECE_W_BISHOP;
	else
		m_ePieceType = PIECE_B_BISHOP;
	m_pBitmap = BitmapManager::GetSingleton()->GetPieceImg(m_ePieceType);
}

void Bishop::SetMovableRange(vector<Piece*> v)
{
	MovableRange.push_back(pos);
	BREAK bCheck;


	for (auto it = MoveRange.begin(); it != MoveRange.end(); it++)
	{
		for (auto iter = v.begin(); iter != v.end(); iter++)
		{
			if (((*iter)->GetPos().x == (*it).x && ((*iter)->GetPos().y == (*it).y)))
			{
				if (m_eColor == COLOR_W)
				{
					if ((*iter)->GetColor() == COLOR_W)
					{
						bCheck = BREAK_YES;
						break;
					}
					else if ((*iter)->GetColor() == COLOR_B)
					{
						bCheck = BREAK_YES_PUSH;
						break;
					}
				}
				else if (m_eColor == COLOR_B)
				{
					if ((*iter)->GetColor() == COLOR_W)
					{
						bCheck = BREAK_YES_PUSH;
						break;
					}
					else if ((*iter)->GetColor() == COLOR_B)
					{
						bCheck = BREAK_YES;
						break;
					}
				}
			}
			else
				bCheck = BREAK_NO_PUSH;
		}
		if (bCheck == BREAK_NO_PUSH)
			MovableRange.push_back((*it));
		else if (bCheck == BREAK_YES_PUSH)
		{
			MovableRange.push_back((*it));
			break;
		}
		else
			break;
	}
}


void Bishop::SetMoveRange(vector<Piece*> v)
{
	MovableRange.clear();
	MoveRange.clear();



	/*대각선*/
	this->RangediagonalLine(v);
}

/*Pawn*/

Pawn::Pawn()
{
}

void Pawn::SetImgColor(COLOR color)
{
	m_eColor = color;
	if(m_eColor == COLOR_W)
		m_ePieceType = PIECE_W_PAWN;
	else
		m_ePieceType = PIECE_B_PAWN;
	m_pBitmap = BitmapManager::GetSingleton()->GetPieceImg(m_ePieceType);
}

bool Pawn::FirstCheck()
{
	if (m_eColor == COLOR_W)
	{
		if (pos.y / IMG_HEIGHT == 6)
			return true;
	}
	else
	{
		if (pos.y / IMG_HEIGHT == 1)
			return true;
	}
	return false;
}

void Pawn::SetMoveRange(vector<Piece*> v)
{
	MovableRange.clear();
	MoveRange.clear();


	if (FirstCheck())
	{
		if (m_eColor == COLOR_W)
		{
			MoveRange.push_back(RangePoint(0, - 1 * IMG_HEIGHT));
			MoveRange.push_back(RangePoint(0, - 2 * IMG_HEIGHT));
		}
		else
		{
			MoveRange.push_back(RangePoint(0, 1 * IMG_HEIGHT));
			MoveRange.push_back(RangePoint(0, 2 * IMG_HEIGHT));
		}
	}
	else
	{
		if (m_eColor == COLOR_W)
		{
			MoveRange.push_back(RangePoint(0, -1 * IMG_HEIGHT));
		}
		else
			MoveRange.push_back(RangePoint(0, 1 * IMG_HEIGHT));
	}
	SetMovableRange(v);
}


void Pawn::SetMovableRange(vector<Piece*> v)
{
	MovableRange.push_back(pos);


	bool bCheck = false;

	for (auto it = MoveRange.begin(); it != MoveRange.end(); it++)
	{
		for (auto iter = v.begin(); iter != v.end(); iter++)
		{
			if ((*iter)->GetPos().x == (*it).x && ((*iter)->GetPos().y == (*it).y))
			{
				bCheck = false;
				break;
			}
			else
				bCheck = true;
		}
		if (bCheck == true)
			MovableRange.push_back((*it));

		POINT point;
		for (auto iter = v.begin(); iter != v.end(); iter++)
		{
			if (m_eColor == COLOR_W) // 나중에 대각선 체크 용
			{

				if ((*iter)->GetColor() == COLOR_B)
				{
					if (pos.x - IMG_WIDTH == (*iter)->GetPos().x && pos.y - IMG_HEIGHT == (*iter)->GetPos().y)
					{
						point = { pos.x - IMG_WIDTH , pos.y - IMG_HEIGHT };
						MovableRange.push_back(point);
					}
					else if (pos.x + IMG_WIDTH == (*iter)->GetPos().x && pos.y - IMG_HEIGHT == (*iter)->GetPos().y)
					{
						point = { pos.x + IMG_WIDTH , pos.y - IMG_HEIGHT };
						MovableRange.push_back(point);
					}
				}
			}
			else
			{
				if ((*iter)->GetColor() == COLOR_W)
				{
					if (pos.x - IMG_WIDTH == (*iter)->GetPos().x && pos.y + IMG_HEIGHT == (*iter)->GetPos().y)
					{
						point = { pos.x - IMG_WIDTH , pos.y + IMG_HEIGHT };
						MovableRange.push_back(point);
					}
					else if (pos.x + IMG_WIDTH == (*iter)->GetPos().x && pos.y + IMG_HEIGHT == (*iter)->GetPos().y)
					{
						point = { pos.x + IMG_WIDTH , pos.y + IMG_HEIGHT };
						MovableRange.push_back(point);
					}
				}
			}

		}
	}
}


/*Knight*/


Knight::Knight()
{
}


void Knight::SetImgColor(COLOR color)
{
	m_eColor = color;
	if (m_eColor == COLOR_W)
		m_ePieceType = PIECE_W_KNIGHT;
	else
		m_ePieceType = PIECE_B_KNIGHT;
	m_pBitmap = BitmapManager::GetSingleton()->GetPieceImg(m_ePieceType);
}


void Knight::SetMoveRange(vector<Piece*> v)
{
	MovableRange.clear();
	MoveRange.clear();


	MoveRange.push_back(RangePoint(2*IMG_WIDTH, 1* IMG_HEIGHT));
	MoveRange.push_back(RangePoint(2 * IMG_WIDTH, -1 * IMG_HEIGHT));

	MoveRange.push_back(RangePoint(-2 * IMG_WIDTH, 1 * IMG_HEIGHT));
	MoveRange.push_back(RangePoint(-2 * IMG_WIDTH, -1 * IMG_HEIGHT));

	MoveRange.push_back(RangePoint(1 * IMG_WIDTH, 2 * IMG_HEIGHT));
	MoveRange.push_back(RangePoint(-1 * IMG_WIDTH, 2 * IMG_HEIGHT));

	MoveRange.push_back(RangePoint(1 * IMG_WIDTH, -2 * IMG_HEIGHT));
	MoveRange.push_back(RangePoint(-1 * IMG_WIDTH,-2 * IMG_HEIGHT));



	SetMovableRange(v);
	MoveRange.clear();

}


void Knight::SetMovableRange(vector<Piece*> v)
{
	MovableRange.push_back(pos);

	bool bCheck = false;

	for (auto it = MoveRange.begin(); it != MoveRange.end(); it++)
	{
		for (auto iter = v.begin(); iter != v.end(); iter++)
		{
			if ((*iter)->GetPos().x == (*it).x && ((*iter)->GetPos().y == (*it).y))
			{
				if (m_eColor == COLOR_W)
				{
					if ((*iter)->GetColor() == COLOR_W)
					{
						bCheck = false;
						break;
					}
				}
				else
				{
					if ((*iter)->GetColor() == COLOR_B)
					{
						bCheck = false;
						break;
					}
				}
			}
			else
				bCheck = true;
		}
		if (bCheck == true)
			MovableRange.push_back((*it));
	}
}


/*Rook*/

Rook::Rook()
{

}


void Rook::SetImgColor(COLOR color)
{
	m_eColor = color;
	if (m_eColor == COLOR_W)
		m_ePieceType = PIECE_W_ROOK;
	else
		m_ePieceType = PIECE_B_ROOK;
	m_pBitmap = BitmapManager::GetSingleton()->GetPieceImg(m_ePieceType);
}

void Rook::SetMoveRange(vector<Piece*> v)
{
	MovableRange.clear();
	MoveRange.clear();

	/*가로세로*/

	this->RangelengthWidth(v);
}


void Rook::SetMovableRange(vector<Piece*> v)
{
	MovableRange.push_back(pos);
	BREAK bCheck;


	for (auto it = MoveRange.begin(); it != MoveRange.end(); it++)
	{
		for (auto iter = v.begin(); iter != v.end(); iter++)
		{
			if (((*iter)->GetPos().x == (*it).x && ((*iter)->GetPos().y == (*it).y)))
			{
				if (m_eColor == COLOR_W)
				{
					if ((*iter)->GetColor() == COLOR_W)
					{
						bCheck = BREAK_YES;
						break;
					}
					else if ((*iter)->GetColor() == COLOR_B)
					{
						bCheck = BREAK_YES_PUSH;
						break;
					}
				}
				else if (m_eColor == COLOR_B)
				{
					if ((*iter)->GetColor() == COLOR_W)
					{
						bCheck = BREAK_YES_PUSH;
						break;
					}
					else if ((*iter)->GetColor() == COLOR_B)
					{
						bCheck = BREAK_YES;
						break;
					}
				}
			}
			else
				bCheck = BREAK_NO_PUSH;
		}
		if (bCheck == BREAK_NO_PUSH)
			MovableRange.push_back((*it));
		else if (bCheck == BREAK_YES_PUSH)
		{
			MovableRange.push_back((*it));
			break;
		}
		else
			break;
	}
}

