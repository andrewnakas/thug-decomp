typedef int qword_0016E3B0 __attribute__((mode(TI)));

struct V_0016E3B0 {
    union {
        qword_0016E3B0 q;
        struct {
            float x, y, z, w;
        };
        unsigned int i[4];
    };
    float operator[](int k) const { return (&x)[k]; }
};

struct M_0016E3B0;
extern "C" void func_00323318(M_0016E3B0* out, void* m, M_0016E3B0* in);

struct M_0016E3B0 {
    V_0016E3B0 r[4];
    M_0016E3B0& operator=(const M_0016E3B0& o)
    {
        r[0] = o.r[0];
        r[1] = o.r[1];
        r[2] = o.r[2];
        r[3] = o.r[3];
        return *this;
    }
};

struct Mat_0016E3B0 {
    M_0016E3B0 m;
    float t[4];
    unsigned int m50;
    bool Big()
    {
        if (m50 & 1) {
            return true;
        }
        return false;
    }
};

struct Ctx_0016E3B0 {
    char pad0[0xC];
    unsigned int mC;
    char pad10[0x18];
    int m28[10];
    Mat_0016E3B0* m50;
};

struct Cnt_0016E3B0 {
    char pad0[0x40];
    int m40;
};

struct Node_0016E3B0 {
    V_0016E3B0 pos;
    float m10, m14, m18;
    unsigned int m1C;
    unsigned int m20;
    unsigned int m24;
    char pad28[0x4];
    Ctx_0016E3B0* m2C;
    char pad30[0x4];
    union {
        int m34;
        struct {
            short m34s;
            short m36s;
        };
    };
    char pad38[0xC];
    Cnt_0016E3B0* m44;
};

extern float D_00394058;
extern float D_0039405C;
extern float D_00394060;
extern float D_00394064;
extern float D_00394070;
extern float D_00394074;
extern float D_00394078;
extern float D_0039407C;
extern float D_00394088;
extern float D_0039408C;
extern float D_003940AC;
extern float D_0038C020;
extern int D_0038C02C;
extern int D_00394094;
extern Ctx_0016E3B0* D_0039427C;
extern Ctx_0016E3B0* D_003942FC;
extern unsigned char* D_00394274;
extern unsigned char* D_00394278;
extern unsigned int D_00394280;
extern V_0016E3B0 D_003E1630;
extern char D_003E1080[];
extern char D_003E1240[];
struct Cam_0016E3B0 {
    char pad0[0x30];
    V_0016E3B0 m_pos;
    V_0016E3B0* GetPos() { return &m_pos; }
};
extern Cam_0016E3B0 D_003E11C0;
extern char D_003E1560[];
extern char D_003E1570[];
extern char D_420[];

extern "C" void func_00323298(V_0016E3B0* out, void* m, V_0016E3B0* v);
extern "C" void func_003233B8(V_0016E3B0* d, V_0016E3B0* s);
extern "C" void func_00323318(M_0016E3B0* out, void* m, M_0016E3B0* in);
extern "C" Mat_0016E3B0* func_00167448(Mat_0016E3B0* m);
extern "C" Mat_0016E3B0* func_00167600(Mat_0016E3B0* m);
extern "C" void func_00168410(Mat_0016E3B0* m, Node_0016E3B0* n);
extern "C" void func_001681B8(Mat_0016E3B0* m, int a, int b);
extern "C" void func_00168580(Mat_0016E3B0* m, int a, int b);
extern "C" void func_00171EB0(Node_0016E3B0* n);
extern "C" void func_001617A0(Ctx_0016E3B0* c);
extern "C" void func_00164E48(int a, unsigned int b);
extern "C" void func_00164F08(void* v);
extern "C" void* func_00168558(Mat_0016E3B0* m);
extern "C" void func_00164EB8(int a);
extern "C" void func_001645F8(int a, int b, int c);
extern "C" void func_001646D0(int a);
extern "C" void func_00160F18(int a, int b);

static inline void Normalize(V_0016E3B0& v)
{
    func_003233B8(&v, &v);
}

static inline void Bind(Ctx_0016E3B0* c)
{
    if (D_0039427C != c) {
        func_001617A0(c);
    }
}

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

static inline void PutV(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    ((unsigned int*)D_00394274)[0] = a;
    ((unsigned int*)D_00394274)[1] = b;
    ((unsigned int*)D_00394274)[2] = c;
    ((unsigned int*)D_00394274)[3] = d;
    D_00394274 += 0x10;
}

