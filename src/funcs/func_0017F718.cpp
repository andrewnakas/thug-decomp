struct Fog_0017F718 {
    int m0[10];
    long m_fog;
    long m_fogcol;
};

struct View_0017F718 {
    int m0[4];
    long* m_scissor;
    int m14[9];
    float m_alpha;
    unsigned int m_color;
    Fog_0017F718* m_fog;
};

extern unsigned char* D_00394274;
extern unsigned char* D_00394278;
extern unsigned int D_00394280;
extern unsigned int D_00394284;
extern unsigned char* D_00394288;
extern unsigned int D_0039428C;
extern unsigned int D_00394290;
extern unsigned int D_00394294;
extern char D_4C0[];
extern "C" void func_001645F8(int a, int b, int c);
extern "C" void func_001646D0(int a);
extern "C" void func_00164408(int a, int b, int c, int d, int e, unsigned int f);

static inline void Put(unsigned int v)
{
    unsigned int* p = (unsigned int*)D_00394274;
    *p = v;
    D_00394274 = (unsigned char*)(p + 1);
}

static inline void Tag(unsigned int v, unsigned int a)
{
    unsigned int* p = (unsigned int*)D_00394274;
    D_00394278 = (unsigned char*)p;
    p[0] = v;
    p[1] = a;
    D_00394274 = (unsigned char*)(p + 2);
}

static inline void Reg(long v, int reg)
{
    unsigned int* p = (unsigned int*)D_00394274;
    p[0] = (unsigned int)v;
    p[1] = (unsigned int)(v >> 32);
    p[2] = reg;
    D_00394274 = (unsigned char*)(p + 3);
}

extern "C" void func_0017F718(View_0017F718* v)
{
    Tag(0x10000000, 0);
    D_00394294 = D_00394280;
    int fog = v->m_fog ? 0x10 : 0;
    func_001645F8(0, 0, 0);
    Reg(*v->m_scissor, 0x40);
    if (v->m_fog) {
        Reg(v->m_fog->m_fog, 6);
        Reg(v->m_fog->m_fogcol, 0x14);
    }
    Reg(0x44, 0x42);
    Reg(1, 0x46);
    Reg(v->m_color, 1);
    func_001646D0(0);
    Put(((unsigned short)D_00394280 & 0x3FF) | 0x6C014000);
    D_00394290 = 1;
    if (v->m_alpha == 0.0f) {
        func_00164408(0x53, 2, 0, fog | 0x146, 1, (unsigned int)D_4C0 >> 3);
    } else {
        func_00164408(0x53, 2, 0, fog | 0x144, 1, (unsigned int)D_4C0 >> 3);
    }
    D_00394284 = 0x20;
    D_0039428C = 4;
    D_00394288 = D_00394274;
    Put((((unsigned short)D_00394280 + 1) & 0x3FF) | 0x6C000000);
}
