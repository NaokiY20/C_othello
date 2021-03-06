#include "othello.hpp"

#define BACK_COLOR COLOR_GREEN

int main(){
    setlocale(LC_ALL,"");
    initscr();
    start_color();
    init_pair(1,COLOR_BLACK,BACK_COLOR);
    init_pair(2,COLOR_WHITE,BACK_COLOR);

    Board b;
    
    b.print_board(5,5);
    getch();
    endwin();
}