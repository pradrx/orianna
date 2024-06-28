#pragma once

#include <cstdint>

/**
 * binary board representation
 * a1 = lsb, h8 = msb: moving from right to left from bottom to top
 * 
 * h8 g8 f8 e8 d8 c8 b8 a8
 * h7 g7 f7 e7 d7 c7 b7 a7
 * h6 g6 f6 e6 d6 c6 b6 a6
 * h5 g5 f5 e5 d5 c5 b5 a5
 * h4 g4 f4 e4 d4 c4 b4 a4
 * h3 g3 f3 e3 d3 c3 b3 a3
 * h2 g2 f2 e2 d2 c2 b2 a2
 * h1 g1 f1 e1 d1 c1 b1 a1
 * 
 * 63 62 61 60 59 58 57 56
 * 55 54 53 52 51 50 49 48
 * 47 46 45 44 43 42 41 40
 * 39 38 37 36 35 34 33 32
 * 31 30 29 28 27 26 25 24
 * 23 22 21 20 19 18 17 16
 * 15 14 13 12 11 10 09 08
 * 07 06 05 04 03 02 01 00
 */

typedef uint64_t Bitboard;

class Board {
    public:
        /*** aliases and enums ***/

        enum enumSquare {
            A1, B1, C1, D1, E1, F1, G1, H1,
            A2, B2, C2, D2, E2, F2, G2, H2,
            A3, B3, C3, D3, E3, F3, G3, H3,
            A4, B4, C4, D4, E4, F4, G4, H4,
            A5, B5, C5, D5, E5, F5, G5, H5,
            A6, B6, C6, D6, E6, F6, G6, H6,
            A7, B7, C7, D7, E7, F7, G7, H7,
            A8, B8, C8, D8, E8, F8, G8, H8
        };

        /*** member variables ***/

        Bitboard white_pawns;
        Bitboard white_knights;
        Bitboard white_bishops;
        Bitboard white_rooks;
        Bitboard white_queens;
        Bitboard white_king;

        Bitboard black_pawns;
        Bitboard black_knights;
        Bitboard black_bishops;
        Bitboard black_rooks;
        Bitboard black_queens;
        Bitboard black_king;

        Bitboard all_white_pieces;
        Bitboard all_black_pieces;
        Bitboard all_pieces;

        // access with enumSquare, bitboard represents the moves for the piece on that index
        Bitboard moves[64];

        /*** constructors ***/

        Board();

        /*** methods ***/

        Bitboard compute_knight_moves(Bitboard knight, Bitboard side);
};
