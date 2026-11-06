/* fuzzy: 84.9 */
typedef int qword __attribute__((mode(TI)));

struct V_001B4A08 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
};

struct Vec_001B4A08 : V_001B4A08 {
    Vec_001B4A08() {}
    Vec_001B4A08(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_001B4A08(const V_001B4A08& o) { q = o.q; }
    Vec_001B4A08(const Vec_001B4A08& o) { q = o.q; }
    Vec_001B4A08& operator=(const V_001B4A08& o) { q = o.q; return *this; }
};

static inline Vec_001B4A08 operator+(const V_001B4A08& a, const V_001B4A08& b)
{
    return Vec_001B4A08(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

static inline Vec_001B4A08 operator-(const V_001B4A08& a)
{
    return Vec_001B4A08(-a.x, -a.y, -a.z, -a.w);
}

static inline Vec_001B4A08 operator*(const V_001B4A08& a, float k)
{
    return Vec_001B4A08(a.x * k, a.y * k, a.z * k, a.w * k);
}

static inline Vec_001B4A08 Cross_001B4A08(const Vec_001B4A08& a, const Vec_001B4A08& b)
{
    return Vec_001B4A08(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0.0f);
}

struct Mat_001B4A08 {
    V_001B4A08 r[4];
};

struct Model_001B4A08 {
    char pad0[0x50];
    V_001B4A08 m_pos;
    char pad60[0x70 - 0x60];
    V_001B4A08 m70;
    V_001B4A08 m80;
    V_001B4A08 m90;
    char padA0[0xC0 - 0xA0];
    Mat_001B4A08 mC0;
};

struct Comp_001B4A08 {
    char pad0[0x50];
    Vec_001B4A08 m_verts[3];
};

extern "C" Comp_001B4A08* func_00185578(Model_001B4A08* m, unsigned int id);
extern "C" void func_003233B8(V_001B4A08* d, V_001B4A08* s);

struct Obj_001B4A08 {
    char pad0[0xC];
    Model_001B4A08* mC;
    char pad10[0xC4 - 0x10];
    float mC4;
    float mC8;
    void Snap();
};

extern "C" int func_001B4828(Obj_001B4A08* self, Vec_001B4A08* start, Vec_001B4A08* end,
                             Vec_001B4A08* hit, Vec_001B4A08* verts);

void Obj_001B4A08::Snap()
{
    Vec_001B4A08 start;
    Vec_001B4A08 end;
    Comp_001B4A08* c = func_00185578(mC, 0x0A015E17);
    mC->m70 = Vec_001B4A08(mC->m80.y * mC->m90.z - mC->m80.z * mC->m90.y,
                           mC->m80.z * mC->m90.x - mC->m80.x * mC->m90.z,
                           mC->m80.x * mC->m90.y - mC->m80.y * mC->m90.x, 0.0f);
    func_003233B8(&mC->m70, &mC->m70);
    Mat_001B4A08 mat = mC->mC0;
    start = mC->m_pos + mat.r[1] * mC4;
    end = mC->m_pos + -mat.r[1] * mC8;
    Vec_001B4A08 hit;
    if (func_001B4828(this, &start, &end, &hit, c->m_verts)) mC->m_pos = hit;
}
