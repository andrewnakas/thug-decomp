typedef int qword __attribute__((mode(TI)));

struct Vec_00152690 {
    union {
        qword q;
        struct {
            float x, y, z, w;
        };
    };
};

struct Pos_00152690 {
    float x, y, z;
};

struct Seg_00152690 {
    char pad0[0x18];
    float m_18;
    float m_1C;
    float m_20;
    float m_24;
    float m_28;
    float m_2C;
};

struct Color_00152690 {
    unsigned char r, g, b, a;
};

struct Regs_00152690 {
    char pad0[0x28];
    long m_28;
    long m_30;
};

extern Vec_00152690 D_003E15A0;
extern Vec_00152690 D_003E15B0;
extern char D_003E1180[];
extern char D_003E13C0[];
extern float D_003E1560[];
extern float D_00394080;
extern float D_00394084;
extern unsigned char* D_00394274;
extern unsigned char* D_00394278;
extern unsigned int D_00394280;
extern unsigned int D_00394284;
extern unsigned char* D_00394288;
extern unsigned int D_0039428C;
extern unsigned int D_00394290;
extern unsigned int D_00394294;
extern char D_0035F860[];
extern char D_310[];
extern char D_380[];
extern char D_3A8[];
extern char D_4A0[];
extern char D_3680[];

extern "C" void func_00164E48(int a, unsigned int b);
extern "C" void func_00164F08(void* v);
extern "C" void func_00164F48(void* m);
extern "C" void func_00164EB8(int a);
extern "C" void func_001645F8(int a, int b, int c);
extern "C" void func_001646D0(int a);
extern "C" void func_00175C90(int a, int b, int c, int d, unsigned int e);
extern "C" void func_00175D20(int a);
extern "C" void func_00103F28(const char* msg);
extern "C" void func_00334148(int a) __attribute__((noreturn));

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

static inline void PutV(float a, float b, unsigned int c, unsigned int d)
{
    ((float*)D_00394274)[0] = a;
    ((float*)D_00394274)[1] = b;
    ((unsigned int*)D_00394274)[2] = c;
    ((unsigned int*)D_00394274)[3] = d;
    D_00394274 += 0x10;
}

static inline void Reg(long v, int reg)
{
    unsigned int* p = (unsigned int*)D_00394274;
    p[0] = (unsigned int)v;
    p[1] = (unsigned int)(v >> 32);
    p[2] = reg;
    D_00394274 = (unsigned char*)(p + 3);
}

static inline void EndUnpack()
{
    unsigned char* end = (unsigned char*)(((int)D_00394274 + 3) & ~3);
    D_00394290 = ((D_00394274 - D_00394288) - 4) * 8 / (D_0039428C * D_00394284);
    while (D_00394274 < end) {
        *D_00394274++ = 0;
    }
    if (D_00394290 == 0) {
        D_00394274 -= 4;
    } else if (D_00394290 < 0x100) {
        D_00394288[2] = D_00394290;
    } else if (D_00394290 == 0x100) {
        D_00394288[2] = 0;
    } else {
        func_00103F28(D_0035F860);
        func_00334148(1);
    }
}


class Trail_00152690 {
public:
    char pad0[0x50];
    float m_x;
    float m_y;
    float m_z;
    char pad5C[0x168 - 0x5C];
    int m_count;
    char pad16C[0x1CC - 0x16C];
    Seg_00152690* m_segs;
    char pad1D0[0x1E4 - 0x1D0];
    float m_split;
    char pad1E8[0x200 - 0x1E8];
    Pos_00152690* m_pts;
    int m_204;
    long m_tex;
    Color_00152690 m_col[3];
    Regs_00152690* m_regs;
    void Draw();
};

void Trail_00152690::Draw()
{
    if (m_count <= 0) return;
    Tag(0x10000000, 0);
    func_00164E48(0, (unsigned int)D_380 >> 3);
    int left = 0;
    float* pts = 0;
    unsigned int* cols = 0;
    int i = 0;
    func_00164F08(&D_003E15A0);
    func_00164F08(&D_003E15B0);
    func_00164F48(D_003E1180);
    func_00164EB8(0);
    func_00164E48(0, (unsigned int)D_4A0 >> 3);
    PutV(640.0f, 480.0f, 0, 0);
    PutV(D_003E1560[0] / D_00394080, D_003E1560[1] / D_00394084, 0, 0);
    func_00164EB8(0);
    func_001645F8(0, 0, 0);
    Reg(m_tex, 0x42);
    Reg(m_regs->m_28, 6);
    Reg(m_regs->m_30, 0x14);
    Reg(0x3F8000003F800000, 2);
    Reg(0x3F80000000000000, 1);
    func_001646D0(0);
    Seg_00152690* seg = m_segs;
    Pos_00152690* p = m_pts;
    for (; i < m_count; i++, seg++, p++) {
        if (i == 0 || left == 0) {
            left = m_count - i;
            if (left > 80) left = 80;
            func_00175C90(0x5125, 4, 0x56, 1, (unsigned int)D_3680 >> 3);
            D_00394284 = 8;
            D_00394288 = D_00394274;
            D_0039428C = 4;
            cols = (unsigned int*)(D_00394274 + 4);
            Put((((unsigned short)D_00394280 + 3) & 0x3FF) | 0x6E004000);
            D_00394274 = (unsigned char*)(cols + left);
            EndUnpack();
            D_00394284 = 0x20;
            D_00394288 = D_00394274;
            D_0039428C = 4;
            pts = (float*)(D_00394274 + 4);
            Put((((unsigned short)D_00394280 + 4) & 0x3FF) | 0x6C000000);
            D_00394274 = (unsigned char*)(pts + left * 4);
            EndUnpack();
            func_00175D20(1);
            Put((((unsigned int)D_310 >> 3) & 0xFFFF) | 0x14000000);
            D_00394294 = D_00394280;
        }
        float t = seg->m_28 / seg->m_2C;
        float w = seg->m_18 + (seg->m_20 - seg->m_18) * t;
        *pts++ = p->x + m_x;
        *pts++ = p->y + m_y;
        *pts++ = p->z + m_z;
        *pts++ = w;
        Color_00152690 a;
        Color_00152690 b;
        if (m_split >= 0.0f) {
            if (t < m_split) {
                a = m_col[0];
                b = m_col[1];
                t = t / m_split;
            } else {
                a = m_col[1];
                b = m_col[2];
                t = (t - m_split) / (1.0f - m_split);
            }
        } else {
            a = m_col[0];
            b = m_col[2];
        }
        unsigned char c[4];
        c[0] = a.r + (int)((b.r - a.r) * t);
        c[1] = a.g + (int)((b.g - a.g) * t);
        c[2] = a.b + (int)((b.b - a.b) * t);
        c[3] = a.a + (int)((b.a - a.a) * t);
        *cols++ = *(unsigned int*)c;
        left--;
    }
    func_00164E48(0, (unsigned int)D_3A8 >> 3);
    func_00164F48(D_003E13C0);
    func_00164EB8(1);
    Put((((unsigned int)D_310 >> 3) & 0xFFFF) | 0x14000000);
    D_00394294 = D_00394280;
    unsigned int type = (*(unsigned int*)D_00394278 >> 28) & 7;
    while ((int)D_00394274 & 0xF) {
        *(unsigned int*)D_00394274 = 0;
        D_00394274 += 4;
    }
    if (type != 3 && type != 0 && type != 4) {
        *(unsigned short*)D_00394278 = (D_00394274 - D_00394278 - 8) >> 4;
    }
}
