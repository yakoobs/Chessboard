//
// Created by Kuba Sokolowski on 27/08/2016.
//

#include "ChessboardConsolePresenter.h"
#include <algorithm>
#include <string>

using namespace std;

void ChessboardConsolePresenter::presentBoard(Board board) {
    cout<<endl;
    for (int rank = kNumberOfRanks; rank >= kFirstRankIndex; rank--) {
        for (int file = kFirstFileIndex; file <= kNumberOfFiles; file++) {
            Piece* piece = board.pieceFromPosition(Position((Rank)rank,(File)file));

            if (piece != NULL) {
                string desc = piece->description();
                string lowerDesc = desc;
                transform(lowerDesc.begin(), lowerDesc.end(), lowerDesc.begin(), ::tolower);
                string simbol = (piece->colour == Black) ? "(" + lowerDesc + ")" : " " + desc + " ";
                cout<< simbol;
            } else {
                cout<< " - ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

void ChessboardConsolePresenter::showInitialInfo() {
    cout<< "Chessboard 0.1 by Jakub Sokołowski" << endl;
}

void ChessboardConsolePresenter::showGameInstructions() {
    cout<< "Type the move in the long algebraic notation (Nb1-c3, e2-e4 etc.):" << endl;
}

void ChessboardConsolePresenter::showDescriptionForIncorrectMove(MoveResult result) {
    switch (result) {
        case Incorrect_ThereIsNoPiece:
            cout<< "There is no piece on the initial-starting position"<<endl;
            break;
        case Incorrect_WrongAttackDirection:
            cout<< "This peace cannot attack in this way, in this direction" <<endl;
            break;
        case Incorrect_WrongPiece:
            cout<< "There is no such piece on starting position" << endl;
            break;
        case Incorrect_WrongPieceColour:
            cout<< "It's not your turn. Other colour of the piece should be moved"<<endl;
            break;
        case Incorrect_KingChecked:
            cout<< "Incorrect move. King is under check"<<endl;
            break;
        case Incorrect_SquareOccupied:
            cout<< "The square is occupied by your piece. Cannot capture your own piece"<<endl;
            break;
        case Incorrect_CannotCaptureTheKing:
            cout<< "Cannot capture the king" << endl;
            break;
        case Incorrect_PositionOutOfRange:
            cout<< "Oh come on! Position is out of the board" <<endl;
            break;
        case Incorrect_CannotMoveThroughOtherPieces:
            cout<< "Cannot move through other pieces. Path must be clear"<<endl;
            break;
        case Incorrect_WrongMoveDirection:
            cout<< "Cannot move in this direction"<<endl;
            break;
        default:
            cout<< "Unknown error" <<endl;
    }
    cout<< "Type the move and try again:"<<endl;
}