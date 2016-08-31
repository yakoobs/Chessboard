//
// Created by Kuba Sokolowski on 23/07/2016.
//

#include "GameEngine.h"
#include <iostream>

using namespace std;

void GameEngine::setupStartingPosition() {
    board.setupStartPosition();
}

MoveResult GameEngine::movePiece(Move move) {
    Piece* pieceFromStartPos = board.pieceFromPosition(move.startPosition);
    if (move.pieceType != (*pieceFromStartPos).pieceType) { return Incorrect_WrongPiece; }

    if (pieceFromStartPos->colour != turn) { return  Incorrect_WrongPieceColour; }

    Piece* pieceOnTheDestinationSqaure = board.pieceFromPosition(move.endPosition);
    bool isSquareOccupied = (pieceOnTheDestinationSqaure != NULL);

    bool isOccupiedByPieceInTheSameColor = (isSquareOccupied && pieceOnTheDestinationSqaure->colour == pieceFromStartPos->colour);
    if (isOccupiedByPieceInTheSameColor) { return Incorrect_SquareOccupied; }

    bool isOccupiedByKing = isSquareOccupied && (pieceOnTheDestinationSqaure->pieceType == PieceType_King);
    if (isOccupiedByKing) { return  Incorrect_CannotCaptureTheKing; }

    bool isAttTrajCorrect = pieceFromStartPos->isAttackingTrajectoryCorrect(move.startPosition, move.endPosition);
    bool isMoveTrajCorrect = pieceFromStartPos->isMoveTrajectoryCorrect(move.startPosition, move.endPosition);

    if (isSquareOccupied && !isAttTrajCorrect) { return Incorrect_WrongAttackDirection; }
    else if (!isSquareOccupied && !isMoveTrajCorrect) { return  Incorrect_WrongMoveDirection; }

    if(!pieceFromStartPos->isTheMovePathClear(move, board)) { return  Incorrect_CannotMoveThroughOtherPieces; };

    board.performMove(move);//Okay, go with it!
    pieceFromStartPos->isMoved = true;
    changeTurn();
    return Correct;
}

void GameEngine::changeTurn() {
    turn = (turn == White) ? Black : White;
}
