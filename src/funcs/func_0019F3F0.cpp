extern "C" float sqrtf(float);

typedef int qword __attribute__((mode(TI)));

struct Row_0019F3F0 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    float& operator[](int i) { return (&x)[i]; }
    const float& operator[](int i) const { return (&x)[i]; }
    Row_0019F3F0& operator+=(const Row_0019F3F0& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        w += o.w;
        return *this;
    }
};

struct Vec_0019F3F0 : Row_0019F3F0 {
    Vec_0019F3F0() {}
    Vec_0019F3F0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_0019F3F0(const Row_0019F3F0& o) { q = o.q; }
};

static inline Vec_0019F3F0 operator-(const Row_0019F3F0& v)
{
    return Vec_0019F3F0(-v.x, -v.y, -v.z, -v.w);
}

static inline Vec_0019F3F0 operator*(const Row_0019F3F0& v, float s)
{
    return Vec_0019F3F0(v.x * s, v.y * s, v.z * s, v.w * s);
}

static inline Vec_0019F3F0 operator+(const Row_0019F3F0& a, const Row_0019F3F0& b)
{
    return Vec_0019F3F0(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}

struct Mat_0019F3F0 {
    Row_0019F3F0 r[4];
    Row_0019F3F0& operator[](int i) { return r[i]; }
    const Row_0019F3F0& operator[](int i) const { return r[i]; }
    Mat_0019F3F0& operator=(const Mat_0019F3F0& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
        return *this;
    }
    Mat_0019F3F0& operator*=(const Mat_0019F3F0& o);
    Vec_0019F3F0 Rotate(const Row_0019F3F0& v) const
    {
        Vec_0019F3F0 o;
        o.x = v.x * r[0].x + v.y * r[1].x + v.z * r[2].x;
        o.y = v.x * r[0].y + v.y * r[1].y + v.z * r[2].y;
        o.z = v.x * r[0].z + v.y * r[1].z + v.z * r[2].z;
        o.w = v.w;
        return o;
    }
};

extern "C" Mat_0019F3F0* func_00323318(Mat_0019F3F0* out, const Mat_0019F3F0* a, const Mat_0019F3F0* b);

inline Mat_0019F3F0& Mat_0019F3F0::operator*=(const Mat_0019F3F0& o)
{
    func_00323318(this, &o, this);
    return *this;
}

struct Body_0019F3F0 {
    char pad0[0x50];
    Row_0019F3F0 m50;
    char pad60[0x70 - 0x60];
    Mat_0019F3F0 m70;
    Row_0019F3F0 mB0;
    Vec_0019F3F0 Vel(float s) const { return Vec_0019F3F0(mB0.x * s, mB0.y * s, mB0.z * s, mB0.w * s); }
};

extern "C" void* func_00185578(void* o, unsigned int name);
extern "C" void* func_0019EBD0(void* o);
extern "C" Mat_0019F3F0* func_0011E7B8(void* skel, int bone, Mat_0019F3F0* out);
extern "C" int func_001E7528(void* s, unsigned int name, Row_0019F3F0* v);
extern "C" void func_00119228(Row_0019F3F0* q, float w);
extern "C" void func_00119230(Row_0019F3F0* q, float x, float y, float z);
extern "C" void func_00186D60(void* mgr, void* a, void* s, int f);
extern void* D_0038C608;

static inline void SetVec_0019F3F0(void* s, unsigned int name, Vec_0019F3F0 v)
{
    func_001E7528(s, name, &v);
}

struct Obj_0019F3F0 {
    char pad0[0xC];
    Body_0019F3F0* mC;
    void Spawn(int bone, void* type, void* params, const Row_0019F3F0* a, const Row_0019F3F0* b,
               Row_0019F3F0* off, float scale);
};

void Obj_0019F3F0::Spawn(int bone, void* type, void* params, const Row_0019F3F0* a, const Row_0019F3F0* b,
                         Row_0019F3F0* off, float scale)
{
    Mat_0019F3F0 m;
    func_0011E7B8(func_0019EBD0(func_00185578(mC, 0x222756D5)), bone, &m);
    Mat_0019F3F0 bm;
    bm = mC->m70;
    bm[3] = mC->m50;
    Row_0019F3F0 t = m[1];
    m[1] = m[2];
    m[2] = -t;
    off->w = 0.0f;
    bm.r[0].w = 0.0f;
    bm.r[1].w = 0.0f;
    bm.r[2].w = 0.0f;
    m[3] += *off;
    m *= bm;
    Row_0019F3F0 r;
    r = m[3];
    func_001E7528(params, 0x7F261953, &r);
    float tr = m[0][0] + m[1][1] + m[2][2];
    float sq;
    if (tr > 0.0f) {
        sq = sqrtf(tr + 1.0f);
        float hw = sq * 0.5f;
        sq = 0.5f / sq;
        func_00119228(&r, hw);
        func_00119230(&r, (m[2][1] - m[1][2]) * sq, (m[0][2] - m[2][0]) * sq, (m[1][0] - m[0][1]) * sq);
    } else {
        int i = 0;
        if (m[0][0] < m[1][1])
            i = 1;
        if (m[i][i] < m[2][2])
            i = 2;
        int j = (i + 1) % 3;
        int k = (j + 1) % 3;
        sq = sqrtf(m[i][i] - (m[j][j] + m[k][k]) + 1.0f);
        r[i] = sq * 0.5f;
        sq = 0.5f / sq;
        r[j] = (m[j][i] + m[i][j]) * sq;
        r[k] = (m[k][i] + m[i][k]) * sq;
        r[3] = (m[k][j] - m[j][k]) * sq;
    }
    if (r.w > 0.0f) {
        SetVec_0019F3F0(params, 0xC97F3AA9, r);
    } else {
        SetVec_0019F3F0(params, 0xC97F3AA9, Vec_0019F3F0(-r.x, -r.y, -r.z, -r.w));
    }
    Vec_0019F3F0 v = mC->Vel(scale) + mC->m70.Rotate(*a);
    SetVec_0019F3F0(params, 0x0C4C809E, v);
    Vec_0019F3F0 u = mC->m70.Rotate(*b);
    SetVec_0019F3F0(params, 0xFB1A83B2, u);
    func_00186D60(D_0038C608, type, params, 1);
}
