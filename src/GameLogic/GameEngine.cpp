//
// Created by Kuba Sokolowski on 23/07/2016.
//

#include "GameEngine.h"
#include <iostream>

using namespace std;

void GameEngine::setupStartingPosition() {
    board.setupStartPosition();
    cout << "Starting positions set up!" << endl;
}

MoveResult GameEngine::movePiece(Move move) {
    Piece* pieceFromStartPos = board.pieceFromPosition(move.startPosition);
    if (move.pieceType != (*pieceFromStartPos).pieceType) { return Incorrect_WrongPiece; }

    if (pieceFromStartPos->colour != turn) { return  Incorrect_WrongPieceColour; }

    Piece* pieceOnTheDestinationSqaure = board.pieceFromPosition(move.endPosition);
    bool isSquareOccupied = (pieceOnTheDestinationSqaure != NULL);

    bool isOccupiedByPieceInTheSameColor = (isSquareOccupied && pieceOnTheDestinationSqaure->colour == pieceFromStartPos->colour);
    if (isOccupiedByPieceInTheSameColor) { return Incorrect_SquareOccupied; }

    bool isAttTrajCorrect = pieceFromStartPos->isAttackingTrajectoryCorrect(move.startPosition, move.endPosition);
    if (isSquareOccupied && !isAttTrajCorrect) { return Incorrect_WrongAttackDirection; }

    bool isOccupiedByKing = isSquareOccupied && (pieceOnTheDestinationSqaure->pieceType == PieceType_King);
    if (isOccupiedByKing) { return  Incorrect_CannotCaptureTheKing; }

    bool isMoveTrajCorrect = pieceFromStartPos->isMoveTrajectoryCorrect(move.startPosition, move.endPosition);
    if (!isSquareOccupied && !isMoveTrajCorrect) { return  Incorrect_WrongMoveDirection; }

    board.performMove(move);//Okay, go with it!
    changeTurn();
    return Correct;
}

void GameEngine::changeTurn() {
    turn = (turn == White) ? Black : White;
}
