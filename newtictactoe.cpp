#include <iostream>
#include <limits>
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;

void drawBoard(char board[3][3]) 
{ 
	cout << "-------------\n"; 
	for (int i = 0; i < 3; i++) { 
		cout << "| "; 
		for (int j = 0; j < 3; j++) { 
			cout << board[i][j] << " | "; 
		} 
		cout << "\n-------------\n"; 
	} 
} 

bool checkWin(char board[3][3], char player) 
{ 
	for (int i = 0; i < 3; i++) { 
		if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
			return true; 
		if (board[0][i] == player && board[1][i] == player && board[2][i] == player) 
			return true; 
	} 
	if (board[0][0] == player && board[1][1] == player && board[2][2] == player) 
		return true; 
	if (board[0][2] == player && board[1][1] == player && board[2][0] == player) 
		return true; 
	return false; 
} 

bool checkDraw(char board[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == ' ')
				return false;
		}
	}
	return true;
}

void resetBoard(char board[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
}

void cpuMove(char board[3][3]) {
	int row, col;
	do {
		row = rand() % 3;
		col = rand() % 3;
	} while (board[row][col] != ' ');

	board[row][col] = 'O';
}

int main() 
{ 
	srand(static_cast<unsigned int>(time(0))); // Seed for random number generation
	char board[3][3];
	char player = 'X'; 
	int row, col; 
	int turn;
	int scoreX = 0, scoreO = 0;
	string playerX, playerO;
	char playAgain;
	bool playWithCPU = false;

	cout << "Welcome to Tic-Tac-Toe!\n"; 
	cout << "Enter name for Player X: ";
	cin >> playerX;
	cout << "Do you want to play against the CPU? (y/n): ";
	char cpuOption;
	cin >> cpuOption;
	if (cpuOption == 'y' || cpuOption == 'Y') {
		playWithCPU = true;
		playerO = "CPU";
	} else {
		cout << "Enter name for Player O: ";
		cin >> playerO;
	}

	do {
		resetBoard(board);
		player = 'X';
		for (turn = 0; turn < 9; turn++) { 
			drawBoard(board); 

			if (player == 'X' || !playWithCPU) {
				while (true) { 
					cout << player << " (" << (player == 'X' ? playerX : playerO) << "), enter row (0-2) and column (0-2): "; 
					cin >> row >> col; 

					if (row < 0 || row > 2 || col < 0 || col > 2 || cin.fail()) {
						cin.clear(); // Clear the error flag
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
						cout << "Invalid input. Try again.\n";
					} 
					else if (board[row][col] != ' ') { 
						cout << "Invalid move. Try again.\n"; 
					} 
					else { 
						break; 
					} 
				}
				board[row][col] = player;
			} else {
				cout << "CPU is making a move...\n";
				cpuMove(board);
			}

			if (checkWin(board, player)) { 
				drawBoard(board); 
				cout << player << " (" << (player == 'X' ? playerX : playerO) << ") wins!\n"; 
				if (player == 'X') scoreX++; else scoreO++;
				break; 
			} 

			player = (player == 'X') ? 'O' : 'X'; 
		} 

		if (turn == 9 && !checkWin(board, 'X') && !checkWin(board, 'O')) { 
			drawBoard(board); 
			cout << "It's a draw!\n"; 
		}

		cout << "Score: " << playerX << " (X): " << scoreX << " - " << playerO << " (O): " << scoreO << "\n";
		cout << "Do you want to play again? (y/n): ";
		cin >> playAgain;

	} while (playAgain == 'y' || playAgain == 'Y');

	cout << "Thanks for playing!\n";
	return 0; 
}
