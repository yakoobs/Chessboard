//
// Created by Kuba Sokolowski on 27/08/2016.
//

#ifndef CHESSBOARD_CHESSBOARDCONSOLEPRESENTER_H
#define CHESSBOARD_CHESSBOARDCONSOLEPRESENTER_H


#include "../Chessboard/Board.h"

class ChessboardConsolePresenter {
public:
    void presentBoard(Board);
    void showInitialInfo();
    void showGameInstructions();
};


#endif //CHESSBOARD_CHESSBOARDCONSOLEPRESENTER_H
