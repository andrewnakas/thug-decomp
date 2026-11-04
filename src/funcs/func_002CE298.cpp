typedef int qword __attribute__((mode(TI)));

union Vec_002CE298 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

struct Color_002CE298 {
    unsigned char m0;
    signed char m1;
    unsigned char m2;
    unsigned char m3;
    unsigned char m4;
    unsigned char m5;
};

extern void* D_0039274C;
extern "C" Color_002CE298* func_002BAA28(Color_002CE298* c, int a, int b, int d, int e, int f, int g);
extern "C" Vec_002CE298 func_002C02B0(void* a, Color_002CE298* c, Vec_002CE298* out);

static inline void Set_002CE298(Color_002CE298* c, int a, int b, int d, int e, int f, int g)
{
    c->m0 = a;
    c->m1 = b;
    c->m2 = d;
    c->m3 = e;
    c->m4 = f;
    c->m5 = g;
}

struct Obj_002CE298 {
    char pad0[2];
    signed char m2;
    char pad3[4];
    unsigned char m7;
    unsigned char m8;
    unsigned char m9;
    unsigned char mA;
    Vec_002CE298 GetCenter();
};

Vec_002CE298 Obj_002CE298::GetCenter()
{
    Color_002CE298 c;
    int x = (unsigned)(m7 + m9) >> 1;
    int z = (unsigned)(m8 + mA) >> 1;
    func_002BAA28(&c, 0, 0, 0, 0, 0, 0);
    Set_002CE298(&c, x, m2, z, 1, 1, 1);
    Vec_002CE298 pos;
    Vec_002CE298 size;
    pos = func_002C02B0(D_0039274C, &c, &size);
    Vec_002CE298 r = pos;
    r.f.x += size.f.x * 0.5f;
    r.f.z += size.f.z * 0.5f;
    return r;
}
