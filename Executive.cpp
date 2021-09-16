#include "Executive.h"
#include "Board.h"
#include "Player.h"
#include <iostream>
using namespace std;


Executive::Executive()
{

}

Executive::~Executive()
{

}

void Executive::run()
{
  int ships;
  cout<<"how many ships would you like to play with.\n";
  cin>>ships;
  cout<<"you have selected: "<<ships <<" ships to play with \n";
  Player player1(ships);
  Player player2(ships);
  player1ships = ships;
  player2ships = ships;
  int counter=0;
  int row=0;
  char column = ' ';
  do{
    player1.getHiddenBoard().print();
    cout<<"where would you like to place a ship.\n";
    cout<<" Please enter a number for the row you would wish to put a ship in.\n";
    cin>>row;
    cout<<"Please enter a letter for the column you wish to put a ship in.\n";
    cin>>column;
    player1.getHiddenBoard().exchange(row,column,'B');
    player1.getHiddenBoard().print();
    break;
  } while(counter != player1ships);


  do {
    break;  
    /*put this here so that the program will end if a test run is down 
    *because right now it just goes endlessly.
    */
  } while(player1ships != 0 && player2ships != 0);
}
