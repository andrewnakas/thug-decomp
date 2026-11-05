typedef int qword __attribute__((mode(TI)));

struct Vec_0015DE88 {
    union {
        qword q;
        struct {
            float x, y, z, w;
        };
    };
    Vec_0015DE88() {}
    Vec_0015DE88(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    void Add(const Vec_0015DE88& b, float s)
    {
        x += b.x * s;
        y += b.y * s;
        z += b.z * s;
        w += b.w * s;
    }
    void operator+=(const Vec_0015DE88& b)
    {
        x += b.x;
        y += b.y;
        z += b.z;
        w += b.w;
    }
};

static inline Vec_0015DE88 operator*(const Vec_0015DE88& a, float s)
{
    return Vec_0015DE88(a.x * s, a.y * s, a.z * s, a.w * s);
}

extern "C" void func_00183CB8(int obj, int* ref);

static inline void Release_0015DE88(int* ref)
{
    if (*ref) {
        func_00183CB8(*ref, ref);
        *ref = 0;
    }
}

struct Feeler_0015DE88 {
    Vec_0015DE88 m_start;
    Vec_0015DE88 m_end;
    char pad20[0xA0 - 0x20];
    Vec_0015DE88 m_point;
    Vec_0015DE88 m_normal;
    int m_ref;
    char padC4[0xE0 - 0xC4];
    ~Feeler_0015DE88()
    {
        Release_0015DE88(&m_ref);
    }
};

struct Cam_0015DE88 {
    char pad0[0x30];
    Vec_0015DE88 m_pos;
};

struct Regs_0015DE88 {
    char pad0[0x28];
    long m_28;
    long m_30;
};

struct Obj_0015DE88 {
    char pad0[0x18];
    float m_rate;
    int m_life;
    float m_height;
    unsigned char m_col[4];
    char pad28[0x4C - 0x28];
    Regs_0015DE88* m_regs;
    char pad50[0x470 - 0x50];
    float m_accum;
    char pad474[0x10A0 - 0x474];
    long m_tex;
    char pad10A8[0x10B0 - 0x10A8];
    float m_x[32];
    float m_y[32];
    float m_z[32];
    int m_left[32];
    int m_next;
};

extern Cam_0015DE88 D_003E11C0;
extern Vec_0015DE88 D_003E15A0;
extern Vec_0015DE88 D_003E15B0;
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

extern "C" void func_00209240(Feeler_0015DE88* f);
extern "C" void func_00209360(Feeler_0015DE88* f, Vec_0015DE88* a);
extern "C" void func_00209370(Feeler_0015DE88* f, Vec_0015DE88* b);
extern "C" int func_002093E8(Feeler_0015DE88* f, int a, int b);
extern "C" int func_003233B8(Vec_0015DE88* d, Vec_0015DE88* s);
extern "C" int func_00100030(int n);
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

extern "C" void func_0015DE88(Obj_0015DE88* o, float x, float z)
{
    int before = (int)o->m_accum;
    o->m_accum += o->m_rate;
    if ((int)o->m_accum != before) {
        Feeler_0015DE88 f;
        func_00209240(&f);
        Vec_0015DE88 pos;
        Vec_0015DE88 dir;
        pos.x = D_003E11C0.m_pos.x;
        pos.y = 50000.0f;
        pos.z = D_003E11C0.m_pos.z;
        pos.w = 1.0f;
        dir.x = x - D_003E11C0.m_pos.x;
        dir.y = 0.0f;
        dir.z = z - D_003E11C0.m_pos.z;
        dir.w = 1.0f;
        func_003233B8(&dir, &dir);
        float r = func_00100030(0x8000) * (1.0f / 32768.0f);
        Vec_0015DE88 side;
        pos.Add(dir, r * 2048.0f);
        side.x = dir.z;
        side.y = 0.0f;
        side.z = -dir.x;
        side.w = 1.0f;
        float t = 1.0f - func_00100030(0x8000) * (1.0f / 32768.0f);
        if (o->m_next & 1) {
            float s = t * 2048.0f;
            pos += side * (r * s);
        } else {
            float s = -t * 2048.0f;
            pos += side * (r * s);
        }
        func_00209360(&f, &pos);
        pos.y = -50000.0f;
        func_00209370(&f, &pos);
        float h;
        if (func_002093E8(&f, 0, 0)) {
            h = f.m_point.y;
        } else {
            h = 50000.0f;
        }
        o->m_x[o->m_next] = pos.x;
        o->m_y[o->m_next] = h + o->m_height;
        o->m_z[o->m_next] = pos.z;
        o->m_left[o->m_next] = o->m_life;
        o->m_next = (o->m_next + 1) % 32;
    }
    int n = 0;
    for (int i = 0; i < 32; i++) {
        if (o->m_left[i]) {
            n++;
        }
    }
    if (n) {
        unsigned int cycle = 4;
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
        func_00175C90(0x5125, 4, 0x56, 1, (unsigned int)D_3680 >> 3);
        D_00394284 = 8;
        D_00394288 = D_00394274;
        D_0039428C = cycle;
        unsigned int* cols = (unsigned int*)(D_00394274 + 4);
        Put((((unsigned short)D_00394280 + 3) & 0x3FF) | 0x6E004000);
        D_00394274 = (unsigned char*)(cols + n);
        EndUnpack();
        D_00394284 = 0x20;
        D_0039428C = 4;
        D_00394288 = D_00394274;
        Vec_0015DE88* pts = (Vec_0015DE88*)(D_00394274 + 4);
        Put((((unsigned short)D_00394280 + 4) & 0x3FF) | 0x6C000000);
        D_00394274 = (unsigned char*)(pts + n);
        EndUnpack();
        func_00175D20(1);
        Put((((unsigned int)D_310 >> 3) & 0xFFFF) | 0x14000000);
        D_00394294 = D_00394280;
        for (int i = 0; i < 32; i++) {
            if (o->m_left[i]) {
                unsigned char c[4];
                c[0] = o->m_col[0] * o->m_left[i] / o->m_life;
                c[1] = o->m_col[1] * o->m_left[i] / o->m_life;
                c[2] = o->m_col[2] * o->m_left[i] / o->m_life;
                c[3] = o->m_col[3] * o->m_left[i] / o->m_life;
                *cols++ = *(unsigned int*)c;
                pts->x = o->m_x[i];
                pts->y = o->m_y[i];
                pts->z = o->m_z[i];
                pts->w = o->m_height;
                pts++;
                o->m_left[i]--;
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
}
