//
// Created by Kuba Sokolowski on 11/08/2016.
//

#ifndef CHESSBOARD_PAWN_H
#define CHESSBOARD_PAWN_H


#include "Piece.h"

class Pawn: public Piece {
public:
    Pawn(Colour colour);
    virtual bool isMoveTrajectoryCorrect(Position start, Position end) override ;
    virtual bool isAttackingTrajectoryCorrect(Position start, Position end) override ;
    virtual string description() override { return  "P"; };
    virtual bool isMoveCorrect(Move, Board) override;
};


#endif //CHESSBOARD_PAWN_H
