#ifndef PLAYER_H
#define PLAYER_H


#include "Board.h"
#include <iostream>
#include <string>


class Player{
private:
  Board hiddenBoard ; // The board shows to opponent
  Board gameBoard; // the board shows ships and hitted space
  Board original_Board;// the board stores all the shps and do not make any change
  int shipsLeft;

public:
  Player();
  ~Player();
  bool checkHit(int row,char col);//checks what is hit
  //@input - int row - the row in which the player wants to place a boat.
  //@input - char col - the column in which the player wants to place a ship.
  //@process - uses the passed parameters to check to see if a B exists at the passed location in the hiddenBoard.
  //@return - the board object of the player class.
  //pass a row and coloumn
  //return 1 if hits ships, 0 if hits water

  int checkShips();
  //@input - none.
  //@input - none.
  //@process - none
  //@return - returns the amount of ships left for the player class.
  void get_hit(int row, char col);//helper function checkHit()
  //@input - int row - the row in which the player wants to place a boat.
  //@input - char col - the column in which the player wants to place a ship.
  //@process - replaces a B in the array with an X.
  //@return - none.
  void getHiddenBoard();
  //@input - none.
  //@input - none.
  //@process - print the hidden board object. Mainly used for calling methods of the board class
  //@return - 
  void getGameBoard();
  //@input - none.
  //@input - none.
  //@process - print the Game board object. Mainly used for calling methods of the board class
  //@return - 
  void getOriginalBoard();
  //@input - none.
  //@input - none.
  //@process - print the Game board object. Mainly used for calling methods of the board class
  //@return - 
  bool placeShip(int row, char col, int size);
  //@input - the row number in which the ship will be placed
  //@input - the column number in which the ship will be place
  //@input - int the size of the ship
  //@process - asking user about the direction of the shop. places a ship in the gameBoard and original_Board
  //@return - true if ship was placed, false if ship wasnt placed.

};
//mark hits with x misses with o

#endif