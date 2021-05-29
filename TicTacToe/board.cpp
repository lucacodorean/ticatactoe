#include "board.h"

Board::Board()
{
    this->init();
}

void Board::init()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            this->board[i][j] = 0;
        }
    }
}

void Board::mark(int player, int positionX, int positionY)
{
    board[positionX][positionY] = player;
}

int Board::isWon()
{
    for (int i = 0; i < 3; i++)
    {
        if (this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] && this->board[i][0] != 0)
        {
            return this->board[i][0];
        }
        if (this->board[0][i] == this->board[1][i] && this->board[1][i] == this->board[2][i] && this->board[0][i] != 0)
        {
            return this->board[0][i];
        }
    }
    if (this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[0][0] != 0)
    {
        return this->board[0][0];
    }
    if (this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] && this->board[2][0] != 0)
    {
        return this->board[0][2];
    }
    return 0;
}

bool Board::isTie()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (this->board[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

void Board::display()
{
    system("cls");

    std::cout << '\n';
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            char c = '_';
            if (this->board[i][j] == 1)
            {
                c = 'x';
            }
            else if (this->board[i][j] == 2)
            {
                c = '0';
            }

            std::cout << c << " \n"[j == 2];
        }
    }
    std::cout << '\n';
}