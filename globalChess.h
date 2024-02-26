//
// Created by GRANT on 2/25/2024.
//

#ifndef GAMECONSOLE_GLOBALCHESS_H
#define GAMECONSOLE_GLOBALCHESS_H

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

enum Side{
    black, white
};


class Coordinate{
public:
//vars
int row;
int col;


//init
Coordinate(int row, int col){
this->row = row;
this->col = col;
}

//overloaded
bool operator==(const Coordinate& other) const;

private:

};



#endif //GAMECONSOLE_GLOBALCHESS_H
