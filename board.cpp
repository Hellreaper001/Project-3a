/*
Program By:
Justin Hynes-Bruell
Andrew Blum

Board.cpp
*/

#include "board.h"


board::board()
   : value(BoardSize+1,BoardSize+1)
// Board constructor
{
   //Sets Up conflict matrix size
   column.resize(BoardSize+1,BoardSize+1);
   row.resize(BoardSize+1,BoardSize+1);
   square.resize(BoardSize+1,BoardSize+1);
}

void board::clear()
{
	for (int i = 1; i <= BoardSize; i++)
      for (int j = 1; j <= BoardSize; j++)
      {
		    //Resets all of conflict tables
	        column[i][j] = false;
            row[i][j] = false;
            square[i][j] = false;
			setCell(i, j, NULL);
      }
}

void board::updateConflicts(){
	//Update Row Conflicts
	for (int i = 1; i <= BoardSize; i++)
      for (int j = 1; j <= BoardSize; j++){
		  if(!isBlank(i,j)){
			  row[i][value[i][j]] = true;
			  column[j][value[i][j]] = true;
			  //Square Chart
			  //-----------
			  //|1 | 2 | 3|
			  //-----------
			  //|4 | 5 | 6|
			  //-----------
			  //|7 | 8 | 9|
			  //-----------
			  if(i <= 3){
				  if(j <= 3) {
					  square[1][value[i][j]] = true;
				  }
				  if(j > 3 && j <=6){
					  square[2][value[i][j]] = true;
				  }
				  if(j > 7){
					  square[3][value[i][j]] = true;
				  }
			  }
			  if(i > 3 && i <=6){
				  if(j <= 3) {
					  square[4][value[i][j]] = true;
				  }
				  if(j > 3 && j <=6){
					  square[5][value[i][j]] = true;
				  }
				  if(j > 7){
					  square[6][value[i][j]] = true;
				  }
			  }
			  if(i > 7){
				  if(j <= 3) {
					  square[7][value[i][j]] = true;
				  }
				  if(j > 3 && j <=6){
					  square[8][value[i][j]] = true;
				  }
				  if(j > 7){
					  square[9][value[i][j]] = true;
				  }
			  }
		  }		  
      }
}

void board::printConflicts()
{
	updateConflicts();
	//Setup ASCII Char
	char endT = 180;
	char beginT = 195;
	char side = 179;
	char line = 196;
   cout << "\nPlease note:\n1 = Conflict\n0 = No Conflict\n";
   cout << "\n           ---Conflicts Row---\n       1  2  3  4  5  6  7  8  9" << endl;
   for (int i = 1; i <= BoardSize; i++)
   {
         cout << "     " << beginT;
	 for (int j = 1; j <= BoardSize; j++)
	    cout << line << line << line;
         cout << endT;
	 cout << endl;
      for (int j = 1; j <= BoardSize; j++)
      {
	 if(j == 1){
		 cout << "Row " << i << side;
	 }
	    cout << " " << row[i][j] << " ";
      }
      cout << side;
      cout << endl;
   }

   cout << "     " << beginT;
   for (int j = 1; j <= BoardSize; j++)
	    cout << line << line << line;
   cout << endT;
   cout << endl;

////////////////////////Columns//////////////
   cout << "\n         ---Conflicts Column---\n       1  2  3  4  5  6  7  8  9" << endl;
   for (int i = 1; i <= BoardSize; i++)
   {
         cout << "     " << beginT;
	 for (int j = 1; j <= BoardSize; j++)
	    cout << line << line << line;
         cout << endT;
	 cout << endl;
      for (int j = 1; j <= BoardSize; j++)
      {
      if(j == 1){
		 cout << "Col " << i << side;
	 }
	    cout << " " << column[i][j] << " ";
      }
      cout << side;
      cout << endl;
   }

   cout << "     " << beginT;
   for (int j = 1; j <= BoardSize; j++)
	    cout << line << line << line;
   cout << endT;
   cout << endl;



   ////////////////////////Square//////////////
   cout << "\n         ---Conflicts Square---\n       1  2  3  4  5  6  7  8  9" << endl;
   for (int i = 1; i <= BoardSize; i++)
   {
         cout << "     " << beginT;
	 for (int j = 1; j <= BoardSize; j++)
	    cout << line << line << line;
         cout << endT;
	 cout << endl;
      for (int j = 1; j <= BoardSize; j++)
      {
      if(j == 1){
		 cout << "Sqr " << i << side;
	 }
	    cout << " " << square[i][j] << " ";
      }
      cout << side;
      cout << endl;
   }

   cout << "     " << beginT;
   for (int j = 1; j <= BoardSize; j++)
	    cout << line << line << line;
   cout << endT;
   cout << endl;

}

