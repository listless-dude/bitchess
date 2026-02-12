#include "board.h"
#include "move.h"
#include "bitboard.h"

void pawn_moves(Board *board, MoveList *list)
{
    U64 pawns = board->bitboards[wP];

    while (pawns)
    {
        int from = __builtin_ctzll(pawns);
        pop_bit(&pawns, from);

        int to = from + 8;

        if (!(board->occupancies[2] & (1ULL << to)))
        {
            list->moves[list->count++] = (Move){from, to, wP};

            // Push 2 ranks
            if (from >= 8 && from <= 15)
            {
                int to2 = from + 16;
                if (!(board->occupancies[2] & (1ULL << to2)))
                {
                    list->moves[list->count++] = (Move){from, to2, wP};
                }
            }
        }

        // Capture left
        if (!(FILE_A & (1ULL << from)))
        {
            int capture = from + 7;
            if (board->occupancies[BLACK] & (1ULL << capture))
            {
                list->moves[list->count++] = (Move){from, capture, wP};
            }
        }

        // Capture right
        if (!(FILE_H & (1ULL << from)))
        {
            int capture = from + 9;
            if (board->occupancies[BLACK] & (1ULL << capture))
            {
                list->moves[list->count++] = (Move){from, capture, wP};
            }
        }
    }
}