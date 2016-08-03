/* 
 * File:   Board.h
 * Author: Jason Nawrocki
 *
 * This is the board class. It holds the state of the board, and also has 
 * the functionality to alter the board as well as make checks on the board
 * for legality and success states.
 * 
 * Created on April 11, 2015, 1:58 PM
 */

#ifndef BOARD_H
#define	BOARD_H
#define DIMENSION 9
#define MAX_VALUE 10
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Board {
public:
    Board();
    void readPuzzle();
    int getValue(int r, int c) {return board[r][c];}
    void setValue(int newVal, int r, int c) {board[r][c] = newVal;}
    Move nextMove(int nextVal);
    bool legalMove(Move move);
    bool success();
    void printBoard();
    
private:
    int board[DIMENSION][DIMENSION];
    
};

#endif	/* BOARD_H */

