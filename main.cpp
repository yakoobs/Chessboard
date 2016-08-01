#include <iostream>
#include "src/GameLogic/Game.h"

using namespace std;

int main() {
    cout << "Game started!" << endl;
    Game game = Game();
    game.setupStartingPosition();
    return 0;
}