#include <ncurses.h>
#include <unistd.h>

char board[11][11];

int main(){
    for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
    board[i][j]='.';
    for(int i=0;i<10;i++)
    board[i][10]='\0';

    initscr();

    
    for(int i=0;i<10;i++){
        mvprintw(i,0,board[i]);
    }
    
    getch();
    endwin();
}