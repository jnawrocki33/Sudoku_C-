/* 
 * File:   Sudoku.h
 * Author: Jason Nawrocki
 * 
 * This is the Sudoku class. It holds a stack of moves in order to identify
 * which moves have/have not worked, allowing for backtracking
 *
 * Created on April 13, 2015, 8:12 PM
 */

#ifndef SUDOKU_H
#define	SUDOKU_H
#include <stack>
#include <string>
#include <iostream>
#include "Move.h"
#include "Board.h"
#define MAX_VALUE 10


class Sudoku {
public:
    Sudoku();
    void solve();
    
private:
    stack <Move> movesToExplore;

};

#endif	/* SUDOKU_H */

