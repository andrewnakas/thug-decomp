// func_00269BC8: rail search; xori+bnel via named negated bool locals (blocked/fail); bbox mn tests written as mn.X() > r->m20.X().
typedef int qword __attribute__((mode(TI)));

struct Vec_00269BC8 {
    union {
        qword q;
        float c[4];
    };
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    float X() const { return c[0]; }
    float Y() const { return c[1]; }
    float Z() const { return c[2]; }
    Vec_00269BC8& operator=(const Vec_00269BC8& o)
    {
        q = o.q;
        return *this;
    }
    void operator-=(const Vec_00269BC8& o)
    {
        c[0] -= o[0];
        c[1] -= o[1];
        c[2] -= o[2];
        c[3] -= o[3];
    }
};

struct Line_00269BC8 {
    Vec_00269BC8 start;
    Vec_00269BC8 end;
};

struct Hit_00269BC8 {
    Vec_00269BC8 m0;
    Vec_00269BC8 m10;
    float m20;
    float m24;
    float m28;
    int m2C;
    void* m30;
};

struct Rail_00269BC8 {
    char pad0[0x10];
    Vec_00269BC8 m10;
    Vec_00269BC8 m20;
    Vec_00269BC8 m30;
    char pad40[0x10];
    Rail_00269BC8* m50;
    int m54;
    int m58;
    char pad5C[4];
};

struct Mgr_00269BC8;
extern "C" void func_00101F38(Line_00269BC8* l);
extern "C" void func_002682E0(Vec_00269BC8* a, Vec_00269BC8* b, Vec_00269BC8* mn, Vec_00269BC8* mx);
extern "C" int func_001CB7B8(Rail_00269BC8* r, int a);
extern "C" int func_00101F60(Line_00269BC8* a, Line_00269BC8* b, Vec_00269BC8* pa, Vec_00269BC8* pb, float* mua, float* mub, int clamp);
extern "C" void func_0026B1B0(Vec_00269BC8* out, Mgr_00269BC8* m, Rail_00269BC8* r);
extern "C" void func_0026B168(Vec_00269BC8* out, Mgr_00269BC8* m, Vec_00269BC8* p);
extern "C" bool func_0026A968(Vec_00269BC8* a, Vec_00269BC8* b);
extern "C" bool func_001C85E8(int ctx, Vec_00269BC8* a, Vec_00269BC8* b, Vec_00269BC8* c, Vec_00269BC8* d, Hit_00269BC8* hit, int e, float t);

static inline void Bounds(Vec_00269BC8& a, Vec_00269BC8& b, Vec_00269BC8& mn, Vec_00269BC8& mx, float r)
{
    func_002682E0(&a, &b, &mn, &mx);
    mn[0] -= r;
    mn[1] -= r;
    mn[2] -= r;
    mn.c[3] = 1.0f;
    mx[0] += r;
    mx[1] += r;
    mx[2] += r;
    mx.c[3] = 1.0f;
}

struct Mgr_00269BC8 {
    char pad0[0x50];
    Rail_00269BC8* m50;
    char pad54[8];
    int m5C;
    int Find(const Vec_00269BC8* a, const Vec_00269BC8* b, const Vec_00269BC8* dir, int ctx, Hit_00269BC8* out, float radius);
};

int Mgr_00269BC8::Find(const Vec_00269BC8* a, const Vec_00269BC8* b, const Vec_00269BC8* dir, int ctx, Hit_00269BC8* out, float radius)
{
    Line_00269BC8 l;
    func_00101F38(&l);
    float best = 1.000000004e+14f;
    l.start = *a;
    l.end = *b;
    Vec_00269BC8 mn;
    Vec_00269BC8 mx;
    float lim = radius;
    Bounds(l.start, l.end, mn, mx, lim);
    int found = 0;
    lim *= lim;
    for (int i = 0; i < m5C; i++) {
        Rail_00269BC8* r = &m50[i];
        if (r->m58 & 0x20) continue;
        if (r->m58 & 8) continue;
        if (!func_001CB7B8(r, 2)) continue;
        if (!r->m50) continue;
        if (mn.X() > r->m20.X()) continue;
        if (mx.X() < r->m10.X()) continue;
        if (mn.Z() > r->m20.Z()) continue;
        if (mx.Z() < r->m10.Z()) continue;
        if (r->m20.Y() < mn[1]) continue;
        if (mx[1] < r->m10.Y()) continue;
        Line_00269BC8 l2;
        func_00101F38(&l2);
        l2.start = r->m30;
        l2.end = r->m50->m30;
        Vec_00269BC8 p1;
        Vec_00269BC8 p2;
        float s;
        float t;
        if (!func_00101F60(&l, &l2, &p1, &p2, &s, &t, 1)) continue;
        Vec_00269BC8 d;
        d.c[0] = p2[0] - p1[0];
        d.c[1] = p2[1] - p1[1];
        d.c[2] = p2[2] - p1[2];
        d.c[3] = p2[3] - p1[3];
        if (lim < d[0] * d[0] + d[1] * d[1] + d[2] * d[2]) continue;
        float dot = (*dir)[0] * d[0] + (*dir)[1] * d[1] + (*dir)[2] * d[2];
        if (dot > 0.0f) {
            float k = dot * 0.6666666865f;
            Vec_00269BC8 proj;
            proj.c[0] = (*dir)[0] * k;
            proj.c[1] = (*dir)[1] * k;
            proj.c[2] = (*dir)[2] * k;
            proj.c[3] = (*dir)[3] * k;
            d -= proj;
        }
        float dist = d[0] * d[0] + d[1] * d[1] + d[2] * d[2];
        if (best < dist) continue;
        Vec_00269BC8 n1;
        Vec_00269BC8 n2;
        func_0026B1B0(&n1, this, r);
        func_0026B1B0(&n2, this, r->m50);
        bool blocked = !func_0026A968(&n1, &n2);
        if (blocked) continue;
        Hit_00269BC8 hit;
        hit.m30 = r;
        func_0026B1B0(&n1, this, r);
        func_0026B1B0(&n2, this, r->m50);
        Vec_00269BC8 v1;
        Vec_00269BC8 v2;
        func_0026B168(&v1, this, &p2);
        func_0026B168(&v2, this, &p1);
        bool fail = !func_001C85E8(ctx, &n1, &n2, &v1, &v2, &hit, 0, t);
        if (fail) continue;
        found = 1;
        best = dist;
        *out = hit;
    }
    return found;
}
