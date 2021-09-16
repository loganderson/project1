#include "Player.h"
using namespace std;


Player::Player(int ships)
{
    shipsLeft = ships;
}

Player::~Player()
{
    
}

bool Player::checkHit(int row,char col)
{
    if(hiddenBoard.is_what(row,col)=='B')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Player::checkShips()
{
    return shipsLeft;
}

void Player::hit(int row,char col)
{
    gameBoard.exchange(row,col,'X');
}

Board Player::getHiddenBoard()
{
    return hiddenBoard;
}

Board Player::getGameBoard()
{
    return gameBoard;
}

bool Player::placeShip(int row, char col)
{
    if(hiddenBoard.is_what(row,col) != 'B')
    {
        if(hiddenBoard.exchange(row,col,'B')==true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}