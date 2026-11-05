struct Vec_00123558 {
    float x, y, z;
};

extern "C" int func_00123558(const Vec_00123558* p, const Vec_00123558* max, const Vec_00123558* min)
{
    if (p->x > max->x) return 0;
    if (p->y > max->y) return 0;
    if (p->z > max->z) return 0;
    if (p->x < min->x) return 0;
    if (p->y < min->y) return 0;
    if (p->z < min->z) return 0;
    return 1;
}
