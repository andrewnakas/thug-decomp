typedef int qword_0028F8F0 __attribute__((mode(TI)));

extern char D_00376CF0[];
extern char D_00376D0F[];
extern char D_00376D40[];

union Vec_0028F8F0 {
    qword_0028F8F0 q;
    float c[4];
    void Set(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
};

struct Body_0028F8F0 {
    char pad0[0x50];
    Vec_0028F8F0 m50;
    char pad60[0xB0 - 0x60];
    Vec_0028F8F0 mB0;
};

struct Sub_0028F8F0 {
    char pad0[0x1C];
    int m1C;
};

struct Other_0028F8F0 {
    char pad0[0xA0];
    Vec_0028F8F0 mA0;
    char padB0[0x5B0 - 0xB0];
    Sub_0028F8F0* m5B0;
    bool AtPos(const Vec_0028F8F0& p) const
    {
        return p.c[0] == mA0.c[0] && p.c[1] == mA0.c[1] && p.c[2] == mA0.c[2] && p.c[3] == mA0.c[3];
    }
};

extern "C" int func_001CE918(void* p, Vec_0028F8F0* a, Vec_0028F8F0* b);
extern "C" int func_00103F28(const char* fmt, ...);
extern "C" void func_0027C720(Other_0028F8F0* o, int v);
extern "C" void func_001848F0(Body_0028F8F0* b, unsigned int name, int v);

struct Obj_0028F8F0 {
    char pad0[0xC];
    Body_0028F8F0* mC;
    char pad10[0x24 - 0x10];
    Other_0028F8F0* m24;
    char pad28[0x30 - 0x28];
    void* m30;
    void Check();
};

void Obj_0028F8F0::Check()
{
    if (!func_001CE918(m30, &mC->m50, &m24->mA0))
        return;
    func_00103F28(D_00376CF0, D_00376D0F, 0x159, D_00376D40);
    if (m24->m5B0->m1C == 4) {
        func_0027C720(m24, 1);
        func_001848F0(mC, 0xAFAA46BA, 0);
        return;
    }
    if (m24->AtPos(mC->m50))
        mC->mB0.Set(0.0f, 0.0f, 0.0f, 1.0f);
}
