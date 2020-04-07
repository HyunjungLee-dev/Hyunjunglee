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

 //1.left, right, up, down ��ư���� �����ϴ� ���� ������.
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

//2.Mouse�����͸� �߽����� ����ٴϴ� ���� ����� ����.
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

//3.Mouse�����͸� �߽����� ����ٴϴ� ���� Rect������ ���� �� �ȿ��� ����� �ʰ� ����ٴϴ� ���� ������.
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


//4.MessageBox�� �̿��ؼ� ���� �簢��, �簢���� ������ �ٲٴ� ���� ������.
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
//			if (MessageBox(hWnd, TEXT("���� �簢������ �����ϰڽ��ϱ�"), TEXT("MessageBox"), MB_YESNO) == IDYES)
//				check = true;
//		}
//		else
//		{
//			if (MessageBox(hWnd, TEXT("������� ������ �����ϰڽ��ϱ�"), TEXT("MessageBox"), MB_YESNO) == IDYES)
//				check = false;
//		}
//		InvalidateRect(hWnd, NULL, TRUE);
//		return 0;
//	case WM_PAINT:
//		hdc = BeginPaint(hWnd, &ps);
//		TextOut(hdc, 50, 50, TEXT("��Ŭ���� �ϸ� ������ �ٲ�ϴ�."), 17);
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
