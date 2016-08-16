//
// Created by Kuba Sokolowski on 11/08/2016.
//

#ifndef CHESSBOARD_QUEEN_H
#define CHESSBOARD_QUEEN_H


#include "Piece.h"

class Queen: public Piece {
public:
    Queen(Colour colour);
    bool isMoveTrajectoryCorrect(Position start, Position end);
};


#endif //CHESSBOARD_QUEEN_H
