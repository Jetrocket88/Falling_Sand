#ifndef GAME_H

#include <stdio.h>

#include "stddef.h"
#include "../include/raylib.h"

#define GAME_H
typedef enum {
    EMPTY,
    SAND,
    WOOD,
    FIRE,
    WATER,
    METAL,
    LIGHTNING,
    ASH
} PART_TYPE;

extern size_t rows;
extern size_t cols;

#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH  800

#define CELL_SIZE 5

#define GRID_AT(grid, x, y) grid[(y) * (cols) + (x)]

void swap_cells(PART_TYPE *grid, Vector2 *p1, Vector2 *p2);
void swap_grids(PART_TYPE **a, PART_TYPE **b);
void draw_grid(PART_TYPE *grid);
void set_cell_type(PART_TYPE *rg, PART_TYPE *wg, PART_TYPE type, Vector2* v);
void show_info();

void sand_physics(PART_TYPE *read_grid, PART_TYPE *write_grid, Vector2* v);

#endif //GAME_H
