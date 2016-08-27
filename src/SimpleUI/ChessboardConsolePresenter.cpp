//
// Created by Kuba Sokolowski on 27/08/2016.
//

#include "ChessboardConsolePresenter.h"
#include <algorithm>
#include <string>

using namespace std;

void ChessboardConsolePresenter::presentBoard(Board board) {
    for (int rank = kNumberOfRanks; rank >= kFirstRankIndex; rank--) {
        for (int file = kFirstFileIndex; file <= kNumberOfFiles; file++) {
            Piece* piece = board.pieceFromPosition(Position((Rank)rank,(File)file));

            if (piece != NULL) {
                string desc = piece ->description();
                string lowerDesc = desc;
                transform(lowerDesc.begin(), lowerDesc.end(), lowerDesc.begin(), ::tolower);
                string simbol = (piece->colour == White) ? "(" + lowerDesc + ")" : " " + desc + " ";
                cout<< simbol;
            } else {
                cout<< " - ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}
