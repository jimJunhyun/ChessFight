#pragma once

#define BOSSHP			100

typedef struct position {
	int x;
	int y;

	bool operator==(const position& r) {
		return this->x == r.x && this->y == r.y;
	}

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