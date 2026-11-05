struct Vec_00101C70 {
    float x, y, z, w;
};

extern "C" float sqrtf(float);
extern "C" float func_00340F60(float a);

extern "C" int func_00101C70(const Vec_00101C70* a, const Vec_00101C70* b, float angle)
{
    float d = a->x * b->x + a->y * b->y + a->z * b->z;
    float len = sqrtf(a->x * a->x + a->y * a->y + a->z * a->z);
    if (len < 0.5f) {
        return 0;
    }
    d /= len;
    len = sqrtf(b->x * b->x + b->y * b->y + b->z * b->z);
    if (len < 0.5f) {
        return 0;
    }
    d /= len;
    float c = func_00340F60(angle * 0.01745329425f);
    if (d >= 0.0f) return d < c; if (c >= 0.0f) return 1; return d < c;
}
