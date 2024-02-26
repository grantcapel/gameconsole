//
// Created by GRANT on 2/25/2024.
//

#include "globalChess.h"

bool Coordinate::operator==(const Coordinate &other) const {
return (row == other.row && col == other.col);
}