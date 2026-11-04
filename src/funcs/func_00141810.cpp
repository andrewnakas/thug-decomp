#include "game/vector.h"

Vector Min_00141810(const Vector& a, const Vector& b)
{
    Vector r = a;
    if (b.x < a.x) {
        r.x = b.x;
    }
    if (b.y < a.y) {
        r.y = b.y;
    }
    if (b.z < a.z) {
        r.z = b.z;
    }
    if (b.w < a.w) {
        r.w = b.w;
    }
    return r;
}
