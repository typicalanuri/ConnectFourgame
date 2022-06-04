#include "Connectfour.h"
#include <iostream>
using namespace std;

Cell::Cell()
{
    val = ' ';
}
bool Cell::addChar(char newchar)
{
    if(val != 'X' && val != 'O')
    {
        val = newchar;
        return true;
    }
    return false;
}
char Cell::getChar()
{
    return val;
}
char Board::start()
{
    char user1, user2;

    std::cout<<"Enter a symbol for user 1: (X or O) ";
    cin>>user1;

    if(user1 == 'X')
    {
        user2 = 'O';
    }
    else{
        user2 = 'X';
    }

    //initialize/create the board
    print();
    return user1;
}
void Board::print()
{
    cout<<"C O N N E C T  F O U R   B O A R D: "<<endl;

    for(int i = 0; i < 6; i++)
    {   
        cout<<"|";
        for(int j = 0; j < 7; j++)
        {
            cout<<board[i][j].getChar()<<" |";
        }
        cout<<endl;
        cout<<"-------------------------"<<endl;
    }
}
bool Board::get_userInput(char user)
{
    int col;
    cout<<"Player "<<user<<" enter the number of the column you want to use (0 to 6): ";
    cin>>col;

    if(col > 6 || col <0)
    {
        cout<<"Column is outside of the accepted range."<<endl;
        return false;
    }
    
    int i = 0; //index used to find the correct row
    
    while((board[i+1][col].getChar() != 'X' && board[i+1][col].getChar() != 'O') && i < 5)
    {   //statement used to find the correct row
        i++;
    }

    if(i > 5)
    {
        cout<<"The column is full"<<endl;
        return false;
    }
    else
    {
        if(board[i][col].addChar(user) == true)
        {
            return true;
        }
        else{
            return false;
        }
    }

    return false;
}
int Board::get_currentStatus(char user1)
{   //check for a winner
    char user2;
    if(user1 == 'X')
    {
        user2 = 'O';
    }
    else
    {
        user2 = 'X';
    }


    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            if(board[i][j].getChar() != ' ')
            {
                if(i == 0)
                {
                    if(j < 4)
                    {
                        if(board[i][j].getChar() == board[i+1][j].getChar() && board[i][j].getChar()== board[i+2][j].getChar() && board[i][j].getChar() == board[i+3][j].getChar())
                        {   //check the vertical
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }
                        else if(board[i][j].getChar() == board[i][j+1].getChar() && board[i][j].getChar() == board[i][j+2].getChar() && board[i][j].getChar() == board[i][j+3].getChar())
                        {//check the horizontal
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }
                        else if(board[i][j].getChar() == board[i+1][j+1].getChar() && board[i][j].getChar() == board[i+2][j+2].getChar() && board[i][j].getChar() == board[i+3][j+3].getChar())
                        {   //check the diagonal
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }
                    }
                    else
                    {
                        if(board[i][j].getChar() == board[i+1][j].getChar() && board[i][j].getChar()== board[i+2][j].getChar() && board[i][j].getChar() == board[i+3][j].getChar())
                        {//checking the vertical
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }
                        else if(board[i][j].getChar() == board[i][j-1].getChar() && board[i][j].getChar() == board[i][j-2].getChar() && board[i][j].getChar() == board[i][j-3].getChar())
                        {//checking the horizontal
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }
                        else if(board[i][j].getChar() == board[i+1][j-1].getChar() && board[i][j].getChar() == board[i+2][j-2].getChar() && board[i][j].getChar() == board[i+3][j-3].getChar())
                        {//check the diagonal
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }
                    }
                }
                else if(i == 1)
                {
                    if(j < 4)
                    {
                        if(board[i][j].getChar() == board[i-1][j].getChar() && board[i][j].getChar()== board[i+1][j].getChar() && board[i][j].getChar() == board[i+2][j].getChar())
                        {   //check the vertical
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }
                        else if(board[i][j].getChar() == board[i][j+1].getChar() && board[i][j].getChar() == board[i][j+2].getChar() && board[i][j].getChar() == board[i][j+3].getChar())
                        {//check the horizontal
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }
                        else if(board[i][j].getChar() == board[i+1][j+1].getChar() && board[i][j].getChar() == board[i+2][j+2].getChar() && board[i][j].getChar() == board[i+3][j+3].getChar())
                        {   //check the diagonal
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }

                        if(j >= 2 && j <= 5)
                        {
                            if(board[i][j].getChar() == board[i-1][j+1].getChar() && board[i][j].getChar() == board[i+1][j-1].getChar() && board[i][j].getChar() == board[i+2][j-2].getChar())
                            {  //check the diagonal in the opposite direction
                                if(board[i][j].getChar() == user1)
                                {
                                    return 1;
                                } 
                                else
                                {
                                    return 2;
                                }
                            }
                        }
                    }
                    else
                    {
                        if(board[i][j].getChar() == board[i-1][j].getChar() && board[i][j].getChar()== board[i+1][j].getChar() && board[i][j].getChar() == board[i+2][j].getChar())
                        {//checking the vertical
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }
                        else if(board[i][j].getChar() == board[i][j-1].getChar() && board[i][j].getChar() == board[i][j-2].getChar() && board[i][j].getChar() == board[i][j-3].getChar())
                        {//checking the horizontal
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }
                        else if(board[i][j].getChar() == board[i+1][j-1].getChar() && board[i][j].getChar() == board[i+2][j-2].getChar() && board[i][j].getChar() == board[i+3][j-3].getChar())
                        {//check the diagonal
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }
                        if(j == 5)
                        {
                            if(board[i][j].getChar() == board[i-1][j+1].getChar() && board[i][j].getChar() == board[i+1][j-1].getChar() && board[i][j].getChar() == board[i+2][j-2].getChar())
                            {  //check the diagonal in the opposite direction
                                if(board[i][j].getChar() == user1)
                                {
                                    return 1;
                                } 
                                else
                                {
                                    return 2;
                                }
                            }
                        }
                    }
                }
                else if(i == 2)
                {
                    if(j < 4)
                    {
                        if(board[i][j].getChar() == board[i+1][j].getChar() && board[i][j].getChar()== board[i+2][j].getChar() && board[i][j].getChar() == board[i+3][j].getChar())
                        {   //check the vertical
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }
                        else if(board[i][j].getChar() == board[i][j+1].getChar() && board[i][j].getChar() == board[i][j+2].getChar() && board[i][j].getChar() == board[i][j+3].getChar())
                        {//check the horizontal
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }
                        else if(board[i][j].getChar() == board[i+1][j+1].getChar() && board[i][j].getChar() == board[i+2][j+2].getChar() && board[i][j].getChar() == board[i+3][j+3].getChar())
                        {   //check the diagonal
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }

                        if(j >= 2 && j <= 5)
                        {
                            if(board[i][j].getChar() == board[i-1][j+1].getChar() && board[i][j].getChar() == board[i+1][j-1].getChar() && board[i][j].getChar() == board[i+2][j-2].getChar())
                            {  //check the diagonal in the opposite direction
                                if(board[i][j].getChar() == user1)
                                {
                                    return 1;
                                } 
                                else
                                {
                                    return 2;
                                }
                            }
                        }
                    }
                    else
                    {
                        if(board[i][j].getChar() == board[i+1][j].getChar() && board[i][j].getChar()== board[i+2][j].getChar() && board[i][j].getChar() == board[i+3][j].getChar())
                        {//checking the vertical
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }
                        else if(board[i][j].getChar() == board[i][j-1].getChar() && board[i][j].getChar() == board[i][j-2].getChar() && board[i][j].getChar() == board[i][j-3].getChar())
                        {//checking the horizontal
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }
                        else if(board[i][j].getChar() == board[i+1][j-1].getChar() && board[i][j].getChar() == board[i+2][j-2].getChar() && board[i][j].getChar() == board[i+3][j-3].getChar())
                        {//check the diagonal
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }
                        if(j == 5)
                        {
                            if(board[i][j].getChar() == board[i-1][j+1].getChar() && board[i][j].getChar() == board[i+1][j-1].getChar() && board[i][j].getChar() == board[i+2][j-2].getChar())
                            {  //check the diagonal in the opposite direction
                                if(board[i][j].getChar() == user1)
                                {
                                    return 1;
                                } 
                                else
                                {
                                    return 2;
                                }
                            }
                        }
                    }
                }
                else if(i == 3)
                {
                    if(j < 4)
                    {
                        if(board[i][j].getChar() == board[i-1][j].getChar() && board[i][j].getChar()== board[i+1][j].getChar() && board[i][j].getChar() == board[i+2][j].getChar())
                        {   //check the vertical
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }
                        else if(board[i][j].getChar() == board[i][j+1].getChar() && board[i][j].getChar() == board[i][j+2].getChar() && board[i][j].getChar() == board[i][j+3].getChar())
                        {//check the horizontal
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }
                        else if(board[i][j].getChar() == board[i-1][j+1].getChar() && board[i][j].getChar() == board[i-2][j+2].getChar() && board[i][j].getChar() == board[i-3][j+3].getChar())
                        {   //check the diagonal
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }
                    }
                    else
                    {
                        if(board[i][j].getChar() == board[i-1][j].getChar() && board[i][j].getChar()== board[i+1][j].getChar() && board[i][j].getChar() == board[i+2][j].getChar())
                        {//checking the vertical
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }
                        else if(board[i][j].getChar() == board[i][j-1].getChar() && board[i][j].getChar() == board[i][j-2].getChar() && board[i][j].getChar() == board[i][j-3].getChar())
                        {//checking the horizontal
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }
                        else if(board[i][j].getChar() == board[i-1][j-1].getChar() && board[i][j].getChar() == board[i-2][j-2].getChar() && board[i][j].getChar() == board[i-3][j-3].getChar())
                        {//check the diagonal
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }
                    }
                }
                else if(i == 4)
                {
                    if(j < 4)
                    {
                        if(board[i][j].getChar() == board[i-2][j].getChar() && board[i][j].getChar()== board[i-1][j].getChar() && board[i][j].getChar() == board[i+1][j].getChar())
                        {   //check the vertical
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }
                        else if(board[i][j].getChar() == board[i][j+1].getChar() && board[i][j].getChar() == board[i][j+2].getChar() && board[i][j].getChar() == board[i][j+3].getChar())
                        {//check the horizontal
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }
                        else if(board[i][j].getChar() == board[i-1][j+1].getChar() && board[i][j].getChar() == board[i-2][j+2].getChar() && board[i][j].getChar() == board[i-3][j+3].getChar())
                        {   //check the diagonal
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }
                    }
                    else
                    {
                        if(board[i][j].getChar() == board[i-2][j].getChar() && board[i][j].getChar()== board[i-1][j].getChar() && board[i][j].getChar() == board[i+1][j].getChar())
                        {//checking the vertical
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }
                        else if(board[i][j].getChar() == board[i][j-1].getChar() && board[i][j].getChar() == board[i][j-2].getChar() && board[i][j].getChar() == board[i][j-3].getChar())
                        {//checking the horizontal
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }
                        else if(board[i][j].getChar() == board[i-1][j-1].getChar() && board[i][j].getChar() == board[i-2][j-2].getChar() && board[i][j].getChar() == board[i-3][j-3].getChar())
                        {//check the diagonal
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }
                    }
                }
                else
                {
                    if(j < 4)
                    {
                        if(board[i][j].getChar() == board[i-3][j].getChar() && board[i][j].getChar()== board[i-2][j].getChar() && board[i][j].getChar() == board[i-1][j].getChar())
                        {   //check the vertical
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }
                        else if(board[i][j].getChar() == board[i][j+1].getChar() && board[i][j].getChar() == board[i][j+2].getChar() && board[i][j].getChar() == board[i][j+3].getChar())
                        {//check the horizontal
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }
                        else if(board[i][j].getChar() == board[i-1][j+1].getChar() && board[i][j].getChar() == board[i-2][j+2].getChar() && board[i][j].getChar() == board[i-3][j+3].getChar())
                        {   //check the diagonal
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }
                    }
                    else
                    {
                        if(board[i][j].getChar() == board[i-3][j].getChar() && board[i][j].getChar()== board[i-2][j].getChar() && board[i][j].getChar() == board[i-1][j].getChar())
                        {//checking the vertical
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }
                        else if(board[i][j].getChar() == board[i][j-1].getChar() && board[i][j].getChar() == board[i][j-2].getChar() && board[i][j].getChar() == board[i][j-3].getChar())
                        {//checking the horizontal
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }
                        else if(board[i][j].getChar() == board[i-1][j-1].getChar() && board[i][j].getChar() == board[i-2][j-2].getChar() && board[i][j].getChar() == board[i-3][j-3].getChar())
                        {//check the diagonal
                            if(board[i][j].getChar() == user1)
                            {
                                return 1;
                            } 
                            else
                            {
                                return 2;
                            }
                        }
                    }
                }
            }
        }
    }

    return -1;
}
int main()
{
    Board connectfour;
    
    char user1 = connectfour.start();
    char user2;

    if(user1 == 'X')
    {
        user2  = 'O';
    }
    else{
        user2 = 'X';
    }

    bool status = connectfour.get_userInput(user1);
    while(status != true)
    {
        status = connectfour.get_userInput(user1);
    }
    cout<<"STATUS USER1: "<<status<<endl;
    status = connectfour.get_userInput(user2);
    while(status != true)
    {
        status = connectfour.get_userInput(user2);
    }
    cout<<"STATUS USER2: "<<status<<endl;
    connectfour.print();    //print the gameboard for updates

    while(connectfour.get_currentStatus(user1) != 1 && connectfour.get_currentStatus(user1) != 2)
    {
        bool status = connectfour.get_userInput(user1);
        cout<<"STATUS USER1: "<<status<<endl;
        if(connectfour.get_currentStatus(user1) == 1)
        {
            break;
        }
        status = connectfour.get_userInput(user2);
        cout<<"STATUS USER2: "<<status<<endl;
        if(connectfour.get_currentStatus(user1) == 2)
        {
            break;
        }
        connectfour.print();
    }

    int winner = connectfour.get_currentStatus(user1);
    if(winner == 1)
    {
        cout<<"User "<<user1<<" wins the game! Congrats!"<<endl;
    }
    else
    {
        cout<<"User "<<user2<<" wins the game! Congrats!"<<endl;
    }

    return 0;
}