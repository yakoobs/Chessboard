#include <iostream>
#include "src/GameLogic/GameEngine.h"
#include "src/Parser/MovesParser.h"
#include "src/SimpleUI/ChessboardConsolePresenter.h"

using namespace std;

int main() {
    cout << "GameEngine started!" << endl;
    GameEngine game = GameEngine();
    MovesParser parser = MovesParser();
    ChessboardConsolePresenter presenter = ChessboardConsolePresenter();
    game.setupStartingPosition();
    presenter.presentBoard(game.board);
    Move move = parser.parseMove("e2-e4");
    game.movePiece(move);
    presenter.presentBoard(game.board);

    move = parser.parseMove("e7-e5");
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

    return 0;
}