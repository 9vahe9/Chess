#include <cstdlib>
#include "Game.h"
#include <iostream>


void Game::run()
{   
    std::system("clear");
    m_board.render();
    waitForInput();
}

Game::waitForInput()
{   
    
    std::cin 
}