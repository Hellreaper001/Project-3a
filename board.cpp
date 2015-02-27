/*
Board.cpp
Authors: Andrew Blum and Justin Hynes-Bruell

Description: Used to create a sudoku board. Created from a file. 
Project 3a: read in board, print board, find initial conflicts, print conflicts
*/

#ifndef BOARD_FUNCTS
#define BOARD_FUNCTS

#include "board.h"

using namespace std;

//initiate a board using sudoku.txt for the file
board::board() {
	readBoard("sudoku.txt");
}

//initiate a board with a filename
board::board(const string fileName) {
	//initiates board from user-inputted file
	readBoard(fileName);
}

//reads boards in from a file
void board::readBoard(const string fileName) {
	currentBoard.resize(9, 9);
	int num;
	string line;
	int r = 0;
	int c = 0;
	
	//opens board file
	ifstream boardfile;
	boardfile.open(fileName.c_str());
	
	//checks to make sure the board file was able to open, if it didn't the sudoku.txt file is opened instead
	if(boardfile == NULL) {
		cout << "Invalid file name entered. Will use sudoku.txt instead.\n";
		boardfile.open("sudoku.txt");
	}
	
	//parses board file
	if(boardfile.is_open()) {
		//reads in each sudoku board and populates the currentBoard matrix in the board class and the remainingBoards vector
		while(boardfile.good()) {
			//reads the next char in the board file, converts it to it's ascii value, and makes 0 = 0
			num = boardfile.get() - '0';
			//if the char was a Z, break
			if(num == 'Z' - '0') {
				break;
			}
			//if the char was a number between 1 and 9, add it to the current board
			if(num > 0 && num < 10) {
				currentBoard[r][c] = num;
			}
			//if the char was a '.' (blank), adds a 0 to the board.
			if(num == '.' - '0') {
				currentBoard[r][c] = 0;
			}
			c++;
			//checks to make sure the last char wasn't a new line, and corrects for that
			if(num == '\n' - '0') {
				c = 0;
			}
			//if a row on the board is full, move on to the next row
			if(c >= 9) {
				c = 0;
				r++;
			}
			//if the board is full, add it to the remaining board list and start over
			if(r >= 9) {
				remainingBoards.push_back(currentBoard);
				r = 0;
				c = 0;
			}
		}
	}
	//closes the grid file
	boardfile.close();
	
	//sets the current board to the first board in the list of remaining boards and then deletes it from the list
	currentBoard = remainingBoards[0];
	remainingBoards.erase(remainingBoards.begin());
}

//prints the current board
void board::printBoard() {
	//wide chars for major borders
	char wside = 221;
	char wbottom = 223;
	for(int i = 0; i < 9; i++) {
		//Sets the horizontal border
		for(int j = 0; j < 9; j++) {
			//thick horizontal border
			if((i+1)%3 == 1 || i == 0) {
				cout << wbottom << wbottom; 
			}
			//side border and small horizontal border (for 
			else if(j == 0 || (j+1)%3 == 1) {
				cout << wside << "-";
			}
			//junction and small horizontal border
			else {
				cout << "+-";
			}
		}
		//front and back side border for number line
		cout << wside << "\n" << wside;
		//number line: outputs correct number with correct border
		for(int j = 0; j < 9; j++) {
			//outputs space if number was 0
			if(currentBoard[i][j] == 0)  {
				cout << " ";
			}
			//outputs number if not 0
			if(currentBoard[i][j] != 0)  {
				cout << currentBoard[i][j];
			}
			//places wide side border if one of the smaller cubes
			if((j+1)%3 == 0) {
				cout << wside;
			}
			//places small side border between numbers when not cube border
			else {
				cout << "|";
			}
		}
		cout << "\n";
	}
	//adds bottom border
	for(int j = 0; j < 9; j++) {
		cout << wbottom << wbottom;
	}
	//goes to a new line after board is printed
	cout << wbottom << "\n";
}

void board::printConflicts() {
	
}

void board::updateConflicts() {
	
}

bool board::checkConflicts(const int val, const int r, const int c) {
	
}

void board::nextBoard() {
	//sets current board to next board in remaining boards list and then deletes it from list
	if(NumRemainingBoards() > 0) {
		currentBoard = remainingBoards[0];
		remainingBoards.erase(remainingBoards.begin());
	}
}

bool board::checkSolved() {
	
}

bool board::cellEmpty(const int r, const int c) {
	if(currentBoard[r][c] == 0) {
		return true;
	}
	return false;
}

void board::fillCells() {
	
}

#endif
