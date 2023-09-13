#include <Windows.h>
#include "Document.h"


#define TID_DROP	1032
void OnCreate(HWND hWnd, CREATESTRUCT* pcs)
{
	Document* doc = Document::GetSingleton();
	doc->MakeDiagram();
	SetTimer(hWnd, TID_DROP, 500, 0);
}
void OnTimer(HWND hWnd, DWORD tid)
{
	Document* doc = Document::GetSingleton();
	if (doc->MoveDown() == false)
	{

	}
	InvalidateRect(hWnd, 0, true);
}
void MoveLeftProc(HWND hWnd)
{
	Document* doc = Document::GetSingleton();
	doc->MoveLeft();
}
void MoveRightProc(HWND hWnd)
{
	Document* doc = Document::GetSingleton();
	doc->MoveRight();
}
void OnKeyDown(HWND hWnd, DWORD key, LPARAM lParam)
{
	switch (key)
	{
	case VK_LEFT: MoveLeftProc(hWnd); break;
	case VK_RIGHT:MoveRightProc(hWnd); break;
	}
	InvalidateRect(hWnd, 0, true);
}
void DrawGameBoard(HWND hWnd, HDC hdc)
{
	HPEN hPen = CreatePen(PS_SOLID, 1, RGB(40, 40, 40));
	HPEN oPen = (HPEN)SelectObject(hdc, hPen);
	for (int r = 0; r <= BOARD_ROW; r++)
	{
		MoveToEx(hdc, BOARD_SX, MY_RY(r), 0);
		LineTo(hdc, MY_RX(BOARD_COL), MY_RY(r));
	}
	for (int c = 0; c <= BOARD_COL; c++)
	{
		MoveToEx(hdc, MY_RX(c), MY_RY(0), 0);
		LineTo(hdc, MY_RX(c), MY_RY(BOARD_ROW));
	}
	SelectObject(hdc, oPen);
	DeleteObject(hPen);
}
void DrawDiagram(HWND hWnd, HDC hdc)
{
	Document* doc = Document::GetSingleton();
	Diagram* now = doc->GetNow();
	int x = now->GetX();
	int y = now->GetY();
	HBRUSH hBrush = CreateSolidBrush(RGB(0, 128, 128));
	HBRUSH oBrush = (HBRUSH)SelectObject(hdc, hBrush);
	Ellipse(hdc, MY_RX(x), MY_RY(y), MY_RX(x + 1) - 1, MY_RY(y + 1) - 1);
	SelectObject(hdc, oBrush);
	DeleteObject(hBrush);
}
void DrawNextBoard(HWND hWnd, HDC hdc)
{
	HPEN hPen = CreatePen(PS_SOLID, 1, RGB(40, 40, 40));
	HPEN oPen = (HPEN)SelectObject(hdc, hPen);
	for (int r = 0; r <= DH; r++)
	{
		MoveToEx(hdc, NEXT_SX, MY_NRY(r), 0);
		LineTo(hdc, MY_NRX(DH), MY_NRY(r));
	}
	for (int c = 0; c <= DW; c++)
	{
		MoveToEx(hdc, MY_NRX(c), MY_NRY(0), 0);
		LineTo(hdc, MY_NRX(c), MY_NRY(DW));
	}
	SelectObject(hdc, oPen);
	DeleteObject(hPen);
}
void DrawNextDiagram(HWND hWnd, HDC hdc)
{

}

void OnDraw(HWND hWnd, HDC hdc)
{
	DrawGameBoard(hWnd, hdc);
	DrawDiagram(hWnd, hdc);
	DrawNextBoard(hWnd, hdc);
	DrawNextDiagram(hWnd, hdc);
}
void OnPaint(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hWnd, &ps);
	OnDraw(hWnd, hdc);
	EndPaint(hWnd, &ps);
}
void OnDestroy(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	PostQuitMessage(0);
}
LRESULT CALLBACK MainProc(HWND hWnd, UINT iMessage,
	WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_CREATE: OnCreate(hWnd, (CREATESTRUCT*)lParam); return 0;
	case WM_TIMER: OnTimer(hWnd, (DWORD)wParam); return 0;
	case WM_KEYDOWN: OnKeyDown(hWnd, (DWORD)wParam, lParam); return 0;
	case WM_PAINT: OnPaint(hWnd); return 0;
	case WM_DESTROY: OnDestroy(hWnd, wParam, lParam); return 0;
	}
	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}
INT APIENTRY WinMain(HINSTANCE hIns,
	HINSTANCE hPrev, LPSTR cmd, INT nShow)
{
	WNDCLASS wndclass = { 0 };
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.style = CS_DBLCLKS;
	wndclass.lpfnWndProc = MainProc;
	wndclass.lpszClassName = TEXT("테트리스");
	wndclass.hCursor = LoadCursor(0, IDC_ARROW);
	wndclass.hIcon = LoadIcon(0, IDI_APPLICATION);
	wndclass.hInstance = hIns;

	RegisterClass(&wndclass);
	HWND hWnd = CreateWindow(TEXT("테트리스"),
		TEXT("테트리스"),
		WS_OVERLAPPEDWINDOW,
		100, 100, 410, 400,
		0,
		0,
		hIns,
		0);
	ShowWindow(hWnd, nShow);
	MSG Message;
	while (GetMessage(&Message, 0, 0, 0))
	{
		DispatchMessage(&Message);
	}
	return 0;
}