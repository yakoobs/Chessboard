//
// Created by Kuba Sokolowski on 11/08/2016.
//

#include "Bishop.h"
#include <cstdlib>

Bishop::Bishop(Colour colour) : Piece(PieceType_Bishop, colour) {}

bool Bishop::isMoveTrajectoryCorrect(Position start, Position end) {
    int absRanks = abs(end.rank - start.rank);
    int absFiles = abs(end.file - start.file);
    return (absRanks == absFiles) && absRanks != 0;
}
