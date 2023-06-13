#include "pch.h"
#include "Rendering.h"
#include "Board.h"


using namespace std;

void Rendering::RenderStartScreen()
{
	HideCur(true, 10);

	_setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L" _______  __   __  _______  _______  _______    _______  ___   _______  __   __  _______ \n";
	wcout << L"|       ||  | |  ||       ||       ||       |  |       ||   | |       ||  | |  ||       |\n";
	wcout << L"|       ||  |_|  ||    ___||  _____||  _____|  |    ___||   | |    ___||  |_|  ||_     _|\n";
	wcout << L"|       ||       ||   |___ | |_____ | |_____   |   |___ |   | |   | __ |       |  |   |  \n";
	wcout << L"|      _||       ||    ___||_____  ||_____  |  |    ___||   | |   ||  ||       |  |   |  \n";
	wcout << L"|     |_ |   _   ||   |___  _____| | _____| |  |   |    |   | |   |_| ||   _   |  |   |  \n";
	wcout << L"|_______||__| |__||_______||_______||_______|  |___|    |___| |_______||__| |__|  |___|  \n";

	wcout << L"\n\n\n";

	SetCurPos(30, 11);
	wcout << L"PRESS ANY KEY TO START\n";
}

void Rendering::EraseAll()
{
	system("cls");
}

void Rendering::RenderBoard( Pieces* board[][BXSIZE], const Pieces& curSel)
{
	for (int y = 0; y < BYSIZE; ++y)
	{
		for (int x = 0; x < BXSIZE; x++)
		{
			SetCurPos(x * 4, y * 2);
			wcout << L"式式式式";
			SetCurPos(x * 4, y * 2 + 1);
			if (board[y][x] != nullptr) {
				wcout << L"| ";
				if ((*board[y][x] == curSel)) {
					SetColor((int)COLOR::RED, (int)COLOR::BLACK);
				}
				wcout << board[y][x]->GetSymbol();
				ResetColor();
			}
			else 
				wcout << L"|  ";
			
		}
		wcout << L" |";
	}
	wcout << endl;
	wcout << L"式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式";
}

void Rendering::RenderPreview(vector<POS> pres)
{
	SetColor((int)COLOR::RED, (int)COLOR::BLACK);
	for (int i = 0; i < pres.size(); ++i)
	{
		SetCurPos(pres[i].x * 4 + 2, pres[i].y * 2 + 1);
		wcout << L"∞";
	}
	ResetColor();
}

void Rendering::RenderPreviewDetail(POS sel)
{
	SetColor((int)COLOR::WHITE, (int)COLOR::RED);
	SetCurPos(sel.x * 4 + 2, sel.y * 2 + 1);
	wcout << L"∞";
	ResetColor();
}



Rendering::Rendering()
{
}

Rendering::~Rendering()
{
}
