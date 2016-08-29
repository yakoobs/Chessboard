//
// Created by Kuba Sokolowski on 12/07/2016.
//

#ifndef CHESSBOARD_PIECE_H
#define CHESSBOARD_PIECE_H

#include <string>
#include "../Position.h"

using namespace std;

class Board;
struct Move;

class Piece {
public:
    Piece(PieceType pieceType, Colour colour) : pieceType(pieceType), colour(colour) {}

    virtual bool isAttackingTrajectoryCorrect(Position start, Position end) { return isMoveTrajectoryCorrect(start, end); }
    virtual bool isMoveTrajectoryCorrect(Position, Position) = 0;
    virtual string description() = 0;
    virtual bool isMoveCorrect(Move, Board) = 0;
    bool isMoved = false;
    PieceType pieceType = PieceType_Unknown;
    Colour colour;
};


#endif //CHESSBOARD_PIECE_H
