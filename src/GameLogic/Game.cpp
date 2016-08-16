//
// Created by Kuba Sokolowski on 23/07/2016.
//

#include "Game.h"
#include <iostream>

using namespace std;

void Game::setupStartingPosition() {
    board.setupStartPosition();
    cout << "Starting positions set up!" << endl;
}

MoveResult Game::isMoveCorrect(Move move) {
    return Incorrect_KingChecked;
}
