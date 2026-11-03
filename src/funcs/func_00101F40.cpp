#include "game/vector.h"

struct Segment {
    Vector a;
    Vector b;
    Segment(const Vector& p, const Vector& q);
};

Segment::Segment(const Vector& p, const Vector& q) : a(p), b(q) {}
