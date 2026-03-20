#ifndef GAME_H

#include "stddef.h"
#include "../include/raylib.h"

#define GAME_H
typedef enum {
    SAND,
    WOOD,
    FIRE,
    WATER,
    METAL,
    LIGHTNING
} PART_TYPE;

extern size_t rows;
extern size_t cols;

#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH  800

#define CELL_SIZE 5


#define GRID_AT(grid, x, y) grid[(y) * cols + (x)]

void SwapGridCells(PART_TYPE *grid);

#endif //GAME_H
