#include "othello.hpp"

char Icon[][4]={"　","●","●"};

Cell::Cell(){
    state=NONE;
    cell_state=NORMAL;
}

STATE Cell::get_state(){
    return state;
}

void Cell::set_state(STATE s){
    state=s;
}

CELL_STATE Cell::get_Cstate(){
    return cell_state;
}

void Cell::set_Cstate(CELL_STATE c){
    cell_state=c;
}

void Cell::print_stone(int x,int y){
    switch(cell_state){
        case SELECT:
            if(state==BLACK) attrset(COLOR_PAIR(B_B));
            else attrset(COLOR_PAIR(W_B));
            break;
        case ABLE:
            if(state==BLACK) attrset(COLOR_PAIR(B_Y));
            else attrset(COLOR_PAIR(W_Y));
            break;
        default:
            if(state==BLACK) attrset(COLOR_PAIR(B_G));
            else attrset(COLOR_PAIR(W_G));
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