#pragma once

typedef struct position {
	int x;
	int y;
} POS, * PPOS;

enum class PIECETYPE {
	NONE,
	PAWN,
	ROOK,
	KNIGHT,
	BISHOP,
	QUEEN,
	KING
};

static const int BXSIZE = 8;
static const int BYSIZE = 8;