#include "pch.h"
#include "Board.h"
#include "Rendering.h"

bool Board::IsValidPos(const POS& p, bool playerView)
{
    return p.x < BXSIZE&& p.x >= 0 && p.y < BYSIZE&& p.y >= 0 && (GetBoardCell(p) == nullptr || (playerView != GetBoardCell(p)->side));
}

bool Board::IsOccupiedByEnemy(const POS& p, bool playerView)
{
    return GetBoardCell(p) != nullptr && (playerView != GetBoardCell(p)->side);
}

void Board::Insert(Pieces& piece)
{
    board[piece.p.y][piece.p.x] = &piece;
    if (piece.side)
        pieces.push_back(piece);
}

void Board::Remove(const Pieces& piece)
{
    board[piece.p.y][piece.p.x] = nullptr;
    for (vector<Pieces>::iterator iter = pieces.begin(); iter != pieces.end(); iter++)
    {
        if (((*iter) == (piece))) {
            iter = pieces.erase(iter);
            break;
        }
    }
    if (pieces.empty()) {
        Rendering::GetInst()->SetEndFlag(2);
    }
    else {
        SelectNext();
    }
    
}

vector<POS> Board::PredMove(const Pieces& p)
{
    vector<POS> results;
    if (p.type == PIECETYPE::PAWN) {
        int dir = 1;
        if (p.p.y == 6)
            dir = 2;
        POS predAtkPosL = POS{ p.p.x - 1 , p.p.y - 1 };
        POS predAtkPosR = POS{ p.p.x + 1, p.p.y - 1 };

        if (IsValidPos(predAtkPosL) && IsOccupiedByEnemy(predAtkPosL))
            results.push_back(predAtkPosL);
        if (IsValidPos(predAtkPosR) && IsOccupiedByEnemy(predAtkPosR))
            results.push_back(predAtkPosR);
        for (int i = 1; i <= dir; i++)
        {
            POS predPos = POS{ p.p.x, p.p.y - i };
            if (IsValidPos(predPos) && !IsOccupiedByEnemy(predPos)) {
                results.push_back(predPos);
            }
        }
        

        
        
    }
    if (p.type == PIECETYPE::KNIGHT) {
        int xP = 1; //1 2 2 1 -1 -2 -2 -1
        int yP = 2; //2 1 -1 -2 -2 -1 1 2
        for (int i = 0; i < 8; i++)
        {
            switch (i)
            {
            case 0:
                xP = 1;
                yP = 2;
                break;
            case 1:
                xP = 2;
                yP = 1;
                break;
            case 2:
                xP = 2;
                yP = -1;
                break;
            case 3:
                xP = 1;
                yP = -2;
                break;
            case 4:
                xP = -1;
                yP = -2;
                break;
            case 5:
                xP = -2;
                yP = -1;
                break;
            case 6:
                xP = -2;
                yP = 1;
                break;
            case 7:
                xP = -1;
                yP = 2;
                break;
            }
            POS predPos = POS{ p.p.x + xP, p.p.y - yP };
            if (IsValidPos(predPos)) {
                results.push_back(predPos);
            }
            
        }
    }
    if (p.type == PIECETYPE::BISHOP) {
        int xP = 1;
        int yP = 1;
        for (int i = 0; i < 4; i++)
        {
            switch (i)
            {
            case 0:
                xP = 1;
                yP = 1;
                break;
            case 1:
                xP = 1;
                yP = -1;
                break;
            case 2:
                xP = -1;
                yP = -1;
                break;
            case 3:
                xP = -1;
                yP = 1;
                break;
            }
            POS predPos = p.p;
            while (true) {
                predPos = POS{ predPos.x + xP, predPos.y - yP };
                if (IsValidPos(predPos)) {
                    results.push_back(predPos);
                }
                else
                    break;
                if (IsOccupiedByEnemy(predPos))
                    break;
            }
            
            
        }
    }
    if (p.type == PIECETYPE::ROOK) {
        int xP = 1;
        int yP = 0;
        for (int i = 0; i < 4; i++)
        {
            switch (i)
            {
            case 0:
                xP = 0;
                yP = 1;
                break;
            case 1:
                xP = 1;
                yP = 0;
                break;
            case 2:
                xP = 0;
                yP = -1;
                break;
            case 3:
                xP = -1;
                yP = 0;
                break;
            }
            POS predPos = p.p;
            while (true) {
                predPos = POS{ predPos.x + xP, predPos.y - yP };
                if (IsValidPos(predPos)) {
                    results.push_back(predPos);
                }
                else
                    break;
                if (IsOccupiedByEnemy(predPos))
                    break;
            }
        }
    }
    if (p.type == PIECETYPE::QUEEN) {
        int xP = 1;
        int yP = 0;
        for (int i = 0; i < 8; i++)
        {
            switch (i)
            {
            case 0:
                xP = 0;
                yP = 1;
                break;
            case 1:
                xP = 1;
                yP = 1;
                break;
            case 2:
                xP = 1;
                yP = 0;
                break;
            case 3:
                xP = 1;
                yP = -1;
                break;
            case 4:
                xP = 0;
                yP = -1;
                break;
            case 5:
                xP = -1;
                yP = -1;
                break;
            case 6:
                xP = -1;
                yP = 0;
                break;
            case 7:
                xP = -1;
                yP = 1;
                break;
            }
            POS predPos = p.p;
            while (true) {
                predPos = POS{ predPos.x + xP, predPos.y - yP };
                if (IsValidPos(predPos)) {
                    results.push_back(predPos);
                }
                else
                    break;
                if (IsOccupiedByEnemy(predPos))
                    break;
            }
        }
    }
    if (p.type == PIECETYPE::KING) {
        int xP = 1;
        int yP = 0;
        int minDist = INT_MAX;
        for (int i = 0; i < pieces.size(); i++)
        {
            int dist = abs(p.p.x - pieces[i].p.x) + abs(p.p.y - pieces[i].p.y);
            if (minDist > dist) {
                minDist = dist;
                xP = p.p.x == pieces[i].p.x ? 0 : p.p.x > pieces[i].p.x ? -1 : 1;
                yP = p.p.y == pieces[i].p.y ? 0 : p.p.y > pieces[i].p.y ? -1 : 1;
            }
        }
        POS predPos = POS{ p.p.x + xP, p.p.y + yP };
        if (IsValidPos(predPos, false)) {
            results.push_back(predPos);
        }
        else {
            for (int i = 0; i < 8; i++)
            {
                switch (i)
                {
                case 0:
                    xP = 0;
                    yP = 1;
                    break;
                case 1:
                    xP = 1;
                    yP = 1;
                    break;
                case 2:
                    xP = 1;
                    yP = 0;
                    break;
                case 3:
                    xP = 1;
                    yP = -1;
                    break;
                case 4:
                    xP = 0;
                    yP = -1;
                    break;
                case 5:
                    xP = -1;
                    yP = -1;
                    break;
                case 6:
                    xP = -1;
                    yP = 0;
                    break;
                case 7:
                    xP = -1;
                    yP = 1;
                    break;
                }
                POS predPos = POS{ p.p.x + xP, p.p.y - yP };
                if (IsValidPos(predPos, false)) {
                    results.push_back(predPos);
                }
            }
        }
    }

    return results;
}

