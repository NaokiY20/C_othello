#include "othello.hpp"

#define BACK_COLOR COLOR_GREEN

int main(){
    setlocale(LC_ALL,"");
    initscr();
    start_color();
    init_pair(1,COLOR_WHITE,BACK_COLOR);
    init_pair(2,COLOR_BLACK,BACK_COLOR);
    init_pair(3,COLOR_WHITE,BACK_COLOR);

    Board b;

    
    
    for(int i=0;i<10;i++){
        if(i&1)
            b.board[i][0].set_state(BLACK);
        else
            b.board[i][0].set_state(NONE);
        b.board[i][0].put_stone(i,0);
    }
    
    getch();
    endwin();
}