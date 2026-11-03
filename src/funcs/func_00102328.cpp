#include "game/vector.h"

struct VecPair {
    Vector a;
    Vector b;
    VecPair(const Vector& p);
};

VecPair::VecPair(const Vector& p) : a(p), b(p) {}
