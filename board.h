/*
Board.h
Authors: Andrew Blum

Description: Used to create a sudoku board. Created from a file. 
Project 3A: read in board, print board, find initial conflicts, print conflicts
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
		board();
		board(const string fileName);
		void readBoard(const string fileName);
		void printBoard();
		void printConflicts();
		void updateConflicts();
		bool checkConflicts(const int val, const int r, const int c);
		int NumRemainingBoards() {return remainingBoards.size();};
		
		void nextBoard();
		void addValue(const int val, const int r, const int c);
		void clearCell(const int r, const int c);
		bool checkSolved();
		bool cellEmpty(const int r, const int c);
		void fillCells();
		
	private:
		
		matrix<int> currentBoard;
		vector<matrix<int> > remainingBoards;
		vector<int> conflicts;
		vector<int> row;
		vector<int> column;
		vector<int> square;
};

#endif
