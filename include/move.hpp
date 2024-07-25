#pragma once

#include <cstdint>

class Move
{
public:
    /*** member variables ***/

    uint64_t curr_pos;
    uint64_t new_pos;

    /*** constructors ***/

    Move(uint64_t curr_pos, uint64_t new_pos);

    /*** methods ***/
};
