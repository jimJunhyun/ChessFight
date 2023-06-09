#pragma once
#include "Structure.h"




class Pieces
{
public:
	Pieces(PIECETYPE type, POS pos, bool isWhite) {
		this->type = type;
		p = pos;
		side = isWhite;
		if (side) {
			maxHp = 1;
			curHp = 1;
		}
		else {
			maxHp = BOSSHP;
			curHp = BOSSHP;
		}
		switch (type)
		{
		case PIECETYPE::PAWN:
			if(side)
				symbol = L'♙';
			else
				symbol = L'♟';
			value = 1;
			break;
		case PIECETYPE::ROOK:
			if (side)
				symbol = L'♖';
			else
				symbol = L'♜';
			value = 5;
			break;
		case PIECETYPE::KNIGHT:
			if (side)
				symbol = L'♘';
			else
				symbol = L'♞';
			value = 3;
			break;
		case PIECETYPE::BISHOP:
			if (side)
				symbol = L'♗';
			else
				symbol = L'♝';
			value = 3;
			break;
		case PIECETYPE::QUEEN:
			if (side)
				symbol = L'♕';
			else
				symbol = L'♛';
			value = 9;
			break;
		case PIECETYPE::KING:
			if (side)
				symbol = L'♔';
			else
				symbol = L'♚';
			value = 20;
			break;
		default:
			symbol = L' ';
			break;
		}
		atk = value * 2;
	}

	POS p;
	PIECETYPE type;

	bool side;

	wchar_t GetSymbol();
	void MoveTo(POS pos);
	bool ShowPreview();
private:
	wchar_t symbol;
	int maxHp;
	int curHp;
	int atk;
	int value;
};

