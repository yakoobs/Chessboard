cmake_minimum_required(VERSION 3.5)
project(Chessboard)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp src/Chessboard/Piece.h src/Chessboard/Board.cpp src/Chessboard/Board.h src/Chessboard/Move.h src/Chessboard/Square.h src/Chessboard/Position.h src/Chessboard/Constants.h "src/GameLogic/Game.cpp" "src/GameLogic/Game.h")
add_executable(Chessboard ${SOURCE_FILES})