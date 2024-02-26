//
// Created by GRANT on 2/25/2024.
//

#ifndef GAMECONSOLE_CHESSPIECES_H
#define GAMECONSOLE_CHESSPIECES_H

enum Side {
    black, white
};


//generic parent class piece
class Piece{
public:
    //constructor
    Piece(Side side) {
        this->side = side;
    }

    //vars
    char id = 'N';

    //methods
    std::string GetIdentifier();
    virtual bool MakeMove(int srcRow, int srcCol, int destRow, int destCol, Piece* board[8][8]);
    virtual std::vector<Coordinate> AllLegalMoves(int currentRow, int currentCol, Piece* board[8][8])

private:

};


//pawn class
class Pawn : public Piece{
public:
    //init
    Pawn(Side side) : Piece(side) {
        id = 'P';
        firstTurn = true;
        if (side == Side::white) {
            direction = 1;
        }
        else {
            direction = -1;
        }
    }

   //vars
   bool firstTurn;
   int direction;

   //methods
   bool MakeMove(int srcRow, int srcCol, int destRow, int destCol, Piece* board[8][8]);
   std::vector<Coordinate> AllLegalMoves(int currentRow, int currentCol, Piece* board[8][8])

private:

};

//rook class
class Rook : public Piece{
public:
    Rook(Side side) : Piece(side){
        id = 'R';
    }

    std::vector<Coordinate> AllLegalMoves(int currentRow, int currentCol, Piece* board[8][8]);

private:

};


class Knight : public Piece{
public:
    //init
    Knight(Side side) : Piece(side){
        id = 'N';
    }

    //methods
    std::vector<Coordinate> AllLegalMoves(int currentRow, int currentCol, Piece* board[8][8]);

private:

};

class Bishop : public Piece{
public:
    //init
   Bishop(Side side) : Piece(side){
       id = 'B';
   }
   //methods
   std::vector<Coordinate> AllLegalMoves(int currentRow, int currentCol, Piece* board[8][8]);

private;

};

class Queen :public Piece{
public:
    //init
    Queen (Side side) : Piece(side){
        id = 'Q';
    }

    //methods
    std::vector<Coordinate> AllLegalMoves(int currentRow, int currentCol, Piece* board[8][8]);

private:

};

class King : public Piece{
public:
    //init
    King(Side side) :  Piece(side){
        id = 'K';
    }

    //methods
    std::vector<Coordinate> AllLegalMoves(int currentRow, int currentCol, Piece* board[8][8]);
    bool CheckDanger(int row, int col, Piece* board[8][8])

private:

};

#endif //GAMECONSOLE_CHESSPIECES_H
