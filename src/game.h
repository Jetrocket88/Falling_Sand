#ifndef GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "stddef.h"
#include "../include/raylib.h"
#include "../nob.h"

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

typedef struct {
    Vector2 *items;
    size_t count;
    size_t capacity;
} DA_Targets;

extern size_t rows;
extern size_t cols;

#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH  800

#define CELL_SIZE 5

#define GRID_AT(grid, x, y) grid[(y) * (cols) + (x)]

void swap_cells(PART_TYPE *grid, Vector2 *p1, Vector2 *p2);
void swap_grids(PART_TYPE **a, PART_TYPE **b);
void set_cell_type(PART_TYPE *rg, PART_TYPE *wg, PART_TYPE type, int x, int y);
void show_info();

void draw_grid(PART_TYPE *grid);
void draw_circle(int cx, int cy, int radius, Color color);
void draw_hline(int x1, int x2, int y, Color color);

void sand_physics(PART_TYPE *write_grid, Vector2* v);

void circle_targets(DA_Targets *targets, int cx, int cy, int radius);
void hline_targets(DA_Targets *targets, int x1, int x2, int y);
void draw_targets(DA_Targets *targets, Color c);
void place_targets(PART_TYPE* rg, PART_TYPE *wg, DA_Targets *targets, PART_TYPE t);


Vector2 screen_to_cell(const Vector2 *pos);

#endif //GAME_H
