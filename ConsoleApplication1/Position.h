#pragma once

class Position {
public:
    virtual bool canPlay() {
        return true;
    }
};

class UnplayablePosition : public Position {
public:
    bool canPlay() override {
        return false;
    }
};

