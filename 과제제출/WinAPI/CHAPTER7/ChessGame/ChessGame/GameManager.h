#pragma once
#include"ChessBoard.h"
#include"Player.h"
class GameManager
{
	ChessBoard m_Chessbrd;
	Player  m_player[PLAYER_END];
	PLAYER m_iGameTurn;
	SELECT m_eSelectState;
public:
	void Init(HWND hWnd);
	void Draw(HDC hdc);
	void TurnLineDraw(HDC hdc);
	void ClickCheck(POINT point, HWND hWnd);
	void Catch();
	void Check(HWND hWnd);
	void GamePlay(HWND hWnd, POINT point);
	vector<Piece*> MovableRange();
	GameManager();
	~GameManager();
};

