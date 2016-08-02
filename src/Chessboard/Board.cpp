//
// Created by Kuba Sokolowski on 12/07/2016.
//

#include "Board.h"
#include <iostream>

using namespace std;

void Board::setupStartPosition() {
    setupPawnsStartingPosition();
}

void Board::setupPawnsStartingPosition() {
    File kStartFile = A;
    File kLastFile = H;

    Rank kWhitePawnsRank = R2;
    Rank kBlackPawnsRank = R7;

    PieceType pawnType = Pawn;
    Colour black = Black;
    Colour white = White;
    Piece blackPawn = Piece(pawnType,black);
    Piece whitePawn = Piece(pawnType, white);

    for (int file = kStartFile; file <= kLastFile; file++) {
        squares[kWhitePawnsRank - 1][file - 1].piece = whitePawn;
        squares[kBlackPawnsRank - 1][file - 1].piece = blackPawn;
        cout<< "Place pawn" << endl;
    }
}

Board::Board() {
    initializeSquares();
}

void Board::initializeSquares() {
    for (int rank = kFirstRankIndex; rank <= kNumberOfRanks; rank++) {
        for (int file = kFirstFileIndex; file <= kNumberOfFiles; file++) {
            Position position = Position((Rank) rank, (File) file);
            squares[rank - 1][file - 1] = Square(position);
        }
    }
}

