#include <iostream>
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
    if((positionX<0 || positionX>=3) && (positionY<0 || positionY>=3)) {
        cout<<"Coordinates aren't valid. Insert a new set of coordinates.\n";
        int x,y;
        cin>>x>>y;
        mark(player, x, y);
    } else {
        if(board[positionX][positionY] == 0) board[positionX][positionY] = player;
        else {
            cout<<"The given cell is already marked. Insert a new set of coordinates.\n";
            int x,y;
            cin>>x>>y;
            mark(player, x, y);
        }
    }
}

bool Board::horizontalWon() {

    bool won = true;

    for(int i=0; i<3; i++) {
        int initalValue = 0;
        if(board[i][i] != 0) initalValue = board[i][i];
        for(int j=0; j<3; j++) {
            if(board[i][j] != initalValue) {
                won = false;
                break;
            }
        }
    }

    return won;
}

bool Board::verticalWon() {

    bool won = true;

    for(int i=0; i<3; i++) {
        int initalValue = 0;
        if(board[i][i] != 0) initalValue = board[i][i];
        for(int j=0; j<3; j++) {
            if(board[j][i] != initalValue) {
                won = false;
                break;
            }
        }
    }

    return won;
}

bool Board::mainDiagonalWon() {

    bool check = true; 
    int initialValue = 0;
    for(int i=0; i<3; i++) {
        if(board[i][i] != 0) {
            initialValue = board[i][i];
            break;
        }
    }

    for(int i=0; i<3; i++) {
        if(board[i][2-i]!=initialValue) {
            check = false;
            break;
        } else initialValue = board[i][2-i];
    }

    return check;
}

bool Board::secondaryDiagonalWon() {
   
    bool check = true; 
    int initialValue = 0;
    for(int i=0; i<3; i++) {
        if(board[i][2-i] != 0) {
            initialValue = board[i][2-i];
            break;
        }
    }

    for(int i=0; i<3; i++) {
        if(board[i][2-i]!=initialValue) {
            check = false;
            break;
        } else initialValue = board[i][2-i];
    }

    return check;
}

int Board::isWon() {
    ///return (mainDiagonalWon() || secondaryDiagonalWon() || verticalWon() || horizontalWon()) ? true : false;
    return false;
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