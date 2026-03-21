#include "game.h"

size_t rows = WINDOW_HEIGHT / CELL_SIZE;
size_t cols = WINDOW_WIDTH  / CELL_SIZE;

void swap_cells(PART_TYPE *grid, Vector2 *p1, Vector2 *p2) {
    PART_TYPE temp = GRID_AT(grid, (int)p1->x, (int)p1->y);
    GRID_AT(grid, (int)p1->x, (int)p1->y) = GRID_AT(grid, (int)p2->x, (int)p2->y);
    GRID_AT(grid, (int)p2->x, (int)p2->y) = temp;
}

void draw_grid(PART_TYPE *grid) {
    Color color;
    int x, y;
    for (int i = 0; i < (int)(rows * cols); i++) {
        x = i % cols;
        y = i / cols;
        switch (grid[i]) {
            case SAND:
                color = YELLOW;
                //printf("Position being drawn: (%d, %d)\n", x * CELL_SIZE, y * CELL_SIZE);
                break;

            case WOOD:
                color = BROWN;
                break;

            case FIRE:
                color = RED;
                break;

            case WATER:
                color = BLUE;
                break;

            case METAL:
                color = GRAY;
                break;

            case LIGHTNING:
                color = WHITE;
                break;

            case EMPTY:
                color = BLACK;
                break;
            default:
                printf("Error\n");
                break;
        }
        DrawRectangle( 
            x * CELL_SIZE,
            y * CELL_SIZE,
            CELL_SIZE,
            CELL_SIZE, 
            color
        );
    }
}

void show_info() {
    printf("[INFO ABOUT PROGRAM]\n");
    printf("Width: %d\n", WINDOW_WIDTH);
    printf("Height: %d\n", WINDOW_HEIGHT);
    printf("Cell Dim: %dx%d\n", CELL_SIZE, CELL_SIZE);
    printf("Number of Rows: %zu\n", rows);
    printf("Number of Cols: %zu\n", cols);
}

void sand_physics(PART_TYPE *write_grid, Vector2* v) {
    //check below first
    if (GRID_AT(write_grid, (int)v->x, (int)v->y + 1) == EMPTY && v->y + 1 < rows) {
        swap_cells(write_grid, v, &(Vector2){.x = v->x, .y = v->y + 1});

    } else if (GRID_AT(write_grid, (int)v->x - 1, (int)v->y + 1) == EMPTY 
        && v->y + 1 < rows && v->x - 1 < 0 
    ) {
        swap_cells(write_grid, v, &(Vector2){.x = v->x - 1, .y = v->y + 1});

    } else if (GRID_AT(write_grid, (int)v->x + 1, (int)v->y + 1) == EMPTY
        && v->y + 1 < rows && v->x + 1 < cols 
    ) {
        swap_cells(write_grid, v, &(Vector2){.x = v->x + 1, .y = v->y + 1});
    } 
}

inline void swap_grids(PART_TYPE **a, PART_TYPE **b) {
    PART_TYPE *tmp = *a;
    *a = *b;
    *b = tmp;
}

inline void set_cell_type(PART_TYPE *rg, PART_TYPE *wg, PART_TYPE type, int x, int y) {
    GRID_AT(rg, x, y)= type;
    GRID_AT(wg, x, y)= type;
}
