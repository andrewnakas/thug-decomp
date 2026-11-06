struct Vec_0014DB18 {
    float x, y, z, w;
};

extern "C" void func_00170638(void* o, float x, float y, float z, float w);
extern "C" void func_001728C0(void* o, float x, float y, float z, float w);

struct Obj_0014DB18 {
    int m0[6];
    void* m18;
    int m1C;
    void* m20;
    void Set(const Vec_0014DB18& v);
};

void Obj_0014DB18::Set(const Vec_0014DB18& v)
{
    if (m20)
        func_00170638(m20, v.x, v.y, v.z, v.w);
    else if (m18)
        func_001728C0(m18, v.x, v.y, v.z, v.w);
}
