#ifndef BOARD_H
#define BOARD_H

#include <stdint.h>

#define FILE_A 0x0101010101010101ULL
#define FILE_H 0x8080808080808080ULL

typedef uint64_t U64;

enum {
    WHITE, BLACK
};

/*
w -> white, b -> black
P -> Pawn, N -> Knight, B -> Bishop 
R -> Rook, Q -> Queen, K -> King
*/
enum {
    wP, wN, wB, wR, wQ, wK,
    bP, bN, bB, bR, bQ, bK
};

/*
bitboards = 6 white + 6 black
occupancies = white, black, both
*/
typedef struct
{
    U64 bitboards[12];
    U64 occupancies[3];
    int side_to_mode;
} Board;

#endif