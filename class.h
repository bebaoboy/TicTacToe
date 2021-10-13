#ifndef _HEADER_
#define _HEADER_
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>

using std::vector;
class TicTacToe
{
public:
    TicTacToe();
    TicTacToe(const short, const short);
    ~TicTacToe();

private:
    void drawMainBoard();
    void mainMenu();
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

    const short BOARD_SIZE = 3;
    const short NUM_OF_PLAYER = 2;

    enum STATE{QUIT = -1, DRAW};

    //debug
    bool debug_mode;
    std::string s;

protected:
    TicTacToe(bool, std::string, const short=3, const short=2);
};

class Test : public TicTacToe
{
public:
    Test(const short, const short, bool, std::string);

private:
};

#endif