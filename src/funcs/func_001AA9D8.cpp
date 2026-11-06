typedef int qword __attribute__((mode(TI)));

static inline void CopyQ_001AA9D8(qword* d, const qword* s)
{
    *d = *s;
}

struct Row_001AA9D8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Row_001AA9D8& operator=(const Row_001AA9D8& o)
    {
        CopyQ_001AA9D8(&q, &o.q);
        return *this;
    }
};

struct Vec_001AA9D8 : public Row_001AA9D8 {
    Vec_001AA9D8() {}
    Vec_001AA9D8(const Row_001AA9D8& o) { q = o.q; }
    Vec_001AA9D8(float ax, float ay, float az)
    {
        x = ax;
        y = ay;
        z = az;
        w = 1.0f;
    }
    Vec_001AA9D8(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

inline Vec_001AA9D8 operator-(const Row_001AA9D8& a, const Row_001AA9D8& b)
{
    return Vec_001AA9D8(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

struct Mat_001AA9D8 {
    Row_001AA9D8 r[4];
    Mat_001AA9D8() {}
    const Row_001AA9D8& operator[](int i) const { return r[i]; }
    Mat_001AA9D8(const Mat_001AA9D8& o)
    {
        r[0].q = o[0].q;
        r[1].q = o[1].q;
        r[2].q = o[2].q;
        r[3].q = o[3].q;
    }
    Mat_001AA9D8& operator=(const Mat_001AA9D8& o)
    {
        r[0].q = o[0].q;
        r[1].q = o[1].q;
        r[2].q = o[2].q;
        r[3].q = o[3].q;
        return *this;
    }
    Mat_001AA9D8 operator*(Mat_001AA9D8& b);
    Vec_001AA9D8 Transform(const Vec_001AA9D8& v);
};

extern "C" void func_00323318(Mat_001AA9D8* d, Mat_001AA9D8* a, Mat_001AA9D8* b);
extern "C" void func_00323298(Vec_001AA9D8* out, Mat_001AA9D8* m, const Vec_001AA9D8* v);
extern "C" Mat_001AA9D8* func_00100928(Mat_001AA9D8* m, float angle);
extern "C" int func_001AA4A0(Row_001AA9D8* from, const Vec_001AA9D8& to);
extern "C" float sqrtf(float);
extern "C" int func_00103F28(const char* fmt, ...);
extern char D_00362878[];
extern void* D_0038FC78;

inline Vec_001AA9D8 Mat_001AA9D8::Transform(const Vec_001AA9D8& v)
{
    Vec_001AA9D8 r;
    func_00323298(&r, this, &v);
    return r;
}

inline Mat_001AA9D8 Mat_001AA9D8::operator*(Mat_001AA9D8& b)
{
    Mat_001AA9D8 t = *this;
    func_00323318(&t, &b, &t);
    return t;
}

struct Obj_001AA9D8 {
    char pad0[0x50];
    Row_001AA9D8 m_pos;
};

extern "C" Obj_001AA9D8* func_0022DD38(void* g);

struct C_001AA9D8 {
    char pad0[0xD0];
    Row_001AA9D8 m_home;
    int CanPlace(Mat_001AA9D8* src, Mat_001AA9D8* out, float angle, float height, float range);
};

int C_001AA9D8::CanPlace(Mat_001AA9D8* src, Mat_001AA9D8* out, float angle, float height, float range)
{
    *out = *src;
    *out = *func_00100928((Mat_001AA9D8*)0x70003FC0, angle * 0.01745329425f) * *out;
    Vec_001AA9D8 p = out->Transform(Vec_001AA9D8(0.0f, 10.0f, height + 15.0f));
    if (func_001AA4A0(&src->r[3], p))
        return 0;
    out->r[3] = out->Transform(Vec_001AA9D8(0.0f, 0.0f, height));
    Row_001AA9D8 pos = out->r[3];
    Obj_001AA9D8* sk = func_0022DD38(D_0038FC78);
    Vec_001AA9D8 d(pos.x - sk->m_pos.x, pos.y - sk->m_pos.y, pos.z - sk->m_pos.z, pos.w - sk->m_pos.w);
    float dist = sqrtf(d.x * d.x + d.y * d.y + d.z * d.z);
    if (dist < 30.0f) {
        func_00103F28(D_00362878, dist);
        return 0;
    }
    Vec_001AA9D8 h(pos.x - m_home.x, pos.y - m_home.y, pos.z - m_home.z, pos.w - m_home.w);
    h.y = 0.0f;
    if (range <= sqrtf(h.x * h.x + h.y * h.y + h.z * h.z))
        return 0;
    return 1;
}
