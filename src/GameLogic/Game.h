//
// Created by Kuba Sokolowski on 23/07/2016.
//

#ifndef CHESSBOARD_GAME_H
#define CHESSBOARD_GAME_H


#include "../Chessboard/Board.h"

class Game {
private:
    Board board;

public:
    MoveResult isMoveCorrect(Move move);
    void setupStartingPosition();
};


#endif //CHESSBOARD_GAME_H
