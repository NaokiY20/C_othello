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
    erase();
    Board board;
    board.set_stone(3,3,BLACK);
    // board.print_board(5,5);
    refresh();
    getch();
    erase();
    // board.set_stone(2,2,WHITE);
    board.set_stone(5,5,WHITE);
    board.print_board(5,5);
    refresh();
    getch();
    erase();
    // board.set_stone(2,2,WHITE);
    board.set_stone(6,5,WHITE);
    board.print_board(5,5);
    refresh();
    getch();
    endwin();
}