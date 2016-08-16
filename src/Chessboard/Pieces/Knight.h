//
// Created by Kuba Sokolowski on 11/08/2016.
//

#ifndef CHESSBOARD_KNIGHT_H
#define CHESSBOARD_KNIGHT_H


#include "Piece.h"

class Knight: public Piece {
public:
    Knight(Colour colour);
    bool isMoveTrajectoryCorrect(Position start, Position end);
};


#endif //CHESSBOARD_KNIGHT_H
