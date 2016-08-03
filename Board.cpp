/* 
 * File:   Board.cpp
 * Author: Jason Nawrocki
 * 
 * Created on April 11, 2015, 1:58 PM
 */

#include "Move.h"
#include "Board.h"

//constructor calls the readPuzzle method automatically
Board::Board() {
    readPuzzle();
}

//This function reads in a puzzle file into a 2x2 array
void Board::readPuzzle() {
    string fileName;
    ifstream puzzleStream;
    // read in the puzzle file name
    do {
        cout << "Enter puzzle file name: ";
        cin >> fileName;
        puzzleStream.open(fileName.c_str(), ios::in);
    } while (!puzzleStream.good());     //keep trying until success
    
    // read in the digits
    for (int r = 0; r < DIMENSION; r++) {
        for (int c = 0; c < DIMENSION; c++) {
            puzzleStream >> board[r][c];
        }
    }
}

//This function returns the next move to be made on the board
//It takes as input an integer value, which is the next value to be made
//The value before next value lead to an unsolveable state

Move Board::nextMove(int nextVal) {
    int row, col;
    //find the first open space on the board
    for (int r = 0; r < DIMENSION; r++) {
        for (int c = 0; c < DIMENSION; c++) {
            if (board[r][c] == 0) {
                row = r;
                col = c;
                break;
            }
        }
    }
    //start testing moves at the open space, going from nextVal to maxVal
    for (int value = nextVal; value < MAX_VALUE; value++) {
        Move newMove = Move(row, col, value);
        //if this move is legal, return it
        if (legalMove(newMove) == true) {
            return newMove;
        }
    }
    //if no legal moves at this location have been found, return a failMove
    //with MAX_VALUE, to indicate a previous error state
    Move failMove(row, col, MAX_VALUE);
    return failMove;
} 

//This function tests if a given move is legal, given the board state
//It takes as input the move to be tested
bool Board::legalMove(Move move) {
    //check that valueAt isn't in line (row and column) with the move location
    for (int r = 0; r < DIMENSION; r++) {
        if (move.getValueAt() == board[r][move.getColumn()]) {
            return false;
        }
    }
    
    for (int c = 0; c < DIMENSION; c++) {
        if (move.getValueAt() == board[move.getRow()][c]) {
            return false;
        }
    }
    //gainRow and gainCol will be shift factors, depending on the modularization
    //of the row and column
    //They allow the board to be broken into 3x3 squares for legality testing
    int gainRow;
    int gainCol;
    //if the row is 0, 3, or 6:
    if (move.getRow() %3 == 0) {
        gainRow = 3;
    }
    //if the row is 1, 4, or 7:
    if (move.getRow() %3 == 1) {
        gainRow = 2;
    }
    //if the row is 2, 5, or 8:
    if (move.getRow() %3 == 2) {
        gainRow = 1;
    }
    //same process for the columns:
    if (move.getColumn() %3 == 0) {
        gainCol = 3;
    }
    if (move.getColumn() %3 == 1) {
        gainCol = 2;
    }
    if (move.getColumn() %3 == 2) {
        gainCol = 1;
    }
   
    //A given 3x3 square goes from rowMin to rowMax, colMin to colMax
    //The following produces the min/max locations, using gainRow/gainCol
    //to offset
    int rowMin = move.getRow() - (3 - gainRow);
    int rowMax = move.getRow() + gainRow;
    int colMin = move.getColumn() - (3 - gainCol);
    int colMax = move.getColumn() + gainCol; 
   
    //Check that the move value isn't already in the 3x3 square
    for (int r = rowMin; r < rowMax; r++) {
        for (int c = colMin; c < colMax; c++) {
            if  (move.getValueAt() == board[r][c]) {
                return false;
            }     
        }
    }

    return true;
}

//tests if there are no zeros on the board, ie if it is the success state.
bool Board::success() {
    for (int r = 0; r < DIMENSION; r++) {
        for (int c = 0; c < DIMENSION; c++) {
            if (board[r][c] == 0) {
                return false;
            }
        }
    }
    return true;
}

//this function prints the board, replacing "0" with "_"
void Board::printBoard() {
    for (int r = 0; r < DIMENSION; r++) {
        for (int c = 0; c < DIMENSION; c++) {
            if (board[r][c] == 0) {
                cout << "_ ";
                continue;
            }
            cout << board[r][c] << " ";
        }
        cout << endl;
    }
}



