//
// Created by Kuba Sokolowski on 12/07/2016.
//

#ifndef CHESSBOARD_SQUARE_H
#define CHESSBOARD_SQUARE_H


#include "Position.h"
#include "Piece.h"

struct Square {
    Position position;
    Piece piece;
};


#endif //CHESSBOARD_SQUARE_H
