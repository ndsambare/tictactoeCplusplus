#include <iostream>
#include <string>
#include "Dimensions.h"
#include "TicTacToeGame.h"
#include <sstream>
#include "Errors.h"
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <time.h>

using namespace std;
//TicTacToe constructor, sets initial game board dimensions while creating empty game board and number of turns to 0 at the beginning. 
TicTacToeGame::TicTacToeGame()
	: width(5), height(5), turnNumber(0)
{
	for (int i = 0; i < height; i++) {
		
		for (int j = 0; j < width; j++) {


			gameBoard[i][j] = ' ';
		}

	}

}
//prints out game board coordinates correctly (descending vertically, ascending horizontally)
ostream& operator << (ostream& output, const TicTacToeGame& game) {

	for (int i = height -1; i >= 0; i--) {
	output << i ;
		for (int j = 0; j < width; j++) {
			
		
			output << game.gameBoard[j][i]; 
		}

		output << endl; 
	}
	cout << ' '; 
	for (unsigned int k = 0; k < width; k++) {
	output << k; 
	}
 

	return output; 
}
//this method checks to see if a player has won the game
bool TicTacToeGame::done() {
	for (int i = 1; i <= width - 2; i++) {

		for (int j = 1; j <= height -2; j++) {
			//checks to see if player has won horizontally
			if (gameBoard[i][j] == gameBoard[i - 1][j] && gameBoard[i][j] == gameBoard[i + 1][j] && gameBoard[i][j] != ' ') {
				return true; 
			}
			//checks to see if player has won vertically
			if (gameBoard[i][j] ==  gameBoard[i][j - 1] && gameBoard[i][j] == gameBoard[i][j + 1] && gameBoard[i][j] != ' ') {
				return true; 
			}
			//checks to see if if player has won on the right diagonal
			if (gameBoard[i][j] ==  gameBoard[i - 1][j - 1] && gameBoard[i][j] == gameBoard[i + 1][j + 1] && gameBoard[i][j] != ' ') {
				return true; 
			}
			//checks to see if the player has won on the left diagonal 
			if (gameBoard[i][j] ==  gameBoard[i + 1][j - 1] && gameBoard[i][j] == gameBoard[i - 1][j + 1] && gameBoard[i][j] != ' ') {
				return true; 
			}
		
		}

	}
	return false; 
}

//checks to see if no one wins the game 
bool TicTacToeGame::draw() {
	//wants to check if there game is won by a player, or if there are any empty spaces left
		if (done() || (gameBoard[one][one] == ' ' || gameBoard[one][two] == ' ' || gameBoard[one][three] == ' ' || gameBoard[two][one] == ' ' || gameBoard[two][two] == ' ' || gameBoard[two][three] == ' ' || gameBoard[three][one] == ' ' || gameBoard[three][two] == ' ' || gameBoard[three][three] == ' '))
		return false; 
	
	else {
		return true; 
	}
}

int TicTacToeGame::prompt(unsigned int& alpha, unsigned int& beta)
{
	cout << "Type where you want to put your piece as a comma separated coordinate (e.g 2,2) or type 'quit' to end the game ";

	int commaCount = zero;
	string inputString;
	while (true) {
		getline(cin, inputString);
		//commaCounter makes sure only one comma is seen in input
		//loop replaces comma with a space
		for (unsigned int i = 0; i < inputString.length(); i++) {
			if (inputString[i] == ',') {
				inputString[i] = ' ';
				commaCount++;
			}
		}

		

		if (inputString != "quit") {

			istringstream iss(inputString);
			if (iss >> alpha) {
				
				if (iss >> beta) {
					//use extraction operator to put the unsigned int inputs into alpha and beta, if incorrect input, user is prompted again
					if (inputString.length() == three) {
						if (commaCount == one) {
							return success;
						}
						else {
							cout << "Type where you want to put your piece as a comma separated coordinate (e.g 2,2) or type 'quit' to end the game " << endl;
						}
						
					}
					else {
						cout << "Type where you want to put your piece as a comma separated coordinate (e.g 2,2) or type 'quit' to end the game " << endl;
					}
					
					
				}
				else {
					cout << "Type where you want to put your piece as a comma separated coordinate (e.g 2,2) or type 'quit' to end the game " << endl;
					
				}
			}
			else {
				cout << "Type where you want to put your piece as a comma separated coordinate (e.g 2,2) or type 'quit' to end the game " << endl;
				
			}

		}
		//if user types "quit" the game is ended
		else {
			cout << "Game is ended.";
			return quitGame;
			
		}





	}
}



