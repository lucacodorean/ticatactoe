#include "board.h"
#include <iostream>

using namespace std;

void Board::init() {
    this->board[3][3] = {0};
}

void Board::mark(int player, int positionX, int positionY) {
    board[positionX][positionY] = player;
}

Board:: Board() {
    this->init();
}

int Board::isWon() {
    
}

bool Board::isTie() {

}

void Board::display() {
    cout << '\n';
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << this->board[i][j] << " \n"[j == 2];
        }
    }
    cout << '\n';
}