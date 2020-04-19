#include "CardMatchGame.h"



CardMatchGame::CardMatchGame()
{
	m_iCardCount = MATCH_FIRST;
	m_StartbuttonRect = { 200,200,400,300 };
	m_TimeRect = { 200, 560, 350,580 };
	m_bGameStart = false;
	m_PlayTime = { 0, 0 ,0,0 };
}

void CardMatchGame::Init(HWND hWnd, HINSTANCE hInst)
{
	BitmapManager::GetSingleton()->Init(hWnd, hInst);
	m_CardManager.Init();
}

void CardMatchGame::Draw(HDC hdc)
{
	if (m_bGameStart == false)
	{
		Rectangle(hdc, m_StartbuttonRect.left, m_StartbuttonRect.top, m_StartbuttonRect.right, m_StartbuttonRect.bottom);
		SetTextAlign(hdc, TA_CENTER);
		TextOut(hdc, 580*0.52, 580 * 0.4, TEXT("Card Match Game"), 15);
		TextOut(hdc, (m_StartbuttonRect.left + m_StartbuttonRect.right)/2,(m_StartbuttonRect.top+m_StartbuttonRect.bottom)/2, TEXT("Game Start"), 10);
	}
	else
	{
	
		DrawText(hdc, sTime, -1, &m_TimeRect, DT_CENTER | DT_WORDBREAK);
		m_CardManager.DrawCardList(hdc);
	}
}

void CardMatchGame::StartGame(HWND hWnd, POINT point)
{
	if (m_bGameStart == false)
	{
		InvalidateRect(hWnd, NULL, true);
		if (PtInRect(&m_StartbuttonRect, point) == true)
		{
			SetTimer(hWnd, 2, 1000, NULL);
			m_bGameStart = true;
		}
	}
	else
	{
		PlayGame(hWnd, point);
	}

}

void CardMatchGame::PlayGame(HWND hWnd, POINT point)
{	
	if (m_CardManager.AllCardCheck(point, m_iCardCount) == true)
	{
		switch (m_iCardCount)
		{
		case MATCH_FIRST:
			InvalidateRect(hWnd, &m_CardManager.GetMatchIndex(m_iCardCount)->GetCardRect(), true);
			m_iCardCount = MATCH_SECOND;
			break;
		case MATCH_SECOND:
			InvalidateRect(hWnd, &m_CardManager.GetMatchIndex(m_iCardCount)->GetCardRect(), true);
			if (!m_CardManager.MatchCard())
			{
				m_iCardCount = MATCH_ING;
				SetTimer(hWnd, 1, 1000, NULL);
			}
			else
			{
				m_iCardCount = MATCH_FIRST;
				if (m_CardManager.AllMatchClear() == true)
				{
					TCHAR text[126];
					wsprintf(text, TEXT("게임 클리어 \n걸린 시간  %d시간 %d분 %d초"),m_PlayTime.hour, m_PlayTime.min, m_PlayTime.sec);
					if (MessageBox(hWnd, text, TEXT("카드매치"), MB_OK) == IDOK)
						SendMessage(hWnd, WM_DESTROY, 0, 0);
				}
			}
			break;
		default:
			break;
		}

	}
}


void CardMatchGame::TimeCloseCard(HWND hWnd)
{
	m_CardManager.MatchCardClose();
	InvalidateRect(hWnd, &m_CardManager.GetMatchIndex(MATCH_FIRST)->GetCardRect(), true);
	InvalidateRect(hWnd, &m_CardManager.GetMatchIndex(MATCH_SECOND)->GetCardRect(), true);
	m_iCardCount = MATCH_FIRST;
}

void CardMatchGame::PlayTime(HWND hWnd)
{
	wsprintf(sTime, TEXT("Play Time  %d:%d:%d"),
		m_PlayTime.hour, m_PlayTime.min, m_PlayTime.sec);
	InvalidateRect(hWnd, NULL, TRUE);


	m_PlayTime.plustime++;
	m_PlayTime.sec = m_PlayTime.plustime % 60;
	m_PlayTime.min = m_PlayTime.plustime / 60 % 60;
	m_PlayTime.hour = m_PlayTime.plustime / 3600;

}

CardMatchGame::~CardMatchGame()
{
}
