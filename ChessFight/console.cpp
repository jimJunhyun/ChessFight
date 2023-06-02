#include "pch.h"
#include "console.h"


void FullScreen() {
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, NULL);
}

void SetCurPos(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

BOOL SetCurPosTest(int x, int y)
{
	COORD pos = { x, y };
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void HideCur(bool visiblity, DWORD size)
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = !visiblity;
	info.dwSize = size;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void SetColor(int col, int bgndCol)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col | (bgndCol << 4));
}

int GetColor()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	
	return info.wAttributes & 0xf;
}

int GetBGColor()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

	return (info.wAttributes & 0xf) >> 4;
}

void ResetColor() {
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
}

void FontSize(UINT wgh, UINT x, UINT y)
{
	static CONSOLE_FONT_INFOEX info;

	info.cbSize = sizeof(info);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	info.FontWeight = wgh;
	info.dwFontSize.X = x;
	info.dwFontSize.Y = y;
	
}

