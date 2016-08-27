//
// Created by Kuba Sokolowski on 27/08/2016.
//

#include "ChessboardConsolePresenter.h"

void ChessboardConsolePresenter::presentBoard(Board board) {
    for (int rank = kNumberOfRanks; rank >= kFirstRankIndex; rank--) {
        for (int file = kFirstFileIndex; file <= kNumberOfFiles; file++) {
            Piece* piece = board.pieceFromPosition(Position((Rank)rank,(File)file));

            if (piece != NULL) {
                string desc = piece ->description();
                string simbol = (piece->colour == White) ? "[" + desc + "]" : "(" + desc + ")";
                cout<< simbol;
            } else {
                cout<< " - ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}
