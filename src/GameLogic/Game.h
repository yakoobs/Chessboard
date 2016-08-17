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
    Colour turn = White;
    MoveResult movePiece(Move move);

    void setupStartingPosition();
    void changeTurn();
};


#endif //CHESSBOARD_GAME_H
