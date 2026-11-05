struct Vec_002682E0 {
    float x, y, z, w;
};

extern "C" void func_002682E0(Vec_002682E0* a, Vec_002682E0* b, Vec_002682E0* mn, Vec_002682E0* mx)
{
    float x0, x1, y0, y1, z0, z1;
    if (a->x < b->x) { x0 = a->x; x1 = b->x; } else { x0 = b->x; x1 = a->x; }
    if (a->y < b->y) { y0 = a->y; y1 = b->y; } else { y0 = b->y; y1 = a->y; }
    if (a->z < b->z) { z0 = a->z; z1 = b->z; } else { z0 = b->z; z1 = a->z; }
    mn->x = x0;
    mn->y = y0;
    mn->z = z0;
    mn->w = 1.0f;
    mx->x = x1;
    mx->y = y1;
    mx->z = z1;
    mx->w = 1.0f;
}
