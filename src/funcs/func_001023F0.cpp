struct Vec_001023F0 {
    float x, y, z, w;
};

struct Box_001023F0 {
    Vec_001023F0 min;
    Vec_001023F0 max;
};

extern "C" int func_001023F0(const Box_001023F0* b, const Vec_001023F0* p, int* flags)
{
    *flags = 0;
    int n = 0;
    if (p->x >= b->min.x && p->x <= b->max.x) {
        n++;
        *flags = 1;
    }
    if (p->y >= b->min.y && p->y <= b->max.y) {
        n++;
        *flags |= 2;
    }
    if (p->z >= b->min.z && p->z <= b->max.z) {
        n++;
        *flags |= 4;
    }
    return n;
}
