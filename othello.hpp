#include <ncurses.h>
#include <locale.h>
#include "param.hpp"

#define height 8
#define width 8

//Cellの状態の列挙。ほとんどの場合これに準ずる
typedef enum {NONE,WHITE,BLACK} STATE;
extern char Icon[][4];


class Cell{
    STATE state;

    public:
        Cell();
        STATE get_state();
        void set_state(STATE);
        void print_stone(int,int);
};  
class Board{
    Cell board[height][width];

    public:
        Board();
        void print_board(int,int);

};