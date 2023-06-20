#include "pch.h"
#include "Rendering.h"
#include "Board.h"


using namespace std;

void Rendering::RenderStartScreen()
{
	HideCur(true, 100);

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

void Rendering::RenderEndScreen()
{
	EraseAll();
	wcout << L" _______  ___      _______  _______  ______    __ \n";
	wcout << L"|       ||   |    |       ||   _   ||    _ |  |  |\n";
	wcout << L"|       ||   |    |    ___||  |_|  ||   | ||  |  |\n";
	wcout << L"|       ||   |    |   |___ |       ||   |_||_ |  |\n";
	wcout << L"|      _||   |___ |    ___||       ||    __  ||__|\n";
	wcout << L"|     |_ |       ||   |___ |   _   ||   |  | | __ \n";
	wcout << L"|_______||_______||_______||__| |__||___|  |_||__|\n";
	wcout << L"\n\n\n";
	SetCurPos(24, 11);
	wcout << L"축하합니다.\n";
}

void Rendering::RenderOverScreen()
{
	EraseAll();
	wcout << L" _______  _______  __   __  _______    _______  __   __  _______  ______   \n";
	wcout << L"|       ||   _   ||  |_|  ||       |  |       ||  | |  ||       ||    _ |  \n";
	wcout << L"|    ___||  |_|  ||       ||    ___|  |   _   ||  |_|  ||    ___||   | ||  \n";
	wcout << L"|   | __ |       ||       ||   |___   |  | |  ||       ||   |___ |   |_||_ \n";
	wcout << L"|   ||  ||       ||       ||    ___|  |  |_|  ||       ||    ___||    __  |\n";
	wcout << L"|   |_| ||   _   || ||_|| ||   |___   |       | |     | |   |___ |   |  | |\n";
	wcout << L"|_______||__| |__||_|   |_||_______|  |_______|  |___|  |_______||___|  |_|\n";

	wcout << L"\n\n\n";
	SetCurPos(30, 11);
	wcout << L"패배했습니다.\n";
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
			wcout << L"────";
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
	wcout << L"────────────────────────────────";
}

void Rendering::RenderPreview(vector<POS> pres)
{
	SetColor((int)COLOR::RED, (int)COLOR::BLACK);
	for (int i = 0; i < pres.size(); ++i)
	{
		SetCurPos(pres[i].x * 4 + 2, pres[i].y * 2 + 1);
		wcout << L"o";
	}
	ResetColor();
}

void Rendering::RenderPreviewDetail(POS sel)
{
	SetColor((int)COLOR::WHITE, (int)COLOR::RED);
	SetCurPos(sel.x * 4 + 2, sel.y * 2 + 1);
	wcout << L"o";
	ResetColor();
}

void Rendering::RenderBossHpBar(int amt)
{
	SetCurPos(40, 5);
	wcout << L"보스 체력 : ";
	
	for (int i = 0; i < BOSSHP / 10; i++)
	{
		if (i < amt / 10) {
			SetColor((int)COLOR::RED, (int)COLOR::RED);
			wcout << L"#";
		}
		else {
			SetColor((int)COLOR::RED, (int)COLOR::GRAY);
			wcout << L" ";
		}
	}
	ResetColor();
}


Rendering::Rendering()
{
}

Rendering::~Rendering()
{
}
