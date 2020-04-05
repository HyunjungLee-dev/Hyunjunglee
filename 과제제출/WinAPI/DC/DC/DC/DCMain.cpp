#include<windows.h>
#include<math.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("TextOut");

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


void MyCircle(HDC hdc, int x, int y, int r) // 삼각함수 이용
{
	double pi = 3.141592;

	for (int i = 0; i < 360; i++)
	{
		SetPixel(hdc, x + int(sin(i*pi / 180)*r), y + int(cos(i*pi / 180)*r), RGB(0, 255, 0));
	}
}

void MyEllipse(HDC hdc, int x, int y, int rx, int ry) // 삼각함수 이용
{
	double pi = 3.141592;

	for (int i = 0; i < 360; i++)
	{
		SetPixel(hdc, x + int(sin(i*pi / 180)*rx), y + int(cos(i*pi / 180)*ry), RGB(255, 0, 0));
	}
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;


	switch (iMessage) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		MoveToEx(hdc, 150, 90, NULL);
		LineTo(hdc, 200, 100);
		LineTo(hdc, 150, 110);
		LineTo(hdc, 200, 120);
		LineTo(hdc, 150, 130);

		Rectangle(hdc, 15, 50, 90, 80);
		Ellipse(hdc, 220, 100, 400, 200);

		MyCircle(hdc, 200, 300, 60);
		MyEllipse(hdc, 100, 200, 50, 80);
		EndPaint(hWnd, &ps);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}