#pragma once

#include "board.hpp"

class Game {
    public:
        /*** member variables ***/

        Board board;

        /*** constructors ***/

        Game();

        /*** methods ***/

        void print_board();
};
