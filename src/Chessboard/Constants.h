//
// Created by Kuba Sokolowski on 13/07/2016.
//

#ifndef CHESSBOARD_ENUMS_H
#define CHESSBOARD_ENUMS_H

#endif //CHESSBOARD_ENUMS_H

const int kFirstRankIndex = 1;
const int kNumberOfRanks = 8;
const int kFirstFileIndex = 1;
const int kNumberOfFiles = 8;

enum PieceType { PieceType_King,
    PieceType_Queen,
    PieceType_Rook,
    PieceType_Knight,
    PieceType_Bishop,
    PieceType_Pawn,
    PieceType_Unknown
} ;

enum Colour { Black, White };

enum Rank {
    R1 = 1,
    R2 = 2,
    R3 = 3,
    R4 = 4,
    R5 = 5,
    R6 = 6,
    R7 = 7,
    R8 = 8,
    Rank_Unknown
};

enum File {
    A = 1,
    B = 2,
    C = 3,
    D = 4,
    E = 5,
    F = 6,
    G = 7,
    H = 8,
    File_Unknown
};

enum MoveResult {
    Correct,
    Incorrect_ThereIsNoPiece,
    Incorrect_WrongAttackDirection,
    Incorrect_WrongPiece,
    Incorrect_WrongPieceColour,
    Incorrect_KingChecked,
    Incorrect_SquareOccupied,
    Incorrect_CannotCaptureTheKing,
    Incorrect_PositionOutOfRange,
    Incorrect_CannotMoveThroughOtherPieces,
    Incorrect_WrongMoveDirection,
    Incorrect_Unknown
};

enum SpecialMoveType {SpecialMoveType_ShortCasteling, SpecialMoveType_LongCasteling, SpecialMoveType_Promotion, SpecialMoveType_None};

enum PlayerStatus { Normal, Check, Checkmate, Stalemate};
