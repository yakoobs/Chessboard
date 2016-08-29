//
// Created by Kuba Sokolowski on 11/08/2016.
//

#include <cstdlib>
#include <algorithm>
#include "King.h"
#include "../Move.h"
#include "../Board.h"

using namespace std;

King::King(Colour colour) : Piece(PieceType_King, colour) {}

bool King::isMoveTrajectoryCorrect(Position start, Position end) {
    int absRanks = abs(end.rank - start.rank);
    int absFiles = abs(end.file - start.file);
    int kCorrectKingsMoveDiff = 1;
    return max(absFiles,absRanks) == kCorrectKingsMoveDiff;
}

bool King::isMoveCorrect(Move, Board) {
    return true;
}
