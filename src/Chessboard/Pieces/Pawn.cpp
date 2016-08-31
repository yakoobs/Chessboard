//
// Created by Kuba Sokolowski on 11/08/2016.
//

#include "Pawn.h"
#include "../Move.h"
#include "../Board.h"

Pawn::Pawn(Colour colour) : Piece(PieceType_Pawn, colour) {}

bool Pawn::isMoveTrajectoryCorrect(Position start, Position end) {
    int rankDiff = (colour == White) ? end.rank - start.rank : start.rank - end.rank;
    int fileDiff = end.file - start.file;

    if (isMoved) {
        return (rankDiff == 1) && (fileDiff == 0);
    }
    //Starting move
    return (rankDiff == 1 || rankDiff == 2) && (fileDiff == 0);
}

bool Pawn::isAttackingTrajectoryCorrect(Position start, Position end) {
    int rankDiff = (colour == White) ? end.rank - start.rank : start.rank - end.rank;
    int absFiles = abs(end.file - start.file);

    return (absFiles == 1) && (rankDiff == 1);
}

bool Pawn::isTheMovePathClear(Move, Board) {
    return true;
}
