cmake_minimum_required(VERSION 3.27)
project(gameconsole)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        chessBoard.cpp
        chessPieces.cpp
        globalChess.cpp
        programControl.cpp
)

add_executable(gameconsole ${SOURCE_FILES})
