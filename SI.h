#ifndef SI_H_INCLUDED
#define SI_H_INCLUDED

struct move_
{
    int x;
    int y;
    int value;
};

int min_max(board br, int max_deep, int deep, int size_, int x, int y);

void SI(board br ,int size_ ,int win_c ,int max_deep);

#endif // SI_H_INCLUDED
