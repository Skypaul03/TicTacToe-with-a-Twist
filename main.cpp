#include <iostream>
using namespace std;

const int SIZE = 4; // Size of the grid (4x4)
char board[SIZE][SIZE]; // The game board
char currentPlayer = 'X'; // Current player

// Function to initialize the game board
void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

// Function to display the game board
void displayBoard() {
    cout << "  ";
    for (int i = 0; i < SIZE; i++) {
        cout << i + 1 << " ";
    }
    cout << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if the board is full
bool isBoardFull() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == '-') {
                return false;
            }
        }
    }
    return true;
}

// Function to check for a win
bool checkWin() {
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        bool rowWin = true;
        for (int j = 1; j < SIZE; j++) {
            if (board[i][j] != board[i][0] || board[i][0] == '-') {
                rowWin = false;
                break;
            }
        }
        if (rowWin) return true;
    }
    // Check columns
    for (int j = 0; j < SIZE; j++) {
        bool colWin = true;
        for (int i = 1; i < SIZE; i++) {
            if (board[i][j] != board[0][j] || board[0][j] == '-') {
                colWin = false;
                break;
            }
        }
        if (colWin) return true;
    }
    // Check diagonals
    bool diag1Win = true;
    bool diag2Win = true;
    for (int i = 1; i < SIZE; i++) {
        if (board[i][i] != board[0][0] || board[0][0] == '-') {
            diag1Win = false;
        }
        if (board[i][SIZE - i - 1] != board[0][SIZE - 1] || board[0][SIZE - 1] == '-') {
            diag2Win = false;
        }
    }
    return diag1Win || diag2Win;
}

// Function to check if current player lost
bool checkLoss() {
    return checkWin();
}

// Function to switch player
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to make a move
void makeMove() {
    int row, col;
    do {
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
        row--;
        col--;
    } while (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != '-');
    board[row][col] = currentPlayer;
}

// Main function
int main() {
    initializeBoard();
    while (true) {
        displayBoard();
        makeMove();
        if (checkLoss()) {
            displayBoard();
            cout << "Player " << currentPlayer << " loses!" << endl;
            cout << "Player " << (currentPlayer == 'X' ? 'O' : 'X') << " wins!" << endl;
            break;
        }
        if (isBoardFull()) {
            displayBoard();
            cout << "The game is a draw!" << endl;
            break;
        }
        switchPlayer();
    }
    return 0;
}
