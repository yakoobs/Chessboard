//
// Created by Kuba Sokolowski on 28/08/2016.
//

#include "Game.h"
#include <iostream>

using namespace std;

void Game::playChess() {
    presenter.showInitialInfo();
    game.setupStartingPosition();
    presenter.presentBoard(game.board);

    performExampleOpeningMoves();

    while (!game.gameEnded) {
        presenter.showGameInstructions();
        string encodedMove;
        getline(std::cin, encodedMove);
        Move move = parser.parseMove(encodedMove);
        game.movePiece(move);
        presenter.presentBoard(game.board);
    }
}

//TODO: This is method just for test purposes
void Game::performExampleOpeningMoves() {
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
}



