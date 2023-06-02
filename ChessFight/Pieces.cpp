#include "pch.h"
#include "Pieces.h"

wchar_t Pieces::GetSymbol()
{
	return symbol;
}

void Pieces::MoveTo(POS pos)
{
	p = pos;
}

bool Pieces::ShowPreview()
{
	return false;
}
