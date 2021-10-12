#ifndef _HEADER_
#define _HEADER_
#include <vector>
#include <string>
#include <iostream>

using std::vector;
class TicTacToe
{
public:
    TicTacToe(const short = 3, const short = 2);
    ~TicTacToe();

private:
    void drawMainBoard();
    bool isWin();
    void mainEvent();
    void makeAMove(short, short, short);
    void endScreen();
    void reset();
    void debugScreen();

    vector<vector<short>> mainboard;
    vector<vector<short>> row, col, diag, op_diag;
    vector<bool> isActive;

    short winner = 0;

    const short BOARD_SIZE;
    const short NUM_OF_PLAYER;

    //debug
    bool debug_mode = 0;
    std::string s = "";

protected:
    TicTacToe(const short = 3, const short = 2, bool = 0, std::string = "");
};

class Test : public TicTacToe
{
public:
    Test(const short = 3, const short = 2, bool = 0, std::string = "");

private:
};

#endif