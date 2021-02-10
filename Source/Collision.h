#ifndef CLEAN_COLLISION_H
#define CLEAN_COLLISION_H

typedef struct clean_point
{
    float x, y;
} clean_point;

typedef struct clean_rect
{
    float x, y, w, h;
} clean_rect;

int clean_point_on_rect(clean_point point, clean_rect rect);

#endif