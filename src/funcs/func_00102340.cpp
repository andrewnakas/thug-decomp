#include "game/vector.h"

struct Segment2 {
    Vector a;
    Vector b;
    Segment2(const Vector& p, const Vector& q);
};

Segment2::Segment2(const Vector& p, const Vector& q) : a(p), b(q) {}
