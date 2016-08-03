/* 
 * File:   Move.h
 * Author: Jason Nawrocki
 * 
 * This is the move class
 * Moves have a row/column location, and a value to be set on the board
 * These moves will be placed in a stack in order to solve the puzzle
 *
 * Created on April 11, 2015, 1:51 PM
 */

#ifndef MOVE_H
#define	MOVE_H
#define MAX_VALUE 10

using namespace std;

class Move {
public:
    Move();
    Move(int row, int column, int valueAt);
    int getRow() {return this->row;}
    int getColumn() {return this->column;}
    int getValueAt() {return this->valueAt;}
    
private:
    int row;
    int column;
    int valueAt;

};

#endif	/* MOVE_H */

