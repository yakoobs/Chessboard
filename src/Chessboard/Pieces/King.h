//
// Created by Kuba Sokolowski on 11/08/2016.
//

#ifndef CHESSBOARD_KING_H
#define CHESSBOARD_KING_H


#import "Piece.h"

class King : public Piece {
public:
    King(Colour colour);
    virtual bool isMoveTrajectoryCorrect(Position start, Position end) override;
};


#endif //CHESSBOARD_KING_H
