typedef int qword __attribute__((mode(TI)));
union Vec_0028E2F0 {
    qword q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    Vec_0028E2F0() {}
    Vec_0028E2F0(float x, float y, float z, float w)
    {
        (*this)[0] = x;
        (*this)[1] = y;
        (*this)[2] = z;
        (*this)[3] = w;
    }
    float Length() const;
    void operator+=(const Vec_0028E2F0& o)
    {
        c[0] += o[0];
        c[1] += o[1];
        c[2] += o[2];
        c[3] += o[3];
    }
};
extern "C" float sqrtf(float);
inline float Vec_0028E2F0::Length() const { return sqrtf(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]); }
inline Vec_0028E2F0 operator*(const Vec_0028E2F0& a, float k) { return Vec_0028E2F0(a[0] * k, a[1] * k, a[2] * k, a[3] * k); }

struct State_0028E2F0 {
    int pad;
    int state;
    unsigned int time;
};
struct Body_0028E2F0 {
    char pad0[0x50];
    Vec_0028E2F0 m50;
    char pad60[0x80 - 0x60];
    Vec_0028E2F0 m80;
    char pad90[0xB0 - 0x90];
    Vec_0028E2F0 mB0;
};
struct Sub_0028E2F0 {
    char pad0[0x1C];
    int m1C;
    char pad20[0x24 - 0x20];
    State_0028E2F0 m24;
    char pad30[0x3C - 0x30];
    State_0028E2F0 m3C;
    char pad48[0x58 - 0x48];
    int m58;
    char pad5C[0x60 - 0x5C];
    State_0028E2F0 m60;
    char pad6C[0x13C - 0x6C];
    int m13C;
};
struct Trick_0028E2F0 {
    char pad0[0x6C];
    int m6C;
};
struct Sk_0028E2F0 {
    char pad0[0x2C];
    int m2C;
};

struct Obj_0028E2F0;
extern "C" bool func_001E8708(void* p, unsigned int key);
extern "C" void func_001BB080(void* p, int a, void* b);
extern "C" float func_00203D40(Body_0028E2F0* o, unsigned int name);
extern "C" void func_00270D30(void* p, int a, float v);
extern "C" void func_00280220(Obj_0028E2F0* o);
extern "C" unsigned int func_0010FC30();
extern "C" int func_00203300(unsigned int, int);
extern "C" int func_001E7EB0(void* p, unsigned int key, float* out, int req);
extern "C" void func_0028D770(Obj_0028E2F0* o);
extern "C" void func_0027C720(Obj_0028E2F0* o, int v);
extern "C" void func_00184920(Body_0028E2F0* b, unsigned int name, float v, int a);

static inline void Set_0028E2F0(State_0028E2F0* s, int v)
{
    if (s->state != v) {
        s->state = v;
        s->time = func_0010FC30();
    }
}

struct Obj_0028E2F0 {
    char pad0[0xC];
    Body_0028E2F0* mC;
    char pad10[0x60 - 0x10];
    Vec_0028E2F0 m60;
    char pad70[0x9C - 0x70];
    int m9C;
    char padA0[0x190 - 0xA0];
    Trick_0028E2F0 m190;
    char pad200[0x3A0 - 0x200];
    Vec_0028E2F0 m3A0;
    char pad3B0[0x3F0 - 0x3B0];
    int m3F0;
    char pad3F4[0x588 - 0x3F4];
    unsigned int m588;
    char pad58C[0x598 - 0x58C];
    void* m598;
    void* m59C;
    char pad5A0[0x5B0 - 0x5A0];
    Sub_0028E2F0* m5B0;
    char pad5B4[0x5B8 - 0x5B4];
    Sk_0028E2F0* m5B8;
    void Land(void* p);
};

void Obj_0028E2F0::Land(void* p)
{
    bool nf = !func_001E8708(p, 0xE13620A8);
    switch (m5B0->m1C) {
    case 0: {
        Trick_0028E2F0* tr = &m190;
        func_001BB080(m598, 2, tr);
        if (m5B8->m2C) return;
        Body_0028E2F0* b = mC;
        m3A0 = b->m50;
        if (nf) {
            float sp = b->mB0.Length();
            float k = func_00203D40(b, 0xCC5F87AA);
            func_00270D30(m59C, tr->m6C, sp / k);
        }
        func_00280220(this);
        Set_0028E2F0(&m5B0->m60, 1);
        break;
    }
    case 1:
        if (nf) {
            Body_0028E2F0* b = mC;
            float sp = b->mB0.Length();
            float k = func_00203D40(b, 0xCC5F87AA);
            func_00270D30(m59C, m190.m6C, sp / k);
        }
        break;
    case 4:
        if (nf) {
            Body_0028E2F0* b = mC;
            float sp = b->mB0.Length();
            float k = func_00203D40(b, 0xCC5F87AA);
            func_00270D30(m59C, m5B0->m13C, sp / k);
        }
        break;
    }
    int lim = func_00203300(0xF733C097, 0);
    bool f = false;
    Sub_0028E2F0* sb = m5B0;
    m3F0 = m3F0 < lim ? m3F0 : lim;
    if (sb->m3C.state || (!sb->m1C && sb->m58)) f = true;
    float hi;
    float lo;
    if (func_001E8708(p, 0xEC6B7FC7)) {
        if (f) {
            hi = func_00203D40(mC, 0x39766891);
            lo = func_00203D40(mC, 0x4CDB18CB);
        } else {
            hi = func_00203D40(mC, 0x8851A76E);
            lo = func_00203D40(mC, 0x6E8EFE38);
        }
    } else {
        if (f) {
            hi = func_00203D40(mC, 0x9F79C8EA);
            lo = func_00203D40(mC, 0x91B07824);
        } else {
            hi = func_00203D40(mC, 0x2ADE3AD);
            lo = func_00203D40(mC, 0xC8815E43);
        }
    }
    float v = lo + (hi - lo) * ((float)m3F0 / (float)lim);
    func_001E7EB0(p, 0xF0D90109, &v, 0);
    Set_0028E2F0(&m5B0->m24, 0);
    if (m5B0->m3C.state && mC->mB0[1] < 0.0f) {
        mC->mB0 += m60 * v;
        v = 0.0f;
        Set_0028E2F0(&m5B0->m3C, 0);
    } else if (mC->mB0[1] < 0.0f) {
        mC->mB0[1] = 0.0f;
    }
    mC->mB0[1] += v;
    if (mC->m80[1] < -0.1f) {
        mC->mB0[1] -= v * 1.5f;
        mC->m50 += mC->m80 * 12.0f;
    }
    int st = m5B0->m1C;
    if (st == 4 || (st == 1 && m9C == 4)) func_0028D770(this);
    func_0027C720(this, 1);
    m588 = func_0010FC30();
    func_00184920(mC, 0x8687163A, 0.0f, 0);
}
