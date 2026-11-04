typedef int qword __attribute__((mode(TI)));
union Vec_0028E1C0 {
    qword q;
    struct { float x, y, z, w; } f;
};
struct Coll_0028E1C0 {
    char pad[0x74];
    int m74;
    int m78;
    char pad1[0x89 - 0x7C];
    signed char m89;
    char pad2[2];
};
extern "C" void func_00209380(Coll_0028E1C0*, void*, void*);
extern "C" void func_00209350(Coll_0028E1C0*, unsigned short, unsigned short);
extern "C" int func_002093E8(Coll_0028E1C0*, int, int);
extern "C" float func_002032A0(unsigned int, int);
extern "C" float func_00341068(float);

struct Obj_0028E1C0 {
    char pad0[0xB0];
    char mB0[0x118 - 0xB0];
    unsigned short m118;
    char pad2[0x160 - 0x11A];
    Vec_0028E1C0 m160;
    char pad3[0x270 - 0x170];
    Vec_0028E1C0 m270;
    Vec_0028E1C0 m280;
    int m290;
    int m294;
    int m298;
    int Test(unsigned short a, unsigned short b);
};

int Obj_0028E1C0::Test(unsigned short a, unsigned short b)
{
    Coll_0028E1C0* c = (Coll_0028E1C0*)mB0;
    func_00209380(c, &m270, &m280);
    func_00209350(c, a, b);
    int r = func_002093E8(c, 1, 0);
    if (!r) return 0;
    if (c->m74) {
        if (c->m89) c->m78 = 0;
    }
    unsigned short fl = m118;
    Vec_0028E1C0 v = m160;
    m298 = 0;
    m294 = (fl >> 3) & 1;
    if (fl & 1) {
        m290 = 1;
    } else if (fl & 2) {
        m290 = 0;
    } else if (fl & 8) {
        m290 = 1;
    } else if (fl & 4) {
        m290 = 0;
        m298 = 1;
    } else {
        if (v.f.y < func_00341068(func_002032A0(0x3EEDE4D3, 0) * 0.01745329425f)) {
            m290 = 0;
        } else {
            m290 = 1;
        }
    }
    return r;
}
