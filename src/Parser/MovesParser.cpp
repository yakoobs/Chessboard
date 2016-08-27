//
// Created by Kuba Sokolowski on 11/08/2016.
//

#include "MovesParser.h"
#include "../Chessboard/Pieces/Piece.h"
#include <string>

using namespace std;

Move MovesParser::parseMove(string encodedMove) {
    int numberOfCharacters = encodedMove.size();
    int kPieceMoveStringLength = 6;
    int kPawnMoveStringLength = 5;

    string kShortCastelingString = "O-O";
    string kLongCastelingString = "O-O-O";

    int len = encodedMove.length();

    Position startPosition;
    Position endPosition;
    int kFirstCharacterIndex = 0;
    PieceType pieceType = PieceType_Pawn;

    if (len == kPieceMoveStringLength){
        string pieceTypeCharacter = encodedMove.substr(kFirstCharacterIndex,1);
        pieceType = pieceTypeForTheLetter(pieceTypeCharacter);
        kFirstCharacterIndex = 1;
    }

    size_t kStartFileIndex = kFirstCharacterIndex;
    size_t kStartRankIndex = kFirstCharacterIndex +1;
    size_t kEndFileIndex = kFirstCharacterIndex +3;
    size_t kEndRankIndex = kFirstCharacterIndex +4;

    string starFileCharacter = encodedMove.substr(kStartFileIndex, 1);
    string startRankCharacter = encodedMove.substr(kStartRankIndex, 1);
    startPosition.file = fileFromTheLetter(starFileCharacter);
    startPosition.rank = rankFromTheLetter(startRankCharacter);

    string endFileCharacter = encodedMove.substr(kEndFileIndex, 1);
    string endRankCharacter = encodedMove.substr(kEndRankIndex, 1);
    endPosition.file = fileFromTheLetter(endFileCharacter);
    endPosition.rank = rankFromTheLetter(endRankCharacter);

    return Move(startPosition, endPosition, pieceType);
}

PieceType MovesParser::pieceTypeForTheLetter(string letter) {
    if(letter.compare("K") == 0) { return PieceType_King; }
    if(letter.compare("Q") == 0) { return PieceType_Queen; }
    if(letter.compare("R") == 0) { return PieceType_Rook; }
    if(letter.compare("N") == 0) { return PieceType_Knight; }
    if(letter.compare("B") == 0) { return PieceType_Bishop; }
    return PieceType_Unknown;
}

Rank MovesParser::rankFromTheLetter(string letter) {
    if(letter.compare("1") == 0) { return R1; }
    if(letter.compare("2") == 0) { return R2; }
    if(letter.compare("3") == 0) { return R3; }
    if(letter.compare("4") == 0) { return R4; }
    if(letter.compare("5") == 0) { return R5; }
    if(letter.compare("6") == 0) { return R6; }
    if(letter.compare("7") == 0) { return R7; }
    if(letter.compare("8") == 0) { return R8; }
    return Rank_Unknown;
}

File MovesParser::fileFromTheLetter(string letter) {
    if (letter.compare("a") == 0) { return A; }
    if (letter.compare("b") == 0) { return B; }
    if (letter.compare("c") == 0) { return C; }
    if (letter.compare("d") == 0) { return D; }
    if (letter.compare("e") == 0) { return E; }
    if (letter.compare("f") == 0) { return F; }
    if (letter.compare("g") == 0) { return G; }
    if (letter.compare("h") == 0) { return H; }
    return File_Unknown;
}
