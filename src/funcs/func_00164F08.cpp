extern float* D_00394274;

struct Vec_00164F08 {
    float x, y, z, w;
};

static inline void Put_00164F08(float x, float y, float z, float w)
{
    D_00394274[0] = x;
    D_00394274[1] = y;
    D_00394274[2] = z;
    D_00394274[3] = w;
    D_00394274 += 4;
}

void func_00164F08(const Vec_00164F08* v)
{
    Put_00164F08(v->x, v->y, v->z, v->w);
}
