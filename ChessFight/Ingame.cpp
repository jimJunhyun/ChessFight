#include "pch.h"
#include "Rendering.h"
#include "Ingame.h"
#include "Board.h"

void Starter()
{
	Rendering::GetInst()->RenderStartScreen();
	while (!_kbhit());
	Rendering::GetInst()->EraseAll();
	Board b;
	b.InitSide(true);
	b.InitSide(false);
	Rendering::GetInst()->RenderBoard(b.GetBoardInfo());
}
