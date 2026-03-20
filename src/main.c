#include "../include/raylib.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "game.h"

void DrawCell(Vector2 *pos, Color color) {
    DrawRectangle(
        pos->x * CELL_SIZE,
        pos->y * CELL_SIZE,
        CELL_SIZE,
        CELL_SIZE,
        color
    );
    return;
}

void ShowInfo() {
    printf("[INFO ABOUT PROGRAM]\n");
    printf("Width: %d\n", WINDOW_WIDTH);
    printf("Height: %d\n", WINDOW_HEIGHT);
    printf("Cell Dim: %dx%d\n", CELL_SIZE, CELL_SIZE);
    printf("Number of Rows: %zu\n", rows);
    printf("Number of Cols: %zu\n", cols);
    return;
}


int main(void) {
    SetTraceLogLevel(LOG_ERROR);
    ShowInfo();

    PART_TYPE *read_grid  = calloc(rows * cols, sizeof(PART_TYPE));
    PART_TYPE *write_grid = calloc(rows * cols, sizeof(PART_TYPE));

    size_t middleC = cols / 2;
    size_t middleR = rows / 2;
    GRID_AT(read_grid, middleC, middleR) = 1;

    InitWindow(800, 800, "Raylib Basic Window");
    SetTargetFPS(10);

    //SwapGridCells(grid, &pos, &newPos);
    
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int y = rows - 1; y >= 0; y--) {
            for (int x = cols - 1; x >= 0; x--) {
                switch (GRID_AT(read_grid, x, y)) {
                    case SAND:
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
                }
                DrawCell(&read_grid, BLACK);
            }
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
