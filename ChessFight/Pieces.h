#pragma once
#include "Structure.h"




class Pieces
{
public:
	Pieces(PIECETYPE type, POS pos, bool isWhite) {
		this->type = type;
		p = pos;
		side = isWhite;

		switch (type)
		{
		case PIECETYPE::PAWN:
			if(side)
				symbol = L'♙';
			else
				symbol = L'♟';
			break;
		case PIECETYPE::ROOK:
			if (side)
				symbol = L'♖';
			else
				symbol = L'♜';
			break;
		case PIECETYPE::KNIGHT:
			if (side)
				symbol = L'♘';
			else
				symbol = L'♞';
			break;
		case PIECETYPE::BISHOP:
			if (side)
				symbol = L'♗';
			else
				symbol = L'♝';
			break;
		case PIECETYPE::QUEEN:
			if (side)
				symbol = L'♕';
			else
				symbol = L'♛';
			break;
		case PIECETYPE::KING:
			if (side)
				symbol = L'♔';
			else
				symbol = L'♚';
			break;
		default:
			symbol = L' ';
			break;
		}
	}

	POS p;
	PIECETYPE type;

	bool side;

	wchar_t GetSymbol();
	void MoveTo(POS pos);
	bool ShowPreview();
private:
	wchar_t symbol;
};

