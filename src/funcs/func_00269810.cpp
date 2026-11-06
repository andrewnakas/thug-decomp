typedef int qword_00269810 __attribute__((mode(TI)));

struct Vec_00269810 {
    union {
        qword_00269810 q;
        float c[4];
    };
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    float X() const { return c[0]; }
    float Y() const { return c[1]; }
    float Z() const { return c[2]; }
    Vec_00269810& operator=(const Vec_00269810& o)
    {
        q = o.q;
        return *this;
    }
};

struct Line_00269810 {
    Vec_00269810 start;
    Vec_00269810 end;
};

struct Hit_00269810 {
    Vec_00269810 m0;
    Vec_00269810 m10;
    float m20;
    Hit_00269810& operator=(const Hit_00269810& o)
    {
        m0 = o.m0;
        m10 = o.m10;
        m20 = o.m20;
        return *this;
    }
};

struct Rot_00269810 {
    float m[4][4];
};

struct Rail_00269810 {
    char pad0[0x10];
    Vec_00269810 m10;
    Vec_00269810 m20;
    Vec_00269810 m30;
    char pad40[0x10];
    Rail_00269810* m50;
    int m54;
    int m58;
    char pad5C[4];
};

struct Mgr_00269810;
extern "C" void func_00101F38(Line_00269810* l);
extern "C" void func_002682E0(Vec_00269810* a, Vec_00269810* b, Vec_00269810* mn, Vec_00269810* mx);
extern "C" float func_001E5318(unsigned int name, int def);
extern "C" int func_001CB7B8(Rail_00269810* r, int a);
extern "C" int func_00101F60(Line_00269810* a, Line_00269810* b, Vec_00269810* pa, Vec_00269810* pb, float* mua, float* mub, int clamp);
extern "C" void func_0026B208(Rot_00269810* out, Mgr_00269810* m, Rail_00269810* r);
extern "C" bool func_001CC368(int ctx, Vec_00269810* p0, Vec_00269810* p1, Rot_00269810* rot, Vec_00269810* p, Hit_00269810* hit, float t);

static inline void Expand(Vec_00269810& mn, Vec_00269810& mx, float r)
{
    mn[0] -= r;
    mn[1] -= r;
    mn[2] -= r;
    mn.c[3] = 1.0f;
    mx[0] += r;
    mx[1] += r;
    mx[2] += r;
    mx.c[3] = 1.0f;
}

struct Mgr_00269810 {
    char pad0[0x50];
    Rail_00269810* m50;
    char pad54[8];
    int m5C;
    bool Find(const Vec_00269810* a, const Vec_00269810* b, int ctx, Hit_00269810* out, Rail_00269810** outRail);
};

bool Mgr_00269810::Find(const Vec_00269810* a, const Vec_00269810* b, int ctx, Hit_00269810* out, Rail_00269810** outRail)
{
    *outRail = 0;
    Line_00269810 l;
    func_00101F38(&l);
    float best = 1.000000004e+14f;
    l.start = *a;
    l.end = *b;
    Vec_00269810 mn;
    Vec_00269810 mx;
    func_002682E0(&l.start, &l.end, &mn, &mx);
    float lim = func_001E5318(0x30CE7F2C, 0);
    Expand(mn, mx, lim);
    lim *= lim;
    for (int i = 0; i < m5C; i++) {
        Rail_00269810* r = &m50[i];
        if (!(r->m58 & 0x20)) continue;
        if (!func_001CB7B8(r, 2)) continue;
        if (!r->m50) continue;
        if (mn.X() > r->m20.X()) continue;
        if (mx.X() < r->m10.X()) continue;
        if (mn.Z() > r->m20.Z()) continue;
        if (mx.Z() < r->m10.Z()) continue;
        if (r->m20.Y() < mn[1]) continue;
        if (mx[1] < r->m10.Y()) continue;
        Line_00269810 l2;
        func_00101F38(&l2);
        l2.start = r->m30;
        l2.end = r->m50->m30;
        Vec_00269810 p1;
        Vec_00269810 p2;
        float s;
        float t;
        if (!func_00101F60(&l, &l2, &p1, &p2, &s, &t, 1)) continue;
        Vec_00269810 d;
        d.c[0] = p2[0] - p1[0];
        d.c[1] = p2[1] - p1[1];
        d.c[2] = p2[2] - p1[2];
        d.c[3] = p2[3] - p1[3];
        float dist = d[0] * d[0] + d[1] * d[1] + d[2] * d[2];
        if (lim < dist) continue;
        if (best < dist) continue;
        Hit_00269810 hit;
        Rot_00269810 rot;
        Rail_00269810* n = r->m50;
        Vec_00269810* to = &n->m30;
        if (r->m30.c[1] < n->m30.c[1]) {
            func_0026B208(&rot, this, r);
            bool fail = !func_001CC368(ctx, &r->m30, to, &rot, &p2, &hit, t);
            if (fail) continue;
            *outRail = r;
        } else {
            func_0026B208(&rot, this, n);
            bool fail = !func_001CC368(ctx, to, &r->m30, &rot, &p2, &hit, 1.0f - t);
            if (fail) continue;
            *outRail = r->m50;
        }
        best = dist;
        *out = hit;
    }
    return *outRail != 0;
}
