//
// Created by Kuba Sokolowski on 11/08/2016.
//

#ifndef CHESSBOARD_KNIGHT_H
#define CHESSBOARD_KNIGHT_H


#include "Piece.h"

class Knight: public Piece {
public:
    Knight(Colour colour);
    virtual bool isMoveTrajectoryCorrect(Position start, Position end) override;
    virtual string description() override { return  "N"; };
    virtual bool isTheMovePathClear(Move, Board) override;
};


#endif //CHESSBOARD_KNIGHT_H
