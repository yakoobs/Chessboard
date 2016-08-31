//
// Created by Kuba Sokolowski on 11/08/2016.
//

#ifndef CHESSBOARD_KING_H
#define CHESSBOARD_KING_H


#include "Piece.h"

class King : public Piece {
public:
    King(Colour colour);
    virtual bool isMoveTrajectoryCorrect(Position start, Position end) override;
    virtual string description() override { return  "K"; };
    virtual bool isTheMovePathClear(Move, Board) override;
};


#endif //CHESSBOARD_KING_H
