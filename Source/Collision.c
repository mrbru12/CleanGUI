#include "Collision.h"

int clean_point_on_rect(clean_point point, clean_rect rect)
{
    return (point.x >= rect.x && point.x <= rect.x + rect.w) && (point.y >= rect.y && point.y <= rect.y + rect.h);
}