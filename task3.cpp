/*Build a simple console-based Tic-Tac-Toe game that
allows two players to play against each other
Game Board: Create a 3x3 grid as the game board.
Players: Assign "X" and "O" to two players.
Display Board: Show the current state of the board.
Player Input: Prompt the current player to enter their move.
Update Board: Update the game board with the player's move.
Check for Win: Check if the current player has won.
Check for Draw: Determine if the game is a draw.
Switch Players: Alternate turns between "X" and "O" players.
Display Result: Show the result of the game (win, draw, or ongoing).
Play Again: Ask if the players want to play another game.*/

#include <iostream>
using namespace std;

char board[3][3]; // Game board
char currentPlayer = 'X'; // Current player ('X' or 'O')

// Function to initialize the game board
void initializeBoard() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

// Function to display the game board
void displayBoard() {
    cout << "  0 1 2" << endl;
    for(int i = 0; i < 3; i++) {
        cout << i << " ";
        for(int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if the move is valid
bool isValidMove(int row, int col) {
    if(row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != '-') {
        return false;
    }
    return true;
}

// Function to check if the current player has won
bool checkWin() {
    // Check rows and columns
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
            return true; // Row win
        }
        if(board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
            return true; // Column win
        }
    }
    // Check diagonals
    if(board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
        return true; // Diagonal win
    }
    if(board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
        return true; // Diagonal win
    }
    return false; // No win
}

// Function to check if the game is a draw
bool checkDraw() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == '-') {
                return false; // Empty cell found, game is not draw
            }
        }
    }
    return true; // No empty cell found, game is draw
}

// Function to switch players
void switchPlayers() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    initializeBoard();
    bool gameOver = false;

    while(!gameOver) {
        displayBoard();
        int row, col;
        cout << "Player " << currentPlayer << "'s turn. Enter row and column (0-2): ";
        cin >> row >> col;

        if(isValidMove(row, col)) {
            board[row][col] = currentPlayer;
            if(checkWin()) {
                displayBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameOver = true;
            } else if(checkDraw()) {
                displayBoard();
                cout << "It's a draw!" << endl;
                gameOver = true;
            } else {
                switchPlayers();
            }
        } else {
            cout << "Invalid move. Please try again." << endl;
        }
    }

    char playAgain;
    cout << "Do you want to play again? (Y/N): ";
    cin >> playAgain;
    if(playAgain == 'Y' || playAgain == 'y') {
        initializeBoard();
        gameOver = false;
        currentPlayer = 'X';
    } else {
        cout << "Thanks for playing!" << endl;
    }

    return 0;
}

