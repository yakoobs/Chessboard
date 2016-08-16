//
// Created by Kuba Sokolowski on 11/08/2016.
//

#ifndef CHESSBOARD_BISHOP_H
#define CHESSBOARD_BISHOP_H


#include "Piece.h"

class Bishop: public Piece {
public:
    Bishop(Colour colour);
    bool isMoveTrajectoryCorrect(Position start, Position end);
};


#endif //CHESSBOARD_BISHOP_H
