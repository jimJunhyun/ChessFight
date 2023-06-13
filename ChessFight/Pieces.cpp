#include "pch.h"
#include "Pieces.h"
#include "Board.h"

void Pieces::MoveTo(POS pos)
{
	p = pos;
}

void Pieces::Damage(int dam)
{
	curHp -= dam;
	if (curHp <= 0) {
		if (!side) {
			//Å¬¸®¾î
		}
	}
}
