struct Vec_0014DB78 {
    float x, y, z, w;
};

extern "C" void func_00171030(void* o, Vec_0014DB78* d);

struct Obj_0014DB78 {
    int m0;
    int m4;
    char pad8[0x20 - 0x8];
    void* m20;
    char pad24[0x60 - 0x24];
    Vec_0014DB78 m60;
    void Fn(const Vec_0014DB78& v);
};

extern "C" void func_0014E048(Obj_0014DB78* self);

void Obj_0014DB78::Fn(const Vec_0014DB78& v)
{
    Vec_0014DB78 d;
    d.x = v.x - m60.x;
    d.y = v.y - m60.y;
    d.z = v.z - m60.z;
    d.w = v.w - m60.w;
    m60.x = v.x;
    m60.y = v.y;
    m60.z = v.z;
    if (m4 != 2)
        func_0014E048(this);
    else
        func_00171030(m20, &d);
}
