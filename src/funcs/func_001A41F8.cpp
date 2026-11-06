typedef int qword_001A41F8 __attribute__((mode(TI)));
struct Mat_001A41F8;
union Vec_001A41F8 {
    qword_001A41F8 q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    Vec_001A41F8 Rotate(const Mat_001A41F8& m) const;
    Vec_001A41F8() {}
    Vec_001A41F8(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    Vec_001A41F8& operator=(const Vec_001A41F8& o)
    {
        q = o.q;
        return *this;
    }
};

struct Mat_001A41F8 {
    Vec_001A41F8 r0, r1, r2, r3;
    const Vec_001A41F8& R0() const { return r0; }
    const Vec_001A41F8& R1() const { return r1; }
    const Vec_001A41F8& R2() const { return r2; }
    const Vec_001A41F8& R3() const { return r3; }
    Mat_001A41F8& operator=(const Mat_001A41F8& o)
    {
        r0.q = o.R0().q;
        r1.q = o.R1().q;
        r2.q = o.R2().q;
        r3.q = o.R3().q;
        return *this;
    }
    Mat_001A41F8& operator*=(const Mat_001A41F8& b);
    Mat_001A41F8() {}
    Mat_001A41F8(const Mat_001A41F8& o)
    {
        r0.q = o.R0().q;
        r1.q = o.R1().q;
        r2.q = o.R2().q;
        r3.q = o.R3().q;
    }
};

extern "C" void func_00323298(Vec_001A41F8* out, const Mat_001A41F8* m, const Vec_001A41F8* in);
extern "C" void func_00323318(Mat_001A41F8* out, const Mat_001A41F8* m, const Mat_001A41F8* in);

inline Vec_001A41F8 Vec_001A41F8::Rotate(const Mat_001A41F8& m) const
{
    Vec_001A41F8 r;
    func_00323298(&r, &m, this);
    return r;
}

inline Mat_001A41F8& Mat_001A41F8::operator*=(const Mat_001A41F8& b)
{
    func_00323318(this, &b, this);
    return *this;
}

static inline Vec_001A41F8 operator+(const Vec_001A41F8& a, const Vec_001A41F8& b)
{
    return Vec_001A41F8(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}

static inline Mat_001A41F8 operator*(const Mat_001A41F8& a, const Mat_001A41F8& b)
{
    Mat_001A41F8 r;
    r = a;
    r *= b;
    return r;
}

struct Model_001A41F8 {
    char pad[0x10];
    Mat_001A41F8 m10;
};

struct Pos_001A41F8 {
    char pad[0x50];
    Vec_001A41F8 m50;
    char pad2[0xC0 - 0x60];
    Mat_001A41F8 mC0;
};

struct Target_001A41F8 {
    int m0, m4, m8;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void SetPos(const Vec_001A41F8& v);
    virtual void SetMatrix(const Mat_001A41F8& m);
};

struct Comp_001A41F8 {
    char pad[0x260];
    void* m260;
};

extern "C" void* func_00185578(void* p, unsigned int id);
extern "C" Model_001A41F8* func_0013EF50(void* p);
extern "C" Target_001A41F8* func_001A41C8(void* p);

struct Obj_001A41F8 {
    int m0, m4, m8;
    Pos_001A41F8* mC;
    void Update();
};

void Obj_001A41F8::Update()
{
    Target_001A41F8* t = func_001A41C8(this);
    if (!t) return;
    Model_001A41F8* m = 0;
    Comp_001A41F8* c = (Comp_001A41F8*)func_00185578(mC, 0x286A8D26);
    if (c) {
        m = func_0013EF50(c->m260);
    }
    if (m) {
        Vec_001A41F8 off = m->m10.r3;
        off[3] = 0.0f;
        off.Rotate(m->m10);
        t->SetPos(mC->m50 + off);
        t->SetMatrix(m->m10 * mC->mC0);
    } else {
        t->SetPos(mC->m50);
        t->SetMatrix(mC->mC0);
    }
}
