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
		selIdxDetail = 0;

		EnemyBoss = Pieces();
	}

	

	bool IsValidPos(const POS& p, bool playerView = true);
	bool IsOccupiedByEnemy(const POS& p, bool playerView = true);
	void Insert(Pieces& piece);
	void Remove(const Pieces& piece);
	vector<POS> PredMove(const Pieces& p);
	void Move(Pieces& move, POS p);
	void InitSide(bool isWhite);

	void SetDetail(vector<POS> val) { detailPos = val; }

	void SelectNext() { ++selIdx %= pieces.size(); }
	void SelectPrev() { (selIdx += pieces.size() - 1) %= pieces.size(); }
	void SelectFirst() { selIdx = 0; }
	void SelectLast() { selIdx = pieces.size() - 1; }


	void ResetDetail() { selIdxDetail = 0; }
	void SelectNextDetail() { ++selIdxDetail %= detailPos.size(); }
	void SelectPrevDetail() { (selIdxDetail += detailPos.size() - 1) %= detailPos.size(); }

	void CheckPromotion();

	inline Pieces* (*GetBoardInfo(void)) [BXSIZE] {return board; }
	inline Pieces* GetBoardCell(const POS& p) { return board[p.y][p.x]; }
	inline Pieces* GetCurSelPieceAt() { return pieces[selIdx]; }
	inline const POS& GetCurSelDetail() { return detailPos[selIdxDetail]; }
	inline Pieces& GetEnemyBossAt() { return EnemyBoss; }
	
private:
	int selIdx;
	int selIdxDetail;
	vector<Pieces*> pieces;
	Pieces EnemyBoss;
	vector<POS> detailPos;
	Pieces* board[BYSIZE][BXSIZE];
};

