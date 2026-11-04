struct Vec_002B7028 {
    float x, y, z;
};

extern "C" void* func_001317D0(void* p);
extern "C" void func_001352D8(void* p, Vec_002B7028* v);

struct Obj_002B7028 {
    void* m0;
    char pad4[0x30 - 4];
    int m30;
    void SetScale(float s);
};

void Obj_002B7028::SetScale(float s)
{
    void* p = func_001317D0(m0);
    Vec_002B7028 v;
    if (m30 & 1) {
        v.x = 1.0f;
        v.z = s;
    } else {
        v.x = s;
        v.z = 1.0f;
    }
    v.y = 1.0f;
    func_001352D8(p, &v);
}
