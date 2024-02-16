# pragma once
#include "ChessBoard.h"

class Game
{
private:
    ChessBoard m_board;

public:
    void run();
    void waitForInput();
};