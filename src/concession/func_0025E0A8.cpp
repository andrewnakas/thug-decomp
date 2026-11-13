/* force: {"kind": "ga", "before": [1451, 1450]} */
// NEAR MISS (6 words, same size): only $s6/$s7 swapped for the hoisted %hi(D_004522D0)/%hi(D_004528D0). Proven: the pseudo order is set by loop2's else-branch RTL order (referencing D_004528D0 before D_004522D0 there flips it, but every such form moves the address computation). R2 (worker1): mechanism confirmed via -dG/-dl dumps: gcse hashes SYMBOL_REF by string CONTENT (decl order irrelevant), so the reaching reg for %hi(D_004528D0) is always created first (pseudo 1450 < 1451); global-alloc priority floor_log2(refs)*refs/live_len*10000 truncates to 169 for both (6 refs, 706 vs 708 insns) so the tie goes to the lower pseudo. The game needs D_004522D0 to have more weighted refs or a clearly shorter live range. Tried: shared inline helper for both quat bodies (size changes: m1C not reloaded), inverted if(!src), -1 != m1C, extern order swaps: none help. R3 (worker1): lreg dump: 1450 (D_004528D0) 6 refs/706 insns, 1451 (D_004522D0) 6 refs/708; refs are loop-depth weighted (flow: 1 set + 2 + 2). Since both are live through both loops, live lengths can only differ by the 2-insn set interval, so the game's 22D0 reg must have carried one extra (weighted) ref at RTL time that is gone in the final code. Tried: stores ordered m50 first (77 diffs), i<->call compare swap, m1C>=0 (size change), negation via repeated D_004522D0[i] (same 6) / D_004522D0[e->m1C] (m1C reloaded, size 0x670).
typedef int qword __attribute__((mode(TI)));

struct Row_0025E0A8 {
    union {
        qword q;
        float c[4];
    };
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
};
struct Vec_0025E0A8 : Row_0025E0A8 {
    Vec_0025E0A8() {}
    Vec_0025E0A8(float x, float y, float z, float w) { c[0] = x; c[1] = y; c[2] = z; c[3] = w; }
};
static inline Vec_0025E0A8 operator-(const Row_0025E0A8& a, const Row_0025E0A8& b) { return Vec_0025E0A8(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]); }
static inline Vec_0025E0A8 Cross(const Row_0025E0A8& a, const Row_0025E0A8& b)
{
    return Vec_0025E0A8(a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0], 0.0f);
}

extern "C" void func_003233B8(Row_0025E0A8* d, Row_0025E0A8* s);
struct Mat_0025E0A8 {
    Row_0025E0A8 r[4];
    Row_0025E0A8& operator[](int i) { return r[i]; }
    const Row_0025E0A8& operator[](int i) const { return r[i]; }
    Mat_0025E0A8() {}
    Mat_0025E0A8(const Mat_0025E0A8& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
    Mat_0025E0A8& operator=(const Mat_0025E0A8& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
        return *this;
    }
    void Ident()
    {
        r[0][0] = 1.0f; r[0][1] = 0.0f; r[0][2] = 0.0f; r[0][3] = 0.0f;
        r[1][0] = 0.0f; r[1][1] = 1.0f; r[1][2] = 0.0f; r[1][3] = 0.0f;
        r[2][0] = 0.0f; r[2][1] = 0.0f; r[2][2] = 1.0f; r[2][3] = 0.0f;
        r[3][0] = 0.0f; r[3][1] = 0.0f; r[3][2] = 0.0f; r[3][3] = 1.0f;
    }
    void FromQuat(const Row_0025E0A8& q, const Row_0025E0A8& t)
    {
        Row_0025E0A8 s, c, w;
        s[0] = q[0] * q[0];
        s[1] = q[1] * q[1];
        s[2] = q[2] * q[2];
        c[0] = q[1] * q[2];
        c[1] = q[2] * q[0];
        c[2] = q[0] * q[1];
        w[0] = q[3] * q[0];
        w[1] = q[3] * q[1];
        w[2] = q[3] * q[2];
        r[0][0] = 1.0f - (s[1] + s[2]) * 2.0f;
        r[0][1] = (c[2] + w[2]) * 2.0f;
        r[0][2] = (c[1] - w[1]) * 2.0f;
        r[0][3] = 0.0f;
        r[1][0] = (c[2] - w[2]) * 2.0f;
        r[1][1] = 1.0f - (s[0] + s[2]) * 2.0f;
        r[1][2] = (c[0] + w[0]) * 2.0f;
        r[1][3] = 0.0f;
        r[2][0] = (c[1] + w[1]) * 2.0f;
        r[2][1] = (c[0] - w[0]) * 2.0f;
        r[2][2] = 1.0f - (s[0] + s[1]) * 2.0f;
        r[2][3] = 0.0f;
        r[3] = t;
        r[3][3] = 1.0f;
    }
};


static inline Vec_0025E0A8 operator+(const Row_0025E0A8& a, const Row_0025E0A8& b) { return Vec_0025E0A8(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]); }
extern "C" void func_00323298(Row_0025E0A8* out, const Mat_0025E0A8* m, const Row_0025E0A8* v);
static inline Vec_0025E0A8 operator*(const Mat_0025E0A8& m, const Row_0025E0A8& v)
{
    Vec_0025E0A8 r;
    func_00323298(&r, &m, &v);
    return r;
}
extern "C" void func_00323318(Mat_0025E0A8* d, const Mat_0025E0A8* a, Mat_0025E0A8* b);

