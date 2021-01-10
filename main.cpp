#include <iostream>
#include "OthelloGame.h"
using namespace std;
int main() {
    int row, col, skipCounter, winner, turnCounter;
    char currentPlayer = 1;
    OthelloMatrix board = {0};
    board[3][3] = -1;
    board[3][4] = 1;
    board[4][3] = 1;
    board[4][4] = -1;
    PrintBoard(board);
    while( turnCounter < 60)
    {
        if (currentPlayer == -1) {
            cout << "Whites's Turn. Please choose a move:" << endl;
        } else if (currentPlayer == 1) {
            cout << "Black's Turn. Please choose a move:" << endl;
        }
        GetMove(row, col);
        while (IsValidMove(board, row, col) == false) {
            cout << "Invalid move. Please choose a move:" << endl;
            GetMove(row, col);
            IsValidMove(board, row, col);
        }
        if ((row == -1 && col == -1)) {
            skipCounter++;
        }
        else {
            skipCounter = 0;
            turnCounter++;
            ApplyMove(board, row, col, currentPlayer);
        }
        if (skipCounter == 2)
        {
            cout << "Game Over.";
            break;
        }
        currentPlayer *= -1;
        PrintBoard(board);
    }
    winner = GetValue(board);
    if (winner == 0) {
        cout << " We have a tie!";
    }
    else if ( winner > 0)
    {
        cout << " Black Wins!";
    }
    else
    {
        cout << " White Wins!";
    }
}

