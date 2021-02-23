#include "othello.hpp"

#define BACK_COLOR COLOR_GREEN

int main(){
    setlocale(LC_ALL,"");
    initscr();
    start_color();
    init_pair(1,COLOR_BLUE,BACK_COLOR);
    init_pair(2,COLOR_RED,BACK_COLOR);

    Board b;
    
    for(int i=0;i<10;i++){
        if(i&1) attrset(COLOR_PAIR(1));
        else attrset(COLOR_PAIR(2));
        mvprintw(i,0,b.board[0][0].get_state());
    }
    
    getch();
    endwin();
}