//
// Created by Kuba Sokolowski on 11/08/2016.
//

#include "Rook.h"
#include <cstdlib>

Rook::Rook(Colour colour) : Piece(PieceType_Rook, colour) {}

bool Rook::isMoveTrajectoryCorrect(Position start, Position end) {
    int absRanks = abs(end.rank - start.rank);
    int absFiles = abs(end.file - start.file);
    return (absRanks > 0 && absFiles == 0) || (absRanks == 0 && absFiles > 0);
}
