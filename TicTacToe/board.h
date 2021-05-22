#pragma once

#include <iostream>

class Board
{
public:
    short int board[3][3];

public:
    Board();

    void init();

    void mark(int player, int positionX, int positionY);

    int isWon();

    bool isTie();

    void display();
};