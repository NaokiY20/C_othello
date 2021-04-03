#include "color.hpp"

void set_color(){
    start_color();

    // C_COLORに準ずる
    init_pair(B_G,COLOR_BLACK,COLOR_GREEN);
    init_pair(W_G,COLOR_WHITE,COLOR_GREEN);
    init_pair(GG,COLOR_RED,COLOR_GREEN);
    init_pair(B_Y,COLOR_BLACK,COLOR_YELLOW);
    init_pair(W_Y,COLOR_WHITE,COLOR_YELLOW);
    init_pair(YY,COLOR_YELLOW,COLOR_YELLOW);
    init_pair(B_B,COLOR_BLACK,COLOR_BLUE);
    init_pair(W_B,COLOR_WHITE,COLOR_BLUE);
    init_pair(BB,COLOR_BLUE,COLOR_BLUE);

}