//
// Created by GRANT on 2/25/2024.
//

#include "chessPieces.h"



// piece class

std::string Piece::GetIdentifier() {
    char sideChar;
    if (side == Side::black) {
        sideChar = 'B';
    }
    else {
        sideChar = 'W';
    }

    return std::string(1, sideChar) + id;
}


 bool Piece::MakeMove(int srcRow, int srcCol, int destRow, int destCol, Piece *(*board)[8]) {
    std::vector<Coordinate> moves = AllLegalMoves(srcRow, srcCol, board);
    if (std::find(moves.begin(), moves.end(), Coordinate(destRow, destCol)) != moves.end()) {
        return true;
    }
    return false;
}

std::vector<Coordinate> Piece::AllLegalMoves(int currentRow, int currentCol, Piece *(*board)[8]) {
    return std::vector<Coordinate>();
}




//pawn class
bool Pawn::MakeMove(int srcRow, int srcCol, int destRow, int destCol, Piece *(*board)[8]) {
    std::vector<Coordinate> moves = AllLegalMoves(srcRow, srcCol, board);
    if (std::find(moves.begin(), moves.end(), Coordinate(destRow, destCol)) != moves.end()) {
        firstTurn = false;
        return true;
    }
    return false;
}

std::vector <Coordinate> Pawn::AllLegalMoves(int currentRow, int currentCol, Piece *(*board)[8]) {
    std::vector<Coordinate> moves;

    if (board[currentRow + direction][currentCol] == NULL) {
        moves.emplace_back(Coordinate(currentRow + direction, currentCol));

        if (firstTurn) {
            if (board[currentRow + (2 * direction)][currentCol] == NULL) {
                moves.emplace_back(Coordinate(currentRow + (2 * direction), currentCol));
            }
        }
    }

    if (board[currentRow + direction][currentCol - 1] != NULL) {
        moves.emplace_back(Coordinate(currentRow + direction, currentCol - 1));
    }
    if (board[currentRow + direction][currentCol + 1] != NULL) {
        moves.emplace_back(Coordinate(currentRow + direction, currentCol + 1));
    }
    return moves;
}




//rook class
std::vector <Coordinate> Rook::AllLegalMoves(int currentRow, int currentCol, Piece *(*board)[8]) {
    std::vector<Coordinate> moves;

    //Check up
    for (int y = currentRow + 1; y < 8; y++) {
        if (board[y][currentCol] == NULL) {
            moves.emplace_back(Coordinate(y, currentCol));
        }
        else {
            if (board[y][currentCol]->side != side) {
                moves.emplace_back(Coordinate(y, currentCol));
            }
            break;
        }
    }

    //Check down
    for (int y = currentRow - 1; y >= 0; y--) {
        if (board[y][currentCol] == NULL) {
            moves.emplace_back(Coordinate(y, currentCol));
        }
        else {
            if (board[y][currentCol]->side != side) {
                moves.emplace_back(Coordinate(y, currentCol));
            }
            break;
        }
    }

    //Check right
    for (int x = currentCol + 1; x < 8; x++) {
        if (board[currentRow][x] == NULL) {
            moves.emplace_back(Coordinate(currentRow, x));
        }
        else {
            if (board[currentRow][x]->side != side) {
                moves.emplace_back(Coordinate(currentRow, x));
            }
            break;
        }
    }

    //Check left
    for (int x = currentCol - 1; x >= 0; x--) {
        if (board[currentRow][x] == NULL) {
            moves.emplace_back(Coordinate(currentRow, x));
        }
        else {
            if (board[currentRow][x]->side != side) {
                moves.emplace_back(Coordinate(currentRow, x));
            }
            break;
        }
    }

    /*for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (x == currentCol || y == currentRow) {
                moves.emplace_back(Coordinate(y, x));
            }
        }
    }*/
    return moves;
}




