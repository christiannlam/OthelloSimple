#include <iostream>
#include "OthelloGame.h"
using namespace std;
void PrintBoard(const OthelloMatrix &board)
{
    int columnCounter = 0;
    cout << "- 0 1 2 3 4 5 6 7" << endl;
    for (int row = 0; row < board.size(); row++)
    {
        cout << columnCounter << " ";
        columnCounter++;
        for (int col = 0; col < board.size(); col++)
        {
            // Default
            if (board[row][col] == 0)
            {
                cout << "." << " ";
            }
                // X Player
            else if (board[row][col] == 1)
            {
                cout << "B" << " ";
            }
                // O Player
            else if (board[row][col] == -1)
            {
                cout << "W" << " ";
            }
        }
        cout << endl;
    }
}

void GetMove(int &row, int &col)
{
    char paren1, paren2, comma;
    cin >> paren1 >> row >> comma >> col >> paren2;
}

bool InBounds(int row, int col)
{
    if((row > -1 && row < BOARD_SIZE) && (col > -1 && col < BOARD_SIZE))
    {
        return true;
    }
}

bool IsValidMove(const OthelloMatrix &board, int row, int col)
{
    if( (InBounds(row,col) == true && board[row][col] == 0) || ( row == -1 && col == -1) )
    {
        return true;
    }
}

void ApplyMove(OthelloMatrix &board, int row, int col, char currentPlayer)
{
    // Sets parameters of row and col to currentPlayer
    board[row][col] = currentPlayer;
    // 8 Directions:
    for(int i = -1; i < 2; i++)
    {
        for(int j = -1; j < 2; j++)
        {
            int tempI = i,tempJ = j,pieceCounter = 0;
            while(board[row + tempI][col + tempJ] != currentPlayer && board[row + tempI][col + tempJ] != 0)
            {
                tempI += i;
                tempJ += j;
                pieceCounter++;
            }
            if(board[row + tempI][col + tempJ] == currentPlayer)
            {
                while( pieceCounter > 0 )
                {
                    tempI = tempI - i;
                    tempJ = tempJ - j;
                    board[row + tempI][col + tempJ] = currentPlayer;
                    pieceCounter--;
                }
            }
        }
    }
}

int GetValue(const OthelloMatrix &board)
{
    int value = 0;
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            value += board[i][j];
        }
    }
    return value;
}

