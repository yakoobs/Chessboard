//
// Created by Kuba Sokolowski on 13/07/2016.
//

#ifndef CHESSBOARD_ENUMS_H
#define CHESSBOARD_ENUMS_H

#endif //CHESSBOARD_ENUMS_H

enum PieceType { King, Queen, Rook, Knight, Bishop, Pawn } ;

enum Colour { Black, White };

enum Rank {
    R1 = 1,
    R2 = 2,
    R3 = 3,
    R4 = 4,
    R5 = 5,
    R6 = 6,
    R7 = 7,
    R8 = 8};

enum File {A, B, C, D, E, F, G, H};

enum PlayerStatus { Normal, Check, Checkmate, Stalemate};