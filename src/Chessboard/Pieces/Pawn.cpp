//
// Created by Kuba Sokolowski on 11/08/2016.
//

#include "Pawn.h"

Pawn::Pawn(Colour colour) : Piece(PieceTypePawn, colour) {}

bool Pawn::isMoveTrajectoryCorrect(Position start, Position end) {
    int rankDiff = end.rank - start.rank;
    int absFile = end.file - start.file;

    if (isMoved) {
        return (rankDiff == 1) && (absFile == 0);
    }
    //Starting move
    return (rankDiff == 1 || rankDiff == 2) && (absFile == 0);
}

bool Pawn::isAttackingTrajectoryCorrect(Position start, Position end) {
    int rankDiff = end.rank - start.rank;
    int absFile = end.file - start.file;
    return (absFile == 1) && (rankDiff == 1);
}
