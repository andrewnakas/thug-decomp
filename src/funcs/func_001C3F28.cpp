typedef int qword_001C3F28 __attribute__((mode(TI)));

union Vec_001C3F28 {
    qword_001C3F28 q;
    struct { float x, y, z, w; } f;
};

struct A38_001C3F28 {
    char pad0[0x28];
    int m28;
    int m2C;
};

struct A28_001C3F28 {
    char pad0[0x14C];
    int m14C;
};

struct Obj_001C3F28 {
    char pad0[0x30];
    char m30[0x10];
    Vec_001C3F28 m40;
    float m50;
    char pad54[0x2C];
    char m80[0x10];
    unsigned int m90;
    char pad94[0x2C];
    int mC0;
    char padC4[0x8EC];
    int m9B0;
    char pad9B4[0x2C];
    char m9E0[0x10];
    char pad9F0[0x38];
    A28_001C3F28* mA28;
    char padA2C[0x8];
    int mA34;
    A38_001C3F28* mA38;
    char padA3C[0x8];
    int mA44;
    char padA48[0x28];
    char mA70[0x10];
    char padA80[0xD0];
    int mB50;

    bool TryIt();
};

extern "C" int func_001E5548(int name, int a);
extern "C" bool func_001E7EB0(int params, unsigned int name, float* out, int required);
extern "C" int func_002817F0(int a, int b, void* c, void* d, Vec_001C3F28* e, void* f);
extern "C" void func_001BB080(int a, int b, void* c);
extern "C" void func_001BF130(Obj_001C3F28* o, int a);

bool Obj_001C3F28::TryIt()
{
    if (mC0) return false;
    if (mA38->m28) return false;
    if (!mA28->m14C) return false;
    Vec_001C3F28 pos;
    pos.q = m40.q;
    float h;
    func_001E7EB0(func_001E5548(0x6775E538, 0), 0xC0491D2E, &h, 1);
    pos.f.y = h;
    if (!func_002817F0(mA44, 0, m30, m80, &pos, m9E0)) return false;
    if (mB50) {
        func_001BB080(mA34, 2, mA70);
        if (mA38->m2C) return true;
    }
    func_001BF130(this, 1);
    m40.q = pos.q;
    m50 = pos.f.y;
    m9B0 = 2;
    m40.f.y = 0.0f;
    m90 = 0x2EDA83EA;
    return true;
}
