//
// Created by Kuba Sokolowski on 12/07/2016.
//

#ifndef CHESSBOARD_BOARD_H
#define CHESSBOARD_BOARD_H


#include "Square.h"

class Board {
    Square  squares[64];
public:
    void setupStartPosition();
};


#endif //CHESSBOARD_BOARD_H
