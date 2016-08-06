//
// Created by Kuba Sokolowski on 12/07/2016.
//

#ifndef CHESSBOARD_BOARD_H
#define CHESSBOARD_BOARD_H


#include "Square.h"
#include "Move.h"

class Board {
public:
    Board();
    void setupStartPosition();
    void performMove(Move move);

private:
    Square squares[8][8];
    Piece pieceFromSquare(Rank rank, File file);

    void setupPawnsStartingPosition();
    void setupPiecesStartingPosition();
    void placeWhitePiece(Piece piece, File file);
    void placeBlackPiece(Piece piece, File file);
    void placePiece(Piece piece, Rank rank, File file);
    void initializeSquares();
    void makeSquareEmpty(Rank rank, File file);
};


#endif //CHESSBOARD_BOARD_H
