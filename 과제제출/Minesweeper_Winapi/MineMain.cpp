#include"GameManager.h"
#include"resource.h"
INT_PTR CALLBACK EndDlgProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK WinDlgProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK OptionDlgProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("지뢰 찾기");

GameManager g_game;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPervlnstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;
	RECT rt = { 0, 0, 870 ,530 };
	srand((unsigned int)time(NULL));
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, false);
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(g_hInst, MAKEINTRESOURCE(IDI_MINE));
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);
	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, rt.right - rt.left, rt.bottom - rt.top, NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	g_game.Init(hWnd);
	HACCEL hAccel;
	hAccel = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDR_ACCELERATOR1));
	while (true)
	{
		if (PeekMessage(&Message, NULL, 0, 0, PM_REMOVE))
		{
			if (Message.message == WM_QUIT)
				break;
			if (!TranslateAccelerator(hWnd, hAccel, &Message))
			{
				TranslateMessage(&Message);
				DispatchMessage(&Message);
			}
		}
		else
		{
			g_game.Update();
			if (g_game.StateCheck() == GAME_DIE)
				DialogBox(g_hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, EndDlgProc);
			else if (g_game.StateCheck() == GAME_WIN)
				DialogBox(g_hInst, MAKEINTRESOURCE(IDD_DIALOG2), hWnd, WinDlgProc);
		}

	}
	return (int)Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	 POINT pos;
	 pos.x = LOWORD(lParam);
	 pos.y = HIWORD(lParam);


	switch (iMessage)
	{
	case WM_LBUTTONDOWN:
		g_game.Collision(pos);
		return 0;
	case WM_RBUTTONDOWN:
		g_game.PutFlag(pos);
		return 0;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_HELP:
			ShellExecute(NULL, TEXT("open"), TEXT("https://support.microsoft.com/hub/4338813/windows-help"), NULL,NULL, SW_SHOW);
			break;
		case ID_ANOTHER:
			ShellExecute(NULL, TEXT("open"), TEXT("https://www.microsoft.com/ko-kr/store/games/windows"), NULL, NULL, SW_SHOW);
			break;
		case ID_NEW:
			g_game.ReStart(GAME_RESET);
			break;
		case ID_OPTION:
			DialogBox(g_hInst, MAKEINTRESOURCE(IDD_DIALOG3), hWnd, OptionDlgProc);
			break;
		case ID_EXIT:
			PostQuitMessage(0);
		}
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}


void SetText(HWND hDlg, GAMESTATE state)
{

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	TCHAR str[128];

	if (state == GAME_WIN)
	{

		if (g_game.Getbestsec())
		{
			wsprintf(str, TEXT("이 난이도에서 최고 기록을 세웠습니다."));
			SetDlgItemText(hDlg, IDC_BESTMES, str);
		}
		wsprintf(str, TEXT("시간: %d초"), g_game.GetSecTime());
		SetDlgItemText(hDlg, IDC_MES2, str);

		if(tm.tm_mon + 1 < 10)
			wsprintf(str, TEXT("날짜: %d-0%d-%d"), tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
		else
			wsprintf(str, TEXT("날짜: %d-%d-%d"), tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
		SetDlgItemText(hDlg, IDC_DAY, str);


		wsprintf(str, TEXT("게임 횟수: %d"), g_game.GetRecord().PlayNum);
		SetDlgItemText(hDlg, IDC_PLAYNUM2, str);

		wsprintf(str, TEXT("이긴 게임 횟수: %d"), g_game.GetRecord().WinNum);
		SetDlgItemText(hDlg, IDC_WINNUM2, str);

		wsprintf(str, TEXT("승률: %d%%"), g_game.GetRecord().winrate);
		SetDlgItemText(hDlg, IDC_WINRATE2, str);

		wsprintf(str, TEXT("최고 기록: %d%초"), g_game.GetBestSec());
		SetDlgItemText(hDlg, IDC_BEST, str);
	}
	else if (state == GAME_DIE)
	{
		wsprintf(str, TEXT("시간: %d초"), g_game.GetSecTime());
		SetDlgItemText(hDlg, IDC_MES, str);

		wsprintf(str, TEXT("게임 횟수: %d"), g_game.GetRecord().PlayNum);
		SetDlgItemText(hDlg, IDC_PLAYNUM1, str);

		wsprintf(str, TEXT("이긴 게임 횟수: %d"), g_game.GetRecord().WinNum);
		SetDlgItemText(hDlg, IDC_WINNUM1, str);

		wsprintf(str, TEXT("승률: %d%%"), g_game.GetRecord().winrate);
		SetDlgItemText(hDlg, IDC_WINRATE1, str);
	}
}

INT_PTR CALLBACK OptionDlgProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static LEVEL level;
	static bool check;
	static int Editnum;

	EnableWindow(GetDlgItem(hDlg, IDC_MINETEXT), check);
	EnableWindow(GetDlgItem(hDlg, IDC_EDIT1), check);
	Editnum = GetDlgItemInt(hDlg, IDC_EDIT1, NULL, NULL);
	switch (uMsg)
	{
	case WM_INITDIALOG:
		CheckRadioButton(hDlg, IDC_RADIO1, IDC_RADIO4, IDC_RADIO1);
		check = false;
		return (INT_PTR)TRUE;
	case WM_COMMAND:
		switch (wParam)
		{
		case IDC_RADIO1:
			level = BEGINNER;
			check = false;
			break;
		case IDC_RADIO2:
			level = INTERMEDIATE;
			check = false;
			break;
		case IDC_RADIO3:
			level = ADVANCED;
			check = false;
			break;
		case IDC_RADIO4:
			check = true;
			level = CUSTOM;
			break;
		case IDOK:
			if (level == CUSTOM)
			{
				if(Editnum > 400 || Editnum < 10)
					return (INT_PTR)TRUE;
				g_game.SetMinenum(Editnum);
			}
			g_game.Setlevel(level);
			g_game.ReStart(GAME_RESET);
			EndDialog(hDlg, 0);
			return (INT_PTR)TRUE;
		case IDCANCEL:
			EndDialog(hDlg, 0);
			return (INT_PTR)TRUE;
		}
	}
	return(INT_PTR)FALSE;
}

INT_PTR CALLBACK EndDlgProc( HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

	switch (uMsg)
	{
	case WM_INITDIALOG:
		SetText(hDlg, GAME_DIE);
		return (INT_PTR)TRUE;
	case WM_COMMAND:
		switch (wParam)
		{
		case IDC_BUTTON1:
			PostQuitMessage(0);
			return (INT_PTR)TRUE;
		case IDC_BUTTON2:
			g_game.ReStart(GAME_REPLAY);
			EndDialog(hDlg, 0);
			return (INT_PTR)TRUE;
		case IDC_BUTTON3:
			g_game.ReStart(GAME_RESET);
			EndDialog(hDlg, 0);
			return (INT_PTR)TRUE;
		}
	}
	return(INT_PTR)FALSE;
}



INT_PTR CALLBACK WinDlgProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

	switch (uMsg)
	{
	case WM_INITDIALOG:
		SetText(hDlg, GAME_WIN);
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		switch (wParam)
		{
		case IDC_WINBUTTON1:
			PostQuitMessage(0);
			return (INT_PTR)TRUE;
		case IDC_WINBUTTON2:
			g_game.ReStart(GAME_RESET);
			EndDialog(hDlg, 0);
			return (INT_PTR)TRUE;
		}
	}
	return (INT_PTR)FALSE;
}