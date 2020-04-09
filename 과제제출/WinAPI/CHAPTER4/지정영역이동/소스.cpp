#include <windows.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void CALLBACK TimeProc(HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("timer");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPervlnstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}

int x = 250;
int y = 250;
int flag = 0;

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static TCHAR sTime[128];

	switch (iMessage)
	{
	case WM_CREATE:
		SetTimer(hwnd, 1, 50, TimeProc);
		SendMessage(hwnd, WM_TIMER, 1, 0);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		Ellipse(hdc, x, y, x+50, y+50);
		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		KillTimer(hwnd, 1);
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hwnd, iMessage, wParam, lParam));
}

void CALLBACK TimeProc(HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
	RECT myRect = { 200, 200, 500, 500 };

	switch (flag)
	{
	case 0:
		x+=10;
		if (myRect.right <= x + 50)
			flag = 1;
		break;

	case 1:
		y+=10;
		if (myRect.bottom <= y + 50)
			flag = 2;
		break;

	case 2:
		x-=10;
		if (myRect.left >= x)
			flag = 3;
		break;

	case 3:
		y-=10;
		if (myRect.top >= y)
			flag = 0;
		break;

	}
	InvalidateRect(hwnd, &myRect, TRUE);
}
