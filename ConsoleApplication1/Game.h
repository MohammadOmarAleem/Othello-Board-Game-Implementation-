#pragma once
#include "Board.h"
#include "Player.h"
#include <fstream>
#include<iostream>
using namespace std;


class Game
{
public:
    // implementation of the game logic
    void saveGame(Board& board, const Player& player1, const Player& player2, const Player& currentPlayer);

    bool loadGame(Board& board, Player& player1, Player& player2, Player*& currentPlayer);
   
    void play(Board& board, Player& player1, Player& player2, Player*& currentPlayer);
    
};
