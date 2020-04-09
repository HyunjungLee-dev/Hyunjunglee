#include<windows.h>
#include<math.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("Clock");
#define PI 3.141592

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

int x, y;
SYSTEMTIME st;


LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static TCHAR sTime[128];
	int cx = 300;
	int cy = 300;
	int radius = 100;



	switch (iMessage)
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 1000, NULL);
		SendMessage(hWnd, WM_TIMER, 1, 0);
		return 0;
	case WM_TIMER:
		GetLocalTime(&st);
		wsprintf(sTime, TEXT("지금 시간은 %d:%d:%d입니다."),
		st.wHour, st.wMinute, st.wSecond);
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		Ellipse(hdc, 190, 190, 420, 420);
		TextOut(hdc, 200, 450, sTime, lstrlen(sTime));


		for (int i = 1; i <= 12; i++)
		{
			x = cx + sin(2 * PI*i / 12) * radius;
			y = cy + -cos(2 * PI *i / 12) * radius;
			wsprintf(sTime, TEXT("%d"),i);
			TextOut(hdc, x,y, sTime, lstrlen(sTime));
		}

		//x = 시작좌표 + 길이 * sin(각도* PI / 180)
		//y = 시작좌표 + 길이 * -cos(각도 * PI/180)

		//시침
		// 각도 =((hour % 12) + (min / 60)) * 30
		//360/12 -> 30/hour
		MoveToEx(hdc, cx, cy, NULL);      
		LineTo(hdc, int(cx + 55 * sin(((st.wHour % 12) + (st.wMinute / 60.0)) * 30.0 * PI / 180)), int(cy + 55 *  -cos(((st.wHour % 12) + (st.wMinute / 60)) * 30 * PI / 180)));

		//분침
		//각도 = (min + sec / 60) * 6
		// 360/60 -> 6/min
		MoveToEx(hdc, cx, cy, NULL);
		LineTo(hdc, int(cx + 80 *sin((st.wMinute + st.wSecond / 60) * 6* PI / 180)), int(cy + 80 * -cos((st.wMinute + st.wSecond / 60) * 6.0* PI / 180)));

		//초침
		//각도 = sec * 6
		//360/60 -> 6/sec
		MoveToEx(hdc, cx, cy, NULL);
		LineTo(hdc, int(cx + 100 * sin(st.wSecond * 6* PI / 180)), int(cy + 100 * -cos(st.wSecond * 6* PI / 180)));

		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY:
		KillTimer(hWnd, 1);
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}
