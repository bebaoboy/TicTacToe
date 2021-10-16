#ifndef _CLASS_H_
#define _CLASS_H_
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>

using std::vector, std::string;
class TicTacToe
{
public:
    TicTacToe();
    TicTacToe(short size, short num_of_player, short to_win);
    void start();

private:
    void init(short, short, short);
    void drawMainBoard();
    bool isWin();
    void mainEvent();
    void makeAMove(short, short, short);
    void endScreen();
    void reset();

    vector<vector<short>> mainboard;
    vector<vector<short>> row, col, diag, op_diag;
    vector<bool> isActive;

    short winner = 0;

    short BOARD_SIZE = 3;
    short NUM_OF_PLAYER = 2;
    short NUM_TO_WIN = 3;

    enum STATE{QUIT = -1, DRAW};

protected:
    void debugScreen(short size, short num_of_player,
                     string s, short to_win);
};


#endif