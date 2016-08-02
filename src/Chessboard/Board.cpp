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

    for (int file = kStartFile; file <= kLastFile; file++) {
        Position position = Position(kWhitePawnsRank, (File) file);
        PieceType pawnType = Pawn;

        Colour black = Black;

        Colour white = White;


        cout<< "Place pawn" <<endl;
    }
}

Board::Board() {
    for (int rank = kFirstRankIndex; rank < kNumberOfRanks; rank++) {
        for (int file = kFirstFileIndex; file < kNumberOfFiles; file++) {
            squares[rank][file] = Square();
        }
    }
}
