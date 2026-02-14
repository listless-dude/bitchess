#include <stdio.h>
#include "board.h"
#include "move.h"
#include "bitboard.h"
#include "utils.h"
#include "movesgen.h"

void init_board(Board *board);
void print_board(Board *board);

int main()
{
    Board board;
    init_board(&board);

    // remove pawn at a2 to free rook
    pop_bit(&board.bitboards[wP], 8);

    // rebuild occupancies
    board.occupancies[WHITE] = 0;
    board.occupancies[BLACK] = 0;

    for (int i = wP; i <= wK; i++)
        board.occupancies[WHITE] |= board.bitboards[i];

    for (int i = bP; i <= bK; i++)
        board.occupancies[BLACK] |= board.bitboards[i];

    board.occupancies[2] =
        board.occupancies[WHITE] |
        board.occupancies[BLACK];

    MoveList list = {0};

    pawn_moves(&board, &list);
    printf("After pawns: %d\n", list.count);

    rook_moves(&board, &list);
    printf("After rooks: %d\n", list.count);

    print_board(&board);

    for (int i = 0; i < list.count; i++)
    {
        print_move(list.moves[i]);
    }
    return 0;
}