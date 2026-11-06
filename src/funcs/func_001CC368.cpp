typedef int qword __attribute__((mode(TI)));

struct Vec_001CC368 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_001CC368() {}
    Vec_001CC368(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_001CC368& operator-=(const Vec_001CC368& o) { x -= o.x; y -= o.y; z -= o.z; w -= o.w; return *this; }
};

static inline Vec_001CC368 operator-(const Vec_001CC368& a, const Vec_001CC368& b)
{
    return Vec_001CC368(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

static inline Vec_001CC368 operator+(const Vec_001CC368& a, const Vec_001CC368& b)
{
    return Vec_001CC368(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

static inline Vec_001CC368 operator*(const Vec_001CC368& a, float s)
{
    return Vec_001CC368(a.x * s, a.y * s, a.z * s, a.w * s);
}

extern "C" void func_00183CB8(void* p, void* pp);
extern "C" void func_003233B8(Vec_001CC368* dst, Vec_001CC368* src);
extern "C" void* func_001E5548(unsigned int id, int flags);
extern "C" int func_001E7EB0(void* params, unsigned int id, float* out, int req);
extern "C" float func_00340F60(float a);

struct Coll_001CC368 {
    Vec_001CC368 start;
    Vec_001CC368 end;
    void SetLine(const Vec_001CC368& a, const Vec_001CC368& b) { start = a; end = b; }
    char pad20[0xC0 - 0x20];
    struct Ref {
        void* p;
        ~Ref()
        {
            if (p) {
                func_00183CB8(p, this);
                p = 0;
            }
        }
    } mC0;
    char padC4[0xE0 - 0xC4];
};

extern "C" Coll_001CC368* func_00209240(Coll_001CC368* c);
extern "C" int func_002093E8(Coll_001CC368* c, int a, int b);

static inline float GetF_001CC368(unsigned int id)
{
    float v;
    func_001E7EB0(func_001E5548(0x6775E538, 0), id, &v, 1);
    return v;
}

struct Surf_001CC368 {
    char pad0[0x20];
    Vec_001CC368 n;
};

struct Out_001CC368 {
    Vec_001CC368 pos;
    Vec_001CC368 n;
    float f;
};

struct Timer_001CC368 {
    int m0;
    int m4;
    unsigned int m8;
};

struct Sub_001CC368 {
    char pad0[0x5B0];
    char* m5B0;
};

extern "C" unsigned int func_0010FC30();

struct Obj_001CC368 {
    char pad0[0x30];
    Vec_001CC368 m30;
    char pad40[0xA44 - 0x40];
    Sub_001CC368* mA44;
    bool Probe(const Vec_001CC368& p, const Vec_001CC368& q, Surf_001CC368* s, const Vec_001CC368& r, Out_001CC368* out, float f);
};

bool Obj_001CC368::Probe(const Vec_001CC368& p, const Vec_001CC368& q, Surf_001CC368* s, const Vec_001CC368& r, Out_001CC368* out, float f)
{
    Vec_001CC368 d = q - p;
    func_003233B8(&d, &d);
    if (d.y < 0.995f) {
        return false;
    }
    if (r.y < p.y + d.y * GetF_001CC368(0x5296E3FD)) {
        return false;
    }
    if (q.y - d.y * GetF_001CC368(0x76BF49E0) < r.y) {
        return false;
    }
    float m = GetF_001CC368(0x35B3BBDA);
    out->pos = r - Vec_001CC368(s->n.x * m, s->n.y * m, s->n.z * m, s->n.w * m);
    Coll_001CC368 c;
    func_00209240(&c);
    c.start = m30;
    c.end = out->pos;
    if (func_002093E8(&c, 1, 0)) {
        return false;
    }
    out->n = s->n;
    out->f = f;
    Timer_001CC368* t = (Timer_001CC368*)(mA44->m5B0 + 0xE4);
    if (t->m4 != 1) {
        t->m4 = 1;
        t->m8 = func_0010FC30();
    }
    return true;
}
