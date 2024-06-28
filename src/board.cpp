#include "board.hpp"
#include "lookup_tables.hpp"

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

Bitboard Board::compute_knight_moves(Bitboard knight, Bitboard side) {
    // mask out A going to A - 1
    Bitboard p1 = (knight & MASK_FILE[FILE_A]) << 15;
    Bitboard p2 = (knight & MASK_FILE[FILE_A]) >> 17;

    // mask out H going to H + 1
    Bitboard p3 = (knight & MASK_FILE[FILE_H]) << 17;
    Bitboard p4 = (knight & MASK_FILE[FILE_H]) >> 15;

    // mask out B going to B - 2 and A going to A - 2
    Bitboard p5 = (knight & MASK_FILE[FILE_A] & MASK_FILE[FILE_B]) << 6;
    Bitboard p6 = (knight & MASK_FILE[FILE_A] & MASK_FILE[FILE_B]) >> 10;

    // mask out G going to G + 2 and H going to H + 2
    Bitboard p7 = (knight & MASK_FILE[FILE_G] & MASK_FILE[FILE_H]) << 10;
    Bitboard p8 = (knight & MASK_FILE[FILE_G] & MASK_FILE[FILE_H]) >> 6;

    Bitboard moves = p1 | p2 | p3 | p4 | p5 | p6 | p7 | p8;
    
    // remove moves that land on your own sides pieces
    return moves & ~side;
}

