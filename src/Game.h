//
// Created by Kuba Sokolowski on 28/08/2016.
//

#ifndef CHESSBOARD_GAME_H
#define CHESSBOARD_GAME_H

#include "Parser/MovesParser.h"
#include "SimpleUI/ChessboardConsolePresenter.h"
#include "GameLogic/GameEngine.h"

class Game {
public:
    void playChess();

private:
    GameEngine game = GameEngine();
    MovesParser parser = MovesParser();
    ChessboardConsolePresenter presenter = ChessboardConsolePresenter();

    void performExampleOpeningMoves();
};


#endif //CHESSBOARD_GAME_H
