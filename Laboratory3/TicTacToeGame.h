#include "Dimensions.h"
#include <iostream>
#include <string>

using namespace std;


class TicTacToeGame {
	TicTacToeGame();
	friend ostream& operator << (ostream& output, const TicTacToeGame& game);



public:
	bool done() {}
	bool draw() {}
	int prompt(unsigned int & alpha, unsigned int & beta) {}
	int turn() {}

private:
	char gameBoard[width][height];
	const int width = width;
	const int height = height;
	bool playerXTurn = true; 

}; 

ostream& operator << (ostream& output, const TicTacToeGame& game);


