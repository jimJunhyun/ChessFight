#include "pch.h"
#include "Pieces.h"
#include "Board.h"
#include "Rendering.h"

void Pieces::MoveTo(POS pos)
{
	p = pos;
}

bool Pieces::Damage(int dam)
{
	curHp -= dam;
	if(!side)
		Rendering::GetInst()->RenderBossHpBar(curHp);
	if (curHp <= 0) {
		if (!side) {
			//클리어
		}
		
		return true;
	}
	return false;
}

void Pieces::SetType(PIECETYPE type)
{
	this->type = type;
	switch (type)
	{
	case PIECETYPE::PAWN:
		if (side)
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
