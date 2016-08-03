/* 
 * File:   Sudoku.cpp
 * Author: Jason Nawrocki
 * 
 * Created on April 13, 2015, 8:12 PM
 */
#include "Move.h"
#include "Board.h"
#include "Sudoku.h"

Sudoku::Sudoku() {
}

//This function solves a Sudoku puzzle using a stack 
void Sudoku::solve() {
    int nextVal = 1; //nextVal is the next Value to use in a move. start at 1
    Move currentMove;
    Board boardObj = Board();
    cout << endl << "The Puzzle" << endl;
    cout << "--------------------" << endl;
    boardObj.printBoard();
    cout << endl << "The Solution" << endl;
    cout << "--------------------" << endl;
    //While it isn't a success state
    while (boardObj.success() != true) {
        //If the next move isn't failMove, ie if there is a legal move to make:
        if (boardObj.nextMove(nextVal).getValueAt() != MAX_VALUE) {
            //make the move, and add it to the stack
            currentMove = boardObj.nextMove(nextVal);
            movesToExplore.push(currentMove);
            boardObj.setValue(currentMove.getValueAt(), currentMove.getRow(), currentMove.getColumn());
            continue;
        }
        
        //If the next move in the current state is failMove, a previous move
        //must have been wrong.
        //Thus backtracking is necessary to find the mistake
        else {
            //infinite backtrack loop
            while (true) {
                //check that the stack isn't empty.
                if (movesToExplore.empty() == true) {
                    cout << "Error - The puzzle was not solvable" << endl;
                    return;
                }
                
                //Backtracking. Set the location of the last move to zero
                currentMove = movesToExplore.top();
                boardObj.setValue(0, currentMove.getRow(), currentMove.getColumn());
                //pop the last move which may have caused an error state
                movesToExplore.pop();
                //the nextVal to look for moves at is the oldVal + 1
                nextVal = currentMove.getValueAt() + 1;
                Move newMove = boardObj.nextMove(nextVal);
                
                //if the newMove is a legal move, do it and stop backtracking
                if (newMove.getValueAt() != MAX_VALUE) {
                    movesToExplore.push(newMove);
                    boardObj.setValue(newMove.getValueAt(), newMove.getRow(), newMove.getColumn());
                    nextVal = 1;
                    break;
                }
                //if the nextMove is a failMove, then continue backtracking
                else {
                    continue;
                }
            }
        }
        //a check to make sure the stack isn't empty
        if (movesToExplore.empty() == true) {
            cout << "Error - The puzzle was not solvable" << endl;
            return;
        }
    }
    
    //success state has been reached. print the solved puzzle
    boardObj.printBoard();
    return;
}
