#include "othello.hpp"

char Icon[][4]={"-","●","●"};

Cell::Cell(){
    state=NONE;
}

STATE Cell::get_state(){
    return state;
}

void Cell::set_state(STATE s){
    state=s;
}

void Cell::put_stone(int x,int y){
    printf("(x,y)=(%d%d)\n",x,y);
    attrset(COLOR_PAIR(state));
    mvprintw(x,y,Icon[state]);
}

Board::Board(){}