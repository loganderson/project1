#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include "Board.h"

class Executive
{
private:
  Board board;
  int player1ships;
  int player2ships;
public:
  Executive();
  ~Executive();
  void run();
};

#endif
