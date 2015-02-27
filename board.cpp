/*
Board.h
Authors: Andrew Blum

Description: Used to create a sudoku board. Created from a file. 
Project 3A: read in board, print board, find initial conflicts, print conflicts
*/

#ifndef BOARD_FUNCTS
#define BOARD_FUNCTS

#include "board.h"

using namespace std;

board::board() {
	//initiate board from sudoku file
	readBoard("sudoku.txt");
}

board::board(const string fileName) {
	//initiates board from user-inputted file
	readBoard(fileName);
}

void board::readBoard(const string fileName) {
	currentBoard.resize(9, 9);
	int num;
	string line;
	int b = 0;
	int r = 0;
	int c = 0;
	
	//opensgrid file
	ifstream boardfile;
	boardfile.open(fileName.c_str());
	
	//parses grid file
	if(boardfile.is_open()) {
		//reads in each sudoku board and populates the currentBoard matrix in the board class and the remainingBoards vector
		while(boardfile.good()) {
			getline(boardfile, line);
			for(int i = 0; i < line.length()-1; i++) {
				if(line[i] == 'Z') {
					break;
				}
				if(c >= 9) {
					c -= 9;
					r++;
				}
				if(r >= 9) {
					break;
				}
				num = line[i] - '0';
				currentBoard[r][c] = 0;
				if(num > 0 && num < 10) {
					currentBoard[r][c] = num;			
				}
				c++;
			}
			remainingBoards.push_back(currentBoard);
			r = 0;
		}
	}
	//closes the grid file
	boardfile.close();
	
	currentBoard = remainingBoards[0];
	remainingBoards.erase(remainingBoards.begin());
}

void board::printBoard() {
	char wside = 221;
	char wbottom = 223;
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			if((i+1)%3 == 1 || i == 0) {
				cout << wbottom << wbottom; 
			}
			else if(j == 0 || (j+1)%3 == 1) {
				cout << wside << "-";
			}
			else {
				cout << "+-";
			}
		}
		cout << wside << "\n" << wside;
		for(int j = 0; j < 9; j++) {
			if(currentBoard[i][j] == 0)  {
				cout << " ";
			}
			if(currentBoard[i][j] != 0)  {
				cout << currentBoard[i][j];
			}
			if((j+1)%3 == 0) {
				cout << wside;
			}
			else {
				cout << "|";
			}
		}
		cout << "\n";
	}
	for(int j = 0; j < 9; j++) {
		cout << wbottom << wbottom;
	}
	cout << wbottom << "\n";
}

void board::printConflicts() {
	
}

bool board::checkConflicts(const int val, const int r, const int c) {
	
}

void board::updateConflicts() {
	
}

void board::nextBoard() {
	if(NumRemainingBoards() > 0) {
		currentBoard = remainingBoards[0];
		remainingBoards.erase(remainingBoards.begin());
	}
}

#endif
