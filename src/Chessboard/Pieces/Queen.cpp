//
// Created by Kuba Sokolowski on 11/08/2016.
//

#include "Queen.h"
#include <cstdlib>
#include "../Move.h"
#include "../Board.h"

Queen::Queen(Colour colour) : Piece(PieceType_Queen, colour) {}

bool Queen::isMoveTrajectoryCorrect(Position start, Position end) {
    int absRanks = abs(end.rank - start.rank);
    int absFiles = abs(end.file - start.file);

    bool isCorrectDiagonalMove = (absRanks == absFiles) && absRanks != 0;
    bool isCorrectStraightMove = (absRanks > 0 && absFiles == 0) || (absRanks == 0 && absFiles > 0);

    return isCorrectDiagonalMove || isCorrectStraightMove;
}

bool Queen::isMoveCorrect(Move, Board) {
    return true;
}
