#include "mouse.h"

//#define HOVER_COLOR (Color){ .}

void mouse_place(PART_TYPE *rg, PART_TYPE *wg, Mouse* m) {
    static DA_Targets targets = {0};
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        Vector2 mouse = GetMousePosition();
        Vector2 cell = screen_to_cell(&mouse);
        circle_targets(&targets, cell.x, cell.y, 10);
        draw_targets(&targets, RED);
        place_targets(rg, wg, &targets, SAND);
        targets.count = 0;

        if (cell.x <= 0 || cell.x >= cols || cell.y <= 0 || cell.y >= rows) return;
        set_cell_type(rg, wg, m->type, cell.x, cell.y);
    }
}
