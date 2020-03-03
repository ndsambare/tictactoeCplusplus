Name: Namit Sambare --- Lab 3



Trial 1: The first error I ran into was that my constructor was not declared correctly. I did not declare the constructor for the class in the TicTacToeGame.cpp source file, and instead I declared it in my header file. This prevented my project from successfully printing the game board. 
Solution: After I moved the constructor into the TicTacToeGame.cpp source file, my game board printed out correctly. The problem was just the printing of the game board, there was no problem with actually putting in an X or O into the game board. 

Trial 2: During the second trial, the issue that occurred was that the beginning of my prompt method kept running. So, whenever I input anything, the console prompted the "Type where you want to put your piece as a comma separated coordinate (e.g 2,2) or type 'quit' to end the game " message.
Solution: There are multiple locations in my code where this message can be printed out to the console. So, I did a test by printing out different messages at each location to know which specific spot in my code program was getting stuck at. I concluded that it was the message at line 85 (the first time the message is printed in the prompt() method). 
Moreover, I also then debugged this program error by looking at my turn() method. I realized that when I was using a boolean to represent if it was Player X's turn or not (true = Player X turn, false = Player O turn), my turn method was never changing who's turn it was. So, I changed my logic here by using a counter variable (turnNumber) to keep track of how many turns had been executed. If the turnNumber mod 2 was equal to 0, it would be Player X's turn. Therefore, if the turnNUmber mod 2 was equal to 1, it would be Player O's turn. 

