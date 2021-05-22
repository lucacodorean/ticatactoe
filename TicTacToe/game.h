class Game 
{
private:
    bool player1, player2;
    Board b;

    struct stats {
        int wins_p1, wins_p2, draws;
    } stats;

public:
    
    void init();
    void play();
    void getPlayerInput(int &x, int &y);
    bool isDone();
};