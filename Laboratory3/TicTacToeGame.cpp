#include <iostream>
#include <string>
#include "Dimensions.h"
#include "TicTacToeGame.h"
#include <sstream>
#include "Errors.h"

using namespace std;



ostream& operator << (ostream& output, const TicTacToeGame& game) {

	for (int i = height -1; i >= 0; i--) {
	cout << i << endl;
		for (int j = 0; j < width; j++) {
			
		
			cout << game.gameBoard[i][j] << endl; 
		}
	
	}

	for (int k = 0; k < width; k++) {
	cout << k << endl; 
	}
 

	return output; 
}

bool TicTacToeGame::done() {
	for (int i = 1; i <= width - 2; i++) {

		for (int j = 1; j <= height -2; j++) {

			if (gameBoard[i][j] == gameBoard[i - 1][j] == gameBoard[i + 1][j]) {
				return true; 
			}

			if (gameBoard[i][j] == gameBoard[i][j - 1] == gameBoard[i][j + 1]) {
				return true; 
			}

			if (gameBoard[i][j] == gameBoard[i - 1][j - 1] == gameBoard[i + 1][j + 1]) {
				return true; 
			}

			if (gameBoard[i][j] == gameBoard[i + 1][j - 1] == gameBoard[i - 1][j + 1]) {
				return true; 
			}
		
		}

	}
	return false; 
}

bool TicTacToeGame::draw() {
	
		if (done() || (gameBoard[one][one] == ' ' || gameBoard[one][two] == ' ' || gameBoard[one][three] == ' ' || gameBoard[two][one] == ' ' || gameBoard[two][two] == ' ' || gameBoard[two][three] == ' ' || gameBoard[three][one] == ' ' || gameBoard[three][two] == ' ' || gameBoard[three][three] == ' '))
		return false; 
	
	else {
		return true; 
	}
}

int TicTacToeGame::prompt(unsigned int& alpha, unsigned int& beta)
{
	cout << "Type where you want to put your piece as a comma separated coordinate (e.g 2,2) or type 'quit' to end the game";


	string inputString;
	while (true) {
		getline(cin, inputString);

		for (int i = 0; i < inputString.length(); i++) {
			if (inputString[i] == ',') {
				inputString[i] = ' ';
			}
		}

		if (inputString != "quit") {

			istringstream iss(inputString);
			if (iss >> alpha) {

				if (iss >> beta) {
					return success;
				}
				else {
					cout << "Type where you want to put your piece as a comma separated coordinate (e.g 2,2) or type 'quit' to end the game";
				}
			}
			else {
				cout << "Type where you want to put your piece as a comma separated coordinate (e.g 2,2) or type 'quit' to end the game";
			}

		}
		else {
			return quitGame;
			cout << "Game is ended.";
		}





	}
}



int TicTacToeGame::turn() {
	unsigned int userInputOne; 
	unsigned int userInputTwo; 

	if (playerXTurn) {
	cout << "It is Player X's turn"; 
	}

	if (!playerXTurn) {
	cout << "It is player O's turn.";
	}

	while (true) {

		if (prompt(userInputOne, userInputTwo) == quitGame) {
			return quitGame;
		}

		if (userInputOne >= one && userInputOne <= three) {
			if (userInputTwo >= one && userInputTwo <= three) {
				if (gameBoard[userInputOne][userInputTwo] == ' ') {

					if (playerXTurn) {
						gameBoard[userInputOne][userInputTwo] = 'X';

					}
					else {
						gameBoard[userInputOne][userInputTwo] = 'O';
					}
					cout << *this;
					return success; 
				}

			

			}
		}
			

		
		
	}


	

	playerXTurn = !playerXTurn; 


}

int TicTacToeGame::play() {




	cout << *this;

	int resultTurn = turn();
	

	while (resultTurn == success) {
		if (done()) {
			if (playerXTurn) {
				cout << "Player O won the game.";
			}
			else {
				cout << "Player X won the game.";
			}
			
			return success;
		}
		else if (draw()) {
			int counter = 0; 
			for (int i = 1; i <= width - 2; i++) {

				for (int j = 1; j <= height - 2; j++) {

					if (gameBoard[i][j] != ' ') {
						counter++;
					}

				}

			}
			cout << "There are no winning moves and the game is a draw, there have been " + to_string(counter) + "turns played.";
		
		
			return drawGame;
		}

		
	}

		if (resultTurn == quitGame) {
			int counter = 0;
			for (int i = 1; i <= width - 2; i++) {

				for (int j = 1; j <= height - 2; j++) {

					if (gameBoard[i][j] != ' ') {
						counter++;
					}

				}

			}
			cout << "The user quit. There were" + to_string(counter) + "turns played.";

			return quitGame;
			
		}
	
	
	
	
}






