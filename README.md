# Tic-tac-Toe-Game Using C++
Hello, I am Rudra Kathait I have Created a Tic tac toe Game for My InHouse Summer Training.

->This is a simple command-line Tic-Tac-Toe game implemented in C++. The game supports two modes:

1. Two-player mode where two human players can play against each other.
2. Single-player mode where a human player can play against the computer (CPU).
->Features
1. Play against another player or the CPU: You can choose to play against another human player or challenge the CPU.
2. Interactive gameplay: The game prompts each player to enter their move and provides feedback if the move is invalid.
3. Score tracking: The game keeps track of the score for both players across multiple rounds.
4. Replay option: After each game, you can choose to play again.
Requirements
C++ compiler (such as g++)
Command-line interface
How to Compile and Run
Compile the program:

bash
Copy code
g++ -o TicTacToe main.cpp
Run the program:

bash
Copy code
./TicTacToe
How to Play
When you start the game, you'll be welcomed with a message and prompted to enter the name for Player X.
You can then choose whether to play against the CPU by entering 'y' or 'n'.
If you choose to play against the CPU, Player O will be set to "CPU". Otherwise, you'll be prompted to enter the name for Player O.
The game will then begin, displaying an empty 3x3 board.
Players take turns entering their move by specifying the row and column numbers (0, 1, or 2).
The game checks for a win or a draw after each move. If a player wins or if the game is a draw, the result is displayed.
The game also displays the current score and asks if you want to play again.
If you choose to play again, the board is reset and a new game begins.
Example Gameplay
markdown
Copy code
Welcome to Tic-Tac-Toe!
Enter name for Player X: Alice
Do you want to play against the CPU? (y/n): y

-------------
|   |   |   | 
-------------
|   |   |   | 
-------------
|   |   |   | 
-------------
Alice (X), enter row (0-2) and column (0-2): 0 0
-------------
| X |   |   | 
-------------
|   |   |   | 
-------------
|   |   |   | 
-------------
CPU is making a move...
-------------
| X |   |   | 
-------------
|   | O |   | 
-------------
|   |   |   | 
-------------
Alice (X), enter row (0-2) and column (0-2): 1 1
-------------
| X |   |   | 
-------------
|   | X |   | 
-------------
|   |   |   | 
-------------
CPU is making a move...
...
Code Explanation
Functions
drawBoard: Draws the current state of the board.
checkWin: Checks if a player has won the game.
checkDraw: Checks if the game is a draw.
resetBoard: Resets the board to its initial empty state.
cpuMove: Generates a random move for the CPU.
Main Function
Initializes the random seed.
Prompts for player names and game mode.
Contains the main game loop where players take turns making moves.
Checks for wins and draws after each move.
Tracks the score and asks if the players want to play again.
Conclusion
This Tic-Tac-Toe game is a simple yet engaging project that helps practice basic C++ programming concepts, including loops, conditionals, functions, and arrays. The addition of playing against the CPU makes it more fun and challenging. Enjoy the game!
