/*
Program By:
Justin Hynes-Bruell
Andrew Blum

Board.h
*/

// Declarations and functions for project #4

#ifndef boardClass
#define boardClass

#include <iostream>
#include <limits.h>
#include "d_matrix.h"
#include "d_except.h"
#include <list>
#include <fstream>

using namespace std;

typedef int ValueType; // The type of the value in a cell
const int Blank = -1;  // Indicates that a cell is blank
 
const int SquareSize = 3;  //  The number of cells in a small square
                           //  (usually 3).  The board has
                           //  SquareSize^2 rows and SquareSize^2
                           //  columns.

const int BoardSize = SquareSize * SquareSize;

const int MinValue = 1;
const int MaxValue = 9;

//int numSolutions = 0;

class board
// Stores the entire Sudoku board
{
   public:
      board();
      void clear();
      void initialize(ifstream &fin);
      void print();
      bool isBlank(int, int);
      ValueType getCell(int, int);
	  void setCell(int i, int j, int input);
	  void printConflicts();
	  void updateConflicts();
	  void clearCell(int i, int j);
	  bool checkConflicts(int i, int j, int input);
	  bool checkSolved();
	  bool solve();
      
   private:

      // The following matrices go from 1 to BoardSize in each
      // dimension.  I.e. they are each (BoardSize+1) X (BoardSize+1)

      matrix<ValueType> value;

	  matrix<bool> column;
	  matrix<bool> row;
	  matrix<bool> square;
};


#endif
