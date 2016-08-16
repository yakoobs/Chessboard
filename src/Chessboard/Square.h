//
// Created by Kuba Sokolowski on 12/07/2016.
//

#ifndef CHESSBOARD_SQUARE_H
#define CHESSBOARD_SQUARE_H

#include <iostream>
#include "Pieces/Piece.h"

struct Square {
    Square() {}
    Square(const Position &position) : position(position), piece(NULL) { }

    Position position;
    Piece* piece;
};


#endif //CHESSBOARD_SQUARE_H
