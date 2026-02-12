#ifndef MOVE_H
#define MOVE_H

#define MAX_MOVES 256

typedef struct
{
    int from;
    int to;
    int piece;
} Move;

typedef struct 
{
    Move moves[MAX_MOVES];
    int count;
} MoveList;

#endif

