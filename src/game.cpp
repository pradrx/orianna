#include "game.hpp"

#include <iostream>
#include <string>

Game::Game() {
    board = Board();
}

/**
 * 56 57 58 59 60 61 62 63
 * 48 49 50 51 52 53 54 55
 * 40 41 42 43 44 45 46 47
 * 32 33 34 35 36 37 38 39
 * 24 25 26 27 28 29 30 31
 * 16 17 18 19 20 21 22 23
 * 08 09 10 11 12 13 14 15
 * 00 01 02 03 04 05 06 07
 */


// This method is terrible but its just for debugging and doesn't affect compute very much
// even if we choose to visualize it (around 500 or so comparisons in worst case each ply).
void Game::print_board() {
    for (int i = 7; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            std::string symbol = ".";

            int bit = i * 8 + j;
            
            if (board.white_pawns & ((uint64_t) 1u << bit)) {
                symbol = "p";
            } else if (board.white_knights & ((uint64_t) 1u << bit)) {
                symbol = "n";
            } else if (board.white_bishops & ((uint64_t) 1u << bit)) {
                symbol = "b";
            } else if (board.white_rooks & ((uint64_t) 1u << bit)) {
                symbol = "r";
            } else if (board.white_queens & ((uint64_t) 1u << bit)) {
                symbol = "q";
            } else if (board.white_king & ((uint64_t) 1u << bit)) {
                symbol = "k";
            } else if (board.black_pawns & ((uint64_t) 1u << bit)) {
                symbol = "P";
            } else if (board.black_knights & ((uint64_t) 1u << bit)) {
                symbol = "N";
            } else if (board.black_bishops & ((uint64_t) 1u << bit)) {
                symbol = "B";
            } else if (board.black_rooks & ((uint64_t) 1u << bit)) {
                symbol = "R";
            } else if (board.black_queens & ((uint64_t) 1u << bit)) {
                symbol = "Q";
            } else if (board.black_king & ((uint64_t) 1u << bit)) {
                symbol = "K";
            }
            std::cout << symbol << " ";
        }
        std::cout << "\n";
    }
}
