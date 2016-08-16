//
// Created by Kuba Sokolowski on 12/07/2016.
//

#ifndef CHESSBOARD_PIECE_H
#define CHESSBOARD_PIECE_H

#import "../Constants.h"
#import "../Position.h"

class Piece {
public:
    Piece(PieceType pieceType, Colour colour) : pieceType(pieceType), colour(colour) {}
    Piece() {}

    virtual bool isAttackingTrajectoryCorrect(Position start, Position end) { return isMoveTrajectoryCorrect(start, end);}
    virtual bool isMoveTrajectoryCorrect(Position start, Position end) {return false; };
    PieceType pieceType;
    Colour colour;
    bool isMoved = false;
};

#endif //CHESSBOARD_PIECE_H
