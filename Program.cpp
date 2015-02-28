/*
Program By:
Justin Hynes-Bruell
Andrew Blum

Main Program
*/

#include "board.h"  //Include board class



int main()
{
   ifstream fin;
   
   // Read the sample grid from the file.
   string fileName = "sudoku.txt";

   fin.open(fileName.c_str());
   if (!fin)
   {
      cerr << "Cannot open " << fileName << endl;
      exit(1);
   }

   try
   {
      board b1;

      while (fin && fin.peek() != 'Z')
      {
	 b1.initialize(fin);
	 b1.print();
	 b1.printConflicts();
	 cout << "\nPress enter to Continue";
	 cin.ignore();
      }
   }
   catch  (indexRangeError &ex)
   {
      cout << ex.what() << endl;
      exit(1);
   }
}



