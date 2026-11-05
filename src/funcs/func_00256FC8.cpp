extern "C" float fabsf(float);

struct Vec_00256FC8 {
    float x, y, z;
};

static inline float MaxAbsZYX(const Vec_00256FC8& v)
{
    float m = fabsf(v.z);
    if (m < fabsf(v.y)) m = fabsf(v.y);
    if (m < fabsf(v.x)) m = fabsf(v.x);
    return m;
}

struct Box_00256FC8 {
    char pad[0x40];
    Vec_00256FC8 m40;
    char pad4C[0x24];
    Vec_00256FC8 m70;
    char pad7C[0x18];
    int m94;
    float m98;
};

struct Obj_00256FC8 {
    float Fn(Box_00256FC8* b);
};

float Obj_00256FC8::Fn(Box_00256FC8* b)
{
    if (b->m94) return b->m98;
    float a = fabsf(b->m40.y);
    if (a < fabsf(b->m40.x)) a = fabsf(b->m40.x);
    if (a < fabsf(b->m40.z)) a = fabsf(b->m40.z);
    float c = MaxAbsZYX(b->m70);
    float r = c + a;
    b->m94 = 1;
    b->m98 = r * r;
    return b->m98;
}
