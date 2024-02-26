#include "AABB.h"

bool aabbOverlap(AABB a, AABB b)
{
    return
        a.max.x >= b.min.x && b.max.x >= a.min.x &&
        a.max.y >= b.min.y && b.max.y >= a.min.y;
}

AABB AABB::fromPositionSize(Vector position, Vector size)
{
    return AABB(
        position - size * 0.5f,
        position + size * 0.5f
    );
}
