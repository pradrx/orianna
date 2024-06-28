#include "board.hpp"

Board::Board() {
    // lsb -> msb: a1 b1 c1 ... h1 a2 b2 ...

    white_pawns =   0x000000000000FF00;
    white_knights = 0x0000000000000024;
    white_bishops = 0x0000000000000042;
    white_rooks =   0x0000000000000081;
    white_queens =  0x0000000000000008;
    white_king =    0x0000000000000010;

    black_pawns =   0x00FF000000000000;
    black_knights = 0x2400000000000000;
    black_bishops = 0x4200000000000000;
    black_rooks =   0x8100000000000000;
    black_queens =  0x0800000000000000;
    black_king =    0x1000000000000000;

    all_white_pieces = white_pawns | white_knights | white_bishops | white_rooks | white_queens | white_king;
    all_black_pieces = black_pawns | black_knights | black_bishops | black_rooks | black_queens | black_king;
    all_pieces = all_white_pieces | all_black_pieces;
}

Board::compute_knight_moves() {

}

