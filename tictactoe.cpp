#include <iostream>
using namespace std;

char board[3][3]; // Game board
char currentPlayer = 'X';

// Function to initialize the board with numbers 1-9
void initializeBoard() {
    char value = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = value++;
        }
    }
}

// Function to display the board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n---+---+---\n";
    }
    cout << "\n";
}

// Function to check if the move is valid
bool isValidMove(int pos) {
    int row = (pos - 1) / 3;
    int col = (pos - 1) % 3;
    return board[row][col] != 'X' && board[row][col] != 'O';
}

// Function to make a move
void makeMove(int pos) {
    int row = (pos - 1) / 3;
    int col = (pos - 1) % 3;
    board[row][col] = currentPlayer;
}

// Function to check if there's a winner
bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == currentPlayer &&
             board[i][1] == currentPlayer &&
             board[i][2] == currentPlayer) ||
            (board[0][i] == currentPlayer &&
             board[1][i] == currentPlayer &&
             board[2][i] == currentPlayer))
            return true;
    }

    // Check diagonals
    if ((board[0][0] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer &&
         board[1][1] == currentPlayer &&
         board[2][0] == currentPlayer))
        return true;

    return false;
}

// Function to check if the board is full
bool isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

// Main game loop
void playGame() {
    int move;

    while (true) {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if (move < 1 || move > 9 || !isValidMove(move)) {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        makeMove(move);

        if (checkWin()) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        } else if (isDraw()) {
            displayBoard();
            cout << "It's a draw!\n";
            break;
        }

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

// Main function
int main() {
    cout << "Welcome to Tic Tac Toe!\n";
    initializeBoard();
    playGame();
    return 0;
}
