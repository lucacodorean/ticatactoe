#include "game.h"

using namespace std;

Game::Game()
{
    srand(time(NULL));
    this->init();
}

void Game::init()
{
    this->player1 = true;
    this->player2 = false;
    this->b.init();
}

bool Game::shouldRunAgain()
{
    char answer;
    do
    {
        cout << "Do you want to play again? Y/N\n";
        cin >> answer;
    } while (answer != 'Y' || answer != 'N');

    return (answer == 'Y' ? 1 : 0);
}

void Game::play()
{
    bool run = true;
    while (run)
    {
        while (!this->isDone())
        {
            int x, y;
            this->getPlayerInput(x, y);

            this->b.mark((this->player1 ? 1 : 2), x, y);

            this->b.display();

            this->switchTurn();
        }
        run = shouldRunAgain();
    }
}

bool Game::isDone()
{
    int winner = this->b.isWon();
    if (winner != 0)
    {
        this->givePoints(winner);
        return true;
    }

    if (this->b.isTie())
    {
        this->stats.draws++;
        return true;
    }
    return false;
}

void Game::givePoints(int winner)
{
    if (winner == 1)
    {
        this->stats.wins_p1++;
        cout << "You won the game!\n";
        return;
    }
    this->stats.wins_p2++;
    cout << "AI won the game!\n";
}

void Game::getPlayerInput(int &x, int &y)
{
    if (this->player1)
    {
        do
        {
            cout << "Enter a potition for X: ";
            cin >> x >> y;
        } while (this->b.board[x][y] != 0);
        return;
    }
    do
    {
        x = rand() % 3;
        y = rand() % 3;
    } while (this->b.board[x][y] != 0);
}

void Game::switchTurn()
{
    player1 = !player1;
    player2 = !player2;
}
