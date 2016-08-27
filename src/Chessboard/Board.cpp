//
// Created by Kuba Sokolowski on 12/07/2016.
//

#include "Board.h"
#include "Pieces/Pawn.h"
#include "Pieces/King.h"
#include "Pieces/Queen.h"
#include "Pieces/Bishop.h"
#include "Pieces/Knight.h"
#include "Pieces/Rook.h"

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

    for (int file = kStartFile; file <= kLastFile; file++) {
        placePiece(new Pawn(White), kWhitePawnsRank, (File) file);
        placePiece(new Pawn(Black), kBlackPawnsRank, (File) file);
    }
}

void Board::setupPiecesStartingPosition() {
    //Rooks
    File kFirstRookFile = A;
    File kSecondRookFile = H;

    placeWhitePiece(new Rook(White), kFirstRookFile);
    placeWhitePiece(new Rook(White), kSecondRookFile);
    placeBlackPiece(new Rook(Black), kFirstRookFile);
    placeBlackPiece(new Rook(Black), kSecondRookFile);

    //Knights
    File kFirstKnightFile = B;
    File kSecondKnightFile = G;

    placeWhitePiece(new Knight(White), kFirstKnightFile);
    placeWhitePiece(new Knight(White), kSecondKnightFile);
    placeBlackPiece(new Knight(Black), kFirstKnightFile);
    placeBlackPiece(new Knight(Black), kSecondKnightFile);

    //Bishoprs
    File kFirstBishopFile = C;
    File kSecondBishopFile = F;

    placeWhitePiece(new Bishop(White), kFirstBishopFile);
    placeWhitePiece(new Bishop(White), kSecondBishopFile);
    placeBlackPiece(new Bishop(Black), kFirstBishopFile);
    placeBlackPiece(new Bishop(Black), kSecondBishopFile);

    //Queens
    File kWhiteQueenFile = D;
    placeWhitePiece(new Queen(White), kWhiteQueenFile);

    File kBlackQueenFile = E;
    placeBlackPiece(new Queen(Black), kBlackQueenFile);

    //Kings
    File kWhiteKingFile = E;
    placeWhitePiece(new King(White), kWhiteKingFile);

    File kBlackKingFile = D;
    placeBlackPiece(new King(Black), kBlackKingFile);
}

Piece* Board::pieceFromPosition(Position position){
    return squares[position.rank - 1][position.file - 1].piece;
}

void Board::placeWhitePiece(Piece* piece, File file) {
    Rank kWhitePiecesRank = R1;
    placePiece(piece, kWhitePiecesRank, file);
}

void Board::placeBlackPiece(Piece* piece, File file) {
    Rank kBlackPiecesRank = R8;
    placePiece(piece, kBlackPiecesRank, file);
}

void Board::placePiece(Piece *piece, Rank rank, File file) {
    squares[rank - 1][file - 1].piece = piece;
}

//MOVE
void Board::movePiece(Position from, Position to) {
    Piece* piece = squares[from.rank - 1][from.file - 1].piece;
    squares[to.rank - 1][to.file - 1].piece = piece;
    squares[from.rank - 1][from.file - 1].piece = NULL;
}

void Board::performMove(Move move) {
    movePiece(move.startPosition, move.endPosition);
}

//CAPTURE
void Board::capturePieceAtPosition(Position position) {
     delete squares[position.rank -1][position.file -1].piece; // Should I remove this in such dirty way?
    squares[position.rank -1][position.file -1].piece = NULL;
}




