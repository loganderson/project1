#include "Board.h"
using namespace std;

Board::Board()
{
    m_map = new char*[9];
    for (int i = 0 ; i < 9 ; i++) //initialize the row
    {
        m_map[i]=new char[10]; //for each row, it has 10 column
    }

    for (int i = 0; i < 9; i ++) // initialize each character with ~
    {
        for (int j = 0; j < 10; j++)
        {
            m_map[i][j] = '~';
        }
    }
}

Board::Board(char hidden_letter)
{
    m_map = new char*[9];
    for (int i = 0 ; i < 9 ; i++) //initialize the row
    {
        m_map[i]=new char[10]; //for each row, it has 10 column
    }

    for (int i = 0; i < 9; i ++) // initialize each character with hidden_letter
    {
        for (int j = 0; j < 10; j++)
        {
            m_map[i][j] = hidden_letter;
        }
    }
}

Board::~Board()
{
    for(int i = 0; i < 9; i++) //delete each row's column
    {
        delete[] m_map[i];
    }
    delete[] m_map;
}

void Board::print()
{
    cout << "  ";// the first empty left-up corner
    for (int i = 0; i < 10; i++)
    {
        cout << (char) (i+'A'); //print the column sequence from A-J
        cout <<' ';
    }
    cout << endl; //switch 1 line
    for (int i = 0; i < 9; i++)
    {
        cout << i+1 <<' ';//print the row sequence from 1-9
        for (int j = 0; j < 10; j++)
        {
            cout << m_map[i][j]; //print thr map
            cout << ' ';
        }
        cout << endl; //switch line
    }

    return ;
}

bool Board::exchange(int row_num, char column_letter, char new_letter)
{
    int column_num = (char)column_letter - 65; //change the letter to the ASCII number and minus the A'ASCII number
    if(row_num>=1 && row_num <=9 && column_num>=0 && column_num <10) //determine if it is in the boundary
    {
        m_map[row_num-1][column_num] = new_letter; //exchange the point's character to the new_letter
        return 1; // return true
    }
    else
    {
        return 0; //return false
    }


}

bool Board::put_column_ship(int row_num, char column_letter, int size,char new_letter)
{
    int column_num = (char)column_letter - 65; //change the letter to the ASCII number and minus the A'ASCII number
    if(row_num>=1 && row_num+size-1 <=9 && column_num>=0 && column_num <10) //determine if it is in the boundary
    {
        int test_num = row_num;
        for(int i = 0; i<size ; i++)  //check if the ship is over put
        {
            if (is_what(test_num,column_letter) != '~')
            {
                return false;
            }
            test_num++;
        }

        int exchange_time = 0; // the time of the exchange
        do
        {
            exchange(row_num,column_letter,new_letter);//exchange the point's letter
            row_num++; //go foward for the ship's boday
            exchange_time++;
        } while (exchange_time < size);
        return 1; //return true
    }
    else
    {
        return 0; //return false
    }


}

bool Board::put_row_ship(int row_num, char column_letter, int size, char new_letter)
{
    int column_num = (char)column_letter - 65; //change the letter to the ASCII number and minus the A'ASCII number
    if(row_num>=1 && row_num<=9 && column_num>=0 && column_num+size-1 <10) //determine if it is in the boundary
    {
        char test_char = column_letter;
        for(int i = 0; i<size ; i++)  //check if the ship is over put
        {
            if (is_what(row_num,test_char) != '~')
            {
                return false;
            }
            test_char = (char)(1+test_char);
        }

        int exchange_time = 0; // the time of the exchange
        do
        {
            exchange(row_num,column_letter,new_letter);//exchange the point's letter
            column_letter=(char)(1+column_letter); //go foward for the ship's boday
            exchange_time++;
        } while (exchange_time < size);
        return 1; //return true
    }
    else
    {
        return 0; //return false
    }
}

char Board::is_what(int row_num, char column_letter)
{
    int column_num = (char)column_letter - 65; //change the letter to the ASCII number and minus the A'ASCII number
    if(row_num>=1 && row_num<=9 && column_num>=0 && column_num <10) //determine if it is in the boundary
    {
        return (m_map[row_num-1][column_num]); // return the letter
    }
    else
    {
        throw (runtime_error("This point is not in the boundary")); // throw the error
    }
}
