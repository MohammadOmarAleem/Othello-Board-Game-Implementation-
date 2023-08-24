#include"Game.h"

void Game::play(Board& board, Player& player1, Player& player2, Player*& currentPlayer) {
    bool gameOver = false;

    while (!gameOver) {
        board.drawBoard();

        int action;
        cout << currentPlayer->getName() << ", choose an action: " << endl;
        cout << "1. Make a move" << endl;
        cout << "2. Save game" << endl;
        cout << "3. Concede game" << endl;
        cout << "4. Forfeit turn" << endl;
        cin >> action;

        switch (action) {
        case 1:
            // Make a move
            cout << "Enter your move (row, col): ";
            int row, col;
            cin >> row >> col;

            if (board.isValidMove(row, col, currentPlayer->getSymbol())) {
                board.makeMove(row, col, currentPlayer->getSymbol());
                if (board.isGameOver()) {
                    gameOver = true;
                }
                else {
                    // switch to the other player
                    if (currentPlayer == &player1) {
                        currentPlayer = &player2;
                    }
                    else {
                        currentPlayer = &player1;
                    }
                }
            }
            else {
                cout << "Invalid move. Try again." << endl;
            }
            break;
        case 2:
            // Save game
            saveGame(board, player1, player2, *currentPlayer);
            break;
        case 3:
            // Concede game
            gameOver = true;
            cout << currentPlayer->getName() << " has conceded the game." << endl;
            break;
        case 4:
            // Forfeit turn
            if (currentPlayer == &player1) {
                currentPlayer = &player2;
            }
            else {
                currentPlayer = &player1;
            }
            cout << currentPlayer->getName() << " has forfeited their turn." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    }

    board.drawBoard();
    cout << "Game over." << endl;
};



bool Game::loadGame(Board& board, Player& player1, Player& player2, Player*& currentPlayer) {
    string filename;
    cout << "Enter filename to load the game: ";
    cin >> filename;

    ifstream inFile(filename);
    if (inFile.is_open()) {
        string line;
        getline(inFile, line);
        player1 = Player(line, 'W');
        getline(inFile, line);
        player2 = Player(line, 'B');
        getline(inFile, line);

        if (line == player1.getName()) {
            currentPlayer = &player1;
        }
        else if (line == player2.getName()) {
            currentPlayer = &player2;
        }
        else {
            cout << "Invalid saved game file." << endl;
            inFile.close();
            return false;
        }

        getline(inFile, line);
        int idx = 0;
        for (int i = 0; i < size_of_board; i++) {
            for (int j = 0; j < size_of_board; j++) {
                board.setBoardCell(i, j, line[idx]);
                idx++;
            }
        }
        inFile.close();
        board.isLoaded = true;
        cout << "Game loaded successfully." << endl;

        return true;
    }
    else {
        cout << "Unable to open file for loading." << endl;
        return false;
    }
}

void Game::saveGame(Board& board, const Player& player1, const Player& player2, const Player& currentPlayer) {
    string filename;
    cout << "Enter filename to save the game: ";
    cin >> filename;

    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << player1.getName() << endl;
        outFile << player2.getName() << endl;
        outFile << currentPlayer.getName() << endl;

        for (int i = 0; i < size_of_board; i++) {
            for (int j = 0; j < size_of_board; j++) {
                outFile << board.getBoardCell(i, j);
            }
        }
        outFile.close();
        cout << "Game saved successfully." << endl;
    }
    else {
        cout << "Unable to open file for saving." << endl;
    }
}