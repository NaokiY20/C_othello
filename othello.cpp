#include "othello.hpp"
#include <vector>
#include <utility>

char Icon[]="●";

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
            switch(state){
                case BLACK:
                    attrset(COLOR_PAIR(B_B));
                    break;
                case WHITE:
                    attrset(COLOR_PAIR(W_B));
                    break;
                default:
                    attrset(COLOR_PAIR(BB));
                    break;
            }
        case ABLE:
            switch(state){
                case BLACK:
                    attrset(COLOR_PAIR(B_Y));
                    break;
                case WHITE:
                    attrset(COLOR_PAIR(W_Y));
                    break;
                default:
                    attrset(COLOR_PAIR(YY));
                    break;
            }
        default:
            switch(state){
                case BLACK:
                    attrset(COLOR_PAIR(B_G));
                    break;
                case WHITE:
                    attrset(COLOR_PAIR(W_G));
                    break;
                default:
                    attrset(COLOR_PAIR(GG));
                    break;
            }
    }
    mvprintw(x,y,Icon);
}


Board::Board(){
    set_stone(3,3,WHITE);
    set_stone(3,4,BLACK);
    set_stone(4,3,BLACK);
    set_stone(4,4,WHITE);
}

void Board::set_stone(int x,int y,STATE s){
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

std::vector<std::pair<int,int>> vec={
    std::make_pair(1,-1),
    std::make_pair(1,0),
    std::make_pair(1,1),
    std::make_pair(0,-1),
    std::make_pair(0,1),
    std::make_pair(-1,-1),
    std::make_pair(-1,0),
    std::make_pair(-1,1)
};

int Board::search_local(int i, int j, STATE turn,std::pair<int,int> vec){
    if(i<0 || j<0 || i>=height || j>= width) return -1;
    if(board[i][j].get_state()==NONE) return -1;
    if(board[i][j].get_state()==turn) return 0;
    else{
        int next = search_local(i+vec.first,j+vec.second,turn,vec);
        if(next==-1) return -1;
        else return next+1;
    }
}


int Board::search_able(STATE turn){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            for(auto k: vec){
                if(search_local(i+k.first,k.second,turn,k)!=-1){
                    board[i][j].set_Cstate(ABLE);
                    break;
                }
            }
        }
    }
}

bool Board::put_stone(int x,int y,STATE s){
    if(board[x][y].get_Cstate()!=ABLE) return false;
    else{
        set_stone(x,y,s);
        return true;
    }
}

Cursol::Cursol(){
    x=0;
    y=0;
}

void Cursol::xpp(){
    x=++x%height;
}

void Cursol::ypp(){
    y=++y%width;
}

void Cursol::xmm(){
    x=--x%height;
}

void Cursol::ymm(){
    y=--y%width;
}

Othello::Othello(){
    turn=BLACK;
    board.search_able(turn);
}

void Othello::game_loop(){
    board.search_able(turn);
    board.print_board(5,10);
}