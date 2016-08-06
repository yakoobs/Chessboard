//
// Created by Kuba Sokolowski on 23/07/2016.
//

#include "Game.h"
#include <iostream>

using namespace std;

void Game::setupStartingPosition() {
    board.setupStartPosition();
    cout << "Starting positions set up!" << endl;

    //Take first move just in test case
    Position start = Position(R2, E);
    Position end = Position(R3, E);
    Piece piece = Piece(Pawn, White);
    Move move = Move(start, end, piece);
    board.performMove(move);

}
