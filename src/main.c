#include "../include/raylib.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH  800

#define GRID_AT(grid, x, y) grid[((y) * WINDOW_WIDTH + (x))]


int main(void) {
    SetTraceLogLevel(LOG_ERROR);

    bool *grid = malloc(WINDOW_WIDTH * WINDOW_HEIGHT * sizeof(bool));
    grid[10] = 1;
    printf("%d\n", GRID_AT(grid, 10, 0)); 

    InitWindow(800, 800, "Raylib Basic Window");
    SetTargetFPS(60);
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
