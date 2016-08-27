//
// Created by Kuba Sokolowski on 12/07/2016.
//

#ifndef CHESSBOARD_PIECE_H
#define CHESSBOARD_PIECE_H

#include "../Constants.h"
#include "../Position.h"

class Piece {
public:
    Piece(PieceType pieceType, Colour colour) : pieceType(pieceType), colour(colour) {}
    Piece() {}

    bool isMoved = false;
    virtual bool isAttackingTrajectoryCorrect(Position start, Position end) { return isMoveTrajectoryCorrect(start, end);}
    virtual bool isMoveTrajectoryCorrect(Position start, Position end) {return false; };

    PieceType pieceType;
    Colour colour;

    bool operator==(const Piece &rhs) const {
        return pieceType == rhs.pieceType;
    }

    bool operator!=(const Piece &rhs) const {
        return !(rhs == *this);
    }
};


#endif //CHESSBOARD_PIECE_H