//knight class
std::vector<Coordinate> Knight::AllLegalMoves(int currentRow, int currentCol, Piece *(*board)[8]) {
    std::vector<Coordinate> moves;

    int X[8] = {1, 1, -1, -1, 2, 2, -2, -2};
    int Y[8] = {2, -2, 2, -2, 1, -1, 1, -1};

    for (int i = 0; i < 8; i++) {

        int y = Y[i] + currentRow;
        int x = X[i] + currentCol;
        if (x >= 0 && x < 8 && y >= 0 && y < 8) {
            if (board[y][x] == NULL || board[y][x]->side != side) {
                moves.emplace_back(Coordinate(y, x));
            }
        }
    }
    return moves;
}




//bishop class
std::vector<Coordinate> Bishop::AllLegalMoves(int currentRow, int currentCol, Piece *(*board)[8]) {
    std::vector<Coordinate> moves;

    //checks in all four diagonal directions
    for (int i = 1; i<8; i++) {
        int y = currentRow + i;
        int x = currentCol + i;

        if (x >= 0 && x < 8 && y >= 0 && y < 8) {
            if (board[y][x] == NULL) {
                moves.emplace_back(Coordinate(y, x));
            }
            else if (board[y][x]->side != side) {
                moves.emplace_back(Coordinate(y, x));
                break;
            }
            else {
                break;
            }
        }
    }

    for (int i = 1; i<8; i++) {
        int y = currentRow + i;
        int x = currentCol - i;

        if (x >= 0 && x < 8 && y >= 0 && y < 8) {
            if (board[y][x] == NULL) {
                moves.emplace_back(Coordinate(y, x));
            }
            else if (board[y][x]->side != side) {
                moves.emplace_back(Coordinate(y, x));
                break;
            }
            else {
                break;
            }
        }
    }

    for (int i = 1; i<8; i++) {
        int y = currentRow - i;
        int x = currentCol + i;

        if (x >= 0 && x < 8 && y >= 0 && y < 8) {
            if (board[y][x] == NULL) {
                moves.emplace_back(Coordinate(y, x));
            }
            else if (board[y][x]->side != side) {
                moves.emplace_back(Coordinate(y, x));
                break;
            }
            else {
                break;
            }
        }
    }

    for (int i = 1; i<8; i++) {
        int y = currentRow - i;
        int x = currentCol - i;

        if (x >= 0 && x < 8 && y >= 0 && y < 8) {
            if (board[y][x] == NULL) {
                moves.emplace_back(Coordinate(y, x));
            }
            else if (board[y][x]->side != side) {
                moves.emplace_back(Coordinate(y, x));
                break;
            }
            else {
                break;
            }
        }
    }
    return moves;
}




