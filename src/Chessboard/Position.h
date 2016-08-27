//
// Created by Kuba Sokolowski on 12/07/2016.
//

#ifndef CHESSBOARD_POSITION_H
#define CHESSBOARD_POSITION_H

#include "Constants.h"

struct Position {
    Position(Rank rank, File file) : rank(rank), file(file) {}
    Position() {}

    Rank rank; // A-H
    File file; // 1-8
};


#endif //CHESSBOARD_POSITION_H
