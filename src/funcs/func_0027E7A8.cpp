typedef int qword __attribute__((mode(TI)));

struct Row_0027E7A8 {
    union {
        qword q;
        float c[4];
    };
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    void operator+=(const Row_0027E7A8& o)
    {
        c[0] += o[0];
        c[1] += o[1];
        c[2] += o[2];
        c[3] += o[3];
    }
    void operator*=(float k)
    {
        c[0] *= k;
        c[1] *= k;
        c[2] *= k;
        c[3] *= k;
    }
};
struct Vec_0027E7A8 : Row_0027E7A8 {
    Vec_0027E7A8() {}
    Vec_0027E7A8(float x, float y, float z, float w) { c[0] = x; c[1] = y; c[2] = z; c[3] = w; }
};
static inline Vec_0027E7A8 operator+(const Row_0027E7A8& a, const Row_0027E7A8& b) { return Vec_0027E7A8(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]); }
static inline Vec_0027E7A8 operator-(const Row_0027E7A8& a, const Row_0027E7A8& b) { return Vec_0027E7A8(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]); }
static inline Vec_0027E7A8 operator-(const Row_0027E7A8& a) { return Vec_0027E7A8(-a[0], -a[1], -a[2], -a[3]); }
static inline Vec_0027E7A8 operator*(const Row_0027E7A8& a, float k) { return Vec_0027E7A8(a[0] * k, a[1] * k, a[2] * k, a[3] * k); }

struct Mat_0027E7A8 {
    Row_0027E7A8 r[4];
    const Row_0027E7A8& operator[](int i) const { return r[i]; }
    Mat_0027E7A8& operator=(const Mat_0027E7A8& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
        return *this;
    }
};

struct Body_0027E7A8 {
    char pad[0x50];
    Row_0027E7A8 m50;
    char pad60[0x10];
    Mat_0027E7A8 m70;
};

struct Comp_0027E7A8 {
    char pad[0x60];
    Row_0027E7A8 m60;
    char pad70[0x20];
    Row_0027E7A8 m90;
    char padA0[0x20];
    Mat_0027E7A8 mC0;
};

struct Link_0027E7A8 {
    Comp_0027E7A8* m0;
    char pad4[0x5C];
    Row_0027E7A8 m60;
};

struct Holder_0027E7A8 {
    char pad[0x1C];
    Link_0027E7A8* m1C;
};

struct Flag_0027E7A8 {
    char pad[0xC4];
    int mC4;
};

struct Btn_0027E7A8 {
    char pad[0x14];
    int m14;
    int Held() { return m14; }
};

struct Pad_0027E7A8 {
    char pad[0xB8];
    Btn_0027E7A8 mB8;
    char padD0[0xDC - 0xD0];
    Btn_0027E7A8 mDC;
    char padF4[0x124 - 0xF4];
    Btn_0027E7A8 m124;
    char pad13C[0x148 - 0x13C];
    Btn_0027E7A8 m148;
};

extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" void func_0026FDC8(Btn_0027E7A8* b);
extern "C" int func_001B7B28(void* coll, const Vec_0027E7A8& dir, Vec_0027E7A8* pos);
extern "C" int func_001B7D50(void* coll, Row_0027E7A8* out, int id);
extern "C" void func_001848F0(void* obj, unsigned int name, int a);
extern "C" float func_002032A0(unsigned int name, int a);
extern "C" float sqrtf(float);

struct Obj_0027E7A8 {
    char pad0[0xC];
    Body_0027E7A8* mC;
    char pad10[0x10];
    Mat_0027E7A8 m20;
    char pad60[0x94 - 0x60];
    float m94;
    char pad98[0x2C0 - 0x98];
    int m2C0;
    int m2C4;
    float m2C8;
    char pad2CC[0x594 - 0x2CC];
    Pad_0027E7A8* m594;
    char pad598[0x5B0 - 0x598];
    Flag_0027E7A8* m5B0;
    Holder_0027E7A8* m5B4;
    void Update();
};

void Obj_0027E7A8::Update()
{
    Pad_0027E7A8* pad = m594;
    Link_0027E7A8* l = m5B4->m1C;
    if (!l) {
        func_001848F0(mC, 0x47D44B84, 0);
        return;
    }
    Comp_0027E7A8* c = l->m0;
    if (!c) {
        func_001848F0(mC, 0x47D44B84, 0);
        return;
    }
    float dir = 0.0f;
    void* coll = func_00185578(c, 0x3506CE64);
    if (pad->mB8.Held()) {
        dir = 1.0f;
        func_0026FDC8(&pad->mB8);
    }
    if (pad->m124.Held()) {
        dir = -1.0f;
        func_0026FDC8(&pad->m124);
    }
    if (pad->mDC.Held()) {
        dir = 1.0f;
        func_0026FDC8(&pad->mDC);
    }
    if (pad->m148.Held()) {
        dir = -1.0f;
        func_0026FDC8(&pad->m148);
    }
    Row_0027E7A8 v;
    if (dir != 0.0f && !(m2C0 && dir == m2C8)) {
        float range = 120.0f;
        for (float d = 6.0f; d < range; d += 6.0f) {
            v = mC->m70[0];
            v *= d * dir;
            Vec_0027E7A8 p = mC->m50 + v;
            int id = func_001B7B28(coll, Vec_0027E7A8(0.0f, 0.0f, 0.0f, 1.0f), &p);
            if (id != m2C4) {
                m2C4 = id;
                m2C0 = 1;
                m2C8 = dir;
                if (dir == 1.0f)
                    func_001848F0(mC, 0x74BF80CF, 0);
                else
                    func_001848F0(mC, 0x2E7474B5, 0);
                break;
            }
        }
    }
    if (!m5B4->m1C) return;
    if (!m5B0->mC4) return;
    if (!func_001B7D50(coll, &v, m2C4)) return;
    mC->m50[3] = 0.0f;
    float k = func_002032A0(0x21FB182C, 0);
    Vec_0027E7A8 p = v + -c->m90 * k;
    if (m2C0) {
        Row_0027E7A8 t = m5B4->m1C->m60;
        mC->m50 += t;
        Vec_0027E7A8 d = p - mC->m50;
        float len2 = d[0] * d[0] + d[1] * d[1] + d[2] * d[2];
        float max = func_002032A0(0x97496256, 0) * m94;
        if (len2 > 32400.0f) {
            func_001848F0(mC, 0x47D44B84, 0);
            return;
        }
        if (len2 <= max * max) {
            mC->m50 = p;
            m2C0 = 0;
        } else {
            d *= max / sqrtf(len2);
            mC->m50 += d;
        }
    } else {
        mC->m50 = p;
    }
    mC->m70 = c->mC0;
    m20 = mC->m70;
}
