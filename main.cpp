#include <iostream>
#include "board.cpp"
#include "SI.cpp"

using namespace std;

int main()
{
    int max_deep=1000;
    int size_;
    int win_c;
    board pl;

    cout<<"Wybierz rozmiar planszy:";
    cin>>size_;
    cout<<"Podaj warunek zwyciestwa:";
    cin>>win_c;
    pl.init(size_,win_c);

    pl.draw();
    while(pl.win()==0)
    {
        bool correct_xy=0;
        cout<<"Podaj wpolrzedne mastepnego ruchu:\n";
        int x,y;
        cout<<"x:";
        cin>>x;
        cout<<"y:";
        cin>>y;
        while(correct_xy==0)
        {
            correct_xy=1;
            if(x>size_ || y>size_ || x<1 || y<1)
            {
                cout<<"Nie ma takiego pola\n";
                correct_xy=0;
            }
            else
                if(pl.get_space(x-1,y-1)!=0)
                {
                    cout<<"To pole jest juz zajete.\n";
                    correct_xy=0;
                }
            if(correct_xy==0)
            {
            cout<<"Podaj wspolrzedne innego pola:\n";
            cout<<"x:";
            cin>>x;
            cout<<"y:";
            cin>>y;
            }
        }
        pl.set_space(x-1,y-1,1);
        pl.draw();

        if(pl.win()!=0)
            break;

        SI(pl, size_, win_c, max_deep);
        pl.draw();
    }
    switch(pl.win())
    {
    case -1:
        cout<<"Remis";
        break;
    case 1:
        cout<<"Wygral: o";
        break;
    case 2:
        cout<<"Wygral: x";
    }

    return 0;
}