void board::setCell(int i, int j, int input)
{
	value[i][j] = input;
	updateConflicts();
}

void board::clearCell(int i, int j)
{
	value[i][j] = NULL;
	updateConflicts();
}

void board::initialize(ifstream &fin)
// Read a Sudoku board from the input file.
{
   char ch;

   clear();
   for (int i = 1; i <= BoardSize; i++)
      for (int j = 1; j <= BoardSize; j++)
      {
	 fin >> ch;

         // If the read char is not Blank
	 if (ch != '.')
	 {
            setCell(i,j,ch-'0');   // Convert char to int
	 }
      }
}

int squareNumber(int i, int j)
// Return the square number of cell i,j (counting from left to right,
// top to bottom.  Note that i and j each go from 1 to BoardSize
{
   // Note that (int) i/SquareSize and (int) j/SquareSize are the x-y
   // coordinates of the square that i,j is in.  

   return SquareSize * ((i-1)/SquareSize) + (j-1)/SquareSize + 1;
}

ostream &operator<<(ostream &ostr, vector<int> &v)
// Overloaded output operator for vector class.
{
   for (int i = 0; i < v.size(); i++)
      ostr << v[i] << " ";
   ostr << endl;
   return ostr;
}

ValueType board::getCell(int i, int j)
// Returns the value stored in a cell.  Throws an exception
// if bad values are passed.
{
   if (i >= 1 && i <= BoardSize && j >= 1 && j <= BoardSize){
      return value[i][j];
   }
   else
      throw rangeError("bad value in getCell");
}

bool board::isBlank(int i, int j)
// Returns true if cell i,j is blank, and false otherwise.
{ 
   if (i < 1 || i > BoardSize || j < 1 || j > BoardSize)
      throw rangeError("bad value in setCell");
   
	if(value[i][j] == NULL)
		return true;
	else
		return false;
}

void board::print()
// Prints the current board.
{

	
	//Setup ASCII Char
	char endT = 180;
	char beginT = 195;
	char side = 179;
	char line = 196;
	char T = 197;

	cout << "       ---Sudoku Table---" << endl;
   for (int i = 1; i <= BoardSize; i++)
   {

      if ((i-1) % SquareSize == 0)
      {
         cout << beginT << line;
	 for (int j = 1; j <= BoardSize; j++)
	    cout << line << line << line;
         cout << line << endT;
	 cout << endl;
      }
      for (int j = 1; j <= BoardSize; j++)
      {
	 if ((j-1) % SquareSize == 0)
	    cout << side;
	 if (!isBlank(i,j))
		cout << " " << getCell(i,j) << " ";
	 else
	    cout << "   ";
      }
      cout << side;
      cout << endl;
   }

    cout << beginT << line;
	 for (int j = 1; j <= BoardSize; j++)
	    cout << line << line << line;
         cout << line << endT;
	 cout << endl;
}


bool board::checkConflicts(int i, int j, int input){
	if(row[i][input] == true){
		return true;
	}
	if(column[j][input] == true){
		return true;
	}
	//Square Chart
	//-----------
	//|1 | 2 | 3|
	//-----------
	//|4 | 5 | 6|
	//-----------
	//|7 | 8 | 9|
	//-----------
	if(i <= 3){
				  if(j <= 3) {
					  return square[1][input];
				  }
				  if(j > 3 && j <=6){
					  return square[2][input];
				  }
				  if(j > 7){
					  return square[3][input];
				  }
	}
	if(i > 3 && i <=6){
				  if(j <= 3) {
					  return square[4][input];
				  }
				  if(j > 3 && j <=6){
					  return square[5][input];
				  }
				  if(j > 7){
					  return square[6][input];
				  }
	}
	if(i > 7){
				  if(j <= 3) {
					  return square[7][input];
				  }
				  if(j > 3 && j <=6){
					  return square[8][input];
				  }
				  if(j > 7){
					  return square[9][input];
				  }
	}
}



bool board::checkSolved(){
	//check Matrix for Full(SOLVED) - we will
	for (int i = 1; i <= BoardSize; i++)
      for (int j = 1; j <= BoardSize; j++){
		  if(isBlank(i,j)){
			  cout << "\nBoard is not Solved\n";
			  return false;
		  }
	}
	cout << "\nCONGRADULATIONS! Board is Solved\n";
	return true;
}
