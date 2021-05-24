class Board
{
private:
    int board[3][3];
    /** Functions' signatures presented below are meant to check if the player that just made the move won or not.*/
    bool horizontalWon();
    bool verticalWon();
    bool mainDiagonalWon();
    bool secondaryDiagonalWon();

public:
    Board();
    int isWon();                                         /// returns the winner
    ///bool isTie();                                     /// checks if the round is a tie or not

    void mark(int player, int positionX, int positionY); /// marks the cell with the given value
    void init();                                         /// Initializes the board with value 0 over all its cells.
    void display();                                      /// returns the board;
};

/** COMPILER CFG.
   g++ main.cpp game.cpp board.cpp -o main
   ./main
*/