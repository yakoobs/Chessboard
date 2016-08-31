//
// Created by Kuba Sokolowski on 11/08/2016.
//

#ifndef CHESSBOARD_MOVESPARSER_H
#define CHESSBOARD_MOVESPARSER_H


#include "../Chessboard/Move.h"
#include <string>

using namespace std;

//Parser uses long algebraic notation (e.g. Bb5xc6, d7xc6, 0-0 Bb4xc3, Ng1-f3, Nb8-c6,)
class MovesParser {
public:
    Move parseMove(string encodedMove);
private:
    PieceType pieceTypeForTheLetter(string letter);
    Rank rankFromTheLetter(string letter);
    File fileFromTheLetter(string letter);
    SpecialMoveType parseSpecialMove(string encodedMove);
    bool isLongCasteling(string encodedMove);
    bool isShortCasteling(string encodedMove);
};

#endif //CHESSBOARD_MOVESPARSER_H
