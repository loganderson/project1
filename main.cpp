#include <iostream>
#include "Executive.h"
#include "Board.h"

int main(int argc, char* argv[])
{
  int ships = 0;
  std::cout << "How many ships would you like?\n";
  std::cin >> ships;
  Executive game;
  Board board;
  board.print();
}
