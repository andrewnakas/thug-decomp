typedef int qword __attribute__((mode(TI)));

struct Vec_001CBE60 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_001CBE60() {}
    Vec_001CBE60(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_001CBE60& operator-=(const Vec_001CBE60& o) { x -= o.x; y -= o.y; z -= o.z; w -= o.w; return *this; }
};

static inline Vec_001CBE60 operator-(const Vec_001CBE60& a, const Vec_001CBE60& b)
{
    return Vec_001CBE60(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

static inline Vec_001CBE60 operator+(const Vec_001CBE60& a, const Vec_001CBE60& b)
{
    return Vec_001CBE60(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

static inline Vec_001CBE60 operator*(const Vec_001CBE60& a, float s)
{
    return Vec_001CBE60(a.x * s, a.y * s, a.z * s, a.w * s);
}

extern "C" void func_00183CB8(void* p, void* pp);
extern "C" void func_003233B8(Vec_001CBE60* dst, Vec_001CBE60* src);
extern "C" void* func_001E5548(unsigned int id, int flags);
extern "C" int func_001E7EB0(void* params, unsigned int id, float* out, int req);
extern "C" float func_00340F60(float a);

struct Coll_001CBE60 {
    Vec_001CBE60 start;
    Vec_001CBE60 end;
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

extern "C" void func_00209240(Coll_001CBE60* c);
extern "C" int func_002093E8(Coll_001CBE60* c, int a, int b);

static inline float GetF_001CBE60(unsigned int id)
{
    float v;
    func_001E7EB0(func_001E5548(0x6775E538, 0), id, &v, 1);
    return v;
}

struct Surf_001CBE60 {
    char pad0[0x20];
    Vec_001CBE60 n;
};

struct Obj_001CBE60 {
    char pad0[0x30];
    Vec_001CBE60 m30;
    char pad40[0x20];
    Vec_001CBE60 m60;
    bool Probe(const Vec_001CBE60& p, const Vec_001CBE60& q, Surf_001CBE60* s, Vec_001CBE60* out);
};

bool Obj_001CBE60::Probe(const Vec_001CBE60& p, const Vec_001CBE60& q, Surf_001CBE60* s, Vec_001CBE60* out)
{
    if (p.y > q.y) {
        return false;
    }
    Vec_001CBE60 d = q - p;
    func_003233B8(&d, &d);
    if (d.y < 0.995f) {
        return false;
    }
    float dot = m60.x * s->n.x + m60.y * s->n.y + m60.z * s->n.z;
    if (dot < func_00340F60(GetF_001CBE60(0x456F216D) * 0.0174532942f)) {
        return false;
    }
    out[0] = p + d * GetF_001CBE60(0x5296E3FD);
    float m = GetF_001CBE60(0x35B3BBDA);
    out[0] -= Vec_001CBE60(s->n.x * m, s->n.y * m, s->n.z * m, s->n.w * m);
    Coll_001CBE60 c;
    func_00209240(&c);
    c.start = m30;
    c.end = out[0] - Vec_001CBE60(s->n.x * 6.0f, s->n.y * 6.0f, s->n.z * 6.0f, s->n.w * 6.0f);
    if (func_002093E8(&c, 1, 0)) {
        return false;
    }
    out[1] = s->n;
    return true;
}
