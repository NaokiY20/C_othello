#include "othello.hpp"

int main(){
    setlocale(LC_ALL,"");
    initscr();
    set_color();

    Board b;
    
    b.print_board(5,5);
    getch();
    endwin();
}