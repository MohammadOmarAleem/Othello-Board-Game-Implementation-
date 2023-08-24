#include "Board.h"
#include<iostream>
#include<sstream>
#include<fstream>

using namespace std;

void Board::drawBoard() {
    cout << "  ";
    for (int i = 0; i < size_of_board; i++) {
        cout << i << " ";
    }
    cout << endl;  // Print the board along with row numbers

    for (int i = 0; i < size_of_board; i++) {
        cout << i << " ";
        for (int j = 0; j < size_of_board; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool Board::isValidMove(int row, int col, char symbol) {
    // Check if the given row and column are within the board boundaries

    if (row < 0 || row >= size_of_board || col < 0 || col >= size_of_board) {
        // row or column is out of bounds
        return false;
    }
    if (board[row][col] != '-') {     // Check if the cell is already occupied
        // cell is already occupied
        return false;
    }
    if (row == 0 && (col == 3 || col == 4)) {    // Check for specific invalid cells
        return false;
    }
    // check if the move flips any pieces
    // ...
    return true;
}

void Board::makeMove(int row, int col, char symbol) {
    // update the board with the new move
    board[row][col] = symbol;
    // Flip the opponent's pieces
    switchPieces(row, col, symbol);
}

bool Board::isGameOver() {
    // Check if all positions on the board are filled with a symbol
    bool boardFull = true;
    for (int row = 0; row < size_of_board; row++) {
        for (int col = 0; col < size_of_board; col++) {
            if (board[row][col] == '-') {
                boardFull = false;
                break;
            }
        }
        if (!boardFull) {
            break;
        }
    }
    if (boardFull) {
        return true;
    }

    // Check if any player has no more moves available
    vector<pair<int, int>> positions;
    findPlayablePositions(positions, 'B');
    if (positions.size() > 0) {
        positions.clear();
        findPlayablePositions(positions, 'W');
        if (positions.size() > 0) {
            return false;
        }
    }

    return true;
}

void Board::switchPiecesDirection(int row, int col, int X_MOVE, int Y_MOVE, char symbol) {
    // Iterate in the given direction
    int r = row + X_MOVE;
    int c = col + Y_MOVE;

    // Check if there are opposite pieces in the given direction to flip
    while (r >= 0 && r < size_of_board && c >= 0 && c < size_of_board && board[r][c] != symbol && board[r][c] != '-') {
        r += X_MOVE;
        c += Y_MOVE;
    }
    // If the current cell contains the same symbol, flip the pieces in the current direction
    if (r >= 0 && r < size_of_board && c >= 0 && c < size_of_board && board[r][c] == symbol) {
        // flip the pieces in the current direction
        r -= X_MOVE;
        c -= Y_MOVE;
        while (r != row || c != col) {
            board[r][c] = symbol;
            r -= X_MOVE;
            c -= Y_MOVE;
        }
    }
}

void Board::switchPieces(int row, int col, char symbol) {
    // Flip pieces in all 8 directions around the placed piece       //********//
    switchPiecesDirection(row, col, -1, 0, symbol);   // up          //********//
    switchPiecesDirection(row, col, 1, 0, symbol);    // down        //********//
    switchPiecesDirection(row, col, 0, -1, symbol);   // left        //********//   
    switchPiecesDirection(row, col, 0, 1, symbol);    // right       //********//
    switchPiecesDirection(row, col, -1, -1, symbol);  // up-left     //********//
    switchPiecesDirection(row, col, -1, 1, symbol);   // up-right    //********//
    switchPiecesDirection(row, col, 1, -1, symbol);   // down-left   //********//
    switchPiecesDirection(row, col, 1, 1, symbol);    // down-right  //********//
}

void Board::findPlayablePositions(vector<pair<int, int>>& positions, char symbol) {
    // Clear the positions vector
    positions.clear();
    // Iterate through the board
    for (int row = 0; row < size_of_board; row++) {
        for (int col = 0; col < size_of_board; col++) {
            // Check if the current cell is empty

            if (board[row][col] == '-') {
                // If the move is valid, add the position to the vector
                if (isValidMove(row, col, symbol)) {
                    positions.push_back(make_pair(row, col));
                }
            }
        }
    }
}
void Board::setBoardCell(int row, int col, char value) {

    board[row][col] = value;
}

char Board::getBoardCell(int row, int col) {
    return board[row][col]; // Return the value at the specified row and column
}

