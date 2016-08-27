#include <iostream>
#include "src/GameLogic/GameEngine.h"
#include "src/Parser/MovesParser.h"

using namespace std;

int main() {
    cout << "GameEngine started!" << endl;
    GameEngine game = GameEngine();
    MovesParser parser = MovesParser();

    game.setupStartingPosition();
    while (!game.gameEnded) {
        cout<< "Type the move encoded with long algebraic notation:"<<endl;
        string encodedMove;
        getline(std::cin, encodedMove);
        Move move = parser.parseMove(encodedMove);
        game.movePiece(move);
    }

    return 0;
}