#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <exception>


class Board
{
    private:
    char** m_map = nullptr;

    public:
    Board(); //initialize the m_map with the size 9x10 character array
    // filled each character with '~' which shows waves

    ~Board(); // delete m_map claen the memory

    Board(char hidden_letter);
    //@process - this function works for hidden_board, which exchange all the '~' into 'hidden_letter'

    void print(); // pint the m_map witch has the row's sequence shows 1-9
    // it has the column's sequence shows A-J
    // it shows the whole m_map

    bool exchange(int row_num, char column_letter, char new_letter);
    //@input - the row, colum and the new_letter
    //@process - exchange the original letter of the point to the new_letter
    //@return - true for success, false for failure

    bool put_column_ship(int row_num, char column_letter, int size, char new_letter);
    //@input - The number of the row, the letter of the column and the size of the ship's head
    //@input - The new_letter for the ship
    //@process -determine if the ship is in the bounday
    //@process -if it is true put the ship with the start point in column with the size and the new_lettter
    //@return - true for success, false for failure

    bool put_row_ship(int row_num, char column_letter, int size, char new_letter);
    //@input - The number of the row, the letter of the column and the size of the ship's head
    //@input - The new_letter for the ship
    //@process -determine if the ship is in the bounday
    //@process- if it is true put the ship with the start point in row with the size and the new_lettter
    //@return - true for success, false for failure

    char is_what(int row_num, char column_letter);
    //@input - Number of the row and the letter for the column
    //@process - determine if the point is in the bounday
    //@return - if it is in the boundary, return the letter
    //@return - if it is not in the boundary,  throw the exception error

};

#endif
