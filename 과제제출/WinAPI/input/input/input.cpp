#include<windows.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPCTSTR lpszClass = TEXT("Input");

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

TCHAR str[256];
int x = 100;
int y = 100;
int mx = 150, my=150;
RECT rt = { 100,100,400,300 };
bool check = false;

 //1.left, right, up, down 버튼으로 조작하는 원을 만들어보자.
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	int len;

	switch (iMessage)
	{
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			Ellipse(hdc, x, y, x+100, y+100);
			EndPaint(hWnd, &ps);
			return 0;

		case WM_KEYDOWN:

			switch (wParam)
			{
				case VK_LEFT:
					x -= 10;
					break;
				case VK_RIGHT:
					x += 10;
					break;
				case VK_UP:
					y -= 10;
					break;
				case VK_DOWN:
					y += 10;
					break;
			}

			InvalidateRect(hWnd, NULL, TRUE);
		return 0;
		
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

//2.Mouse포인터를 중심으로 따라다니는 원을 만들어 보자.
//LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
//{
//	HDC hdc;
//	PAINTSTRUCT ps;
//
//	switch (iMessage)
//	{
//	case WM_MOUSEMOVE:
//		mx = LOWORD(lParam);
//		my = HIWORD(lParam);
//		InvalidateRect(hWnd, NULL, TRUE);
//		return 0;
//	case WM_PAINT:
//		hdc = BeginPaint(hWnd, &ps);
//		Ellipse(hdc, mx-50,my-50, mx+50,my+50);
//		EndPaint(hWnd, &ps);
//		return 0;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		return 0;
//	}
//	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
//}

//3.Mouse포인터를 중심으로 따라다니는 원을 Rect영역을 만들어서 그 안에서 벗어나지 않고 따라다니는 원을 만들어보자.
//LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
//{
//	HDC hdc;
//	PAINTSTRUCT ps;
//
//	switch (iMessage)
//	{
//	case WM_MOUSEMOVE:
//		mx = LOWORD(lParam);
//		my = HIWORD(lParam);
//		InvalidateRect(hWnd, &rt, TRUE);
//		return 0;
//	case WM_PAINT:
//		hdc = BeginPaint(hWnd, &ps);
//		Ellipse(hdc, mx-50,my-50, mx+50,my+50);
//		EndPaint(hWnd, &ps);
//		return 0;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		return 0;
//	}
//	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
//}


//4.MessageBox를 이용해서 원을 사각형, 사각형을 원으로 바꾸는 것을 만들어보자.
//LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
//{
//	HDC hdc;
//	PAINTSTRUCT ps;
//
//	switch (iMessage)
//	{
//	case WM_LBUTTONDOWN:
//		if (check == false)
//		{
//			if (MessageBox(hWnd, TEXT("원을 사각형으로 변경하겠습니까"), TEXT("MessageBox"), MB_YESNO) == IDYES)
//				check = true;
//		}
//		else
//		{
//			if (MessageBox(hWnd, TEXT("사격형을 원으로 변경하겠습니까"), TEXT("MessageBox"), MB_YESNO) == IDYES)
//				check = false;
//		}
//		InvalidateRect(hWnd, NULL, TRUE);
//		return 0;
//	case WM_PAINT:
//		hdc = BeginPaint(hWnd, &ps);
//		TextOut(hdc, 50, 50, TEXT("좌클릭을 하면 도형이 바뀝니다."), 17);
//		if(check == false)
//			Ellipse(hdc, 220, 100, 320, 200);
//		else
//			Rectangle(hdc, 220, 100, 320, 200);
//		EndPaint(hWnd, &ps);
//		return 0;
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		return 0;
//	}
//	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
//}