static inline void Put4(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int* p = (unsigned int*)D_00394274;
    p[0] = a;
    p[1] = b;
    p[2] = c;
    p[3] = d;
    D_00394274 = (unsigned char*)(p + 4);
}

static inline void StRow(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    Put(0x30000000);
    Put4(a, b, c, d);
}

static inline void Reg(long v, int reg)
{
    unsigned int* p = (unsigned int*)D_00394274;
    p[0] = (unsigned int)v;
    p[1] = (unsigned int)(v >> 32);
    p[2] = reg;
    D_00394274 = (unsigned char*)(p + 3);
}

static inline void Close()
{
    int kind = (*(unsigned int*)D_00394278 >> 28) & 7;
    while ((unsigned int)D_00394274 & 0xF) {
        *(unsigned int*)D_00394274 = 0;
        D_00394274 += 4;
    }
    if (kind != 3 && kind != 0 && kind != 4) {
        *(unsigned short*)D_00394278 = ((D_00394274 - D_00394278) - 8) >> 4;
    }
}

static inline bool Outside(const V_0016E3B0& v)
{
    float r = v.w;
    float z = v.z;
    bool res = false;
    if (z - D_00394088 > r || D_00394058 * z - D_00394060 * v.x > r || D_00394058 * z + D_00394060 * v.x > r ||
        D_0039405C * z + D_00394064 * v.y > r || D_0039405C * z - D_00394064 * v.y > r || D_0039408C - z > r) {
        res = true;
    }
    return res;
}

static inline bool Inside(const V_0016E3B0& v)
{
    float r = v.w;
    float z = v.z;
    if (D_00394088 - z > r) {
        float a = -D_00394070 * z;
        float b = D_00394078 * v.x;
        if (a + b > r && a - b > r) {
            a = -D_00394074 * z;
            b = D_0039407C * v.y;
            if (a - b > r && a + b > r && z - D_0039408C > r) {
                return true;
            }
        }
    }
    return false;
}

static inline void PutMat(Mat_0016E3B0* c, bool full)
{
    int n = full ? 18 : 7;
    Tag((n | ((n - 1) << 16)) | 0x30000000, (unsigned int)&c->m50);
    Put((unsigned short)D_00394280 | 0x03000000);
    Put(0x02000000);
    D_00394280 += n - 1;
}

static inline void Fog(int& mode, const V_0016E3B0& v)
{
    if (D_0038C02C && D_0038C020 < v.w - v.z) {
        mode |= 0x10;
    }
}

static inline void Draw(Node_0016E3B0* n, int mode)
{
    Tag(n->m24, n->m20);
    Put((unsigned short)D_00394280 | 0x03000000);
    Put((unsigned short)mode | 0x04000000);
    D_00394280 += n->m24 >> 16;
    if (n->m1C & 0x80000) {
        func_00160F18(6, 2);
        D_00394274 -= 8;
        Put(0x13000000);
        Put(0);
    }
}

static inline void PutM(const M_0016E3B0& m)
{
    unsigned int* d = (unsigned int*)D_00394274;
    unsigned int* s = (unsigned int*)&m;
    for (int i = 0; i < 16; i++) {
        *d++ = *s++;
    }
    D_00394274 = (unsigned char*)d;
}

