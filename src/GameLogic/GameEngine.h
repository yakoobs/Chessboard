//
// Created by Kuba Sokolowski on 23/07/2016.
//

#ifndef CHESSBOARD_GAMEENGINE_H
#define CHESSBOARD_GAMEENGINE_H


#include "../Chessboard/Board.h"

class GameEngine {
public:
    Board board;
    Colour turn = White;
    MoveResult movePiece(Move move);

    void setupStartingPosition();
    void changeTurn();
    bool gameEnded = false;
};


#endif //CHESSBOARD_GAMEENGINE_H
