#include "othello.hpp"

char Icon[][4]={"　","●","●"};

Cell::Cell(){
    state=NONE;
}

STATE Cell::get_state(){
    return state;
}

void Cell::set_state(STATE s){
    state=s;
}

void Cell::print_stone(int x,int y){
    switch(state){
        case BLACK:
            attrset(COLOR_PAIR(1));
            break;
        default:
            attrset(COLOR_PAIR(2));
            break;
    }
    mvprintw(x,y,Icon[state]);
}

Board::Board(){
    put_stone(3,3,WHITE);
    put_stone(3,4,BLACK);
    put_stone(4,3,BLACK);
    put_stone(4,4,WHITE);

}

void Board::put_stone(int x,int y,STATE s){
    board[x][y].set_state(s);
}

void Board::print_board(int x,int y){
    for(int i=0;i<height;i++){
        int j2=y;
        for(int j=0;j<width;j++){
            attrset(COLOR_PAIR(1));
            mvprintw(i+x,j2++,"|");
            board[i][j].print_stone(i+x,j2++);
        }
        attrset(COLOR_PAIR(1));
        mvprintw(i+x,j2++,"|");
    }
}