#ifndef _TEST_H_
#define _TEST_H_

#include "class.h"
#include <string>
using std::string;

class Test : public TicTacToe
{
public:
    Test(short size, short num_of_player,
         string s, short to_win = 3);

private:
    //TicTacToe t;
};

#endif