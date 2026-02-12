#ifndef BITBOARD_H
#define BITBOARD_H

#include <stdint.h>

typedef uint64_t U64;

static inline void set_bit(U64 *bb, int square) {
    *bb |= (1ULL << square);
}

static inline void pop_bit(U64 *bb, int square) {
    *bb &= ~(1ULL << square);
}

static inline int get_bit(U64 bb, int square) {
    return (bb >> square) & 1ULL;
}
#endif