
#include "mouse.h"

void mouse_place(PART_TYPE *rg, PART_TYPE *wg) {
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        Vector2 mouse = GetMousePosition();
        Vector2 cell = screen_to_cell(&mouse);
        set_cell_type(rg, wg, SAND, cell.x, cell.y);
    }
}
