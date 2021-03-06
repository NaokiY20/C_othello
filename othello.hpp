#include <ncurses.h>
#include <locale.h>
#include "param.hpp"
#include "color.hpp"

#define height 8
#define width 8

//Cellの状態の列挙。ほとんどの場合これに準ずる
typedef enum {NONE,WHITE,BLACK} STATE;
typedef enum {NORMAL,SELECT,ABLE} CELL_STATE;
extern char Icon[][4];


class Cell{
    STATE state;
    CELL_STATE cell_state;

    public:
        Cell();
        STATE get_state();
        void set_state(STATE);
        CELL_STATE get_Cstate();
        void set_Cstate(CELL_STATE);
        void print_stone(int,int);
};  
class Board{
    Cell board[height][width];

    public:
        Board();
        void print_board(int,int);
        void put_stone(int,int,STATE);
};