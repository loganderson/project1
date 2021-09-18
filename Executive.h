#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include "Player.h"

class Executive
{
private:
  Player player1;
  Player player2;
  int player1ships;
  int player2ships;
  int ships;
public:
  Executive();

  ~Executive();

  void run();
  //@process - cout the paly menu and running the following functions

  void place_ship(int size, Player& new_player);
  //@input - the size of the ships and which player
  //@prociess - put the ship form size 1 to the input size

  void game_start(Player& player1, Player& player2, int size);
  //@input - player1, player2 and the size of ships
  //@process - take turns until one palyer fialure

};

#endif
