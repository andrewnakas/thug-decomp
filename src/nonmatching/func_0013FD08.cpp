/* fuzzy: 99.3 */
typedef int qword __attribute__((mode(TI)));

struct Vec_0013FD08 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    void Set(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

struct Mat_0013FD08;
extern "C" Mat_0013FD08* func_00100890(Mat_0013FD08* out, float a);
extern "C" Mat_0013FD08* func_00100928(Mat_0013FD08* out, float a);
extern "C" Mat_0013FD08* func_001009C0(Mat_0013FD08* out, float a);
extern "C" void func_00323318(Mat_0013FD08* d, Mat_0013FD08* a, Mat_0013FD08* b);

struct Mat_0013FD08 {
    Vec_0013FD08 r[4];
    Vec_0013FD08& operator[](int i) { return r[i]; }
    void RotateX(float a)
    {
        Mat_0013FD08 t;
        func_00323318(this, func_00100890(&t, a), this);
    }
    void RotateY(float a)
    {
        Mat_0013FD08 t;
        func_00323318(this, func_00100928(&t, a), this);
    }
    void RotateZ(float a)
    {
        Mat_0013FD08 t;
        func_00323318(this, func_001009C0(&t, a), this);
    }
};

struct Part_0013FD08 {
    float px, py, pz;
    float c0, c1, c2;
    float d0, d1, d2, d3;
    int m28;
    float m2C;
};

extern "C" void func_003233B8(Vec_0013FD08* d, Vec_0013FD08* s);
extern "C" Vec_0013FD08 func_00323298(Mat_0013FD08* m, Vec_0013FD08* v);
extern "C" int func_00335048();
extern "C" float fabsf(float);
extern "C" float sqrtf(float);

static inline Vec_0013FD08 Xform(Mat_0013FD08* m, Vec_0013FD08* v)
{
    Vec_0013FD08 r = func_00323298(m, v);
    return r;
}

static inline float RandRange(float lo, float hi, int r)
{
    float t = (hi - lo) * 4.656613e-10f;
    return t * (float)r + lo;
}

static inline void Cross(Vec_0013FD08& r, const Vec_0013FD08& a, const Vec_0013FD08& b)
{
    r.w = 0.0f;
    r.x = a.y * b.z - a.z * b.y;
    r.y = a.z * b.x - a.x * b.z;
    r.z = a.x * b.y - a.y * b.x;
}

class B_0013FD08 {
public:
    int m0;
    int m4;
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void SetChannel(int i, int j, float x, float y, float z);
    virtual void v15();
    virtual int NumChannels();
};

class C_0013FD08 : public B_0013FD08 {
public:
    char m_pad[0x164 - 0xC];
    int m164;
    int m168;
    float m16C;
    float m170;
    float m174;
    float m178;
    float m17C;
    int m180;
    int m184;
    float m188, m18C, m190;
    float m194, m198, m19C, m1A0;
    float m1A4, m1A8;
    float m1AC, m1B0, m1B4;
    float m1B8, m1BC, m1C0;
    int m1C4;
    int m1C8;
    Part_0013FD08* m1CC;
    char m_pad2[0x1E8 - 0x1D0];
    int m1E8;
    void Emit(int n);
};

void C_0013FD08::Emit(int n)
{
    if (m1C8) return;
    int start = m168;
    if (start + n <= m164) {
        m168 = start + n;
    } else {
        m168 = m164;
    }
    Mat_0013FD08 m;
    int end = m168;
    m[3].Set(0.0f, 0.0f, 0.0f, 1.0f);
    m[2].Set(m1AC, m1B0, m1B4, 1.0f);
    func_003233B8(&m.r[2], &m.r[2]);
    Vec_0013FD08 up;
    up.Set(0.0f, 1.0f, 0.0f, 1.0f);
    if (fabsf(m.r[2].y) > fabsf(m.r[2].x) && fabsf(m.r[2].y) > fabsf(m.r[2].z)) {
        up.Set(0.0f, 0.0f, 1.0f, 1.0f);
    }
    {
        Vec_0013FD08 c;
        Cross(c, up, m.r[2]);
        m.r[0] = c;
    }
    func_003233B8(&m.r[0], &m.r[0]);
    {
        Vec_0013FD08 c;
        Cross(c, m.r[0], m.r[2]);
        m.r[1] = c;
    }
    func_003233B8(&m.r[1], &m.r[1]);
    m.RotateX(m1B8 * 0.01745329425f);
    m.RotateY(m1BC * 0.01745329425f);
    m.RotateZ(m1C0 * 0.01745329425f);
    for (int i = start; i < end; i++) {
        if (m1E8) {
            float a = (float)func_00335048() * 4.656613e-10f * 2.0f - 1.0f;
            float b = (float)func_00335048() * 4.656613e-10f * 2.0f - 1.0f;
            Vec_0013FD08 dir;
            float ax = a * 0.7853981853f;
            float x = ax * m17C;
            float ay = b * 0.7853981853f;
            float y = ay * m17C;
            dir.Set(x, y, 1.0f - (x * x + y * y), 1.0f);
            int r = func_00335048();
            float s = RandRange(m16C, m170, r);
            dir.x *= s;
            dir.y *= s;
            dir.z *= s;
            if (m180) {
                a = (float)func_00335048() * 4.656613e-10f * 2.0f - 1.0f;
                b = (float)func_00335048() * 4.656613e-10f * 2.0f - 1.0f;
            }
            if (m184) {
                float inv = 1.0f / sqrtf(a * a + b * b);
                a *= inv * fabsf(a);
                b *= inv * fabsf(b);
            }
            Vec_0013FD08 vel;
            vel.Set(m174 * a, m178 * b, 0.0f, 1.0f);
            m1CC[i].c0 = m188;
            m1CC[i].c1 = m18C;
            m1CC[i].c2 = m190;
            m1CC[i].d0 = m194;
            m1CC[i].d1 = m198;
            m1CC[i].d2 = m19C;
            m1CC[i].d3 = m1A0;
            m1CC[i].m28 = 0;
            r = func_00335048();
            m1CC[i].m2C = RandRange(m1A4, m1A8, r);
            Vec_0013FD08 p;
            p = Xform(&m, &dir);
            m1CC[i].px = p.x;
            m1CC[i].py = p.y;
            m1CC[i].pz = p.z;
            p = Xform(&m, &vel);
            for (int j = 0; j < NumChannels(); j++) {
                SetChannel(i, j, p.x, p.y, p.z);
            }
        } else {
            m1CC[i].d0 = m194;
            m1CC[i].d1 = m198;
            m1CC[i].d2 = m19C;
            m1CC[i].d3 = m1A0;
            m1CC[i].m28 = 0;
            int r = func_00335048();
            m1CC[i].m2C = RandRange(m1A4, m1A8, r);
            for (int j = 0; j < NumChannels(); j++) {
                SetChannel(i, j, 0.0f, 0.0f, 0.0f);
            }
        }
    }
}
