typedef int qword __attribute__((mode(TI)));

union Vec_0016FFE8 {
    qword q;
    struct {
        float x, y, z, w;
    };
    float& operator[](int i) { return (&x)[i]; }
};

struct Ctx_0016FFE8 {
    char pad[0x50];
    unsigned int m50;
};

struct Tex_0016FFE8 {
    char pad[0x28];
    int used[1];
    char pad2c[0x24];
    Ctx_0016FFE8* m_last;
};

struct Node_0016FFE8 {
    Vec_0016FFE8 m_sphere;
    float m10[3];
    unsigned int m_flags;
    union {
        Node_0016FFE8* m_children;
        unsigned int m_data;
    };
    union {
        unsigned int m_tag;
        struct {
            unsigned short m_tagLo;
            unsigned short m_count;
        };
    };
    Node_0016FFE8* m_next;
    Tex_0016FFE8* m_tex;
    int pad30;
    int m34;
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
extern Tex_0016FFE8* D_0039427C;
extern int D_00394094;
extern unsigned int* D_00394274;
extern unsigned int* D_00394278;
extern unsigned int D_00394280;
extern int D_0038C02C;

extern "C" void func_00323298(Vec_0016FFE8* out, Ctx_0016FFE8* m, Vec_0016FFE8* in);
extern "C" Ctx_0016FFE8* func_00167448(Ctx_0016FFE8* ctx);
extern "C" Ctx_0016FFE8* func_00167600(Ctx_0016FFE8* ctx);
extern "C" void func_00168410(Ctx_0016FFE8* ctx, Node_0016FFE8* n);
extern "C" void func_001681B8(Ctx_0016FFE8* ctx, int a, unsigned int b);
extern "C" void func_001617A0(Tex_0016FFE8* t);
extern "C" void func_00160F18(int a, int b);

static inline bool Outside_0016FFE8(const Vec_0016FFE8& v)
{
    bool out = false;
    if (v.w < v.z - D_00394088
        || v.w < D_00394058 * v.z - D_00394060 * v.x
        || v.w < D_00394058 * v.z + D_00394060 * v.x
        || v.w < D_0039405C * v.z + D_00394064 * v.y
        || v.w < D_0039405C * v.z - D_00394064 * v.y
        || v.w < D_0039408C - v.z)
        out = true;
    return out;
}

static inline bool Inside_0016FFE8(const Vec_0016FFE8& v)
{
    bool in = false;
    if (v.w < D_00394088 - v.z
        && v.w < -D_00394070 * v.z + D_00394078 * v.x
        && v.w < -D_00394070 * v.z - D_00394078 * v.x
        && v.w < -D_00394074 * v.z - D_0039407C * v.y
        && v.w < -D_00394074 * v.z + D_0039407C * v.y
        && v.w < v.z - D_0039408C)
        in = true;
    return in;
}

static inline void Tag_0016FFE8(unsigned int a, unsigned int b)
{
    unsigned int* p = D_00394274;
    D_00394278 = p;
    p[0] = a;
    p[1] = b;
    D_00394274 = p + 2;
}

static inline void Add_0016FFE8(unsigned int a)
{
    unsigned int* p = D_00394274;
    *p = a;
    D_00394274 = p + 1;
}

static inline void AddPos_0016FFE8(float x, float y, float z)
{
    int* q = (int*)D_00394274;
    q[0] = (int)x;
    q[1] = (int)y;
    q[2] = (int)z;
    q[3] = 0;
    D_00394274 = (unsigned int*)(q + 4);
}

extern "C" void func_0016FFE8(Node_0016FFE8* n, Ctx_0016FFE8* ctx, unsigned int flags)
{
    if (!(n->m_flags & 1))
        return;
    Ctx_0016FFE8* c = ctx;
    if (flags & 3) {
        Vec_0016FFE8 v;
        v = n->m_sphere;
        v.w = 1.0f;
        func_00323298(&v, c, &v);
        v.w = n->m_sphere.w;
        if (Outside_0016FFE8(v))
            return;
        if (Inside_0016FFE8(v))
            flags &= ~3;
    }
    if (n->m_flags & 0x10) {
        flags |= 8;
        c = func_00167448(ctx);
        func_00168410(c, n);
    }
    if (n->m_flags & 2) {
        if (n->m_flags & 0x200) {
            if (c == ctx)
                c = func_00167600(c);
            func_001681B8(c, n->m34, n->m_flags & 0x10000);
        }
        Tex_0016FFE8* t = n->m_tex;
        if (D_0039427C != t)
            func_001617A0(t);
        n->m_tex->used[D_00394094] = 1;
        Tag_0016FFE8(0x10000001, 0);
        Add_0016FFE8(0);
        float x = n->m_sphere[0] * 16.0f;
        float y = n->m_sphere[1] * 16.0f;
        float z = n->m_sphere[2] * 16.0f;
        Add_0016FFE8(0x30000000);
        AddPos_0016FFE8(x, y, z);
        if (c != n->m_tex->m_last) {
            int b = (c->m50 & 1) ? 1 : 0;
            int k = b ? 0x12 : 7;
            Tag_0016FFE8(k | ((k - 1) << 16) | 0x30000000, (unsigned int)&c->m50);
            Add_0016FFE8((unsigned short)D_00394280 | 0x3000000);
            Add_0016FFE8(0x2000000);
            D_00394280 += k - 1;
            n->m_tex->m_last = c;
        }
        unsigned int mode;
        if (!(flags & 2)) {
            if (flags & 1)
                mode = 1;
            else
                mode = 0;
        } else {
            mode = 2;
        }
        unsigned int f8 = flags & 8;
        f8 |= mode;
        mode = f8;
        if (D_0038C02C)
            mode |= 0x10;
        Tag_0016FFE8(n->m_tag, n->m_data);
        Add_0016FFE8((unsigned short)D_00394280 | 0x3000000);
        Add_0016FFE8((mode & 0xFFFF) | 0x4000000);
        D_00394280 += n->m_count;
        if (n->m_flags & 0x80000) {
            func_00160F18(6, 2);
            D_00394274 -= 2;
            Add_0016FFE8(0x13000000);
            Add_0016FFE8(0);
        }
    } else {
        for (Node_0016FFE8* ch = n->m_children; ch; ch = ch->m_next)
            func_0016FFE8(ch, c, flags);
    }
}
