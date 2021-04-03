#include "othello.hpp"

void start_up(){
    setlocale(LC_ALL,"");
    initscr();
    set_color();
}

int main(){
    start_up();
    
    // Othello othello;
    // othello.game_loop();
    Board board;
    board.set_stone(6,4,WHITE);
    board.print_board(5,5);
    refresh();
    getch();
    
    board.set_stone(6,4,BLACK);
    board.set_stone(6,5,BLACK);
    // getch();
    erase();
    refresh();
    board.print_board(5,5);
    refresh();
    getch();
    erase();
    
    endwin();
}