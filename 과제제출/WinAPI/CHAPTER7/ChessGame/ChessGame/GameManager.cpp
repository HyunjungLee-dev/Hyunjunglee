#include "GameManager.h"



GameManager::GameManager()
{
	m_iGameTurn = PLAYER_WHITE;
	m_eSelectState = WAIT_SELECTION;
	//m_bCheck = false;
}

void GameManager::Init(HWND hWnd)			// 비트맵 , 체스보드, 각각 플레이어의 기물
{
	BitmapManager::GetSingleton()->Init(hWnd);
	m_Chessbrd.SetPos(0, 0);
	m_player[PLAYER_BLACK].init(0, 0, COLOR_B);
	m_player[PLAYER_WHITE].init(0, 0, COLOR_W);
}

void GameManager::Draw(HDC hdc)
{
	m_Chessbrd.Draw(hdc);
	m_player[PLAYER_BLACK].GetPieceList()->PieceListDraw(hdc);
	m_player[PLAYER_WHITE].GetPieceList()->PieceListDraw(hdc);
	TurnLineDraw(hdc);
}

void GameManager::Message(HWND hWnd)
{
	if (m_eCheck == CHECKMATE)
	{
		TCHAR text[126];
		if (m_iGameTurn == PLAYER_WHITE)
		{
			wsprintf(text, TEXT("흑의 킹이 체크메이트 되었습니다."));
		}
		else
		{
			wsprintf(text, TEXT("백의 킹이 체크메이트 되었습니다."));
		}
		m_eSelectState = END_SELECT;
		InvalidateRect(hWnd, NULL, true);
		if (MessageBox(hWnd, text, TEXT("체크메이트"), MB_OK) == IDOK)
			SendMessage(hWnd, WM_DESTROY, 0, 0);
	}
}

void GameManager::Checkmate()
{
	vector<POINT> Range = m_player[m_iGameTurn].GetSelectPiece()->GetMovableRange();
	POINT p = m_player[m_iGameTurn].GetSelectPiece()->GetPos();

	PLAYER NextP;
	if (m_iGameTurn == PLAYER_WHITE)
	{
		NextP = PLAYER_BLACK;
	}
	else
	{
		NextP = PLAYER_WHITE;
	}

	m_player[NextP].GetPieceList()->SetAllMovable(false);
	for (auto it = Range.begin(); it != Range.end(); it++)
	{
		m_player[NextP].GetPieceList()->CheckAllPieceMovable((*it), MovableRange(), p);
	}


	for (auto it = Range.begin(); it != Range.end(); it++)
	{
		if (m_player[NextP].GetPieceList()->CheckAllPieceMovable())	
			m_eCheck = CHECKING;
		else
			m_eCheck = CHECKMATE;
	}
}

void GameManager::Check()
{
	Piece* SelectPiece = m_player[m_iGameTurn].GetSelectPiece();
	if (SelectPiece == NULL)
		return;
	vector<POINT> Range = m_player[m_iGameTurn].GetSelectPiece()->GetMovableRange();
	PLAYER NextP;
	if (m_iGameTurn == PLAYER_WHITE)
		NextP = PLAYER_BLACK;
	else
		NextP = PLAYER_WHITE;

	for (auto it = Range.begin(); it != Range.end(); it++)
	{
		if (m_player[NextP].GetPieceList()->SearchKing((*it)))	    
		{
			m_eCheck = CHECKED; 
			Checkmate();
			break;
		}
		else
		{
			m_eCheck = NOTCHECK;
		}
	}

	if(m_eCheck == NOTCHECK)
		m_player[NextP].GetPieceList()->SetAllMovable(true);
}

void GameManager::Catch()
{
	RECT rcTemp = { 0 };
	PLAYER NextP;
	if (m_iGameTurn == PLAYER_WHITE)
		NextP = PLAYER_BLACK;
	else
		NextP = PLAYER_WHITE;

	if (m_player[m_iGameTurn].GetSelectPiece() == NULL)
		return;
	m_player[NextP].GetPieceList()->ErasePiece(m_player[m_iGameTurn].GetSelectPiece());
	
}

void GameManager::TurnLineDraw(HDC hdc)
{
	if(m_eSelectState == WAIT_SELECTION)
		m_player[m_iGameTurn].ListLineDraw(hdc);
	else if(m_eSelectState == SELECTING)
		m_player[m_iGameTurn].SelectLineDraw(hdc);
}

vector<Piece*>  GameManager::MovableRange()
{
	vector<Piece*> AllPiece;
	vector<Piece*> BlackPiece = m_player[PLAYER_BLACK].GetPieceList()->GetPieceList();
	vector<Piece*> WhitePiece  = m_player[PLAYER_WHITE].GetPieceList()->GetPieceList();

	AllPiece.insert(AllPiece.end(), BlackPiece.begin(), BlackPiece.end());
	AllPiece.insert(AllPiece.end(), WhitePiece.begin(), WhitePiece.end());

	return AllPiece;
	
}

void GameManager::ClickCheck(POINT point, HWND hWnd)
{
		m_player[m_iGameTurn].CheckPiece(point, MovableRange());
		Catch();
		Check();
		Message(hWnd);
		m_player[m_iGameTurn].GetPieceList()->UpgradePawn();
		if (m_player[m_iGameTurn].GetPieceMove() == SUCCESS)
		{
			m_player[m_iGameTurn].SetNULLSelectPiece();
			if (m_iGameTurn == PLAYER_WHITE)
				m_iGameTurn = PLAYER_BLACK;
			else
				m_iGameTurn = PLAYER_WHITE;
			m_eSelectState = WAIT_SELECTION;
		}
		else if(m_player[m_iGameTurn].GetPieceMove() == RETRY )
			m_eSelectState = WAIT_SELECTION;
		else if (m_player[m_iGameTurn].GetPieceMove() == FAILURE)
			m_eSelectState = SELECTING;
}


void GameManager::GamePlay(HWND hWnd, POINT point)
{
	m_eSelectState = SELECTING;
	ClickCheck(point, hWnd);
	InvalidateRect(hWnd, NULL, true);
}


GameManager::~GameManager()
{
}
