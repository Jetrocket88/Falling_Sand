#include "mouse.h"

//#define HOVER_COLOR (Color){ .}

void mouse_place(PART_TYPE *rg, PART_TYPE *wg, Mouse* m) {

    DA_Targets targets = {0};
    Vector2 mouse = GetMousePosition();
    Vector2 cell = screen_to_cell(&mouse);
    circle_targets(&targets, cell.x, cell.y, m->radius);

    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
        place_targets(rg, wg, &targets, m->type);
    } else {
        Color draw_color = colors[m->type];
        if (draw_color != (Color){.r = 1.0f, .b = 1.0f, .g = 1.0f, .a = 1.0f})
            draw_color.a *= 0.3;
        draw_targets(&targets, draw_color);
    }
    targets.count = 0;
}

void handle_inputs(PART_TYPE *rg, PART_TYPE *wg, Mouse *m) {
    static double pressed = 0;
    const double delay = 0.5f;
    if (IsKeyDown(KEY_U) && GetTime() - pressed > delay) {
        m->radius += 1;
        pressed = GetTime();
    } else if (IsKeyDown(KEY_D) && GetTime() - pressed > delay) {
        m->radius -= 1;
        pressed = GetTime();
    }

    if (IsKeyDown(KEY_LEFT) && GetTime() - pressed > delay) {
        pressed = GetTime();
        m->type++;
        if (m->type == EMPTY) {
            m->type = SAND;
        }
    }

    if (IsKeyDown(KEY_C)) {
        clear_grid(rg, wg);
    }
}
