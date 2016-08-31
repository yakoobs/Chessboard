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
    presenter.showGameInstructions();

//TODO: This is method just for test purposes
//    performExampleOpeningMoves();

    while (!game.gameEnded) {
        try
        {
            string encodedMove;
            getline(std::cin, encodedMove);
            Move move = parser.parseMove(encodedMove);
            MoveResult result = game.movePiece(move);
            if (result == Correct) {
                presenter.presentBoard(game.board);
                presenter.showGameInstructions();
            } else {
                presenter.showDescriptionForIncorrectMove(result);
            }
        }
        catch(std::exception& e)
        {
            std::cout << "Cannot parse your move, try again with correct long algebraic notation: " << std::endl;
        }

    }
}



//TODO: This is method just for test purposes
void Game::performExampleOpeningMoves() {
    Move move = parser.parseMove("e2-e4");
    game.movePiece(move);
    move = parser.parseMove("d7-d5");
    game.movePiece(move);
    move = parser.parseMove("Bf1-b5");
    game.movePiece(move);
    move = parser.parseMove("Qe8-e7");
    game.movePiece(move);
    move = parser.parseMove("Bb5-e7");
    game.movePiece(move);
    presenter.presentBoard(game.board);
}



