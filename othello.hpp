#include <ncurses.h>
#include <locale.h>
#include "param.hpp"
#include "color.hpp"
#include <utility>

#define height 8
#define width 8

//Cellの状態の列挙。ほとんどの場合これに準ずる
typedef enum {NONE,WHITE,BLACK} STATE; //Cellに何が置かれているのか
typedef enum {NORMAL,SELECT,ABLE} CELL_STATE; //Cellの状態
extern char Icon[][4];


class Cell{
    STATE state;
    CELL_STATE cell_state;

    public:
        Cell();
        STATE get_state();
        void set_state(STATE);
        CELL_STATE get_Cstate();
        void set_Cstate(CELL_STATE);
        void print_stone(int,int);
};  
class Board{
    Cell board[height][width];

    int search_local(int,int);

    public:
        Board();
        void print_board(int,int); //左上の座標を指定して盤面を表示
        void set_stone(int,int,STATE); //盤面にSTATEの石を設置
        int search_able(STATE); //STATEの石を置けるセルを探し、そのセルをABLEにする(置ける数を返す)
        bool put_stone(int,int,STATE); //置けることを確認して設置(置けないならfalseを返す)
};

class Cursol{
    int x,y;

    public:
        Cursol();
        void xpp(); //xインクリメント
        void ypp(); //yインクリメント
        void xmm(); //xデクリメント
        void ymm(); //yデクリメント
};

class Othello{
    Board board;
    STATE turn;
    Cursol cursol;

    public:
        Othello();
        void game_loop();
};