extern "C" void func_0016E3B0(Node_0016E3B0* node, Mat_0016E3B0* m, unsigned int flags)
{
    V_0016E3B0 v;
    v.q = node->pos.q;
    v.w = 1.0f;
    func_00323298(&v, m, &v);
    v.w = node->pos.w;
    if (flags & 3) {
        if (Outside(v)) {
            return;
        }
        if (Inside(v)) {
            flags &= ~3;
        }
    }
    if (flags & 4) {
        if ((node->m1C & 0xC000) || node->pos.x + node->m10 < D_003E1630.x - 64.0f ||
            node->pos.x - node->m10 > D_003E1630.x + 64.0f || node->pos.z + node->m18 < D_003E1630.z - 64.0f ||
            node->pos.z - node->m18 > D_003E1630.z + 64.0f) {
            flags &= ~4;
        }
    }
    Mat_0016E3B0* cur = m;
    if (node->m1C & 0x10) {
        flags |= 8;
        cur = func_00167448(cur);
        func_00168410(cur, node);
    }
    if (node->m1C & 0x4600) {
        if (node->m1C & 0x4200) {
            if (cur == m) {
                cur = func_00167600(cur);
            }
            if (node->m1C & 0x200) {
                func_001681B8(cur, node->m34, node->m1C & 0x10000);
            }
            if (node->m1C & 0x4000) {
                func_00168580(cur, node->m34s, node->m36s);
            }
        }
        if (node->m1C & 0x400) {
            func_00171EB0(node);
        }
    }
    Bind(node->m2C);
    node->m2C->m28[D_00394094] = 1;
    if (node->m44) {
        node->m44->m40++;
    }
    float* org = cur->t;
    Tag(0x10000001, v.i[2]);
    Put(0);
    StRow((int)cur->t[0] + (int)(node->pos[0] * 16.0f), (int)cur->t[1] + (int)(node->pos[1] * 16.0f),
         (int)cur->t[2] + (int)(node->pos[2] * 16.0f), 0);
    if (node->m1C & 0x8000) {
        V_0016E3B0 b;
        V_0016E3B0 a;
        a.q = cur->m.r[1].q;
        a.z = 0.0f;
        a.w = 0.0f;
        Normalize(a);
        b.x = a.y;
        b.y = -a.x;
        b.z = 0.0f;
        b.w = 0.0f;
        V_0016E3B0* pb = &b;
        V_0016E3B0* pa = &a;
        func_00323298(pb, D_003E1240, pb);
        func_00323298(pa, D_003E1240, pa);
        b.z = 0.0f;
        b.w = 0.0f;
        a.z = 0.0f;
        a.w = 0.0f;
        Tag(0x20000010, (unsigned int)(D_00394274 + 0x110));
        Put((unsigned short)D_00394280 | 0x03000000);
        Put(0x02000000);
        unsigned int saved = D_00394280;
        D_00394280 = 0;
        func_00164E48(1, (unsigned int)D_420 >> 3);
        func_00164F08(pb);
        func_00164F08(pa);
        func_00164F08(D_003E1560);
        PutV(0, 0, 0, 0);
        PutV(0, 0, 0, 0);
        func_00164F08(D_003E11C0.GetPos());
        func_00164F08(func_00168558(m));
        func_00164F08(D_003E1570);
        M_0016E3B0 mat;
        {
            M_0016E3B0 t;
            M_0016E3B0* p = &t;
            *p = cur->m;
            func_00323318(p, D_003E1240, p);
            mat = t;
        }
        PutM(mat);
        func_00164EB8(0);
        float s;
        float z;
        if (flags & 0x10) {
            z = cur->m.r[3].z;
        } else {
            V_0016E3B0 p;
            float* k = (float*)D_003E1080;
            float x = node->pos.x;
            float y = node->pos.y;
            float zz = node->pos.z;
            V_0016E3B0 tmp;
            tmp.x = x * k[0] + y * k[4] + zz * k[8] + k[12];
            tmp.y = x * k[1] + y * k[5] + zz * k[9] + k[13];
            tmp.z = x * k[2] + y * k[6] + zz * k[10] + k[14];
            tmp.w = x * k[3] + y * k[7] + zz * k[11] + k[15];
            p.q = tmp.q;
            z = p.z;
        }
        z = -z;
        if (D_0038C020 < z && D_0038C02C) {
            s = D_003940AC * (D_0038C020 / z - 1.0f) + 1.0f;
        } else {
            s = 1.0f;
        }
        func_001645F8(1, 0, 0);
        Reg((long)(int)(s * 255.99f) << 56, 0xA);
        func_001646D0(0);
        Close();
        ((unsigned short*)D_00394278)[1] |= D_00394280 & 0x3FF;
        D_00394280 += saved;
        node->m2C->m50 = 0;
    } else if (cur != node->m2C->m50 || (node->m2C->mC & 4)) {
        PutMat(cur, cur->Big());
        node->m2C->m50 = cur;
    }
    int mode = (flags & 2) ? 2 : (flags & 1);
    int m8 = mode | 8;
    if (flags & 8) {
        mode = m8;
    }
    Fog(mode, v);
    Draw(node, mode);
    if ((node->m2C->mC & 4) && D_0039427C) {
        func_001617A0(0);
    }
    if (!(flags & 4)) {
        return;
    }
    if (node->m1C & 0x100) {
        return;
    }
    Bind(D_003942FC);
    Tag(0x10000001, v.i[2]);
    Put(0);
    StRow((int)org[0] + (int)(node->pos[0] * 16.0f), (int)org[1] + (int)(node->pos[1] * 16.0f),
         (int)org[2] + (int)(node->pos[2] * 16.0f), 0);
    PutMat(D_003942FC->m50, true);
    mode = (flags & 2) ? 6 : ((flags & 1) ? 5 : 4);
    Fog(mode, v);
    Draw(node, mode);
}
