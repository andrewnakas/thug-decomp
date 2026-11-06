struct Vec_00190CF8 {
    float x, y, z, w;
    float LengthSqr() const { return x * x + y * y + z * z; }
};

struct Obj_00190CF8 {
    char pad0[0x48];
    float m48;
    float m4C;
    char pad50[0xB4 - 0x50];
    unsigned int mB4;
    char padB8[0xC0 - 0xB8];
    Vec_00190CF8 mC0;
    float mD0;
    char padD4[0xE0 - 0xD4];
    Vec_00190CF8 mE0;
    Vec_00190CF8 mF0;
    char pad100[0x10];
    Vec_00190CF8 m110;
    char pad120[0x160 - 0x120];
    signed char m160;
    void Check();
};

extern "C" void func_00190E50(Obj_00190CF8* self);

void Obj_00190CF8::Check()
{
    if (m160 < 3) return;
    if (m48 < mF0.LengthSqr()) return;
    if (m4C < m110.LengthSqr()) return;
    func_00190E50(this);
    if ((mB4 & 1) == 0) return;
    Vec_00190CF8 d;
    d.x = mE0.x - mC0.x;
    d.y = mE0.y - mC0.y;
    d.z = mE0.z - mC0.z;
    d.w = mE0.w - mC0.w;
    if (d.LengthSqr() < 2304.0f) return;
    mD0 = 1.5f;
}
