#pragma once
#include <string>
using namespace std;

class Player {
private:
    string name;
    char symbol;
public:
    Player(string name, char symbol) {
        this->name = name;
        this->symbol = symbol;
    }
    string getName() const {
        return name;
    }
    char getSymbol() {
        return symbol;
    }
};