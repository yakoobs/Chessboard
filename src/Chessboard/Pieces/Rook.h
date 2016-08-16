//
// Created by Kuba Sokolowski on 11/08/2016.
//

#ifndef CHESSBOARD_ROOK_H
#define CHESSBOARD_ROOK_H


#include "Piece.h"

class Rook: public Piece {
public:
    Rook(Colour colour);
    virtual bool isMoveTrajectoryCorrect(Position start, Position end);
};

#endif //CHESSBOARD_ROOK_H
