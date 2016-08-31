//
// Created by Kuba Sokolowski on 11/08/2016.
//

#ifndef CHESSBOARD_QUEEN_H
#define CHESSBOARD_QUEEN_H


#include "Piece.h"

class Queen: public Piece {
public:
    Queen(Colour colour);
    virtual bool isMoveTrajectoryCorrect(Position start, Position end) override;
    virtual string description() override { return  "Q"; };
};


#endif //CHESSBOARD_QUEEN_H
