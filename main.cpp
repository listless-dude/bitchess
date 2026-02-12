#include <stdio.h>
#include "board.h"
#include "move.h"
#include "bitboard.h"
#include "utils.h"

void init_board(Board *board);
void print_board(Board *board);

int main()
{
    Board board;
    init_board(&board);
    
    print_board(&board);

    return 0;
}