//
// Created by Kuba Sokolowski on 12/07/2016.
//

#ifndef CHESSBOARD_MOVE_H
#define CHESSBOARD_MOVE_H

#include "Position.h"

struct Move {
    Move(Position start, Position end, PieceType pieceType) : startPosition(start), endPosition(end), pieceType(pieceType) {}

    Position startPosition;
    Position endPosition;
    PieceType pieceType;
};


#endif //CHESSBOARD_MOVE_H
