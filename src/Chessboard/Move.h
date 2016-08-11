//
// Created by Kuba Sokolowski on 12/07/2016.
//

#ifndef CHESSBOARD_MOVE_H
#define CHESSBOARD_MOVE_H

#include "Pieces/Piece.h"
#include "Position.h"

struct Move {
    Move(Position start, Position end, Piece piece): startPosition(start), endPosition(end), piece(piece) {}

    Position startPosition;
    Position endPosition;
    Piece piece;
};


#endif //CHESSBOARD_MOVE_H
