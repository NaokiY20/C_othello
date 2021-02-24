#include "othello.hpp"

char Icon[][4]={" ","●","●"};

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
    printf("%d\n",state);
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

Board::Board(){}