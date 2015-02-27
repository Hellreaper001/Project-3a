/*
main.cpp
Authors: Andrew Blum and Justin Hynes-Bruell

Description: Reads boards in from a file and completes them, printing out before and after versions of each board. 
Project 3a: read in board, print board, find initial conflicts, print conflicts
		3b: finish the program
*/

#include "board.cpp"

using namespace std;

void playgame();

int main() {
	playgame();
	return 0;
}

//main subprogram to run the program, allows self calling
void playgame() {
	//sets file name
	string fileName;
	cout << "What file would you like to use? ";
	cin >> fileName;
	board game(fileName);
	//ignores the enter from when the filename is inputted
	cin.ignore();
	//prints each board from the file (after Enter is pressed)
	while(game.NumRemainingBoards() > 0){
		game.printBoard();
		
		cout << "Ready to continue? (Press ENTER to continue)\n";
		//waits for user input
		cin.ignore();
		game.nextBoard();
	}
	//prints last game from list (while loop doesn't do this)
	game.printBoard();
	
	//checks to see if the player wants to play again
	cout << "Play again? (y/n) ";
	cin >> fileName;
	if(fileName == "y" || fileName == "Y") {
		playgame();
	}
}
