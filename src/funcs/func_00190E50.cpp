extern "C" void* func_00184B30(void* obj, void* a, void* b, int c, int d);
extern "C" void func_001EFDC0(void* p);

struct Vec_00190E50 {
    float x, y, z, w;
    void Set(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Obj_00190E50 {
    char pad0[0xC];
    void* mC;
    char pad10[0x8C - 0x10];
    void* m8C;
    char pad90[0x94 - 0x90];
    void* m94;
    char pad98[0xD4 - 0x98];
    int mD4;
    char padD8[0xF0 - 0xD8];
    Vec_00190E50 mF0;
    char pad100[0x110 - 0x100];
    Vec_00190E50 m110;
    void Fn();
};

void Obj_00190E50::Fn()
{
    if (m8C)
        func_001EFDC0(func_00184B30(mC, m8C, m94, 0, 0));
    mF0.Set(0.0f, 0.0f, 0.0f, 1.0f);
    m110.Set(0.0f, 0.0f, 0.0f, 1.0f);
    mD4 = 0;
}
