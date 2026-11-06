typedef int qword __attribute__((mode(TI)));

struct Row_001A47B0 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Row_001A47B0& operator+=(const Row_001A47B0& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        w += o.w;
        return *this;
    }
};

struct Vec_001A47B0 : Row_001A47B0 {
    Vec_001A47B0() {}
    Vec_001A47B0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

static inline Vec_001A47B0 operator*(const Row_001A47B0& a, float s)
{
    return Vec_001A47B0(a.x * s, a.y * s, a.z * s, a.w * s);
}

struct Mat_001A47B0;
extern "C" void func_00323318(Mat_001A47B0* d, const Mat_001A47B0* a, const Mat_001A47B0* b);
extern "C" void func_00323298(Vec_001A47B0* d, const Mat_001A47B0* m, const Row_001A47B0* v);

struct Mat_001A47B0 {
    Row_001A47B0 r[4];
    Mat_001A47B0() {}
    const Row_001A47B0& operator[](int i) const { return r[i]; }
    Mat_001A47B0(const Mat_001A47B0& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
    Mat_001A47B0& operator=(const Mat_001A47B0& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
        return *this;
    }
    Mat_001A47B0 operator*(const Mat_001A47B0& b) const
    {
        Mat_001A47B0 t = *this;
        func_00323318(&t, &b, &t);
        return t;
    }
    Vec_001A47B0 operator*(const Row_001A47B0& v) const
    {
        Vec_001A47B0 o;
        func_00323298(&o, this, &v);
        return o;
    }
};

struct Obj_001A47B0 {
    char pad0[0x18];
    unsigned int m18;
    char pad1C[0x50 - 0x1C];
    Row_001A47B0 m50;
    char pad60[0x70 - 0x60];
    Mat_001A47B0 m70;
    Row_001A47B0 mB0;
    Mat_001A47B0 mC0;
    Vec_001A47B0 Offset(const Row_001A47B0& t) const
    {
        return Vec_001A47B0(m50.x + t.x, m50.y + t.y, m50.z + t.z, m50.w + t.w);
    }
    Vec_001A47B0 To(const Row_001A47B0& p) const
    {
        return Vec_001A47B0(p.x - m50.x, p.y - m50.y, p.z - m50.z, p.w - m50.w);
    }
};

struct Comp_001A47B0 {
    char pad0[0x260];
    void* m260;
    char pad264[0x288 - 0x264];
    int m288;
};

struct Ctl_001A47B0 {
    char pad0[0xC];
    Obj_001A47B0* m_obj;
    char pad10[0x24 - 0x10];
    int m24;
    char pad28[0x30 - 0x28];
    Row_001A47B0 m30;
    float m40;
    float m44;
    float m48;
    float m4C;
    float m50;
    int m54;
    int m58;
    int m5C;
    void Update();
};

extern "C" Obj_001A47B0* func_001A4750(Ctl_001A47B0* self);
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" void* func_0019EBD0(void* p);
extern "C" int func_0011E7B8(void* p, int id, Mat_001A47B0* m);
extern "C" void func_0018C340(void* p, Mat_001A47B0* m);
extern "C" unsigned int func_0010FC30();
extern "C" float func_00341068(float a);
extern "C" void func_0013CD08(void* p, Mat_001A47B0* m, int a, void* b);

static inline bool Check(Comp_001A47B0* c, Obj_001A47B0* o)
{
    if (c->m288)
        return true;
    return o->m18 < 8;
}

void Ctl_001A47B0::Update()
{
    Mat_001A47B0 saved = m_obj->m70;
    Obj_001A47B0* src = func_001A4750(this);
    if (!src)
        return;
    Row_001A47B0 pos = m_obj->m50;
    if (m24) {
        void* s = 0;
        if (func_00185578(src, 0x222756D5))
            s = func_0019EBD0(func_00185578(src, 0x222756D5));
        if (s && func_0011E7B8(s, m24, &m_obj->m70)) {
            Row_001A47B0 trans = m_obj->m70.r[3];
            m_obj->m70.r[3] = Vec_001A47B0(0.0f, 0.0f, 0.0f, 1.0f);
            Obj_001A47B0* o = m_obj;
            o->m70 = o->m70 * src->m70;
            pos = src->mC0 * trans;
            pos += src->Offset(m_obj->m70 * m30);
        }
    } else {
        Comp_001A47B0* c = (Comp_001A47B0*)func_00185578(src, 0x286A8D26);
        if (Check(c, src)) {
            Mat_001A47B0 m;
            func_0018C340(c, &m);
            pos = m * m30;
            m.r[3] = Vec_001A47B0(0.0f, 0.0f, 0.0f, 1.0f);
            m_obj->m70 = m;
        } else {
            m_obj->m70 = src->mC0;
            pos = src->Offset(m_obj->m70 * m30);
        }
    }
    if (m58) {
        Obj_001A47B0* o = m_obj;
        o->m50 = o->Offset(o->To(pos) * m40);
        unsigned int t = func_0010FC30() + m54;
        t &= 0x3FF;
        float a = func_00341068(m4C * t * 2.0f * 0.0030679616f);
        float b = func_00341068(m50 * t * 2.0f * 0.0030679616f);
        m40 = m44 + (a * b + 1.0f) * (m48 - m44) * 0.5f;
    } else {
        m_obj->m50 = pos;
    }
    m_obj->mB0 = src->mB0;
    if (m5C) {
        m_obj->m70.r[1] = saved.r[1];
        m_obj->m70.r[2] = saved.r[2];
        m_obj->m70.r[0] = saved.r[0];
    }
    void* r = 0;
    if (func_00185578(m_obj, 0x286A8D26))
        r = ((Comp_001A47B0*)func_00185578(m_obj, 0x286A8D26))->m260;
    if (r) {
        void* s = 0;
        if (func_00185578(m_obj, 0x222756D5))
            s = func_0019EBD0(func_00185578(m_obj, 0x222756D5));
        Mat_001A47B0 m = m_obj->mC0;
        m.r[3] = m_obj->m50;
        m.r[3].w = 1.0f;
        func_0013CD08(r, &m, 1, s);
    }
}
