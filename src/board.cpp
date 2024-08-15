#include <iostream>

#include "board.hpp"
#include "lookup_tables.hpp"

Board::Board()
{
    // lsb -> msb: a1 b1 c1 ... h1 a2 b2 ...

    white_pawns = 0x000000000000FF00;
    white_knights = 0x0000000000000042;
    white_bishops = 0x0000000000000024;
    white_rooks = 0x0000000000000081;
    white_queens = 0x0000000000000008;
    white_king = 0x0000000000000010;

    black_pawns = 0x00FF000000000000;
    black_knights = 0x4200000000000000;
    black_bishops = 0x2400000000000000;
    black_rooks = 0x8100000000000000;
    black_queens = 0x0800000000000000;
    black_king = 0x1000000000000000;

    all_white_pieces = white_pawns | white_knights | white_bishops | white_rooks | white_queens | white_king;
    all_black_pieces = black_pawns | black_knights | black_bishops | black_rooks | black_queens | black_king;
    all_pieces = all_white_pieces | all_black_pieces;

    compute_movesets();
}

// take two arguments
// 1. Bitboard piece: represents position of the piece on board
// 2. Bitboard move: represents where the piece wants to move
// validate:
// - if there is a piece on that position
// - if the move they have inputted exists in that pieces moveset
// once we have determined this move is valid we need to:
// - update our bitboard states for our pieces
// - for the moving piece we need to change its location in the specific piece board
//   (white_knight, white_bishops, etc...)
// - if there is a piece on the space we are moving to (its a capture since it has to be
//   opposite side as generated in our moveset), we need to remove that piece from the
//   specific piece board as well
// - once we have made sure all of the specific piece bitboards are accurate we can then
//   regenerate our all_white_pieces, all_black_pieces, and all_pieces bitboards
// - at this point, our state bitboards should all be accurate and represent the current
//   position we're in after making said move
void user_make_move() {}

// after a move is performed, our state bitboards should be accurate but we need to
// regenerate our moveset for each piece, do that here
// we can also change the name of this function cause we need to do this at the start
// of the game as well
void after_move() {}

void Board::print_bitboard(Bitboard board)
{
    for (int i = 63; i >= 0; --i)
    {
        // Mask to check each bit
        uint64_t mask = 1ULL << i;

        // Print 1 or 0 based on whether the bit is set
        if (board & mask)
        {
            std::cout << "1 ";
        }
        else
        {
            std::cout << "0 ";
        }

        // Optionally add line breaks for better visualization
        if (i % 8 == 0)
        {
            std::cout << "\n"; // Line break after every 8 bits (1 byte)
        }
    }

    std::cout << "\n\n";
}

void Board::compute_movesets()
{
    Bitboard side;

    for (int i = 0; i < 64; i++)
    {
        if ((PIECE[i] & all_pieces) == 0)
            continue; // skip if theres no piece

        if (PIECE[i] & all_white_pieces)
        {
            side = all_white_pieces;
        }
        else
        {
            side = all_black_pieces;
        }

        if (PIECE[i] & (white_knights | black_knights))
        {
            movesets[i] = compute_knight_moves(PIECE[i], side);
        }
    }
}

Bitboard Board::compute_knight_moves(Bitboard knight, Bitboard side)
{
    // mask out A going to A - 1
    Bitboard p1 = (knight & CLEAR_FILE[FILE_A]) << 15;
    Bitboard p2 = (knight & CLEAR_FILE[FILE_A]) >> 17;

    // mask out H going to H + 1
    Bitboard p3 = (knight & CLEAR_FILE[FILE_H]) << 17;
    Bitboard p4 = (knight & CLEAR_FILE[FILE_H]) >> 15;

    // mask out B going to B - 2 and A going to A - 2
    Bitboard p5 = (knight & CLEAR_FILE[FILE_A] & CLEAR_FILE[FILE_B]) << 6;
    Bitboard p6 = (knight & CLEAR_FILE[FILE_A] & CLEAR_FILE[FILE_B]) >> 10;

    // mask out G going to G + 2 and H going to H + 2
    Bitboard p7 = (knight & CLEAR_FILE[FILE_G] & CLEAR_FILE[FILE_H]) << 10;
    Bitboard p8 = (knight & CLEAR_FILE[FILE_G] & CLEAR_FILE[FILE_H]) >> 6;

    Bitboard moves = p1 | p2 | p3 | p4 | p5 | p6 | p7 | p8;

    // remove moves that land on your own sides pieces
    return moves & ~side;
}

Bitboard Board::compute_straight_ray_moves(Bitboard piece, Bitboard side) {
    return (uint64_t) 0u;
}

Bitboard Board::compute_diagonal_ray_moves(Bitboard piece, Bitboard side) {
    return (uint64_t) 0u;
}

