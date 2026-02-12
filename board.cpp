#include "board.h"
#include "bitboard.h"
#include <string.h>
#include <stdio.h>

void init_board(Board *board)
{
    memset(board, 0, sizeof(Board));

    // White pieces
    // 64-bit Hexadecimal Representations
    board->bitboards[wP] = 0x000000000000FF00ULL;
    board->bitboards[wR] = 0x0000000000000081ULL;
    board->bitboards[wN] = 0x0000000000000042ULL;
    board->bitboards[wB] = 0x0000000000000024ULL;
    board->bitboards[wQ] = 0x0000000000000008ULL;
    board->bitboards[wK] = 0x0000000000000010ULL;

    // Black pieces
    board->bitboards[bP] = 0x00FF000000000000ULL;
    board->bitboards[bR] = 0x8100000000000000ULL;
    board->bitboards[bN] = 0x4200000000000000ULL;
    board->bitboards[bB] = 0x2400000000000000ULL;
    board->bitboards[bQ] = 0x0800000000000000ULL;
    board->bitboards[bK] = 0x1000000000000000ULL;

    board->side_to_mode = WHITE;

    // Occupancies
    for (int i = wP; i <= wK; i++)
    {
        board->occupancies[WHITE] |= board->bitboards[i];
    }
    for (int i = bP; i <= bK; i++)
    {
        board->occupancies[BLACK] |= board->bitboards[i];
    }

    board->occupancies[2] = board->occupancies[WHITE] | board->occupancies[BLACK];
}

void print_board(Board *board)
{
    printf("\n");

    for (int rank = 7; rank >= 0; rank--)
    {
        printf(" %d ", rank + 1);

        for (int file = 0; file < 8; file++)
        {
            int square = rank * 8 + file;

            char piece = '.';

            for (int bb = 0; bb < 12; bb++)
            {
                if (get_bit(board->bitboards[bb], square))
                {
                    char pieces[] = "PNBRQKpnbrqk";
                    piece = pieces[bb];
                }
            }

            printf("%c ", piece);
        }

        printf("\n");
    }

    printf("   a b c d e f g h \n");
}