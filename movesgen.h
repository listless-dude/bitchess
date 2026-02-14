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

void rook_moves(Board *board, MoveList *list)
{
    U64 rooks = board->bitboards[wR];

    while (rooks)
    {
        int from = __builtin_ctzll(rooks);
        pop_bit(&rooks, from);

        int rank = from / 8;
        int file = from % 8;

        // Move up
        for (int r = rank + 1; r < 8; r++)
        {
            int to = r * 8 + file;
            if (board->occupancies[WHITE] & (1ULL << to))
            {
                break;
            }
            list->moves[list->count++] = (Move){from, to, wR};

            if (board->occupancies[BLACK] & (1ULL << to))
            {
                break;
            }
        }
        
        // Move down
        for (int r = rank - 1; r >= 0; r--)
        {
            int to = r * 8 + file;

            if (board->occupancies[WHITE] & (1ULL << to))
                break;

            list->moves[list->count++] = (Move){from, to, wR};

            if (board->occupancies[BLACK] & (1ULL << to))
                break;
        }

        // Move right
        for (int f = file + 1; f < 8; f++)
        {
            int to = rank * 8 + f;

            if (board->occupancies[WHITE] & (1ULL << to))
                break;

            list->moves[list->count++] = (Move){from, to, wR};

            if (board->occupancies[BLACK] & (1ULL << to))
                break;
        }

        // Move left
        for (int f = file - 1; f >= 0; f--)
        {
            int to = rank * 8 + f;

            if (board->occupancies[WHITE] & (1ULL << to))
                break;

            list->moves[list->count++] = (Move){from, to, wR};

            if (board->occupancies[BLACK] & (1ULL << to))
                break;
        }


    }
}

void bishop_moves(Board *board, MoveList *list)
{
    U64 bishops = board->bitboards[wB];

    while (bishops)
    {
        int from = __builtin_ctzll(bishops);
        pop_bit(&bishops, from);

        int rank = from / 8;
        int file = from % 8;

        // Move up-right
        for (int r = rank + 1, f = file + 1; r < 8 && f < 8; r++, f++)
        {
            int to = r * 8 + f;
            if (board->occupancies[WHITE] & (1ULL << to))
            {
                break;
            }
            list->moves[list->count++] = (Move){from, to, wB};

            if (board->occupancies[BLACK] & (1ULL << to))
            {
                break;
            }
        }
        
        // Move up-left
        for (int r = rank + 1, f = file - 1; r < 8 && f >= 0; r++, f--)
        {
            int to = r * 8 + f;

            if (board->occupancies[WHITE] & (1ULL << to))
                break;

            list->moves[list->count++] = (Move){from, to, wB};

            if (board->occupancies[BLACK] & (1ULL << to))
                break;
        }

        // Move down-right
        for (int r = rank - 1, f = file + 1; r >= 0 && f < 8; r--, f++)
        {
            int to = rank * 8 + f;

            if (board->occupancies[WHITE] & (1ULL << to))
                break;

            list->moves[list->count++] = (Move){from, to, wB};

            if (board->occupancies[BLACK] & (1ULL << to))
                break;
        }

        // Move down-left
        for (int r = rank - 1, f = file - 1; r >= 0 && f >= 0; r--, f--)
        {
            int to = rank * 8 + f;

            if (board->occupancies[WHITE] & (1ULL << to))
                break;

            list->moves[list->count++] = (Move){from, to, wB};

            if (board->occupancies[BLACK] & (1ULL << to))
                break;
        }


    }
}