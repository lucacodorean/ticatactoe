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

bool Board::winCheck() {  
    bool won = false;
    
    for(int row=0; row<3; row++) {
        if(board[row][0] != 0  && board[row][0] == board[row][1] && board[row][1]== board[row][2]) {
            won = true;
            break;
        }
    }

    for(int column=0; column<3; column++) {
        if(board[0][column] != 0 && board[1][column] == board[0][column] && board[1][column] == board[2][column]) {
            won = true;
            break;
        }
    }

    return won;
}

void Board::aiMoves(int positionX, int positionY) {

    srand (time(NULL));

    default_random_engine generator;
    uniform_int_distribution<int> values(0,3);

    int di[4] = {-1,0,1,0};
    int dj[4] = {0,-1,0,1};

    int k = values(generator);
    int l = values(generator);

    int nexti = positionX + di[k];
    int nextj = positionY + dj[l];

    if(board[nexti][nextj] == 0) {
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

void Board::display() {
    cout << '\n';
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << this->board[i][j] << " \n"[j == 2];
        }
    }
    cout << '\n';
}
