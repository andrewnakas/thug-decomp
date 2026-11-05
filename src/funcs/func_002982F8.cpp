struct Vec_002982F8 {
    float x, y, z, w;
};

extern "C" float sqrtf(float);

extern "C" bool func_002982F8(Vec_002982F8* a, Vec_002982F8* b)
{
    Vec_002982F8 d;
    d.x = a->x - b->x;
    d.y = a->y - b->y;
    d.z = a->z - b->z;
    d.w = a->w - b->w;
    return sqrtf(d.x * d.x + d.y * d.y + d.z * d.z) > 4500.0f;
}
