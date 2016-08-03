/* 
 * File:   Move.cpp
 * Author: Jason Nawrocki
 *
 * Created on April 11, 2015, 1:51 PM
 */

#include "Move.h"

Move::Move() {
}

//constructor. make a move at a given location with a given value
Move::Move(int row, int column, int valueAt) {
    this->row = row;
    this->column = column;
    this->valueAt = valueAt;
}


