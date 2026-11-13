/* fuzzy: 94.6 */
extern "C" float sqrtf(float);

typedef int qword __attribute__((mode(TI)));

struct Row_002692B0 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
};

struct Vec_002692B0 : Row_002692B0 {
    Vec_002692B0() {}
    Vec_002692B0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

static inline Vec_002692B0 operator*(const Row_002692B0& v, float s)
{
    return Vec_002692B0(v.x * s, v.y * s, v.z * s, v.w * s);
}

static inline Vec_002692B0 operator+(const Row_002692B0& a, const Row_002692B0& b)
{
    return Vec_002692B0(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

static inline Vec_002692B0 operator-(const Row_002692B0& a, const Row_002692B0& b)
{
    return Vec_002692B0(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

extern "C" void func_00183CB8(int obj, int* ref);

static inline void Release_002692B0(int* ref)
{
    if (*ref) {
        func_00183CB8(*ref, ref);
        *ref = 0;
    }
}

struct Feeler_002692B0 {
    Vec_002692B0 m_start;
    Vec_002692B0 m_end;
    char pad20[0xC0 - 0x20];
    int m_ref;
    char padC4[0xE0 - 0xC4];
    ~Feeler_002692B0()
    {
        Release_002692B0(&m_ref);
    }
};

static inline void Swap_002692B0(Vec_002692B0& a, Vec_002692B0& b)
{
    Vec_002692B0 t = b;
    b = a;
    a = t;
}

struct Other_002692B0 {
    char pad0[0x30];
    Vec_002692B0 m_pos;
};

extern "C" Feeler_002692B0* func_00209240(Feeler_002692B0* f);
extern "C" void func_00209380(Feeler_002692B0* f, const Vec_002692B0& a, const Vec_002692B0& b);
extern "C" int func_002093E8(Feeler_002692B0* f, int a, int b);

static inline bool Hit_002692B0(Feeler_002692B0* f)
{
    bool h = true;
    if (!func_002093E8(f, 1, 0))
        h = false;
    return h;
}

struct Obj_002692B0 {
    char pad0[0x30];
    Vec_002692B0 m_pos;
    char pad40[0x50 - 0x40];
    Other_002692B0* m_other;
    int Check(Vec_002692B0* dir);
};

int Obj_002692B0::Check(Vec_002692B0* dir)
{
    Vec_002692B0 a = m_pos;
    Vec_002692B0 b = m_other->m_pos;
    Feeler_002692B0 f;
    func_00209240(&f);
    Vec_002692B0 mid = (a + b) * 0.5f;
    mid = a + (mid - a) * 0.5f;
    Vec_002692B0 d = b - a;
    d.y = 0.0f;
    float len = sqrtf(d.x * d.x + d.z * d.z);
    mid.y -= 6.0f;
    if (d.y < len) {
        float s = 4.0f / len;
        d.x *= s;
        d.z *= s;
    }
    float t = d.x;
    d.x = d.z;
    d.z = -t;
    int r = 0;
    bool hit1 = false;
    func_00209380(&f, mid + d, mid - d);
    if (func_002093E8(&f, 1, 0))
        hit1 = true;
    Swap_002692B0(f.m_start, f.m_end);
    bool hit2 = Hit_002692B0(&f);
    if (hit1 && !hit2)
        r = -1;
    else if (hit2)
        r = hit1 ? 0 : 1;
    if (r) {
        Vec_002692B0 v = b - a;
        if (dir->x * v.x + dir->y * v.y + dir->z * v.z < 0.0f)
            r = -r;
    }
    return r;
}
