class Board
{
private:
    short int board[3][3];

public:
    Board();
    int isWon();                                         /// returns the winner
    bool isTie();                                        /// checks if the round is a tie or not

    void mark(int player, int positionX, int positionY); /// marks the cell with the given value
    void init();                                         /// Initializes the board with value 0 over all its cells.
    void display();                                      /// returns the board;
};