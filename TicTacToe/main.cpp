#include <iostream>

#include "board.h"
#include "game.h"

using namespace std;

int main()
{
    Game TicTacToe;
    TicTacToe.play();
    // Temp
    return 0;
}

/*

Compilation fails, because you have only declared this function. Its definition is in different compilation unit, and you're not linking those two together.
Do: g++ -Wall -o main main.cpp game.cpp board.cpp

*/