struct Box_0025E0A8 {
    Vec_0025E0A8 a;
    Vec_0025E0A8 b;
    Box_0025E0A8(float bx, float by, float bz, float ax, float ay, float az) : a(ax, ay, az, 1.0f), b(bx, by, bz, 1.0f) {}
};

struct Node_0025E0A8 {
    char pad0[0x50];
    Row_0025E0A8 m50;
    char pad60[0x10];
    Mat_0025E0A8 m70;
    char padB0[0x10];
    Mat_0025E0A8 mC0;
};

struct Elem_0025E0A8 {
    unsigned int m0;
    char pad4[0x10];
    Node_0025E0A8* m14;
    Node_0025E0A8* m18;
    int m1C;
};

extern Vec_0025E0A8 D_004522D0[];
extern Vec_0025E0A8 D_004528D0[];
extern "C" void func_00144D58(void* p, Row_0025E0A8* q, Row_0025E0A8* t, float f);
extern "C" int func_00144D90(void* p);
extern "C" unsigned int func_00144DD0(void* p, int i);
extern "C" Node_0025E0A8* func_00184D70(unsigned int id);
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" void* func_0019EBD0(void* p);
extern "C" void func_0011EAF0(void* p, unsigned int name, Row_0025E0A8* v);
extern "C" void func_0011E7B8(void* p, unsigned int name, Mat_0025E0A8* m);
extern "C" void func_0025DF58(Node_0025E0A8* n);
extern "C" int func_001E53A0(unsigned int name, int a);
extern "C" void func_00123610(Mat_0025E0A8* m, Row_0025E0A8* p, Box_0025E0A8* b, int a, int c, int d, unsigned int color);

struct Obj_0025E0A8 {
    char pad0[0x10];
    void* m10;
    char pad14[0x40];
    Elem_0025E0A8 m54[64];
    int m854;
    char pad858[0xB70 - 0x858];
    float mB70;
    void Update();
};

void Obj_0025E0A8::Update()
{
    if (!m10) return;
    func_00144D58(m10, D_004522D0, D_004528D0, mB70);
    for (int i = 0; i < func_00144D90(m10); i++) {
        unsigned int id = func_00144DD0(m10, i);
        int found = 0;
        for (int j = m854 - 1; j >= 0; j--) {
            if (m54[j].m0 == id) found = 1;
        }
        if (found) continue;
        Node_0025E0A8* n = func_00184D70(id);
        if (!n) continue;
        Mat_0025E0A8 m;
        Vec_0025E0A8 one(0.0f, 0.0f, 0.0f, 1.0f);
        Row_0025E0A8& q = D_004522D0[i];
        q[0] = -q[0];
        q[1] = -q[1];
        q[2] = -q[2];
        m.FromQuat(q, one);
        n->m70 = m;
        n->mC0 = m;
        n->m50 = D_004528D0[i];
    }
    for (int j = m854 - 1; j >= 0; j--) {
        Elem_0025E0A8* e = &m54[j];
        Node_0025E0A8* src = e->m18;
        Node_0025E0A8* dst = e->m14;
        if (src) {
            void* b = func_0019EBD0(func_00185578(src, 0x222756D5));
            Vec_0025E0A8 off;
            func_0011EAF0(b, 0x5A0E0860, &off);
            dst->m50 = src->m50 + src->mC0 * off;
            dst->m50[3] = 1.0f;
            Mat_0025E0A8 m;
            func_0011E7B8(b, 0x5A0E0860, &m);
            Mat_0025E0A8 w = src->mC0;
            w[3] = src->m50;
            w[0][3] = 0.0f;
            w[1][3] = 0.0f;
            w[2][3] = 0.0f;
            func_00323318(&m, &w, &m);
            m[3] = Vec_0025E0A8(0.0f, 0.0f, 0.0f, 1.0f);
            dst->m70 = m;
            dst->mC0 = m;
            func_0025DF58(dst);
        } else if (e->m1C != -1) {
            Mat_0025E0A8 m;
            Vec_0025E0A8 one(0.0f, 0.0f, 0.0f, 1.0f);
            Row_0025E0A8& q = D_004522D0[e->m1C];
            q[0] = -q[0];
            q[1] = -q[1];
            q[2] = -q[2];
            m.FromQuat(q, one);
            dst->m70 = m;
            dst->mC0 = m;
            dst->m50 = D_004528D0[e->m1C];
            func_0025DF58(dst);
        }
        if (func_001E53A0(0x5ECC0073, 0)) {
            Box_0025E0A8 box(-1.0f, -1.0f, -1.0f, 1.0f, 10.0f, 1.0f);
            func_00123610(&dst->mC0, &dst->m50, &box, 0, 1, 0, 0xFF0000C8);
        }
    }
}
