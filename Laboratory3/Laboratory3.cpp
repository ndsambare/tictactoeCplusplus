// Laboratory3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Dimensions.h"
#include "Header.h"
#include "TicTacToeGame.h"
using namespace std;






int main(int argc, char * argv[])
{
	
	
	if (argc == correctNumArgs) {
	
		string word = argv[inputName];
		
		//second argument must be TicTacToe to play the game
		
		if (word == "TicTacToe") {
		     TicTacToeGame game; 
			int playReturn = game.play(false); 
			return playReturn; 


		}
		else {
			//returns correct input if input to play the game is incorrect
			 return usageFunction(argv[programName], "Laboratory3.exe TicTacToe");
		}
   }
	else if (argc == autoPlayer) {
		string word = argv[inputName];
		string wordTwo = argv[two];

		if (word == "TicTacToe" && wordTwo == "auto_player") {
			TicTacToeGame game;
			int playReturn = game.play(true);
			return playReturn;


		}
		else {
			//returns correct input if input to play the game is incorrect
			return usageFunction(argv[programName], "Laboratory3.exe TicTacToe auto_player");
		}

	}
	else {
		//returns correct input if input to play the game is incorrect
		return usageFunction(argv[programName], "Laboratory3.exe TicTacToe auto_player");
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
