#include "pch.h"
#include "Pieces.h"
#include "Board.h"

wchar_t Pieces::GetSymbol()
{
	return symbol;
}

void Pieces::MoveTo(POS pos)
{
	p = pos;
}
