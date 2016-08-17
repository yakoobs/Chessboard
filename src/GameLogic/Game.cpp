//
// Created by Kuba Sokolowski on 23/07/2016.
//

#include "Game.h"
#include <iostream>

using namespace std;

void Game::setupStartingPosition() {
    board.setupStartPosition();
    cout << "Starting positions set up!" << endl;
}

MoveResult Game::movePiece(Move move) {
    //Check whether piece from the move is the same as at the starting position.
    if (move.piece != *board.pieceFromPosition(move.startPosition)) { return Incorrect_WrongPiece; }

    //Check whether piece colour is the same as the current turn colour.
    if (move.piece.colour != turn) { return  Incorrect_WrongPieceColour; }


    Piece* pieceOnTheDestinationSqaure = board.pieceFromPosition(move.endPosition);

    bool isSquareOccupied = (pieceOnTheDestinationSqaure != NULL);

    //Check whether piece destination square is occupied by the other of the player's pieces.
    bool isOccupiedByPieceInTheSameColor = (isSquareOccupied && pieceOnTheDestinationSqaure->colour == move.piece.colour);
    if (isOccupiedByPieceInTheSameColor) { return Incorrect_SquareOccupied; }

    //Check whether piece on the destination square can be attacked
    bool isAttTrajCorrect = move.piece.isAttackingTrajectoryCorrect(move.startPosition, move.endPosition);
    if (isSquareOccupied && !isAttTrajCorrect) { return Incorrect_WrongAttackDirection; }

    //Chceck whether piece on the destination square is the king
    bool isOccupiedByKing = isSquareOccupied && (pieceOnTheDestinationSqaure->pieceType == PieceTypeKing);
    if (isOccupiedByKing) { return  Incorrect_CannotCaptureTheKing; }

    //Check whether piece can simply move
    bool isMoveTrajCorrect = move.piece.isMoveTrajectoryCorrect(move.startPosition, move.endPosition);
    if (!isSquareOccupied && !isMoveTrajCorrect) { return  Incorrect_WrongMoveDirection; }


    //Perform move as a correct one
    board.performMove(move);
    changeTurn();
    return Correct;
}

void Game::changeTurn() {
    turn = (turn == White) ? Black : White;
}
