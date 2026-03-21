#include "../include/raylib.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"


int main(void) {
    SetTraceLogLevel(LOG_ERROR);
    show_info();

    PART_TYPE *read_grid  = calloc(rows * cols, sizeof(PART_TYPE));
    PART_TYPE *write_grid = calloc(rows * cols, sizeof(PART_TYPE));

    set_cell_type(read_grid, write_grid, SAND, cols / 2, rows / 2);
    set_cell_type(read_grid, write_grid, SAND, cols / 2, rows / 2 - 1);
    printf("Type at middle : %d", GRID_AT(read_grid, cols / 2, rows / 2));

    InitWindow(800, 800, "Raylib Basic Window");
    SetTargetFPS(10);

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        memcpy(write_grid, read_grid, rows * cols * sizeof(PART_TYPE));

        for (int y = rows - 1; y >= 0; y--) {
            for (int x = cols - 1; x >= 0; x--) {
                Vector2 v = {.x = x, .y = y};
                switch (GRID_AT(read_grid, x, y)) {
                    case SAND:
                        sand_physics(write_grid, &v);
                    break;

                    case WOOD:
                    break;

                    case FIRE:
                    break;

                    case WATER:
                    break;

                    case METAL:
                    break;

                    case LIGHTNING:
                    break;

                    default:
                    break;
                }
            }
        }
        draw_grid(write_grid);
        swap_grids(&read_grid, &write_grid);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
