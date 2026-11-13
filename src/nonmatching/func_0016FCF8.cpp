/* fuzzy: 92.8 */
typedef int qword_0016FCF8 __attribute__((mode(TI)));

struct V_0016FCF8 {
    union {
        qword_0016FCF8 q;
        struct {
            float x, y, z, w;
        };
        unsigned int i[4];
    };
    float operator[](int k) const { return (&x)[k]; }
};

struct M_0016FCF8;
extern "C" void func_00323318(M_0016FCF8* out, void* m, M_0016FCF8* in);

struct M_0016FCF8 {
    V_0016FCF8 r[4];
    M_0016FCF8& operator=(const M_0016FCF8& o)
    {
        r[0] = o.r[0];
        r[1] = o.r[1];
        r[2] = o.r[2];
        r[3] = o.r[3];
        return *this;
    }
};

struct Mat_0016FCF8 {
    M_0016FCF8 m;
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

struct Ctx_0016FCF8 {
    char pad0[0xC];
    unsigned int mC;
    char pad10[0x18];
    int m28[10];
    Mat_0016FCF8* m50;
};

struct Cnt_0016FCF8 {
    char pad0[0x40];
    int m40;
};

struct Node_0016FCF8 {
    V_0016FCF8 pos;
    float m10, m14, m18;
    unsigned int m1C;
    unsigned int m20;
    unsigned int m24;
    char pad28[0x4];
    Ctx_0016FCF8* m2C;
    char pad30[0x4];
    union {
        int m34;
        struct {
            short m34s;
            short m36s;
        };
    };
    char pad38[0xC];
    Cnt_0016FCF8* m44;
};

extern float D_003940AC;
extern float D_0038C020;
extern int D_0038C02C;
extern int D_00394094;
extern Ctx_0016FCF8* D_0039427C;
extern Ctx_0016FCF8* D_003942FC;
extern unsigned char* D_00394274;
extern unsigned char* D_00394278;
extern unsigned int D_00394280;
extern V_0016FCF8 D_003E1630;
extern char D_003E1080[];
extern char D_003E1240[];
struct Cam_0016FCF8 {
    char pad0[0x30];
    V_0016FCF8 m_pos;
    V_0016FCF8* GetPos() { return &m_pos; }
};
extern Cam_0016FCF8 D_003E11C0;
extern char D_003E1560[];
extern char D_003E1570[];
extern char D_420[];

extern "C" void func_00323298(V_0016FCF8* out, void* m, V_0016FCF8* v);
extern "C" void func_003233B8(V_0016FCF8* d, V_0016FCF8* s);
extern "C" void func_00323318(M_0016FCF8* out, void* m, M_0016FCF8* in);
extern "C" Mat_0016FCF8* func_00167448(Mat_0016FCF8* m);
extern "C" Mat_0016FCF8* func_00167600(Mat_0016FCF8* m);
extern "C" void func_00168410(Mat_0016FCF8* m, Node_0016FCF8* n);
extern "C" void func_001681B8(Mat_0016FCF8* m, int a, int b);
extern "C" void func_00168580(Mat_0016FCF8* m, int a, int b);
extern "C" void func_00171EB0(Node_0016FCF8* n);
extern "C" void func_001617A0(Ctx_0016FCF8* c);
extern "C" void func_00164E48(int a, unsigned int b);
extern "C" void func_00164F08(void* v);
extern "C" void* func_00168558(Mat_0016FCF8* m);
extern "C" void func_00164EB8(int a);
extern "C" void func_001645F8(int a, int b, int c);
extern "C" void func_001646D0(int a);
extern "C" void func_00160F18(int a, int b);

static inline void Normalize(V_0016FCF8& v)
{
    func_003233B8(&v, &v);
}

static inline void Bind(Ctx_0016FCF8* c)
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

static inline void PutMat(Mat_0016FCF8* c, bool full)
{
    int n = full ? 18 : 7;
    Tag((n | ((n - 1) << 16)) | 0x30000000, (unsigned int)&c->m50);
    Put((unsigned short)D_00394280 | 0x03000000);
    Put(0x02000000);
    D_00394280 += n - 1;
}

static inline void Fog(int& mode, float radius, float depth)
{
    if (D_0038C02C && D_0038C020 < radius - depth) {
        mode |= 0x10;
    }
}

static inline void Draw(Node_0016FCF8* n, int mode)
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

static inline void PutM(const M_0016FCF8& m)
{
    unsigned int* d = (unsigned int*)D_00394274;
    unsigned int* s = (unsigned int*)&m;
    for (int i = 0; i < 16; i++) {
        *d++ = *s++;
    }
    D_00394274 = (unsigned char*)d;
}

extern "C" int func_0016FBD0(Node_0016FCF8* node, int count, float radius);

// Single VU0 macro-mode operations.
static inline unsigned int GetVF5()
{
    unsigned int r;
    __asm__ __volatile__("qmfc2.ni %0, $vf5" : "=r"(r));
    return r;
}

// Plain draw of one mesh: culls its bounding sphere (func_0016FBD0 leaves the view depth in VU0 vf5.x), binds
// its material and appends the DMA/VIF packet: depth, fixed-point position (STROW), the matrix context when it
// changed, and the mesh data with its MSCAL.
extern "C" void func_0016FCF8(Node_0016FCF8* node, Mat_0016FCF8* m)
{
    if (func_0016FBD0(node, 1, node->pos.w)) {
        return;
    }
    Bind(node->m2C);
    node->m2C->m28[D_00394094] = 1;
    if (node->m44) {
        node->m44->m40++;
    }
    // volatile: stands in for the original memory-operand asm that type-puns the VU0 depth value (qmfc2 store, lwc1 reload).
    volatile union {
        unsigned int i;
        float f;
    } depth;
    depth.i = GetVF5();
    Tag(0x10000001, depth.i);
    Put(0);
    StRow((int)m->t[0] + (int)(node->pos[0] * 16.0f), (int)m->t[1] + (int)(node->pos[1] * 16.0f),
         (int)m->t[2] + (int)(node->pos[2] * 16.0f), 0);
    if (m != node->m2C->m50 || (node->m2C->mC & 4)) {
        PutMat(m, m->Big());
        node->m2C->m50 = m;
    }
    Tag(node->m24, node->m20);
    Put((unsigned short)D_00394280 | 0x03000000);
    // game reads the depth unconditionally (lwc1 $f1, 0($sp) in the beqz delay slot at 0x0016FF18)
    float d = depth.f;
    if (D_0038C02C && D_0038C020 < node->pos.w - d) {
        Put(0x04000010);
    } else {
        Put(0x04000000);
    }
    D_00394280 += node->m24 >> 16;
    if (node->m1C & 0x80000) {
        func_00160F18(6, 2);
        D_00394274 -= 8;
        Put(0x13000000);
        Put(0);
    }
    if ((node->m2C->mC & 4) && D_0039427C) {
        func_001617A0(0);
    }
}
