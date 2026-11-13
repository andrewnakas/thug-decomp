/* fuzzy: 93.4 */
/* blocked: global-alloc priority difference (flags 20/250 vs c 20/234 live length; forced = MATCH) (oracle) */
typedef int qword __attribute__((mode(TI)));

union Vec_0016DED8 {
    qword q;
    struct {
        float x, y, z, w;
    };
};

struct Ctx_0016DED8 {
    char pad[0x50];
    unsigned int m50;
    int m54;
};

struct Node_0016DED8 {
    Vec_0016DED8 m_sphere;
    float m10[3];
    unsigned int m_flags;
    Node_0016DED8* m_children;
    void* m_matrix;
    Node_0016DED8* m_next;
    int m2C;
    char pad30[0x11];
    signed char m41;
    char pad42[6];
    float m_lodDist;
    Node_0016DED8* m_lodNext;
};

struct Tab_0016DED8 {
    char pad[0x44];
    char* m44;
};

extern unsigned int D_00394098;
extern Tab_0016DED8* D_0038BCD4;
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
extern float D_003E1630[3];

extern "C" Ctx_0016DED8* func_00167600(Ctx_0016DED8* ctx);
extern "C" void func_001671A8(Ctx_0016DED8* ctx, void* m);
extern "C" Ctx_0016DED8* func_00167448(Ctx_0016DED8* ctx);
extern "C" void func_001677C0(Ctx_0016DED8* ctx, char* p);
extern "C" void func_00323298(Vec_0016DED8* out, void* m, Vec_0016DED8* in);
extern "C" int func_0016D6F8(Node_0016DED8* n, float* a, Node_0016DED8* b);
extern "C" int func_0016FBD0(void* v, int a, float r);
extern "C" void func_00168410(Ctx_0016DED8* ctx, Node_0016DED8* n);
extern "C" void func_00168560(Ctx_0016DED8* ctx, int id);
extern "C" void func_0016E3B0(Node_0016DED8* n, Ctx_0016DED8* ctx, unsigned int flags);
extern "C" void func_0016F050(Node_0016DED8* n, Ctx_0016DED8* ctx, unsigned int flags);

static inline void Xform_0016DED8(Vec_0016DED8& t, void* m)
{
    func_00323298(&t, m, &t);
}
static inline bool Outside_0016DED8(const Vec_0016DED8& v)
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

static inline bool Inside_0016DED8(const Vec_0016DED8& v)
{
    bool in = false;
    float z = v.z;
    float r = v.w;
    if (r < D_00394088 - z) {
        float a = -D_00394070 * z;
        float b = D_00394078 * v.x;
        if (r < a + b && r < a - b) {
            a = -D_00394074 * z;
            b = D_0039407C * v.y;
            if (r < a - b && r < a + b && r < z - D_0039408C)
                in = true;
        }
    }
    return in;
}

extern "C" void func_0016DED8(Node_0016DED8* n, Ctx_0016DED8* ctx, unsigned int flags)
{
    if (!(n->m_flags & 1))
        return;
    if (!(n->m_flags & D_00394098))
        return;
    Ctx_0016DED8* c;
    if (n->m_flags & 8) {
        flags |= 0x10;
        c = func_00167600(ctx);
        func_001671A8(c, n->m_matrix);
    } else {
        c = ctx;
    }
    if ((flags & 0x20) && n->m41 >= 0) {
        if (c == ctx)
            c = func_00167448(c);
        func_001677C0(c, D_0038BCD4->m44 + n->m41 * 64);
    }
    Vec_0016DED8 v;
    v = n->m_sphere;
    v.w = 1.0f;
    func_00323298(&v, c, &v);
    v.w = n->m_sphere.w;
    if (flags & 3) {
        if (Outside_0016DED8(v))
            return;
        if (Inside_0016DED8(v))
            flags &= ~3;
        if ((flags & 3) && !(flags & 0x10) && !(n->m_flags & 8)) {
            if (func_0016D6F8(n, n->m10, n))
                return;
        }
    }
    if (n->m_sphere.w > 1e20f)
        goto lod;
    {
        if (n->m_flags & 8) {
            Vec_0016DED8 t = n->m_sphere;
            t.w = 1.0f;
            Xform_0016DED8(t, n->m_matrix);
            if (func_0016FBD0(&t, 1, n->m_sphere.w))
                return;
        } else if (!(flags & 0x10)) {
            if (func_0016FBD0(n, 1, n->m_sphere.w))
                return;
        }
    }
lod:
    if (flags & 4) {
        if ((n->m_flags & 8)
            || n->m_sphere.x + n->m10[0] < D_003E1630[0] - 64.0f
            || n->m_sphere.x - n->m10[0] > D_003E1630[0] + 64.0f
            || n->m_sphere.z + n->m10[2] < D_003E1630[2] - 64.0f
            || n->m_sphere.z - n->m10[2] > D_003E1630[2] + 64.0f)
            flags &= ~4;
    }
    if (n->m_flags & 0x10) {
        if (c == ctx)
            c = func_00167448(c);
        func_00168410(c, n);
        flags |= 8;
    }
    if (n->m2C && n->m2C != ctx->m54) {
        if (c == ctx || (c->m50 & 1) == 0)
            c = func_00167600(ctx);
        func_00168560(c, n->m2C);
    }
    Node_0016DED8* ch = 0;
    float d = -v.z;
    for (Node_0016DED8* l = n; l; l = l->m_lodNext) {
        if (d < l->m_lodDist) {
            ch = l->m_children;
            break;
        }
    }
    if (flags & 0x10) {
        for (; ch; ch = ch->m_next)
            func_0016E3B0(ch, c, flags);
    } else {
        for (; ch; ch = ch->m_next)
            func_0016F050(ch, c, flags);
    }
}
