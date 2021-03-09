#include "othello.hpp"

void start_up(){
    setlocale(LC_ALL,"");
    initscr();
    set_color();
}

int main(){
    start_up();
    
    Othello othello;
    othello.game_loop();
    getch();
    endwin();
}