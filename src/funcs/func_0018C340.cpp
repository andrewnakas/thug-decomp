typedef int qword __attribute__((mode(TI)));

struct Vec_0018C340;

struct V_0018C340 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_0018C340 operator-() const;
    V_0018C340& operator+=(const V_0018C340& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        w += o.w;
        return *this;
    }
};

struct Vec_0018C340 : V_0018C340 {
    Vec_0018C340() {}
    Vec_0018C340(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_0018C340& operator=(const V_0018C340& o) { q = o.q; return *this; }
};

inline Vec_0018C340 V_0018C340::operator-() const
{
    return Vec_0018C340(-x, -y, -z, -w);
}

static inline Vec_0018C340 operator-(const V_0018C340& a, const V_0018C340& b)
{
    return Vec_0018C340(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

struct Mat_0018C340;
extern "C" Mat_0018C340* func_00100890(Mat_0018C340* out, float a);
extern "C" Mat_0018C340* func_00100928(Mat_0018C340* out, float a);
extern "C" Mat_0018C340* func_001009C0(Mat_0018C340* out, float a);
extern "C" void func_00323318(Mat_0018C340* d, Mat_0018C340* a, Mat_0018C340* b);
extern "C" void func_00323298(V_0018C340* d, Mat_0018C340* m, V_0018C340* v);

struct Mat_0018C340 {
    V_0018C340 r[4];
    void Ident()
    {
        r[0].x = 1.0f; r[0].y = 0.0f; r[0].z = 0.0f; r[0].w = 0.0f;
        r[1].x = 0.0f; r[1].y = 1.0f; r[1].z = 0.0f; r[1].w = 0.0f;
        r[2].x = 0.0f; r[2].y = 0.0f; r[2].z = 1.0f; r[2].w = 0.0f;
        r[3].x = 0.0f; r[3].y = 0.0f; r[3].z = 0.0f; r[3].w = 1.0f;
    }
    Mat_0018C340() {}
    const V_0018C340& operator[](int i) const { return r[i]; }
    Mat_0018C340(const Mat_0018C340& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
    void Flip()
    {
        r[2] = Vec_0018C340(-r[2].x, -r[2].y, -r[2].z, -r[2].w);
        r[0] = Vec_0018C340(-r[0].x, -r[0].y, -r[0].z, -r[0].w);
    }
    void RotX(float a)
    {
        Mat_0018C340 t;
        func_00323318(this, func_00100890(&t, a), this);
    }
    void RotY(float a)
    {
        Mat_0018C340 t;
        func_00323318(this, func_00100928(&t, a), this);
    }
    void RotZ(float a)
    {
        Mat_0018C340 t;
        func_00323318(this, func_001009C0(&t, a), this);
    }
};

static inline Vec_0018C340 Xform_0018C340(Mat_0018C340& m, Vec_0018C340& v)
{
    Vec_0018C340 r;
    func_00323298(&r, &m, &v);
    return r;
}

static inline Mat_0018C340 Mul_0018C340(const Mat_0018C340& a, Mat_0018C340& b)
{
    Mat_0018C340 r(a);
    func_00323318(&r, &b, &r);
    return r;
}

struct Model_0018C340 {
    char pad0[0x50];
    V_0018C340 m50;
    char pad60[0xC0 - 0x60];
    V_0018C340 mC0[3];
};

struct Angle_0018C340 {
    char pad[0xA8];
};

extern "C" float func_0018DD60(Angle_0018C340* a);

struct Obj_0018C340 {
    char pad0[0xC];
    Model_0018C340* mC;
    char pad10[0x30 - 0x10];
    V_0018C340 m30;
    Angle_0018C340 m40;
    int mE8;
    Angle_0018C340 mEC;
    int m194;
    Angle_0018C340 m198;
    int m240;
    int m244;
    char pad248[0x250 - 0x248];
    V_0018C340 m250;
    void GetMatrix(Mat_0018C340* out);
    void Offset(V_0018C340& p) { p.x += m250.x; p.y += m250.y; p.z += m250.z; p.w += m250.w; }
};

void Obj_0018C340::GetMatrix(Mat_0018C340* out)
{
    Model_0018C340* o = mC;
    out->r[0] = o->mC0[0];
    out->r[1] = o->mC0[1];
    out->r[2] = o->mC0[2];
    out->r[3] = Vec_0018C340(0.0f, 0.0f, 0.0f, 1.0f);
    if (m244) {
        out->Flip();
    }
    int ident = 1;
    float a;
    Mat_0018C340 rot;
    if (mE8) {
        a = func_0018DD60(&m40);
        if (a != 0.0f) {
            rot.Ident();
            ident = 0;
            rot.RotX(a * 0.0174532942f);
        }
    }
    if (m194) {
        a = func_0018DD60(&mEC);
        if (a != 0.0f) {
            if (ident) {
                rot.Ident();
            }
            ident = 0;
            rot.RotY(a * 0.0174532942f);
        }
    }
    if (m240) {
        a = func_0018DD60(&m198);
        if (a != 0.0f) {
            if (ident) {
                rot.Ident();
            }
            ident = 0;
            rot.RotZ(a * 0.0174532942f);
        }
    }
    Vec_0018C340 t(0.0f, 0.0f, 0.0f, 0.0f);
    if (!ident) {
        t = m30;
        if (t.x != 0.0f || t.y != 0.0f || t.z != 0.0f) {
            t = t - Xform_0018C340(rot, t);
            t = Xform_0018C340(*out, t);
        }
        *out = Mul_0018C340(rot, *out);
    }
    out->r[3] = mC->m50;
    V_0018C340& p = out->r[3];
    p += t;
    Offset(p);
    out->r[3].w = 1.0f;
}
