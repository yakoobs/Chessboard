//
// Created by Kuba Sokolowski on 12/07/2016.
//

#ifndef CHESSBOARD_MOVE_H
#define CHESSBOARD_MOVE_H

#include "Piece.h"
#include "Position.h"

struct Move {
    Position startPosition;
    Position endPosition;
    Piece piece;
};


#endif //CHESSBOARD_MOVE_H
