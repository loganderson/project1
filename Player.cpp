#include "Player.h"
using namespace std;


Player::Player()
{
    
}

Player::~Player()
{
    
}

bool Player::checkHit(int row,char col)
{
    if(gameBoard.is_what(row,col)=='B')
    {
        return true;
    }
    else if (gameBoard.is_what(row,col) == '~')
    {
        hiddenBoard.exchange(row,col,'O');
        return false;
    }
}

int Player::checkShips()
{
    return shipsLeft;
}

void Player::get_hit(int row,char col)
{
    gameBoard.exchange(row,col,'X');
    hiddenBoard.exchange(row,col,'X');
}

void Player::getHiddenBoard()
{
    hiddenBoard.print();
}

void Player::getGameBoard()
{
    gameBoard.print();
}

void Player::getOriginalBoard()
{
    original_Board.print();
}

bool Player::placeShip(int row, char col, int size)
{
    string direction;
    cout << "In which direction do you want to place? (row/col)";
    cin >> direction;
    if (direction == "row") // when the direction is row
    {
        if(gameBoard.put_row_ship(row,col,size,'B'))
        {
            original_Board.put_row_ship(row,col,size,'B');
            return true;
        }
        else // over boundary or over put
        {
            return false;
        }
    }
    else if (direction == "col") // when the direction is col
    {
        if(gameBoard.put_column_ship(row,col,size,'B'))
        {
            original_Board.put_column_ship(row,col,size,'B');
            return true;
        }
        else // over boundary or over put
        {
            return false;
        }
    }
    else //invalid input
    {
        return false;
    }
}