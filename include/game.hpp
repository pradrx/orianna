#pragma once

#include "board.hpp"
#include "move.hpp"

#include <string>

class Game
{
public:
    /*** member variables ***/

    Board board;

    /*** constructors ***/

    Game();

    /*** methods ***/

    void print_board();
    Move parse_input(std::string move);
};
