//
// Created by GRANT on 2/25/2024.
//

#ifndef GAMECONSOLE_CHESSBOARD_H
#define GAMECONSOLE_CHESSBOARD_H

#include "globalChess.h"
#include "chessPieces.h"



class Board {
public:
    //vars
    Piece* pieces[8][8];

    //init
    Board() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                pieces[i][j] = NULL;
            }
        }
        //Board Setup:

        //Black:
        //pawns
        for (int i = 0; i < 8; i++) {
            pieces[6][i] = new Pawn(Side::black);
        }
        //other pieces
        pieces[7][0] = new Rook(Side::black);
        pieces[7][1] = new Knight(Side::black);
        pieces[7][2] = new Bishop(Side::black);
        pieces[7][3] = new Queen(Side::black);
        pieces[7][4] = new King(Side::black);
        pieces[7][5] = new Bishop(Side::black);
        pieces[7][6] = new Knight(Side::black);
        pieces[7][7] = new Rook(Side::black);

        //White:
        //pawns
        for (int i = 0; i < 8; i++) {
            pieces[1][i] = new Pawn(Side::white);
        }
        //other pieces
        pieces[0][0] = new Rook(Side::white);
        pieces[0][1] = new Knight(Side::white);
        pieces[0][2] = new Bishop(Side::white);
        pieces[0][3] = new Queen(Side::white);
        pieces[0][4] = new King(Side::white);
        pieces[0][5] = new Bishop(Side::white);
        pieces[0][6] = new Knight(Side::white);
        pieces[0][7] = new Rook(Side::white);
    }

    //methods
    void PrintBoard(std::vector<Coordinate> possibleMoves = std::vector<Coordinate>());

        private:

};

class Game{
public:
    //vars
    Side currentTurn;
    Board board;

    //init
    Game() {
        board = Board();

        currentTurn = Side::white;
    }


    //methods
    void Start();
    void GetNextMove();
    int AskCol();
    int AskRow();
    bool GameOver();

private:

};


#endif //GAMECONSOLE_CHESSBOARD_H
