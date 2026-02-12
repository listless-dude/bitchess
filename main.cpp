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
    
    MoveList list = {0};

    pawn_moves(&board, &list);
    rook_moves(&board, &list);
    print_board(&board);

    for (int i = 0; i < list.count; i++)
    {
        print_move(list.moves[i]);
    }
    return 0;
}