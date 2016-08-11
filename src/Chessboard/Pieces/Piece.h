//
// Created by Kuba Sokolowski on 12/07/2016.
//

#ifndef CHESSBOARD_PIECE_H
#define CHESSBOARD_PIECE_H

#import "../Constants.h"

struct Piece {
    Piece(PieceType pieceType, Colour colour) : pieceType(pieceType), colour(colour) {}
    Piece() {}

    PieceType pieceType;
    Colour colour;
};


#endif //CHESSBOARD_PIECE_H
