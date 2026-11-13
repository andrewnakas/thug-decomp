typedef int qword __attribute__((mode(TI)));

struct Vec_001C1308 {
    union {
        struct { float x, y, z, w; };
        float c[4];
        qword q;
    };
    const float& operator[](int i) const { return c[i]; }
    Vec_001C1308() {}
    Vec_001C1308(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    float LengthSqr() const { return x * x + y * y + z * z; }
    Vec_001C1308& operator-=(const Vec_001C1308& o) { x -= o.x; y -= o.y; z -= o.z; w -= o.w; return *this; }
};

static inline Vec_001C1308 operator-(const Vec_001C1308& a, const Vec_001C1308& b)
{
    return Vec_001C1308(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}

static inline Vec_001C1308 operator+(const Vec_001C1308& a, const Vec_001C1308& b)
{
    return Vec_001C1308(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}

static inline Vec_001C1308 operator*(const Vec_001C1308& a, float s)
{
    return Vec_001C1308(a[0] * s, a[1] * s, a[2] * s, a[3] * s);
}

extern "C" void func_00183CB8(void* p, void* pp);
extern "C" void func_003233B8(Vec_001C1308* dst, Vec_001C1308* src);
extern "C" void* func_001E5548(unsigned int id, int flags);
extern "C" int func_001E7EB0(void* params, unsigned int id, float* out, int req);
extern "C" float func_00340F60(float a);

struct Coll_001C1308 {
    Vec_001C1308 start;
    Vec_001C1308 end;
    void SetLine(const Vec_001C1308& a, const Vec_001C1308& b) { start = a; end = b; }
    char pad20[0x90 - 0x20];
    float m90;
    char pad94[0xA0 - 0x94];
    Vec_001C1308 point;
    char padB0[0xC0 - 0xB0];
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

extern "C" Coll_001C1308* func_00209240(Coll_001C1308* c);
extern "C" int func_002093E8(Coll_001C1308* c, int a, int b);

static inline float GetF_001C1308(unsigned int id)
{
    float v;
    func_001E7EB0(func_001E5548(0x6775E538, 0), id, &v, 1);
    return v;
}

extern "C" float fabsf(float);
extern "C" Vec_001C1308* func_001016A8(Vec_001C1308* v, const Vec_001C1308* n);

struct Obj_001C1308 {
    char pad0[0x30];
    Vec_001C1308 m30;
    Vec_001C1308 m40;
    char pad50[0x60 - 0x50];
    Vec_001C1308 m60;
    char pad70[0x98 - 0x70];
    float m98;
    char pad9C[0xB0 - 0x9C];
    float mB0;
    char padB4[0x960 - 0xB4];
    float m960;
    int m964;
    char pad968[0xA50 - 0x968];
    Vec_001C1308 mA50;
    void Update();
};

void Obj_001C1308::Update()
{
    Vec_001C1308 d = m60;
    func_001016A8(&d, &mA50);
    float y = d.y;
    if (y < 0.0f) y = 0.0f;
    d.y = y;
    func_003233B8(&d, &d);
    Coll_001C1308 c;
    func_00209240(&c);
    c.start = m30;
    c.start.y += 0.5f;
    c.end = m30 + d * GetF_001C1308(0x11EDCC52);
    c.end.y += 0.5f;
    if (func_002093E8(&c, 1, 0)) {
        float frac = c.m90;
        c.start = c.end = c.point + d * 0.5f;
        c.start.y = m30.y + GetF_001C1308(0xCEE3A3E1);
        if (func_002093E8(&c, 1, 0)) {
            float t = (1.0f - frac) * (c.point.y - m30.y);
            if (fabsf(m960) < 0.01f && mB0 == 0.0f) {
                float l = m40.LengthSqr();
                float th = GetF_001C1308(0x227D72EE);
                if (l < th * th)
                    goto done;
            }
            m960 = m960 + (t - m960) * (GetF_001C1308(0x856A80D3) * m98);
        done:
            m964 = 1;
        }
    }
}
