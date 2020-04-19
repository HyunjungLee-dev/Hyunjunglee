#pragma once
#include"CardManager.h"

typedef struct _Time
{
	int  hour;
	int min;
	int sec;
	int plustime;
}Time;

class CardMatchGame
{
private:
	MATCH m_iCardCount;
	CardManager m_CardManager;
	RECT m_StartbuttonRect;
	RECT m_TimeRect;
	TCHAR sTime[128];
	bool m_bGameStart;
	Time m_PlayTime;
public:
	void Init(HWND hWnd, HINSTANCE hInst);
	void Draw(HDC hdc);
	void StartGame(HWND hWnd, POINT point);
	void PlayGame(HWND hWnd, POINT point);
	void TimeCloseCard(HWND hWnd);
	void PlayTime(HWND hWnd);
	CardMatchGame();
	~CardMatchGame();
};

