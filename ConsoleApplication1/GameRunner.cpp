#include <iostream>
#include "Board.h"
#include "Game.h"
#include "Player.h"
using namespace std;

int main() {
    int choice;
    bool quit = false;
    string filename;
    string name1;
    string name2;

    Game game;
    Board board(false);
    Player player1("", 'B');
    Player player2("", 'W');
    Player* currentPlayer = nullptr;

    while (!quit) {
        cout << "Menu:" << endl;
        cout << "1. Load a Game" << endl;
        cout << "2. Start a New Game" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        switch (choice) {
        case 1:
            // Load a game from file
        {
          
            if (game.loadGame(board, player1, player2, currentPlayer)) {
                game.play(board, player1, player2, currentPlayer);
            }
        
        break;
        }
    
        case 2:
            // Start a new game
            cout << "Enter Player 1 name: ";
            cin >> name1;
            cout << "Enter Player 2 name: ";
            cin >> name2;
            // Set player names
            player1 = Player(name1, 'B');
            player2 = Player(name2, 'W ');
            currentPlayer = &player1;
            board = Board();
            game.play(board, player1, player2, currentPlayer);
            break;
            
            
        case 3:
            // Quit the program
            quit = true;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    }

    return 0;
}
