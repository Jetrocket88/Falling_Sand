#ifndef MOUSE_H
#define MOUSE_H

#include "game.h"

typedef struct {
    PART_TYPE type;
    int radius;
} Mouse;

void mouse_place(PART_TYPE *rg, PART_TYPE *wg, Mouse* m);
void handle_inputs(PART_TYPE *rg, PART_TYPE *wg, Mouse *m);

#endif //MOUSE_H
