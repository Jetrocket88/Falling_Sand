#include "game.h"

size_t rows = WINDOW_HEIGHT / CELL_SIZE;
size_t cols = WINDOW_WIDTH  / CELL_SIZE;

/*void SwapGridCells(PART_TYPE *grid, Vector2 *p1, Vector2 *p2) {
    if (p1->x >= cols || p2->x >= cols) return;
    if (p1->y >= rows || p2->y >= rows) return;

    bool temp = GRID_AT(grid, p1->x, p1->y);
    GRID_AT(grid, p1->x, p1->y) = GRID_AT(grid, p2->x, p2->y);
    GRID_AT(grid, p2->x, p2->y) = temp;
    return;
}*/
