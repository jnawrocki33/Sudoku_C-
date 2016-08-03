/* 
 * File:   main.cpp
 * Author: Jason Nawrocki
 *
 * This program solves Sudoku puzzles by maintaining a stack of moves
 * and backtracking when a wrong move has been made.
 * It is a brute force solving method.
 * 
 * Created on April 11, 2015, 1:50 PM
 */

#include <cstdlib>
#include "Move.h"
#include "Board.h"
#include "Sudoku.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Sudoku puzzle = Sudoku();
    puzzle.solve();
    return 0;
}

