#pragma once
#include "Dimensions.h"
#include <iostream>
#include <string>

using namespace std;


class TicTacToeGame {
	
	friend ostream& operator << (ostream& output, const TicTacToeGame& game);



public:
	TicTacToeGame();
	bool done();
	bool draw();
	int prompt(unsigned int& alpha, unsigned int& beta);
	int turn();
	int play();
	

private:
	char gameBoard[width][height];
	const int width;
	const int height;
	int turnNumber; 

}; 

ostream& operator << (ostream& output, const TicTacToeGame& game);


