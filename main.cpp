#include "board.cpp"

using namespace std;

void playgame();

int main() {
	playgame();
	return 0;
}

void playgame() {
	string fileName;
	cout << "What file would you like to use? ";
	cin >> fileName;
	board game(fileName);
	while(game.NumRemainingBoards() > 0){
		game.printBoard();
		
		cout << "Ready to continue? (Press ENTER to continue)\n";
		cin.ignore();
		game.nextBoard();
	}
	cout << "Play again? ";
	cin >> fileName;
	if(fileName == "y") {
		playgame();
	}
}