//queen class
std::vector<Coordinate> Queen::AllLegalMoves(int currentRow, int currentCol, Piece *(*board)[8]) {
    std::vector<Coordinate> moves;

    //Check up
    for (int y = currentRow + 1; y < 8; y++) {
        if (board[y][currentCol] == NULL) {
            moves.emplace_back(Coordinate(y, currentCol));
        }
        else {
            if (board[y][currentCol]->side != side) {
                moves.emplace_back(Coordinate(y, currentCol));
            }
            break;
        }
    }

    //Check down
    for (int y = currentRow - 1; y >= 0; y--) {
        if (board[y][currentCol] == NULL) {
            moves.emplace_back(Coordinate(y, currentCol));
        }
        else {
            if (board[y][currentCol]->side != side) {
                moves.emplace_back(Coordinate(y, currentCol));
            }
            break;
        }
    }

    //Check right
    for (int x = currentCol + 1; x < 8; x++) {
        if (board[currentRow][x] == NULL) {
            moves.emplace_back(Coordinate(currentRow, x));
        }
        else {
            if (board[currentRow][x]->side != side) {
                moves.emplace_back(Coordinate(currentRow, x));
            }
            break;
        }
    }

    //Check left
    for (int x = currentCol - 1; x >= 0; x--) {
        if (board[currentRow][x] == NULL) {
            moves.emplace_back(Coordinate(currentRow, x));
        }
        else {
            if (board[currentRow][x]->side != side) {
                moves.emplace_back(Coordinate(currentRow, x));
            }
            break;
        }
    }

    //checks in all four diagonal directions
    for (int i = 1; i < 8; i++) {
        int y = currentRow + i;
        int x = currentCol + i;

        if (x >= 0 && x < 8 && y >= 0 && y < 8) {
            if (board[y][x] == NULL) {
                moves.emplace_back(Coordinate(y, x));
            }
            else if (board[y][x]->side != side) {
                moves.emplace_back(Coordinate(y, x));
                break;
            }
            else {
                break;
            }
        }
    }

    for (int i = 1; i < 8; i++) {
        int y = currentRow + i;
        int x = currentCol - i;

        if (x >= 0 && x < 8 && y >= 0 && y < 8) {
            if (board[y][x] == NULL) {
                moves.emplace_back(Coordinate(y, x));
            }
            else if (board[y][x]->side != side) {
                moves.emplace_back(Coordinate(y, x));
                break;
            }
            else {
                break;
            }
        }
    }

    for (int i = 1; i < 8; i++) {
        int y = currentRow - i;
        int x = currentCol + i;

        if (x >= 0 && x < 8 && y >= 0 && y < 8) {
            if (board[y][x] == NULL) {
                moves.emplace_back(Coordinate(y, x));
            }
            else if (board[y][x]->side != side) {
                moves.emplace_back(Coordinate(y, x));
                break;
            }
            else {
                break;
            }
        }
    }

    for (int i = 1; i < 8; i++) {
        int y = currentRow - i;
        int x = currentCol - i;

        if (x >= 0 && x < 8 && y >= 0 && y < 8) {
            if (board[y][x] == NULL) {
                moves.emplace_back(Coordinate(y, x));
            }
            else if (board[y][x]->side != side) {
                moves.emplace_back(Coordinate(y, x));
                break;
            }
            else {
                break;
            }
        }
    }
    return moves;
}

//king class

std::vector<Coordinate> King::AllLegalMoves(int currentRow, int currentCol, Piece *(*board)[8]) {
    std::vector<Coordinate> moves;

    int Y[8] = { 1, -1, 0, 1, -1, 0,  1, -1 };
    int X[8] = { 0, 0,  1, 1, 1, -1, -1, -1 };

    for (int i = 0; i < 8; i++) {

        int y = Y[i] + currentRow;
        int x = X[i] + currentCol;

        if (x >= 0 && x < 8 && y >= 0 && y < 8) {
            if (board[y][x] == NULL || board[y][x]->side != side) {
                if (!CheckDanger(y, x, board)) {
                    moves.emplace_back(Coordinate(y, x));
                }
            }
        }
    }
    return moves;
}

bool King::CheckDanger(int row, int col, Piece *(*board)[8]) {
    //Make a copy of the board
    Piece* refBoard[8][8];
    memcpy(refBoard, board, sizeof(board));
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (board[y][x] != NULL) {

                refBoard[y][x] = board[y][x];
            }
            else {
                refBoard[y][x] = NULL;
            }
        }
    }

    //remove king from the board
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (refBoard[y][x] == this) {
                //deletes this king from the reference board
                refBoard[y][x] = NULL;

                //breaks the loop
                goto exit;
            }
        }
    }
    exit:;

    refBoard[row][col] = this;

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (refBoard[y][x] != NULL) {
                // check if piece color is opposite
                if (refBoard[y][x]->side != side) {
                    // Get valid moves
                    std::vector<Coordinate> moves = refBoard[y][x]->AllLegalMoves(y, x, refBoard);
                    // check if desired location is one of its valid moves
                    if (std::find(moves.begin(), moves.end(), Coordinate(row, col)) != moves.end()) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}