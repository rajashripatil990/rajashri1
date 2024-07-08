#include <iostream>
using namespace std;

const int SIZE = 3; // The size of the board (3x3 for Tic Tac Toe)

// Function to display the game board
void displayBoard(char board[SIZE][SIZE]) {
    cout << "\n";
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            cout << " " << board[row][col];
            if (col < SIZE - 1) cout << " |";
        }
        cout << "\n";
        if (row < SIZE - 1) cout << "---+---+---\n";
    }
    cout << "\n";
}

// Function to check if there is a winner
bool checkWin(char board[SIZE][SIZE], char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check for a draw
bool checkDraw(char board[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            if (board[row][col] == ' ') {
                return false; // Found an empty space, so not a draw
            }
        }
    }
    return true; // No empty spaces, so it's a draw
}

// Function to handle a player's move
bool makeMove(char board[SIZE][SIZE], int row, int col, char player) {
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    } else {
        return false; // Invalid move
    }
}

int main() {
    char board[SIZE][SIZE] = {
        { ' ', ' ', ' ' },
        { ' ', ' ', ' ' },
        { ' ', ' ', ' ' }
    };

    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;

    cout << "Welcome to Tic Tac Toe!\n";
    displayBoard(board);

    while (!gameWon && !gameDraw) {
        int row, col;
        cout << "Player " << currentPlayer << "'s turn. Enter row and column (0-2): ";
        cin >> row >> col;

        if (makeMove(board, row, col, currentPlayer)) {
            displayBoard(board);

            if (checkWin(board, currentPlayer)) {
                gameWon = true;
                cout << "Player " << currentPlayer << " wins!\n";
            } else if (checkDraw(board)) {
                gameDraw = true;
                cout << "It's a draw!\n";
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch player
            }
        } else {
            cout << "Invalid move. Try again.\n";
        }
    }

    return 0;
}

