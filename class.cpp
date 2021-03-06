#include "class.h"
#include<sstream>
#include<iostream>
//@enum the symbol for players
using std::cout, std::cin, std::endl, std::stringstream;

TicTacToe::TicTacToe()
{
}

TicTacToe::TicTacToe(short size, 
                    short num_of_player, short to_win)
    : BOARD_SIZE(size), NUM_OF_PLAYER(num_of_player), NUM_TO_WIN(to_win)
{
}

void TicTacToe::init(short size, short num_of_player, short to_win) {
    mainboard.reserve(BOARD_SIZE);

    for (int i = 0; i < NUM_OF_PLAYER; ++i)
    {
        vector<short> temp;
        for (int k = 0; k < BOARD_SIZE; ++k)
        {
            temp.push_back(0);
        }
        row.push_back(temp);
        col.push_back(temp);
        diag.push_back(temp);
        op_diag.push_back(temp);
        isActive.push_back(1);
    }

    for (int j = 0; j < BOARD_SIZE; ++j)
    {
        vector<short> temp;
        for (int k = 0; k < BOARD_SIZE; ++k)
        {
            temp.push_back(0);
        }
        mainboard.push_back(temp);
    }
}

void TicTacToe::start()
{
    cout << "Press Enter to begin!" << endl
         << "Player one goes first." << endl;
    getchar();
    cout << "Use default configuration? (3x3 - 2 player) (y/n): ";
    if (tolower(getchar()) == 'n')
    {
        cout << "Board size: ";
        cin >> BOARD_SIZE;
        cout << "Num of player (must be < " << BOARD_SIZE << "): ";
        cin >> NUM_OF_PLAYER;
        while (NUM_OF_PLAYER >= BOARD_SIZE)
        {
            cout << "Num of player (must be < " << BOARD_SIZE << "): ";
            cin >> NUM_OF_PLAYER;
        }
        cout << "Number to win: ";
        cin >> NUM_TO_WIN;
    }
    cout << "All set. Enjoy the game!" << endl
         << endl;
    init(BOARD_SIZE, NUM_OF_PLAYER, NUM_TO_WIN);
    getchar();
    mainEvent();
}

void TicTacToe::drawMainBoard()
{
    //7 per block
    // cout << ":::::::::::::::::::::::::" << endl
    //      << ":       :       :       :" << endl
    //      << ":       :       :       :" << endl
    //      << ":       :       :       :" << endl
    //      << ":::::::::::::::::::::::::" << endl //
    //      << ":       :       :       :" << endl
    //      << ":       :       :       :" << endl
    //      << ":       :       :       :" << endl
    //      << ":::::::::::::::::::::::::" << endl //
    //      << ":       :       :       :" << endl
    //      << ":       :       :       :" << endl
    //      << ":       :       :       :" << endl
    //      << ":::::::::::::::::::::::::" << endl //
    //     ;
    for (int i = 0; i < BOARD_SIZE; ++i)
    {
        for (int j = 0; j < BOARD_SIZE; ++j)
        {  
            cout << mainboard[i][j] << " ";            
        }
        cout << endl;
    }
}

void TicTacToe::mainEvent() {
    while(!winner && winner!=STATE::QUIT && !isWin()) {
        drawMainBoard();
        for (int i = 0; i < NUM_OF_PLAYER; ++i) {
            short a=0, b=0;
            cout << "Player " << i + 1 << ", please enter x,y (-1 -1 for quit): ";
            cin >> a >> b;

            try {
                makeAMove(i, a, b);
                if(!isActive[i]) {
                    winner = STATE::QUIT;
                    break;
                } 
            }
            catch (std::invalid_argument &e) {
                std::cerr << e.what() << endl;
                i--;  
            }
        }
    }
    endScreen();
}

void TicTacToe::makeAMove(short player, short x, short y) {
    if(x==STATE::QUIT || y==STATE::QUIT)
    {
        isActive[player] = 0;
    }
    else if (x < BOARD_SIZE && y < BOARD_SIZE 
            && x>= 0 && y >= 0 && !mainboard[x][y])
    {
        mainboard[x][y] = player+1;
        row[player][x]++;
        col[player][y]++;
        if(x==y)
            diag[player][x]++;
        if(x+y+1 == BOARD_SIZE)
            op_diag[player][x]++;
    }
    else
        throw std::invalid_argument("Invalid move!\n");
}

void TicTacToe::endScreen() {
    cout << endl
         << endl;
    drawMainBoard();
    if(winner == STATE::QUIT) {
        cout << "Player quitted" << endl;
    }
    else if(winner!=STATE::DRAW) {
        cout << "Winner is player " << winner << endl;
    }
    else {
        cout << "Draw/No winner" << endl;
    }
    cout << endl << endl;
    cout << "Press R to restart the game!";
    if (tolower(getchar() == 'r'))
    {
        reset();
        getchar();
        start();
    }
    else cout << "Game ended" << endl
                << endl;
    
    getchar();
}

bool TicTacToe::isWin() {
    for (int i = 0; i < NUM_OF_PLAYER; ++i) {
        short sum_diag = 0, sum_op_diag = 0;

        for (int j = 0; j < BOARD_SIZE; ++j) {
            if(row[i][j] == NUM_TO_WIN || col[i][j] == NUM_TO_WIN)
            {
                winner = i+1;
                return true;
            }
            sum_diag += diag[i][j];
            sum_op_diag += op_diag[i][j];
        }
        if (sum_diag == NUM_TO_WIN || sum_op_diag == NUM_TO_WIN)
        {
            winner = i+1;
            return true;
        }
    }
    return false;
}

void TicTacToe::reset()
{
    isActive.clear();
    row.clear();
    col.clear();
    diag.clear();
    op_diag.clear();
    for (int k = 0; k < BOARD_SIZE; ++k)
    {
        mainboard[k].clear();
    }
    mainboard.clear();
    winner = 0;
}

void TicTacToe::debugScreen(const short size, const short num_of_player,
                            string s, const short to_win)
{

    init(size, num_of_player, to_win);
    const int N = s.length();
    const int NUM_BASE = 48;

    cout << "Debug mode is on!" << endl;

    if (N % 2 != 0 || N > BOARD_SIZE * BOARD_SIZE * 2 + 2)
    {
        cout << "Invalid test string!" << endl;
    }
    else
    {
        stringstream stream(s);
        string temp = "";
        std::getline(stream, temp, '-');
        cout << temp << endl;
        int i = 0, j = 0;

        while (!isWin() && !winner && i < N - 2)
        {
            short x = s[i] - NUM_BASE, y = s[i + 1] - NUM_BASE;
            try
            {
                makeAMove(j, x, y);
            }
            catch (std::invalid_argument &e)
            {
                std::cerr << e.what() << endl;
                break;
            }
            if (!isActive[j])
            {
                winner = 0;
                break;
            }
            i += 2;
            j++;
            if (j == NUM_OF_PLAYER)
                j = 0;
        }
        drawMainBoard();

        if (winner != s[N - 1] - NUM_BASE)
        {
            cout << "Wrong winner!\nWinner in game is " << winner
                 << " while test winner is " << s[N - 1] << endl << endl;
        }
        else
        {
            cout << "Test succesfully!" << endl;
            cout << "Winner is " << s[N - 1] << endl
                 << endl;
        }
    }
}
