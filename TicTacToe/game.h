#pragma once
#include "board.h"

#include <iostream>
#include <ctime>

class Game
{
private:
    bool player1, player2;
    Board b;

    struct stats
    {
        int wins_p1, wins_p2, draws;
    } stats;

public:
    Game();

    void init();

    void play();

    bool isDone();

    void givePoints(int winner);

    void getPlayerInput(int &x, int &y);

    void switchTurn();

    bool shouldRunAgain();
};