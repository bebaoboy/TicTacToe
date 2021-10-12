#include "class.h"

using std::string;

Test::Test(const short size, const short num_of_player,
           bool isDebug, string s) : TicTacToe(size, num_of_player, isDebug, s) 
{
}

void test() {
    Test t[] = {{3, 2, 1, "001001110222-1"},      //row
                {3, 2, 1, "000201121122-2"},      //col
                {3, 2, 1, "001011202202-1"},      //diag
                {3, 2, 1, "100222111220-2"},      //op_diag
                {3, 2, 1, "000102101112202122-1"}, //random
                {3, 2, 1, "010002101112202122-0"}};
}