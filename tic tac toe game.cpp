#include <iostream>
using namespace std;

char square[9] = {'0','1','2','3','4','5','6','7','8'};

// Method to draw the Tic Tac Toe board
void drawBoard() {
    cout << " " << square[0] << " | " << square[1] << " | " << square[2] << endl;
    cout << "-----------" << endl;
    cout << " " << square[3] << " | " << square[4] << " | " << square[5] << endl;
    cout << "-----------" << endl;
    cout << " " << square[6] << " | " << square[7] << " | " << square[8] << endl;
}

// Method to handle player move
void playerMove(int player) {
    int move;
    cout << "Player " << player << ", enter your move (0-8): ";
    cin >> move;

    if (move < 0 || move > 8) {
        cout << "Invalid move, try again." << endl;
        playerMove(player);
    } else if (square[move] == 'X' || square[move] == 'O') {
        cout << "Square is already occupied, try again." << endl;
        playerMove(player);
    } else {
        if (player == 1) {
            square[move] = 'X';
        } else {
            square[move] = 'O';
        }
    }
}

// Method to check for a win
int checkWin() {
    int winningCombinations[][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
    for (int i = 0; i < 8; i++) {
        if (square[winningCombinations[i][0]] == square[winningCombinations[i][1]] && square[winningCombinations[i][1]] == square[winningCombinations[i][2]]) {
            if (square[winningCombinations[i][0]] == 'X') {
                return 1;
            } else if (square[winningCombinations[i][0]] == 'O') {
                return 2;
            }
        }
    }
    return 0;
}

// Method to play the game
void playGame() {
    int player = 1;
    int moveCount = 0;
    int result = 0;

    while (moveCount < 9) {
        drawBoard();
        playerMove(player);
        result = checkWin();

        if (result == 1) {
            drawBoard();
            cout << "Player 1 wins!" << endl;
            break;
        } else if (result == 2) {
            drawBoard();
            cout << "Player 2 wins!" << endl;
            break;
        }

        player = (player == 1) ? 2 : 1;
        moveCount++;
    }

    if (result == 0) {
        drawBoard();
        cout << "It's a draw!" << endl;
    }
}

int main() {
    playGame();
    return 0;
}
