#include "class.h"
#include "test.h"

using std::string;

Test::Test(short size, short num_of_player,
           string s, short to_win)
{
    debugScreen(size, num_of_player, s, to_win);
}

void test() {
    Test is_win[] = {{3, 2, "001001110222-1"},      //row
                {3, 2, "000201121122-2"},      //col
                {3, 2, "001011202202-1"},      //diag
                {3, 2, "100222111220-2"},      //op_diag
                {3, 2, "000102101112202122-1"}, //random
                {3, 2, "010002101112202122-1"}}; //random

    Test invalid_move[] = {{3, 2, "000011102221-1"}};
}