void Board::Move(Pieces& move, POS p)
{
    if (IsOccupiedByEnemy(p, move.side)) {
        Pieces enemy = *GetBoardCell(p);
        if (GetBoardCell(p)->Damage(move.GetAttack())) {
            Remove(*GetBoardCell(p));

            board[move.p.y][move.p.x] = nullptr;
            move.p = p;
            board[move.p.y][move.p.x] = &move;
        }
        if (board[move.p.y][move.p.x]->Damage(enemy.GetAttack())) {
            Remove(move);
        }
    }
    else {
        board[move.p.y][move.p.x] = nullptr;
        move.p = p;
        board[move.p.y][move.p.x] = &move;
    }
    CheckPromotion();
}

void Board::InitSide(bool isWhite)
{
    if (isWhite) {
        for (int x = 0; x < 8; x++)
        {
            Insert(*(new Pieces(PIECETYPE::PAWN, POS{ x, 6 }, true))); //폰은 아직 문제가 좀 많음.
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
        EnemyBoss = *(new Pieces(PIECETYPE::KING, POS{ 3, 0 }, false));
        Insert(EnemyBoss);
    }
}

void Board::CheckPromotion()
{
    for (int i = 0; i < BXSIZE; i++)
    {
        if (board[0][i] != nullptr && board[0][i]->type == PIECETYPE::PAWN) {
            board[0][i]->SetType(PIECETYPE::QUEEN);
        }
    }
}
