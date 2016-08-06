//
// Created by Kuba Sokolowski on 12/07/2016.
//

#include "Board.h"

using namespace std;

//Constructor
Board::Board() {
    initializeSquares();
}
//Squares initialization
void Board::initializeSquares() {
    for (int rank = kFirstRankIndex; rank <= kNumberOfRanks; rank++) {
        for (int file = kFirstFileIndex; file <= kNumberOfFiles; file++) {
            Position position = Position((Rank) rank, (File) file);
            squares[rank - 1][file - 1] = Square(position);
        }
    }
}

//Setting up starting positions for pawns and pieces
void Board::setupStartPosition() {
    setupPawnsStartingPosition();
    setupPiecesStartingPosition();
}

void Board::setupPawnsStartingPosition() {
    File kStartFile = A;
    File kLastFile = H;
    Rank kWhitePawnsRank = R2;
    Rank kBlackPawnsRank = R7;

    Piece blackPawn = Piece(Pawn, Black);
    Piece whitePawn = Piece(Pawn, White);

    for (int file = kStartFile; file <= kLastFile; file++) {
        placePiece(whitePawn, kWhitePawnsRank, (File) file);
        placePiece(blackPawn, kBlackPawnsRank, (File) file);
    }
}

void Board::setupPiecesStartingPosition() {
    //Rooks
    Piece whiteRook = Piece(Rook, White);
    Piece blackRook = Piece(Rook, Black);
    File kFirstRookFile = A;
    File kSecondRookFile = H;

    placeWhitePiece(whiteRook, kFirstRookFile);
    placeWhitePiece(whiteRook, kSecondRookFile);
    placeBlackPiece(blackRook, kFirstRookFile);
    placeBlackPiece(blackRook, kSecondRookFile);

    //Knights
    Piece whiteKnight = Piece(Knight, White);
    Piece blackKnight = Piece(Knight, Black);
    File kFirstKnightFile = B;
    File kSecondKnightFile = G;

    placeWhitePiece(whiteKnight, kFirstKnightFile);
    placeWhitePiece(whiteKnight, kSecondKnightFile);
    placeBlackPiece(blackKnight, kFirstKnightFile);
    placeBlackPiece(blackKnight, kSecondKnightFile);

    //Bishoprs
    Piece whiteBishop = Piece(Bishop, White);
    Piece blackBishop = Piece(Bishop, Black);
    File kFirstBishopFile = C;
    File kSecondBishopFile = F;

    placeWhitePiece(whiteBishop, kFirstBishopFile);
    placeWhitePiece(whiteBishop, kSecondBishopFile);
    placeBlackPiece(blackBishop, kFirstBishopFile);
    placeBlackPiece(blackBishop, kSecondBishopFile);

    //Queens
    Piece whiteQueen = Piece(Queen, White);
    File kWhiteQueenFile = D;
    placeWhitePiece(whiteQueen, kWhiteQueenFile);

    Piece blackQueen = Piece(Queen, Black);
    File kBlackQueenFile = E;
    placeBlackPiece(blackQueen, kBlackQueenFile);

    //Kings
    Piece whiteKing = Piece(King, White);
    File kWhiteKingFile = E;
    placeWhitePiece(whiteKing, kWhiteKingFile);

    Piece blackKing = Piece(King, Black);
    File kBlackKingFile = D;
    placeBlackPiece(blackKing, kBlackKingFile);
}

Piece Board::pieceFromSquare(Rank rank, File file) {
    return squares[rank - 1][file - 1].piece;
}

void Board::placeWhitePiece(Piece piece, File file) {
    Rank kWhitePiecesRank = R1;
    placePiece(piece, kWhitePiecesRank, file);
}

void Board::placeBlackPiece(Piece piece, File file) {
    Rank kBlackPiecesRank = R8;
    placePiece(piece, kBlackPiecesRank, file);
}

void Board::placePiece(Piece piece, Rank rank, File file) {
    squares[rank - 1][file - 1].piece = piece;
}

void Board::makeSquareEmpty(Rank rank, File file) {
    //&squares[rank - 1][file - 1].piece = NULL;
}

void Board::performMove(Move move) {
    makeSquareEmpty(move.startPosition.rank, move.startPosition.file);
    placePiece(move.piece, move.endPosition.rank, move.endPosition.file);
}




