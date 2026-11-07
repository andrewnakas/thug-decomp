/* fuzzy: 82.0 */
typedef int qword __attribute__((mode(TI)));

struct Vec_0015CF50 {
    union {
        qword q;
        struct {
            float x, y, z, w;
        };
    };
    Vec_0015CF50() {}
    Vec_0015CF50(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    void Add(const Vec_0015CF50& b, float s)
    {
        x += b.x * s;
        y += b.y * s;
        z += b.z * s;
        w += b.w * s;
    }
    void operator+=(const Vec_0015CF50& b)
    {
        x += b.x;
        y += b.y;
        z += b.z;
        w += b.w;
    }
};

static inline Vec_0015CF50 operator*(const Vec_0015CF50& a, float s)
{
    return Vec_0015CF50(a.x * s, a.y * s, a.z * s, a.w * s);
}

extern "C" void func_00183CB8(int obj, int* ref);

static inline void Release_0015CF50(int* ref)
{
    if (*ref) {
        func_00183CB8(*ref, ref);
        *ref = 0;
    }
}

struct Feeler_0015CF50 {
    Vec_0015CF50 m_start;
    Vec_0015CF50 m_end;
    char pad20[0xA0 - 0x20];
    Vec_0015CF50 m_point;
    Vec_0015CF50 m_normal;
    int m_ref;
    char padC4[0xE0 - 0xC4];
    ~Feeler_0015CF50()
    {
        Release_0015CF50(&m_ref);
    }
};

struct Cam_0015CF50 {
    char pad0[0x30];
    Vec_0015CF50 m_pos;
};

struct Regs_0015CF50 {
    char pad0[0x28];
    long m_28;
    long m_30;
};

struct Span_0015CF50 {
    unsigned short m_start;
    unsigned short m_end;
    unsigned short m_off;
};

struct Obj_0015CF50 {
    char pad0[0x28];
    int m_on;
    char pad2C[0x30 - 0x2C];
    float m_fadeH;
    int m_fadeN;
    float m_base;
    char pad3C[0x40 - 0x3C];
    unsigned int m_col;
    char pad44[0x50 - 0x44];
    Regs_0015CF50* m_regs;
    unsigned char* m_map;
    Span_0015CF50* m_spans;
    int m_heights[0x460 / 4 - 0x5C / 4];
    int m_rows;
    float m_x0;
    float m_z0;
    char pad46C[0x490 - 0x46C];
    unsigned char m_type[0x400];
    unsigned char m_dx[0x400];
    unsigned char m_dz[0x400];
    char padC90x[0x10A8 - 0x1090];
    long m_tex;
};

extern Cam_0015CF50 D_003E11C0;
extern Vec_0015CF50 D_003E15A0;
extern Vec_0015CF50 D_003E15B0;
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
extern char D_00360658[];
extern char D_310[];
extern char D_380[];
extern char D_3A8[];
extern char D_4A0[];
extern char D_3680[];

extern "C" void func_00209240(Feeler_0015CF50* f);
extern "C" void func_00209360(Feeler_0015CF50* f, Vec_0015CF50* a);
extern "C" void func_00209370(Feeler_0015CF50* f, Vec_0015CF50* b);
extern "C" int func_002093E8(Feeler_0015CF50* f, int a, int b);
extern "C" int func_003233B8(Vec_0015CF50* d, Vec_0015CF50* s);
extern "C" float func_00341068(float a);
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
        func_00103F28(D_00360658);
        func_00334148(1);
    }
}

