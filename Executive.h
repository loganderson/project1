#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include "Player.h"

class Executive
{
private:
  int player1ships;
  int player2ships;
public:
  Executive();
  ~Executive();
  void run();
};

#endif
