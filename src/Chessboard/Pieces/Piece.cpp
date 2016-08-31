//
// Created by Kuba Sokolowski on 31/08/2016.
//
#include "Piece.h"
#include "../Move.h"
#include "../Board.h"

//This implementation is valid for queens, rooks and bishops - other pieces just should return true
//It checks whether there are any pieces on the route between queen's/rook's/bishop's start and destination positions
bool Piece::isTheMovePathClear(Move move, Board board) {
    bool goRightFromStartRankPosition = (move.startPosition.file < move.endPosition.file);
    bool goLeftFromStartRankPosition = (move.startPosition.file > move.endPosition.file);
    bool goUpFromStartRankPosition = (move.startPosition.rank < move.endPosition.rank);
    bool goDownFromStartRankPosition = (move.startPosition.rank > move.endPosition.rank);

    Rank sRank = move.startPosition.rank;
    File sFile = move.startPosition.file;
    if (goRightFromStartRankPosition){ sFile = (File) (sFile + 1); }
    else if (goLeftFromStartRankPosition) { sFile = (File) (sFile - 1); }

    if (goUpFromStartRankPosition) { sRank = (Rank) (sRank + 1); }
    else if (goDownFromStartRankPosition) { sRank = (Rank) (sRank - 1); }

    while (sRank != move.endPosition.rank || sFile != move.endPosition.file) {
        if (board.pieceFromPosition(Position(sRank,sFile)) != NULL) {
            return false;
        }

        if (goRightFromStartRankPosition){ sFile = (File) (sFile + 1); }
        else if (goLeftFromStartRankPosition) { sFile = (File) (sFile - 1); }

        if (goUpFromStartRankPosition) { sRank = (Rank) (sRank + 1); }
        else if (goDownFromStartRankPosition) { sRank = (Rank) (sRank - 1); }
    }
    return true;
}
