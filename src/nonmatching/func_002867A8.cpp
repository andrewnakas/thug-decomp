/* fuzzy: 92.2 */
typedef int qword __attribute__((mode(TI)));
union Row_002867A8 {
    qword q;
    struct { float x, y, z, w; } f;
};
struct Mat_002867A8 {
    Row_002867A8 r[4];
    Mat_002867A8& operator=(const Mat_002867A8& o)
    {
        r[0].q = o.r[0].q;
        r[1].q = o.r[1].q;
        r[2].q = o.r[2].q;
        r[3].q = o.r[3].q;
        return *this;
    }
};


extern "C" Mat_002867A8* func_00100928(Mat_002867A8* out, float angle);
extern "C" void func_00323318(Mat_002867A8* a, Mat_002867A8* b, Mat_002867A8* out);
extern "C" float func_002032A0(unsigned int, int);
extern "C" float func_003412F0(float x);
extern "C" unsigned int func_0010FC30();
extern "C" float func_00101D60(Row_002867A8* a, Row_002867A8* b, Row_002867A8* c);
extern "C" void func_002376C0(void* p, int v);

struct Body_002867A8 {
    char pad[0x70];
    Mat_002867A8 m70;
};

struct Btn_002867A8 {
    int m0;
    int m4;
    char pad8[0xC];
    int m14;
    char pad18[0xC];
};

extern "C" unsigned int func_0026FDA0(Btn_002867A8* b);
extern "C" void func_0026FDC8(Btn_002867A8* b);
extern "C" float func_00203D40(Body_002867A8* o, unsigned int name);

struct Timer_002867A8 {
    int m0;
    int m4;
    unsigned int m8;
    void Stop()
    {
        if (m4) {
            m4 = 0;
            m8 = func_0010FC30();
        }
    }
};

struct Sub_002867A8 {
    char pad[0x40];
    int m40;
    char pad44[0x90 - 0x44];
    Timer_002867A8 m90;
    char pad9C[0xAC - 0x9C];
    int mAC;
    char padB0[0x118 - 0xB0];
    int m118;
};

struct Pad_002867A8 {
    int m0;
    Btn_002867A8 btn[8];
    Btn_002867A8* Get(int i) { return &btn[i]; }
};

struct Ctl_002867A8 {
    char pad[0x24];
    Pad_002867A8 m24;
};

struct Stats_002867A8 {
    char pad[0x13F0];
    float m13F0;
};

struct Anim_002867A8 {
    char pad[0x1C];
    void* m1C;
};

static inline float Clamp_002867A8(float v, float lo, float hi)
{
    if (v > hi)
        v = hi;
    if (v < lo)
        v = lo;
    return v;
}

struct Obj_002867A8 {
    char pad0[0xC];
    Body_002867A8* mC;
    char pad10[0x10];
    Mat_002867A8 m20;
    char pad60[0x94 - 0x60];
    float m94;
    char pad98[0x310 - 0x98];
    Row_002867A8 m310;
    char pad320[0x368 - 0x320];
    int m368;
    float m36C;
    char pad370[0x3D4 - 0x370];
    int m3D4;
    char pad3D8[0x428 - 0x3D8];
    int m428;
    char pad42C[0x594 - 0x42C];
    Ctl_002867A8* m594;
    char pad598[0x5A0 - 0x598];
    Stats_002867A8* m5A0;
    char pad5A4[4];
    Anim_002867A8* m5A8;
    char pad5AC[4];
    Sub_002867A8* m5B0;
    void Spin();
    void Rot(Mat_002867A8* dst, float a)
    {
        Mat_002867A8 tm;
        Mat_002867A8 r;
        Mat_002867A8* src = func_00100928((Mat_002867A8*)0x70003FC0, a);
        Mat_002867A8* p = &r;
        *p = *src;
        func_00323318(p, dst, p);
        tm = r;
        *dst = tm;
    }
};

