/* fuzzy: 94.2 */
typedef int qword __attribute__((mode(TI)));

struct Vec_0019CD30 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_0019CD30() {}
    Vec_0019CD30(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_0019CD30 Sub(const Vec_0019CD30& o) const { return Vec_0019CD30(x - o.x, y - o.y, z - o.z, w - o.w); }
};

struct Seg_0019CD30 {
    Vec_0019CD30 a;
    Vec_0019CD30 b;
};

struct Obj_0019CD30;

extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" void func_001B80F8(void* p);
extern "C" void func_0019D0D0(Obj_0019CD30* o);
extern "C" void func_0019D2D0(Obj_0019CD30* o);
extern "C" void func_0019D498(Obj_0019CD30* o);
extern "C" float func_003412F0(float x);
extern "C" float func_0010FAB8();
extern "C" float func_00341068(float a);
extern "C" float func_00340F60(float a);
extern "C" void func_003233B8(Vec_0019CD30* d, Vec_0019CD30* s);
extern "C" void func_0018B200(Vec_0019CD30* a, Vec_0019CD30* b, const Vec_0019CD30& c, const Vec_0019CD30& d, int e, int f);

static inline Vec_0019CD30 operator*(const Vec_0019CD30& v, float s)
{
    return Vec_0019CD30(v.x * s, v.y * s, v.z * s, v.w * s);
}

static inline Vec_0019CD30 operator-(const Vec_0019CD30& a, const Vec_0019CD30& b)
{
    return Vec_0019CD30(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

struct Obj_0019CD30 {
    char pad0[0xC];
    void* mC;
    char pad10[0x30 - 0x10];
    Vec_0019CD30 m30;
    Vec_0019CD30 m40;
    Vec_0019CD30 m50;
    Vec_0019CD30 m60;
    char pad70[0x80 - 0x70];
    Vec_0019CD30 m80;
    char pad90[0xA4 - 0x90];
    float mA4;
    char padA8[0xAC - 0xA8];
    float mAC;
    Vec_0019CD30 Ofs() const { return Vec_0019CD30(m80.x * mA4, m80.y * mA4, m80.z * mA4, m80.w * mA4); }
    Vec_0019CD30 Back(const Vec_0019CD30& o) const
    {
        return Vec_0019CD30(m50.x - o.x, m50.y - o.y, m50.z - o.z, m50.w - o.w);
    }
    Seg_0019CD30 Ray() const
    {
        Seg_0019CD30 s;
        s.b = Ofs();
        s.a = Vec_0019CD30(m50.x - s.b.x, m50.y - s.b.y, m50.z - s.b.z, m50.w - s.b.w);
        return s;
    }
    bool Side() const
    {
        Vec_0019CD30 c(m30.y * m40.z - m30.z * m40.y, m30.z * m40.x - m30.x * m40.z,
                       m30.x * m40.y - m30.y * m40.x, 0.0f);
        return c.y > 0.0f;
    }
    void Update();
};

static inline float Clamp_0019CD30(float v, float lo, float hi)
{
    if (v > hi) {
        v = hi;
    }
    if (v < lo) {
        v = lo;
    }
    return v;
}

void Obj_0019CD30::Update()
{
    Vec_0019CD30* f = &m30;
    func_001B80F8(func_00185578(mC, 0xC4E311FA));
    func_0019D0D0(this);
    float d = Clamp_0019CD30(m30.x * m40.x + m30.y * m40.y + m30.z * m40.z, -1.0f, 1.0f);
    float ang = func_003412F0(d);
    if (ang > 1.570796371f) {
        ang = 3.141592741f - ang;
    }
    bool pos = Side();
    float r = mAC * ang * func_0010FAB8();
    if (r > ang) {
        r = ang;
    }
    ang = r;
    if (!pos) {
        ang = -ang;
    }
    float s = func_00341068(ang);
    float co = func_00340F60(ang);
    float x = m30.x;
    float z = f->z;
    m30.x = co * x + s * z;
    f->z = -s * x + co * z;
    func_003233B8(f, f);
    func_0019D2D0(this);
    func_0018B200(&m50, &m60, Back(Ofs()), Back(Ofs()), 0, 0);
    func_0019D498(this);
}
