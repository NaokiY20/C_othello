#include <ncurses.h>
#include <locale.h>
#include "param.h"

enum icon{NONE,BLACK,WHITE};
extern char Icon[][4];

class Cell{
    char* state;
    public:
    Cell();
    char* get_state();
};  
class Board{
    public:
    Board();
    Cell board[height][width];
};