//
// Created by Kuba Sokolowski on 11/08/2016.
//

#include "Knight.h"
#include <cstdlib>
Knight::Knight(Colour colour) : Piece(PieceTypeKnight, colour) {}

bool Knight::isMoveTrajectoryCorrect(Position start, Position end) {
    int absRanks = abs(end.rank - start.rank);
    int absFiles = abs(end.rank - start.rank);
    return (absRanks == 2 && absFiles == 1) ||  (absRanks == 1 && absFiles == 2);
}
