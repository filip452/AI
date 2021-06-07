#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

class board
{
    int b_size;
    int win_c;
    int **tab_board;
public:
    board();
    void init(int new_size, int new_win_c);
    void set_space(int x, int y, int value);
    int get_space(int x, int y);
    void draw();
    int win();
};

#endif // BOARD_H_INCLUDED
