#pragma once
#include <Windows.h>

enum class COLOR {
	BLACK,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET, 
	YELLOW,
	LGRAY,
	GRAY,
	LBLUE,
	LGREEN,
	MINT, 
	LRED,
	LVIOLET,
	LYELLOW,
	WHITE
};

void FullScreen();
void SetCurPos(int , int);
BOOL SetCurPosTest(int, int);
void HideCur(bool, DWORD);
void SetColor(int, int);
int GetColor();
int GetBGColor();
void ResetColor();
void FontSize(UINT wgh, UINT x, UINT y);