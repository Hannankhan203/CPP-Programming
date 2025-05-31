#include <iostream>
#include <vector>

using namespace std;

// Function to draw the Tic Tac Toe board
void drawBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if there is a winner
char checkWinner(const vector<vector<char>>& board) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != '.' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
        if (board[0][i] != '.' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    // Check diagonals
    if (board[0][0] != '.' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != '.' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    return ' '; // No winner yet
}

// Function to play the game
void playGame() {
    vector<vector<char>> board(3, vector<char>(3, '.'));
    int row, col;
    char currentPlayer = 'X';
    char winner = ' ';

    while (winner == ' ') {
        drawBoard(board);
        cout << "Player " << currentPlayer << "'s turn. Enter row and column (0-2): ";
        cin >> row >> col;

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != '.') {
            cout << "Invalid move! Try again." << endl;
            continue;
        }

        board[row][col] = currentPlayer;
        winner = checkWinner(board);

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    drawBoard(board);
    if (winner != ' ') {
        cout << "Player " << winner << " wins!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }
}

int main() {
    playGame();
    return 0;
}
