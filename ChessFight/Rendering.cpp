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

void Rendering::RenderBoard(Pieces* board[][BXSIZE])
{
	for (int y = 0; y < BYSIZE; ++y)
	{
		for (int x = 0; x < BXSIZE; x++)
		{
			SetCurPos(x * 4, y * 2);
			wcout << L"式式式式";
			SetCurPos(x * 4, y * 2 + 1);
			if(board[y][x] != nullptr)
				wcout << L"| " << board[y][x]->GetSymbol();
			else 
				wcout << L"|  ";
			
		}
		wcout << L" |";
	}
	wcout << endl;
	wcout << L"式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式";
}



Rendering::Rendering()
{
}

Rendering::~Rendering()
{
}
