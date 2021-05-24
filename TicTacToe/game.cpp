#include <iostream>
#include "game.h"

using namespace std;

/**
* Initializes the board and the players
* 
* @return void
*/

void Game::init() { 
    this->player1 = true;
    this->player2 = false;
    this->b.init();
}

bool Game::isDone(){
    return b.isWon(); ///|| this->isTie();
}

/**
* 
* @return void
*/

void Game::play() {
    while(!this->isDone())
    {
        cout << (this->player1 ? "Player1" : "Player2") << "'s turn.\n";

        int x, y;

        if (this->player1) {
           cin >> x >> y;

           this->b.mark(1, x, y);
           swap(this->player1, this->player2);

        } else {
           cin >> x >> y;

           this->b.mark(2, x, y);
           swap(this->player1, this->player2);
        }


        this->b.display();

        if (this->b.isWon()) {
            cout << (this->player1 ? "Player1" : "Player2") << " has won this game!\n";
            // Increase points for player;
            break;
        }
    }
}