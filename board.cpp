#include <iostream>
#include "board.h"

using std::cout;
using std::endl;

board::board()
{
    b_size=0;
    win_c=0;
    tab_board=new int *[0];
}

void board::init(int new_size, int new_win_condition)
{
    for(int i=0; i<b_size; i++)
        delete [] tab_board[i];
    delete [] tab_board;

    b_size=new_size;
    win_c=new_win_condition;

    tab_board=new int *[new_size];
    for(int i=0; i<new_size; i++)
        tab_board[i]=new int [new_size];

    for(int i=0; i<new_size; i++)
        for(int j=0; j<new_size; j++)
            tab_board[i][j]=0;
}

void board::set_space(int x, int y, int value)
{
    tab_board[x][y]=value;
}

int board::get_space(int x, int y)
{
    return tab_board[x][y];
}

void board::draw()
{
    cout<<"   ";
    for(int i=1; i<b_size+1; i++)
    {
        if(i<10)
            cout<<' '<<i<<"  ";
        else
            cout<<' '<<i<<' ';
    }
    cout<<" y"<<endl;

    for(int i=0; i<b_size; i++)
    {
        if(i<9)
            cout<<' '<<i+1<<' ';
        else
            cout<<i+1<<' ';

        for(int j=0; j<b_size; j++)
        {
            int W=tab_board[i][j];
            switch(W)
            {
            case 0:
                cout<<"   ";
                break;
            case 1:
                cout<<" o ";
                break;
            case 2:
                cout<<" x ";
            }
            if(j<b_size-1)
                cout<<"|";
        }
        cout<<endl;
        if(i<b_size-1)
        {
            cout<<"   ";
            for(int j=0; j<b_size*4-1; j++)
                cout<<'_';
            cout<<endl;
        }
    }
    cout<<" x"<<endl;
}

int board::win()
{
    bool win;
    for(int i=0; i<b_size; i++)
        for(int j=0; j<b_size-win_c+1; j++)
        {
            //wiersze
            win=1;
            for(int k=1; k<win_c; k++)
                if(tab_board[i][j]!=tab_board[i][j+k])
                    win=0;
            if(win==1 && tab_board[i][j]!=0)
                return tab_board[i][j];

            //kolumny
            win=1;
            for(int k=1; k<win_c; k++)
                if(tab_board[j][i]!=tab_board[j+k][i])
                    win=0;
            if(win==1 && tab_board[j][i]!=0)
                return tab_board[j][i];
        }

    //skosy w prawo
    for(int i=0; i<(b_size-win_c)+1; i++)
    {
        int ile_j=1;
        for(int j=0; j<b_size-win_c+ile_j; j++)
        {
            win=1;
            for(int k=1; k<win_c; k++)
                if(tab_board[i][j]!=tab_board[i+k][j+k])
                    win=0;
            if(win==1 && tab_board[i][j]!=0)
                return tab_board[i][j];

            win=1;
            for(int k=1; k<win_c; k++)
                if(tab_board[j][i]!=tab_board[j+k][i+k])
                    win=0;
            if(win==1 && tab_board[j][i]!=0)
                return tab_board[j][i];
        }

        ile_j--;
    }

    //skosy w lewo
    for(int i=b_size-1; i>win_c-2; i--)
    {
        int ile_j=1;
        for(int j=0; j<b_size-win_c+ile_j; j++)
        {
            win=1;
            for(int k=1; k<win_c; k++)
                if(tab_board[i][j]!=tab_board[i-k][j+k])
                    win=0;
            if(win==1 && tab_board[i][j]!=0)
                return tab_board[i][j];

            win=1;
            for(int k=1; k<win_c; k++)
                if(tab_board[j][i]!=tab_board[j+k][i-k])
                    win=0;
            if(win==1 && tab_board[j][i]!=0)
                return tab_board[j][i];
        }

        ile_j--;
    }

    for(int i=0; i<b_size; i++)
        for(int j=0; j<b_size; j++)
            if(tab_board[i][j]==0)
                return 0;

    return -1;
}
