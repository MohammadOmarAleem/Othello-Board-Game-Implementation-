#pragma once
#include"player.h"
#include <iostream>
#include <vector>
using namespace std;
const int size_of_board = 8;


class Board
{
public:
  
    //DONE
    Board(bool Setting_Up_Board=true) {
        if (Setting_Up_Board) {
                int PreferredPosition;// Declare an integer variable to store the preferred starting position
                isLoaded = false;
                cout << "Tell Your preferred starting position !!!" << endl;// Prompt user for the preferred starting position
                cout << "1) is the standard  Starting Position" << endl;
                cout << "2) is the  Four-by-Four Starting Position (A non-standard, but still centered Othello starting position.)" << endl;
                
                cin >> PreferredPosition;// Read the user's input and store it in the variable PreferredPosition

                if (PreferredPosition == 1)// Check if the user chose starting position 1
                {
                    // Initialize the board with empty cells (using '-' character)
                    for (int i = 0; i < size_of_board; i++) {
                        for (int j = 0; j < size_of_board; j++) {
                            board[i][j] = '-';
                        }
                    }
                    // Set the standard starting position

                    board[3][3] = 'W';
                    board[3][4] = 'B';
                    board[4][3] = 'B';
                    board[4][4] = 'W';
                }
                else if (PreferredPosition == 2) // Check if the user chose starting position 2
                {
                    // Initialize the board with empty cells (using '-' character)
                    for (int i = 0; i < size_of_board; i++) {
                        for (int j = 0; j < size_of_board; j++) {
                            board[i][j] = '-';
                        }
                    }
                    // Set the custom starting position
                    board[2][2] = 'W';
                    board[2][3] = 'W';
                    board[3][2] = 'W';
                    board[3][3] = 'W';
                    board[4][4] = 'W';
                    board[4][5] = 'W';
                    board[5][4] = 'W';
                    board[5][5] = 'W';
                    board[2][4] = 'B';
                    board[2][5] = 'B';
                    board[3][4] = 'B';
                    board[3][5] = 'B';
                    board[4][2] = 'B';
                    board[4][3] = 'B';
                    board[5][2] = 'B';
                    board[5][3] = 'B';
                }

            }
        } 
    
    void drawBoard();

    bool isValidMove(int, int, char);

    void makeMove(int, int, char);

    bool isGameOver();

    void switchPiecesDirection(int, int, int, int, char);

    void switchPieces(int, int, char);

    void findPlayablePositions(vector<pair<int, int>>& positions, char symbol);

    bool isLoaded;

    char getBoardCell(int, int);

    void setBoardCell(int, int, char);
private:
    char board[size_of_board][size_of_board];


};
