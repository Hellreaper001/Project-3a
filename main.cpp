#include "board.cpp"

using namespace std;

void playgame();

int main() {
	playgame();
	return 0;
}

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