void Obj_002867A8::Spin()
{
    Pad_002867A8* pad = &m594->m24;
    if (m3D4)
        return;
    if (m5B0->mAC)
        m5B0->m90.Stop();
    float spin = 0.0f;
    int held = 0;
    Btn_002867A8* r;
    if (m368) {
        Btn_002867A8* l = pad->Get(4);
        r = pad->Get(7);
        if (l->m14) {
            func_0026FDC8(l);
            if (!r->m4)
                m36C += 3.141592741f;
        }
        if (r->m14) {
            func_0026FDC8(r);
            if (!l->m4)
                m36C -= 3.141592741f;
        }
        if (m36C != 0.0f) {
            float sign = 1.0f;
            held = 1;
            if (m36C < 0.0f)
                sign = -1.0f;
            float s = sign * func_00203D40(mC, 0xF7A2ACC1);
            if (__builtin_fabsf(m36C) < __builtin_fabsf(s * m94))
                m36C = 0.0f;
            else
                m36C = m36C - s * m94;
            spin = s;
        }
    } else {
        Btn_002867A8* l = pad->Get(4);
        r = pad->Get(7);
        if (l->m4 && !r->m4) {
            held = 1;
            spin = func_00203D40(mC, 0x4957DB43);
            if ((float)func_0026FDA0(l) > func_002032A0(0xABDD3395, 0))
                m5B0->m90.Stop();
        }
        if (r->m4 && !l->m4) {
            held = 1;
            spin = -func_00203D40(mC, 0x4957DB43);
            if ((float)func_0026FDA0(r) > func_002032A0(0xABDD3395, 0))
                m5B0->m90.Stop();
        }
    }
    if (!m5B0->m118 && !held) {
        Btn_002867A8* u = pad->Get(2);
        if (u->m4) {
            spin = func_00203D40(mC, 0x4957DB43);
            held = func_0026FDA0(u);
            if ((float)held > func_002032A0(0xABDD3395, 0))
                m5B0->m90.Stop();
        }
        Btn_002867A8* d = pad->Get(3);
        if (d->m4) {
            spin = -func_00203D40(mC, 0x4957DB43);
            held = func_0026FDA0(d);
            if ((float)held > func_002032A0(0xABDD3395, 0))
                m5B0->m90.Stop();
        }
        float lo = func_002032A0(0xA092B2BE, 0);
        float hi = func_002032A0(0x5D756349, 0);
        float ft = (float)held;
        if (ft <= lo)
            spin = 0.0f;
        if (ft < hi)
            spin = spin * (ft - lo) / (hi - lo);
    }
    if (spin == 0.0f && m5B0->m40 && m5B0->m90.m4) {
        float ang = func_003412F0(Clamp_002867A8(mC->m70.r[2].f.y, -1.0f, 1.0f));
        if (ang < func_002032A0(0x61224F2E, 0) * 0.01745329425f) {
            m5B0->m90.Stop();
        } else {
            float sign = 1.0f;
            float d = func_00101D60(&mC->m70.r[2], &m310, &mC->m70.r[1]);
            if (d < 0.0f)
                sign = -1.0f;
            spin = sign * func_002032A0(0x9DB33213, 0);
            if (__builtin_fabsf(d) < __builtin_fabsf(spin * m94)) {
                spin = d / m94;
                m5B0->m90.Stop();
            }
        }
    }
    if (spin == 0.0f)
        return;
    m428 = spin > 0.0f;
    spin *= m94;
    Rot(&mC->m70, spin);
    Rot(&m20, spin);
    m5A0->m13F0 += spin * 57.29577637f;
    if (m5B0->m40 && !m5B0->mAC) {
        float a = __builtin_fabsf(m5A0->m13F0);
        if (360.0f - func_002032A0(0x50C5CC2F, 0) + 0.1f <= a)
            func_002376C0(m5A8->m1C, (int)m5A0->m13F0);
    } else {
        func_002376C0(m5A8->m1C, (int)m5A0->m13F0);
    }
}
