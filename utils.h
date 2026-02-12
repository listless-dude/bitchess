#include <stdio.h>
#include "move.h"

void print_move(Move move)
{
    char from_file = 'a' + (move.from % 8);
    char from_rank = '1' + (move.from / 8);

    char to_file = 'a' + (move.to % 8);
    char to_rank = '1' + (move.to / 8);

    printf("%c%c -> %c%c\n",
            from_file, from_rank,
            to_file, to_rank);
}