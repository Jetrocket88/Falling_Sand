#include "../include/raylib.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"
#include "mouse.h"


int main(void) {
    SetTraceLogLevel(LOG_ERROR);
    show_info();

    PART_TYPE *read_grid  = calloc(rows * cols, sizeof(PART_TYPE));
    PART_TYPE *write_grid = calloc(rows * cols, sizeof(PART_TYPE));

    InitWindow(800, 800, "Raylib Basic Window");
    SetTargetFPS(100);

    Mouse m = {.type = WOOD, .radius = 4};

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        memcpy(write_grid, read_grid, rows * cols * sizeof(PART_TYPE));

        //mouse_place(read_grid, write_grid, &m);

        for (int y = rows - 1; y >= 0; y--) {
            for (int x = cols - 1; x >= 0; x--) {
                Vector2 v = {.x = x, .y = y};
                switch (GRID_AT(read_grid, x, y)) {
                    case SAND:
                        sand_physics(write_grid, &v);
                    break;

                    case WOOD:
                        wood_physics(write_grid, &v);
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

        handle_inputs(read_grid, write_grid, &m);
        draw_grid(write_grid);
        mouse_place(read_grid, write_grid, &m);
        swap_grids(&read_grid, &write_grid);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
