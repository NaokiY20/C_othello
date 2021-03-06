#include "othello.hpp"

void start_up(){
    setlocale(LC_ALL,"");
    initscr();
    set_color();
}

int main(){
    start_up();
    
    Board b;
    b.print_board(5,5);
    getch();
    endwin();
}