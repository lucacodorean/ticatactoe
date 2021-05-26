class Board
{
private:
    int board[3][3];
    /** Functions' signatures presented below are meant to check if the player that just made the move won or not.*/
    bool winCheck();
    bool primaryDiagonalWon();
    bool secondaryDiagonalWon();
    bool possibleMove(int positionX, int positionY);
    int  winValue;

public:
    Board();
    bool isWon();                                        /// returns the winner
    bool isTie();                                        /// checks if the round is a tie or not

    void aiMoves(int positionX, int positionY);          /// the computer does a move.
    void mark(int player, int positionX, int positionY); /// marks the cell with the given value
    void init();                                         /// Initializes the board with value 0 over all its cells.
    void display();                                      /// returns the board;
    void setWonValue(int value);
    int getWonValue();
};

/** COMPILER CFG.
   g++ main.cpp game.cpp board.cpp -o main
   ./main
*/