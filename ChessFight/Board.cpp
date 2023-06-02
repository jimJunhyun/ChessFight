#include "pch.h"
#include "Board.h"

bool Board::IsValidPos(const POS& p)
{
    return p.x < BXSIZE&& p.x >= 0 && p.y < BYSIZE&& p.y >= 0 && (GetBoardCell(p) == nullptr || !GetBoardCell(p)->side);
}

void Board::Insert(Pieces& piece)
{
    board[piece.p.y][piece.p.x] = &piece;
}

vector<POS> Board::PredMove(Pieces& p)
{
    vector<POS> results;
    if (p.type == PIECETYPE::PAWN) {
        int dir = 1;
        for (int i = 0; i < 2; i++)
        {
            if (!p.side)
                dir = -1;
            POS predPos = POS{ p.p.x, p.p.y + i * dir };
            if(GetBoardCell(predPos))
            if (IsValidPos(predPos)) {
                results.push_back(predPos);
            }
        }
    }
    if (p.type == PIECETYPE::KNIGHT) {

    }
    if (p.type == PIECETYPE::BISHOP) {

    }
    if (p.type == PIECETYPE::ROOK) {

    }
    if (p.type == PIECETYPE::QUEEN) {

    }
    if (p.type == PIECETYPE::KING) {

    }

    //return new POS{0, 0};
}

void Board::Move(Pieces& move, POS p)
{
}

void Board::InitSide(bool isWhite)
{
    if (isWhite) {
        for (int x = 0; x < 8; x++)
        {
            Insert(*(new Pieces(PIECETYPE::PAWN, POS{ x, 6 }, true)));
        }
        for (int x = 0; x < 8; x++)
        {
            PIECETYPE pType;

            switch (x)
            {
            case 0:
            case 7:
                pType = PIECETYPE::ROOK;
                break;
            case 1:
            case 6:
                pType = PIECETYPE::KNIGHT;
                break;
            case 2:
            case 5:
                pType = PIECETYPE::BISHOP;
                break;
            case 3:
            case 4:
                pType = PIECETYPE::QUEEN;
                break;
            default:
                break;
            }
            Insert(*(new Pieces(pType, POS{ x, 7 }, true)));
            //board[7][x] = ;
        }
    }
    else {
        Insert(*(new Pieces(PIECETYPE::KING, POS{ 3, 0 }, false)));
    }
}
