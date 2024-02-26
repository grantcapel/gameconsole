//
// Created by GRANT on 2/25/2024.
//

#include "chessBoard.h"

bool Coordinate::operator==(const Coordinate &other) const {
    return (row == other.row && col == other.col);
}




void PrintBoard(std::vector<Coordinate> possibleMoves = std::vector<Coordinate>()) {
    for (int y = 7; y >=0; y--) {

        std::cout << "---";

        for (int x = 0; x < 8; x++) {

            if (std::find(possibleMoves.begin(), possibleMoves.end(), Coordinate(y, x)) != possibleMoves.end()) {
                std::cout << "@@@@@@";
            }
            else if (y % 2 != x % 2) {
                std::cout << "******";
            }
            else {
                std::cout << "      ";
            }
        }

        std::cout << std::endl;

        //next line:

        std::cout << "-" << y+1 << "-";

        //Prints the letters of the piece on the square
        for (int x = 0; x < 8; x++) {

            if (std::find(possibleMoves.begin(), possibleMoves.end(), Coordinate(y, x)) != possibleMoves.end()) {
                if (pieces[y][x] != NULL) {
                    std::cout << "@@" << pieces[y][x]->GetIdentifier() << "@@";
                }
                else {
                    std::cout << "@@@@@@";
                }
            }
            else if (y % 2 != x % 2) {
                if (pieces[y][x] != NULL) {
                    std::cout << "**" << pieces[y][x] -> GetIdentifier()  << "**";
                }
                else {
                    std::cout << "******";
                }
            }
            else {
                if (pieces[y][x] != NULL) {
                    std::cout << "  " << pieces[y][x] -> GetIdentifier() << "  ";
                }
                else {
                    std::cout << "      ";
                }
            }
        }

        std::cout << std::endl;
        std::cout << "---";

        for (int x = 0; x < 8; x++) {

            if (std::find(possibleMoves.begin(), possibleMoves.end(), Coordinate(y, x)) != possibleMoves.end()) {
                std::cout << "@@@@@@";
            }
            else if (y % 2 != x % 2) {
                std::cout << "******";
            }
            else {
                std::cout << "      ";
            }
        }
        std::cout << std::endl;
    }

    std::cout << "---";
    for (int x = 0; x < 8; x++) {
        std::cout << "|----|";
    }
    std::cout << std::endl;
    std::cout << "---";

    //labels each column from a - h
    for (int x = 0; x < 8; x++) {
        std::cout << "|-" << (char)(x + 'a') << "--|";
    }
    std::cout << std::endl;
    std::cout << "---";

    for (int x = 0; x < 8; x++) {
        std::cout << "|----|";
    }
    std::cout << std::endl;
}




//game class
void Game::Start() {
    do {

        if (currentTurn == Side::white) {
            std::cout << "White's Turn:\n";
        }
        else {
            std::cout << "Black's Turn:\n";
        }

        //Gets next player's move
        GetNextMove();

        /*
        if (currentTurn == Side::white) {
            currentTurn = Side::black;
        }
        else {
            currentTurn = Side::white;
        }*/

    } while (!GameOver());
}

void Game::GetNextMove() {
    bool validMove = false;

    //infinite loop that either gets broken out of or continued
    while (true) {

        board.PrintBoard();

        //choose piece you want to move
        std::cout << "Pick the piece you would like to move: column row\n";

        int srcCol = AskCol();
        int srcRow = AskRow();


        if ((srcRow < 0 || srcRow > 7) || (srcCol < 0 || srcCol > 7)) {
            std::cout << "That is not a valid coordinate\n";
            continue;
        }

        if (board.pieces[srcRow][srcCol] != NULL) {
            if (board.pieces[srcRow][srcCol]->side == currentTurn) {
                std::cout << "That is your " << board.pieces[srcRow][srcCol]->GetIdentifier() << "\n";
            } else {
                std::cout << "That is not your piece\n";
                continue;
            }
        } else {
            std::cout << "There is no piece here\n";
            continue;
        }

        std::vector <Coordinate> validMoves = board.pieces[srcRow][srcCol]->AllLegalMoves(srcRow, srcCol, board.pieces);

        if (validMoves.size() == 0) {
            std::cout << "This piece has no valid moves\n";
            continue;
        }

        board.PrintBoard(validMoves);

        //Choose where to move piece

        std::cout << "Pick where you would like to move that piece: column row\n";

        int destCol = AskCol();
        int destRow = AskRow();


        std::cout << destCol << destRow << std::endl;
        if ((destRow < 0 || destRow > 7) || (destCol < 0 || destCol > 7)) {
            std::cout << "That is not a valid coordinate\n";
            continue;
        }

        //check to make sure that it is not your own piece
        if (board.pieces[destRow][destCol] != NULL) {
            if (board.pieces[destRow][destCol]->side == currentTurn) {
                std::cout << "That is your piece\n";
                continue;
            }
        }

        //check if is a valid move
        if (!board.pieces[srcRow][srcCol]->MakeMove(srcRow, srcCol, destRow, destCol, board.pieces)) {
            std::cout << "That is not a valid move\n";
            continue;
        }

        board.pieces[destRow][destCol] = board.pieces[srcRow][srcCol];
        board.pieces[srcRow][srcCol] = NULL;

        break;
    }
}

int Game::AskCol() {
    char colChar;
    std::cin >> colChar;

    return (int)(colChar - 'a');
}

int Game::AskRow() {
    char rowChar;
    std::cin >> rowChar;

    return (int)(rowChar - '0' - 1);
}

bool Game::GameOver() {
    return false;
}