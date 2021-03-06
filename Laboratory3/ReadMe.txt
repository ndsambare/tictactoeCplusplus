Name: Namit Sambare --- Lab 3



Trial 1: The first error I ran into was that my constructor was not declared correctly. I did not declare the constructor for the class in the TicTacToeGame.cpp source file, and instead I declared it in my header file. This prevented my project from successfully printing the game board. 
Solution: After I moved the constructor into the TicTacToeGame.cpp source file, my game board printed out correctly. The problem was just the printing of the game board, there was no problem with actually putting in an X or O into the game board. 

Trial 2: During the second trial, the issue that occurred was that the beginning of my prompt method kept running. So, whenever I input anything, the console prompted the "Type where you want to put your piece as a comma separated coordinate (e.g 2,2) or type 'quit' to end the game " message.
Solution: There are multiple locations in my code where this message can be printed out to the console. So, I did a test by printing out different messages at each location to know which specific spot in my code program was getting stuck at. I concluded that it was the message at line 85 (the first time the message is printed in the prompt() method). 
Moreover, I also then debugged this program error by looking at my turn() method. I realized that when I was using a boolean to represent if it was Player X's turn or not (true = Player X turn, false = Player O turn), my turn method was never changing who's turn it was. So, I changed my logic here by using a counter variable (turnNumber) to keep track of how many turns had been executed. If the turnNumber mod 2 was equal to 0, it would be Player X's turn. Therefore, if the turnNUmber mod 2 was equal to 1, it would be Player O's turn. 

Trial 3: During the third trial, an error I ran into was that my play method was only calling my turn method once, and this was making my code only work again for one iteration of the game. So, I moved my call to turn in the while true loop (which I break out of in the correct scenarios). 
Solution: The solution of moving my call to turn in the loop fixed the problem and allowed the game to iterate through each turn instead of stopping after just one turn. 

Trial 4: My game seemingly worked correctly now. However, I noticed that the game wasn't determining when a player had won.
Solution: I realized that my syntax was incorrect as I tried to compare three spots in the game board at once. I forgot to put an && in between. So, the correct way to check if a player had one was to check if the first spot on the board was equal to the second spot && the first spot on the board was eqwual to the third spot && the first spot was not equal to a space. This logic worked and allowed me to determine the winner of the game. 

Trial 5: Next, I tried inputting various arguments that should not make sense. For example, the program should only take in input of the type "2,3", where both numbers are numbers between 1 and 3 and there is no other punctuation. 

   Various Input I tried: 
   1. "3,3" - worked as expected and put a mark at 3,3
   2. "3, 3" - spaces are not allowd so there was no mark put and user was prompted again
   3. "3 3" - spaces are not allowed and the numbers must be separated by commas so the user was prompted again 
   4. "3,3,3" - only two numbers are allowed so the user was prompted again
   5. "1,1," -only three characters are allowed : two numbers and one comma, so the user was prompted again
   6. "     " - there must be numbers so the user was prompted again
   7. "0,0" - This coordinate is not in the correct board range, so the user was prompted again
   8. "a,s" - There are no numbers so the user was prompted again

Trial 6: Next, I played the game so that the X's would win in a horizontal fashion, and the program worked as expected and printed out that X won. 

Trial 7: I played the game so that the X's would win in a vertical fashionm, and the program worked as expected and printed out that X won. 

Trial 8: I played the game so that the X's would win in both diagonal fashions, and the program worked as expected and printed out that X won. 

Trial 9: I tested each case (one vertical, one horizontal, and two diagonals) of winning the game for Player O, and the program worked as expected and printed out that O won. 

Trial 10: My input for the first terminal input was "Laboratory3.exe      " 
I recieved the correct expected output of the usage message prompting me with the correct output of "Laboratory3.exe TicTacToe"

Trial 11: My input for the first terminal input was "         "
I recieved the correct expected output of the usage message prompting me with the correct output of "Laboratory3.exe TicTacToe"

Trial 12:  My input for the first terminal input was "       

"
I recieved the correct expected output of the usage message prompting me with the correct output of "Laboratory3.exe TicTacToe"

Trial 13: I played the game so that no moves would remain and it would be a draw, and I got the expected output and the program printed that it was a draw. 

Trial 14: I played the game and halfway through I typed "quit" and the program did as expected and quit the game. 

Trial 15: I played the game and halfway through I typed "qui" and the program did as expected and prompted the user again. 

EXTRA CREDIT:
I implemented the extra credit by first adding a boolean as an argument to the play method. If the argument boolean is true, then that would indicate that the game will run with the auto player. I changed the main method in the Laboratory3.cpp file so that it checks if the terminal argument
includes "auto_player," and if it does then I would call the play method with the true boolean argument. If "auto_player" is not included in the terminal argument, then I would call the play method with the false argument parameter. In the TicTacToeGame.cpp file, I implemented 
a turnAuto method that was very similar to the turn method, but instead of having the human provide input for both Player X and Player O, the turnAuto only requires that the human provides input for Player X. For player O, it relies on the auto_player() method that I implemented to provide the correct coordinates for 
where the auto player (player O) should put down their piece. Finally, in the auto_player() method, I did an exhaustive check of the entire game board for two different scenarios. 
I first checked through the entire game board and checked to see if a spot had a space. If a spot had a space, I used a copy of the gameboard to check if putting an O down at that spot would lead to Player O winning. 
I used the done() method to check this. If the done() method returned true, then I would return the pair of coordinates where the done method returned true and use these as the spot for where the auto player would move. 
If the done() method did not return true, then I would simply put a space back into the copy of the game board and move to the next spot. 
Next, after checking if Player O could win, I had the method check if Player X would win anywhere and if they would, I had player O block player X. So, I iterated over all spots in the game board again that had a space. And if there was a space, then I would put an X in that spot. After putting the X in the spot, I would check to see 
if the done() method returned true. If it did, then I would remove the X with a space, and then return the coordinates of that spot, so that the auto player (player O) would block X's winning move. 
If the done() method returned false, then I would simply replace the X with another space. Finally, the final thing the auto_player method did was to randomly place a piece if there was no opportunity to win or block the X's. 

When run with the extra credit portion, the output is the same as if run with the regular portion. The program says if the game is a draw, or if someone wins. Also, when it is the human's turn, the program keeps reprompting if there is any bad input. 
