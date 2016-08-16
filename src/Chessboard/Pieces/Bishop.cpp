//
// Created by Kuba Sokolowski on 11/08/2016.
//

#include "Bishop.h"
#include <cstdlib>

Bishop::Bishop(Colour colour) : Piece(PieceTypeBishop, colour) {}

bool Bishop::isMoveTrajectoryCorrect(Position start, Position end) {
    int absRanks = abs(end.rank - start.rank);
    int absFiles = abs(end.rank - start.rank);
    return (absRanks == absFiles) && absRanks != 0;
}
