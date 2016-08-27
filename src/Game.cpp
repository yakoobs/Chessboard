//
// Created by Kuba Sokolowski on 28/08/2016.
//

#include "Game.h"
#include "Parser/MovesParser.h"
#include "SimpleUI/ChessboardConsolePresenter.h"
#include "GameLogic/GameEngine.h"
#include <iostream>

using namespace std;

void Game::playChess() {
    cout << "GameEngine started!" << endl;
    GameEngine game = GameEngine();
    MovesParser parser = MovesParser();
    ChessboardConsolePresenter presenter = ChessboardConsolePresenter();
    game.setupStartingPosition();
    presenter.presentBoard(game.board);

    Move move = parser.parseMove("e2-e4");
    game.movePiece(move);
    move = parser.parseMove("e7-e5");
    game.movePiece(move);
    move = parser.parseMove("Bf1-b5");
    game.movePiece(move);
    move = parser.parseMove("Qe8-e7");
    game.movePiece(move);
    move = parser.parseMove("Bb5-e7");
    game.movePiece(move);

    presenter.presentBoard(game.board);

    while (!game.gameEnded) {
        cout<< "Type the move encoded with long algebraic notation:"<<endl;
        string encodedMove;
        getline(std::cin, encodedMove);
        Move move = parser.parseMove(encodedMove);
        game.movePiece(move);
        presenter.presentBoard(game.board);
    }
}
