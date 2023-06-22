#include "pch.h"
#include "Buttons.h"
#include "Board.h"

Buttons::Buttons(Board* board, const POS& pos, BUTTONTYPE type, int dam)
{
	b = board;
	p = pos;
	switch (type)
	{
	case BUTTONTYPE::ATTACKBOSS:
		onPressed = [=]() {
			(*b).GetEnemyBossAt().Damage(dam);
		};
		icon = L'➳';
		break;
	case BUTTONTYPE::DAMAGETRAP:
		onPressed = [=]() {
			(*b).GetBoardCell(p)->Damage(dam);
		};
		icon = L'☠';
		break;
	default:
		break;
	}
	
}

Buttons::~Buttons()
{
	
}

bool Buttons::CheckPieceOn()
{
	if ((*b).GetBoardCell(p) != nullptr) {
		onPressed();
		return true;
	}
	return false;
}