extern "C" void func_0015CF50(Obj_0015CF50* o, float x, float z)
{
    if (!o->m_on) {
        return;
    }
    int cx = (int)((x - o->m_x0) * (1.0f / 128.0f));
    int cz = (int)((z - o->m_z0) * (1.0f / 128.0f));
    int x0 = cx - 16;
    int x1 = cx + 16;
    int z0 = cz - 16;
    int z1 = cz + 16;
    if (z1 < 0) {
        return;
    }
    if (o->m_rows - 1 < z0) {
        return;
    }
    Tag(0x10000000, 0);
    func_00164E48(0, (unsigned int)D_380 >> 3);
    func_00164F08(&D_003E15A0);
    func_00164F08(&D_003E15B0);
    func_00164F48(D_003E1180);
    func_00164EB8(0);
    func_00164E48(0, (unsigned int)D_4A0 >> 3);
    PutV(640.0f, 480.0f, 0, 0);
    PutV(D_003E1560[0] / D_00394080, D_003E1560[1] / D_00394084, 0, 0);
    func_00164EB8(0);
    func_001645F8(0, 0, 0);
    Reg(o->m_tex, 0x42);
    Reg(o->m_regs->m_28, 6);
    Reg(o->m_regs->m_30, 0x14);
    Reg(0x3F8000003F800000, 2);
    Reg(0x3F80000000000000, 1);
    func_001646D0(0);
    float fade[256];
    float lin[256];
    float wave[256];
    int n = o->m_fadeN;
    float bx = o->m_x0;
    float bz = o->m_z0;
    int i;
    for (i = 0xFE - n; i < 0x100; i++) {
        fade[i] = o->m_fadeH - (i - 0xFE + n) / (float)n * o->m_fadeH;
    }
    for (i = 0; i < 0x100; i++) {
        lin[i] = i * 0.2509804f;
    }
    for (i = 0; i < 0x100; i++) {
        wave[i] = func_00341068(i * 0.024543693f) * 64.0f;
    }
    int left = 0;
    unsigned int* cols = 0;
    Vec_0015CF50* pts = 0;
    for (int r = z0; r <= z1; r++) {
        int row;
        if (r >= 0) {
            row = o->m_rows - 1 < r ? o->m_rows - 1 : r;
        } else {
            row = 0;
        }
        Span_0015CF50* s = &o->m_spans[row];
        if (s->m_start != 0x4000) {
            int idx = s->m_off + (x0 - s->m_start);
            float fx = x0 * 128.0f + bx;
            float fz = row * 128.0f + bz;
            int rowbits = (row & 0xF) * 16;
            for (int c = x0; c <= x1; c++) {
                int col = o->m_spans[row].m_start;
                if (col < c) {
                    col = o->m_spans[row].m_end;
                    if (c < col) {
                        col = c;
                    }
                }
                float h = o->m_heights[o->m_map[idx]] >> 4;
                idx++;
                fx += 128.0f;
                int cell = rowbits + (col & 0xF);
                for (int k = 0; k < 4; k++) {
                    unsigned char t = o->m_type[cell];
                    if (t != 0xFF) {
                        unsigned char a = o->m_dx[cell];
                        unsigned char b = o->m_dz[cell];
                        float py = h + fade[t] + o->m_base;
                        float px = fx + lin[a] + wave[(b + t) & 0xFF];
                        float pz = fz + lin[b] + wave[(a + t) & 0xFF];
                        if (left == 0) {
                            func_00175C90(0x5125, 4, 0x56, 1, (unsigned int)D_3680 >> 3);
                            D_00394284 = 8;
                            D_00394288 = D_00394274;
                            D_0039428C = 4;
                            cols = (unsigned int*)(D_00394274 + 4);
                            Put((((unsigned short)D_00394280 + 3) & 0x3FF) | 0x6E004000);
                            D_00394274 = (unsigned char*)(cols + 0x50);
                            EndUnpack();
                            D_00394284 = 0x20;
                            D_00394288 = D_00394274;
                            D_0039428C = 4;
                            pts = (Vec_0015CF50*)(D_00394274 + 4);
                            Put((((unsigned short)D_00394280 + 4) & 0x3FF) | 0x6C000000);
                            D_00394274 = (unsigned char*)(pts + 0x50);
                            EndUnpack();
                            func_00175D20(1);
                            left = 0x50;
                            Put((((unsigned int)D_310 >> 3) & 0xFFFF) | 0x14000000);
                            D_00394294 = D_00394280;
                        }
                        left--;
                        *cols++ = o->m_col;
                        pts->x = px;
                        pts->y = py;
                        pts->z = pz;
                        pts->w = o->m_base;
                        pts++;
                    }
                    cell += 0x100;
                }
            }
        }
    }
    if (left) {
        for (int i = 0; i < left; i++) {
            ((int*)pts)[0] = 0;
            ((int*)pts)[1] = 0;
            ((int*)pts)[2] = 0;
            ((int*)pts)[3] = 0;
            pts++;
        }
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
