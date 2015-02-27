/*
Board.h
Authors: Andrew Blum and Justin Hynes-Bruell

Description: Used to create a sudoku board. Created from a file. 
Project 3a: read in board, print board, find initial conflicts, print conflicts
*/

#ifndef BOARD_CLASS
#define BOARD_CLASS

#include <stdlib.h>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <iostream>

#include "d_matrix.h"

using namespace std;

class board {
	public:
		board();																			//finished
		board(const string fileName);														//finished
		void readBoard(const string fileName);												//finsihed
		void printBoard();																	//finished
		void printConflicts();																//Still need to complete
		void updateConflicts();																//Still need to complete
		bool checkConflicts(const int val, const int r, const int c);						//Still need to complete
		int NumRemainingBoards() {return remainingBoards.size();};							//finished
		
		void nextBoard();																	//finished
		void addValue(const int val, const int r, const int c) {currentBoard[r][c] = val;};	//finished
		void clearCell(const int r, const int c) {currentBoard[r][c] = 0;};					//finished
		bool checkSolved();																	//Complete for 3b
		bool cellEmpty(const int r, const int c);											//finished
		void fillCells();																	//Complete for 3b
		
	private:
		
		matrix<int> currentBoard;
		vector<matrix<int> > remainingBoards;
		vector<int> conflicts;
		vector<int> row;
		vector<int> column;
		vector<int> square;
};

#endif
