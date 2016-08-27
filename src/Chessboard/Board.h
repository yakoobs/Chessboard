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
    void capturePieceAtPosition(Position position);
    Piece* pieceFromPosition(Position position);


private:
    Square squares[kNumberOfRanks][kNumberOfFiles];

    void setupPawnsStartingPosition();
    void setupPiecesStartingPosition();
    void placeWhitePiece(Piece piece, File file);
    void placeBlackPiece(Piece piece, File file);
    void placePiece(Piece piece, Rank rank, File file);
    void initializeSquares();
    void movePiece(Position from, Position to);
};


#endif //CHESSBOARD_BOARD_H