int TicTacToeGame::turn() {
	unsigned int userOne, userTwo;
	unsigned int& userInputOne = userOne; 
	unsigned int& userInputTwo = userTwo; 
	
	//uses turnNumber to determine who's turn it is as turns alternate between player X and player O
	if ((turnNumber % 2) == zero) {
	cout << " It is Player X's turn. " << endl; 
	}

	if ((turnNumber % 2) == one) {
	cout << " It is Player O's turn. " << endl;
	}

	while (true) {
		

		if (prompt(userInputOne, userInputTwo) == quitGame) {
			return quitGame;
		}
		//makes sure user inputs numbers in the correct dimensions and that there is a space for where the user wants to put their piece
		else if (userInputOne >= one && userInputOne <= three) {
			if (userInputTwo >= one && userInputTwo <= three) {
				if (gameBoard[userInputOne][userInputTwo] == ' ') {

					if ((turnNumber % 2) == zero) {
						
						gameBoard[userInputOne][userInputTwo] = 'X';
						
						turnNumber = turnNumber + 1;

						cout << *this;
						return success;

					}
					else if ((turnNumber % 2) == one) {
						gameBoard[userInputOne][userInputTwo] = 'O';
						
						turnNumber = turnNumber + 1;
						cout << *this;
						return success;
					}
					
				}

			

			}
		}
			

		
		
	}


	

	


}


int TicTacToeGame::turnAuto() {
	unsigned int userOne, userTwo;
	unsigned int& userInputOne = userOne;
	unsigned int& userInputTwo = userTwo;

	//uses turnNumber to determine who's turn it is as turns alternate between player X and player O
	if ((turnNumber % 2) == zero) {
		cout << " It is Player X's turn. " << endl;
	}

	if ((turnNumber % 2) == one) {
		cout << " It is Player O's turn. " << endl;
	}

	while (true) {
		

	if ((turnNumber % 2) == one) {
		
		pair<int,int> coordinates = auto_player();
		if (gameBoard[coordinates.first][coordinates.second] == ' ' && gameBoard[coordinates.first][coordinates.second] != 'X' && gameBoard[coordinates.first][coordinates.second] != 'O') {
			gameBoard[coordinates.first][coordinates.second] = 'O';
		}
		
		
		
		cout << *this;
		turnNumber++;
		return success;
	}
	else {
		if (prompt(userInputOne, userInputTwo) == quitGame) {
			return quitGame;
		}

		if (userInputOne >= one && userInputOne <= three) {
			if (userInputTwo >= one && userInputTwo <= three) {
				if (gameBoard[userInputOne][userInputTwo] == ' ') {

					if ((turnNumber % 2) == zero) {

						gameBoard[userInputOne][userInputTwo] = 'X';

						turnNumber++;

						cout << *this;
						return success;

					}


				}



			}
		}




	}

	}


		
		
	







}

int TicTacToeGame::play(bool ifAuto) {




	cout << *this;
	//prints out the game board at the beginning

	bool result = true;

	//loop calls turn, done, and draw repeatedly to keep progressing through the game
	while (true) {
		int resultTurn;
	

		if (ifAuto) {
			resultTurn = turnAuto();
		}
		else {
			resultTurn = turn();
		}
		if (resultTurn == quitGame) {
			cout << "The user quit. There were " + to_string(turnNumber) + " turns played.";

			return quitGame;
			break;
		}
		//checks if game is done
		if (done()) {
			if ((turnNumber % 2) == zero) {
				cout << " Player O won the game. ";
			}
			else if ((turnNumber % 2) == one) {
				cout << " Player X won the game. ";
			}
			result = false;
			return success;

		}
		//checks if game is a draw
		else if (draw()) {

			cout << " There are no winning moves and the game is a draw, there have been " + to_string(turnNumber) + " turns played.";

			result = false;
			return drawGame;
		}
		


	}
}











	pair<int,int> TicTacToeGame::auto_player() {
		
		TicTacToeGame t = *this;
		cout << t << endl;
			//CPU will be the O's and human will be the X'
				for (int i = 1; i <= 3; i++) {
					for (int j = 1; j <= 3; j++) {
						//checks if putting an O down will win the game and puts it down if thats the case
						if (t.gameBoard[i][j] == ' ') {
							t.gameBoard[i][j] = 'O';
							if (t.done()) {
								return { i,j };
							}
							else {
								t.gameBoard[i][j] = ' ';
							}
						}
						
					}
				}

				for (int i = 1; i <= 3; i++) {
					for (int j = 1; j <= 3; j++) {
						//checks if putting an X down will win the game and puts an O in the spot if thats the case
						if (t.gameBoard[i][j] == ' ') {
							t.gameBoard[i][j] = 'X';
							if (t.done()) {
								t.gameBoard[i][j] = ' ';
								t.gameBoard[i][j] = 'O';

								return { i,j };
							}
							else {

								t.gameBoard[i][j] = ' ';

							}
						}
					}
				}
				srand(time(NULL));
				
				int xRandom = rand() % 3 + 1;
				int yRandom = rand() % 3 + 1;
					
				while (t.gameBoard[xRandom][yRandom] != ' ' && (t.gameBoard[xRandom][yRandom] == 'X' || t.gameBoard[xRandom][yRandom] == 'O')) {
				 xRandom = rand() % 3 + 1;
				  yRandom = rand() % 3 + 1;
					
				}
				

				t.gameBoard[xRandom][yRandom] = 'O';

				return { xRandom,yRandom };
			
		







	}







