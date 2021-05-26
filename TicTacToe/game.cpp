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
    return b.isWon() || b.isTie();
}

/**
* 
* @return void
*/

void Game::play() {

    cout<<"Current score:\n Player: "<<this->stats.playerWins<<' '<<"Computer: "<<this->stats.computerWins<<' '<<"Draws: "<<this->stats.draws<<endl;
    while(!this->isDone())
    {   
        cout << (this->player1 ? "Player1" : "Player2") << "'s turn.\n";

        int x, y;
        cin >> x >> y;
        
        this->b.mark(1, x, y);
        this->b.aiMoves(x,y);

        this->b.display();

        if (this->b.isWon()) {
            if (this->b.getWonValue() == 1) {
                cout<< "Player has won this game!\n";
                this->stats.playerWins++;
            } else {
                cout<< "Computer has won this game!\n";
                this->stats.computerWins++;
            } 
            break; 
        } else if(this->b.isTie()) {
            cout<<"Tie.";
            this->stats.draws++;
        }
    }

    cout<<"Would you like to continue playing?\nIf yes, type 1, otherwise type 0.\n";

    bool answerValue;
    cin>>answerValue;

    if(answerValue) {
        this->b.init();
        this->replay();
    } else cout<<"\nGame over.";
}

void Game::replay() {
    cout<<"Replaying...\n";
    this->play();
}