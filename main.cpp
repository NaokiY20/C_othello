#include "othello.hpp"

#define BACK_COLOR COLOR_GREEN

int main(){
    setlocale(LC_ALL,"");
    initscr();
    start_color();
    init_pair(1,COLOR_BLACK,BACK_COLOR);
    init_pair(2,COLOR_WHITE,BACK_COLOR);

    Board b;
    
    b.board[3][3].set_state(BLACK);
    b.board[3][4].set_state(WHITE);
    b.board[4][3].set_state(WHITE);
    b.board[4][4].set_state(BLACK);
    for(int i=0;i<9;i++){
        int j2=0;
        for(int j=0;j<9;j++){
            attrset(COLOR_PAIR(1));
            mvprintw(i,j2++,"|");
            b.board[i][j].print_stone(i,j2++);
        }
        attrset(COLOR_PAIR(1));
        mvprintw(i,j2++,"|");
    }
    getch();
    endwin();
}