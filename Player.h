#ifndef PLAYER_H
#define PLAYER_H


#include "Board.h"


class Player{
private:
  Board hiddenBoard;
  Board gameBoard;
  int shipsLeft;

public:
  Player(int ships);
  ~Player();
  bool checkHit(int row,char col);//checks what is hit
  //pass a row and coloumn
  //return 1 if hits ships, 0 if hits water

  int checkShips();
  void hit(int row, char col);//helper function checkHit()
  Board getHiddenBoard();
  Board getGameBoard();
  bool placeShip(int row, char col);

};
//mark hits with x misses with o

#endif