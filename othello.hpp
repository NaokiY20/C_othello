#include <ncurses.h>
#include <locale.h>
#include "param.h"

#define height 9
#define width 9

//Cellの状態の列挙。ほとんどの場合これに準ずる
typedef enum {NONE,WHITE,BLACK} STATE;
extern char Icon[][4];


class Cell{
    STATE state;

    public:
        Cell();
        STATE get_state();
        void set_state(STATE);
        void put_stone(int,int);
};  
class Board{
    public:
        Board();
        Cell board[height][width];
};