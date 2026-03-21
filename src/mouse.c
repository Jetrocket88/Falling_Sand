#include "mouse.h"

//#define HOVER_COLOR (Color){ .}

void mouse_place(PART_TYPE *rg, PART_TYPE *wg, Mouse* m) {
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        Vector2 mouse = GetMousePosition();
        Vector2 cell = screen_to_cell(&mouse);
        draw_circle(rg, (int)cell.x, (int)cell.y, 10, LIGHTGRAY);
        if (cell.x <= 0 || cell.x >= cols || cell.y <= 0 || cell.y >= rows) return;
        set_cell_type(rg, wg, m->type, cell.x, cell.y);
    }
}
