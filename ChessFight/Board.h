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
		selIdx = 0;
	}

	

	bool IsValidPos(const POS& p);
	bool IsOccupiedByEnemy(const POS& p);
	void Insert(Pieces& piece);
	void Remove(Pieces& piece);
	vector<POS> PredMove(const Pieces& p);
	void Move(Pieces move, POS p);
	void InitSide(bool isWhite);

	void SetDetail(vector<POS> val) { detailPos = val; }

	void SelectNext() { ++selIdx %= pieces.size(); }
	void SelectPrev() { (selIdx += pieces.size() - 1) %= pieces.size(); }

	void SelectNextDetail() { ++selIdxDetail %= detailPos.size(); }
	void SelectPrevDetail() { (selIdxDetail += detailPos.size() - 1) %= detailPos.size(); }

	inline Pieces* (*GetBoardInfo(void))[BXSIZE] {return board; }
	inline Pieces* GetBoardCell(const POS& p) { return board[p.y][p.x]; }
	inline Pieces& GetCurSelPieceAt() { return pieces[selIdx]; }
	inline const POS& GetCurSelDetail() { return detailPos[selIdxDetail]; }
	
private:
	int selIdx;
	int selIdxDetail;
	vector<Pieces> pieces;
	vector<POS> detailPos;
	Pieces* board[BYSIZE][BXSIZE];
};

