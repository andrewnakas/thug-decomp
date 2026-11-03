#include "game/vector.h"

Vector Max_00141890(const Vector& a, const Vector& b)
{
    Vector r = a;
    if (a.x < b.x) {
        r.x = b.x;
    }
    if (b.y > a.y) {
        r.y = b.y;
    }
    if (b.z > a.z) {
        r.z = b.z;
    }
    if (b.w > a.w) {
        r.w = b.w;
    }
    return r;
}
