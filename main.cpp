#include <ncurses.h>
#include <unistd.h>

#define BACK_COLOR COLOR_GREEN

char board[11][11];

int main(){
    for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
    board[i][j]='*';
    for(int i=0;i<10;i++)
    board[i][10]='\0';

    initscr();
    start_color();
    init_pair(1,COLOR_BLUE,BACK_COLOR);
    init_pair(2,COLOR_RED,BACK_COLOR);
    

    
    for(int i=0;i<10;i++){
        if(i&1) attrset(COLOR_PAIR(1));
        else attrset(COLOR_PAIR(2));
        mvprintw(i,0,board[i]);
    }
    
    getch();
    endwin();
}