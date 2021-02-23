#include "othello.hpp"

char Icon[][4]={"-","○","●"};

Cell::Cell(){
    state=Icon[NONE];
}

char* Cell::get_state(){
    return state;
}

Board::Board(){}