//
// Created by Kuba Sokolowski on 12/07/2016.
//

#ifndef CHESSBOARD_BOARD_H
#define CHESSBOARD_BOARD_H


#include "Square.h"

class Board {
public:
    Board();

    void setupStartPosition();

private:
    Square  squares[8][8];
    void setupPawnsStartingPosition();
    void initializeSquares();
};


#endif //CHESSBOARD_BOARD_H
