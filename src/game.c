#include "game.h"

size_t rows = WINDOW_HEIGHT / CELL_SIZE;
size_t cols = WINDOW_WIDTH  / CELL_SIZE;
Color colors[] = {BLACK, YELLOW, BROWN, RED, BLUE, LIGHTGRAY, ORANGE, GRAY };

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

            case ASH:
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
    if (v->y + 1 < rows && GRID_AT(write_grid, (int)v->x, (int)v->y + 1) == EMPTY) {
        swap_cells(write_grid, v, &(Vector2){.x = v->x, .y = v->y + 1});

    } 
    else if (v->y + 1 < rows && v->x + 1 < cols 
        && GRID_AT(write_grid, (int)v->x + 1, (int)v->y + 1) == EMPTY
    ) {
        swap_cells(write_grid, v, &(Vector2){.x = v->x + 1, .y = v->y + 1});
    } 
    else if (v->y + 1 < rows && v->x - 1 >= 0 
        && GRID_AT(write_grid, (int)v->x - 1, (int)v->y + 1) == EMPTY 
    ) {
        swap_cells(write_grid, v, &(Vector2){.x = v->x - 1, .y = v->y + 1});
    }
}

inline void swap_grids(PART_TYPE **a, PART_TYPE **b) {
    PART_TYPE *tmp = *a;
    *a = *b;
    *b = tmp;
}

inline void set_cell_type(PART_TYPE *rg, PART_TYPE *wg, PART_TYPE type, int x, int y) {
    if (GRID_AT(rg, x, y) != EMPTY) return;
    if (GRID_AT(wg, x, y) != EMPTY) return;
    GRID_AT(rg, x, y)= type;
    GRID_AT(wg, x, y)= type;
}


inline Vector2 screen_to_cell(const Vector2 *pos) {
    Vector2 cell = {.x = pos->x / CELL_SIZE, .y = pos->y / CELL_SIZE};
    return cell;
}


void draw_circle(int cx, int cy, int radius, Color color) {
    int x = 0;
    int y = radius;
    int d = 1 - radius;

    while (x <= y) {
        draw_hline(cx - x, cx + x, cy + y, color); // Top/bottom wide spans
        draw_hline(cx - x, cx + x, cy - y, color);
        draw_hline(cx - y, cx + y, cy + x, color); // Middle spans
        draw_hline(cx - y, cx + y, cy - x, color);
        if (d < 0) {
            d += 2 * x + 3;
        } else {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;

    }

}

void circle_targets(DA_Targets *targets, int cx, int cy, int radius) {
    int x = 0;
    int y = radius;
    int d = 1 - radius;

    while (x <= y) {
        hline_targets(targets, cx - x, cx + x, cy + y); // Top/bottom wide spans
        hline_targets(targets, cx - x, cx + x, cy - y);
        hline_targets(targets, cx - y, cx + y, cy + x); // Middle spans
        hline_targets(targets, cx - y, cx + y, cy - x);
        if (d < 0) {
            d += 2 * x + 3;
        } else {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;

    }
}


void draw_hline(int x1, int x2, int y, Color color) {
    for (int x =  x1; x <= x2; x++) {
        DrawRectangle(x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE, color);
    }
}

void hline_targets(DA_Targets *targets, int x1, int x2, int y) {
    for (int x =  x1; x <= x2; x++) {
        Vector2 temp = {.x = x, .y = y};
        da_append(targets, temp);
    }
}

void draw_targets(DA_Targets *targets, Color c) {
    for (int i = 0; i < (int)targets->count; i++) {
        Vector2 target = targets->items[i];
        DrawRectangle(target.x * CELL_SIZE,
                      target.y * CELL_SIZE,
                      CELL_SIZE,
                      CELL_SIZE,
                      c 
                  );
    }
}


void place_targets(PART_TYPE* rg, PART_TYPE *wg, DA_Targets *targets, PART_TYPE t) {
    Vector2 *target = {0};
    for (int i = 0; i < (int)targets->count; i++) {
        target = &targets->items[i];
        if (target->x <= 0 || target->x >= cols || target->y <= 0 || target->y >= rows) continue;
        set_cell_type(rg, wg, t, target->x, target->y);
    }
}


void wood_physics(PART_TYPE *write_grid, Vector2* v) {
    (void)write_grid;
    (void)v;
}


void clear_grid(PART_TYPE *rg, PART_TYPE *wg) {
    memset(rg, EMPTY, rows * cols * sizeof(PART_TYPE));
    memset(wg, EMPTY, rows * cols * sizeof(PART_TYPE));
}
