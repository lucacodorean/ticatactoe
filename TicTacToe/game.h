#include "board.h"

class Game 
{

private:
    bool player1, player2;
    Board b;

    struct stats {
        int playerWins=0, computerWins=0, draws=0;
    } stats;

public:
    void init();                                /// initializes the game
    void play();                                /// play method.
    void replay();                              /// replay method.
    void getPlayerInput(int &x, int &y);        /// get the values that the user has typed.
    bool isDone();                              /// check if the round is over.
};