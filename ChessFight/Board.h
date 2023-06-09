#pragma once
#include "Pieces.h"

class Board
{
public:
	Board() {
		for (int y = 0; y < BYSIZE; y++)
		{
			for (int x = 0; x < BXSIZE; x++)
			{
				board[y][x] = nullptr;
			}
		}
	}

	

	bool IsValidPos(const POS& p);
	bool IsOccupiedByEnemy(const POS& p);
	void Insert(Pieces& piece);
	void Remove(Pieces& piece);
	vector<POS> PredMove(Pieces& p);
	void Move(Pieces& move, POS p);
	void InitSide(bool isWhite);

	inline Pieces* (*GetBoardInfo(void))[BXSIZE] {return board; }
	inline Pieces* GetBoardCell(const POS& p) { return board[p.y][p.x]; }

	
private:
	Pieces* board[BYSIZE][BXSIZE];
};

