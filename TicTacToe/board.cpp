#include <iostream>
#include <random>
#include <time.h>
#include <functional>
#include "board.h"

using namespace std;

void Board::init() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++){
            this->board[i][j] = 0;
        }
    }
}

Board::Board() {
    this->init();
}

void Board::mark(int player, int positionX, int positionY) {
    if((positionX<0 || positionX>=3) || (positionY<0 || positionY>=3)) {
        cout<<"Coordinates aren't valid. Insert a new set of coordinates.\n";
        int x,y;
        cin>>x>>y;
        mark(player, x, y);
    } else {
        if(board[positionX][positionY] == 0) {
            board[positionX][positionY] = player;
        } else {
            cout<<"The given cell is already marked. Insert a new set of coordinates.\n";
            int x,y;
            cin>>x>>y;
            mark(player, x, y);
        }
    }
}

void Board::setWonValue(int value) {
    this->winValue = value;
}

int Board::getWonValue() { return this->winValue; }

bool Board::winCheck() {  
    bool won = false;
    
    for(int row=0; row<3; row++) {
        if(board[row][0] != 0  && board[row][0] == board[row][1] && board[row][1]== board[row][2]) {
            won = true;
            this->setWonValue(board[row][0]);
            break;
        }
    }

    for(int column=0; column<3; column++) {
        if(board[0][column] != 0 && board[1][column] == board[0][column] && board[1][column] == board[2][column]) {
            won = true;
            this->setWonValue(board[0][column]);
            break;
        }
    }

    return won;
}

bool Board::possibleMove(int positionX, int positionY) {
    return ((positionX<0 || positionX>=3) || (positionY<0 || positionY>=3)) ? false : true;
}

void Board::aiMoves(int positionX, int positionY) {

    srand (time(NULL));

    //default_random_engine generator;
    //uniform_int_distribution<int> values(0,3);
    int nexti, nextj;

    do
    {
        nexti = rand() % 3;
        nextj = rand() % 3;
    } while (this->board[nexti][nextj] != 0);


    if(board[nexti][nextj] == 0 && possibleMove(nexti, nextj)) {
        board[nexti][nextj] = 2;
    }
}

bool Board::primaryDiagonalWon() {
    return (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != 0);
}

bool Board::secondaryDiagonalWon() {
    return (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != 0);
}
 
bool Board::isWon() {
    return (winCheck() == true || primaryDiagonalWon() == true || secondaryDiagonalWon() == true) ? true : false;
}

bool Board::isTie() {
    bool tie = true;

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == 0) {
                tie = false; 
                break;
            }
        }
    } 

    return tie;
}

void Board::display() {
    cout << '\n';
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(this->board[i][j]==1) cout<<" X ";
            if(this->board[i][j]==2) cout<<" O ";
            else if(this->board[i][j]==0) cout<<" - ";
        }
        cout<<endl;
    }
    cout << '\n';
}