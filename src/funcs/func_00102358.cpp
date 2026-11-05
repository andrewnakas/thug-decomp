struct Vec_00102358 {
    float x, y, z, w;
};

struct Box_00102358 {
    Vec_00102358 min;
    Vec_00102358 max;
};

extern "C" void func_00102358(Box_00102358* b, const Vec_00102358* p)
{
    if (p->x < b->min.x) b->min.x = p->x;
    if (p->y < b->min.y) b->min.y = p->y;
    if (p->z < b->min.z) b->min.z = p->z;
    if (p->x > b->max.x) b->max.x = p->x;
    if (p->y > b->max.y) b->max.y = p->y;
    if (p->z > b->max.z) b->max.z = p->z;
}
