typedef int qword __attribute__((mode(TI)));

struct Row_00259660;
extern "C" void func_003233B8(Row_00259660* dst, Row_00259660* src);

struct Row_00259660 {
    union {
        qword q;
        float c[4];
    };
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    void operator*=(float k)
    {
        c[0] *= k;
        c[1] *= k;
        c[2] *= k;
        c[3] *= k;
    }
    void Add(const Row_00259660& o)
    {
        float x = o[0];
        float y = o[1];
        float z = o[2];
        float w = o[3];
        c[0] += x;
        c[1] += y;
        c[2] += z;
        c[3] += w;
    }
    void operator+=(const Row_00259660& o)
    {
        c[0] += o[0];
        c[1] += o[1];
        c[2] += o[2];
        c[3] += o[3];
    }
};
struct Vec_00259660 : Row_00259660 {
    Vec_00259660() {}
    Vec_00259660(float x, float y, float z, float w) { c[0] = x; c[1] = y; c[2] = z; c[3] = w; }
};
static inline Vec_00259660 operator-(const Row_00259660& a, const Row_00259660& b) { return Vec_00259660(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]); }
static inline Vec_00259660 operator*(const Row_00259660& a, float k) { return Vec_00259660(a[0] * k, a[1] * k, a[2] * k, a[3] * k); }

struct Obj_00259660;
extern "C" int func_002587E0(Obj_00259660* self);
extern "C" void func_00258F18(Obj_00259660* self);
extern "C" void func_00258FF0(Obj_00259660* self, float dt);
extern "C" int func_00259480(Obj_00259660* self);
extern "C" void func_00259530(Obj_00259660* self);
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" void func_001A6BB8(void* obj, int node);

struct Obj_00259660 {
    char pad0[0x10];
    Row_00259660 m10;
    void* m20;
    char pad24[0x50 - 0x24];
    Row_00259660 m50;
    char pad60[0x10];
    int m70;
    int m74;
    char pad78[8];
    Row_00259660 m80;
    Row_00259660 m90;
    char padA0[0x18];
    float mB8;
    float mBC;
    float mC0;
    int mC4;
    float mC8;
    char padCC[4];
    Row_00259660 mD0;
    Row_00259660 mE0;
    char padF0[4];
    float mF4;
    char padF8[4];
    int mFC;
    int m100;
    float Rate(float dt, const Row_00259660& up)
    {
        float d = up[0] * m50[0] + up[1] * m50[1] + up[2] * m50[2];
        if (d == 0.0f) return 1.0f;
        return dt * d;
    }
    int Update(float dt, const Row_00259660* up);
};

int Obj_00259660::Update(float dt, const Row_00259660* up)
{
    int state = mFC;
    if (state == 4) return 1;
    float step = up ? Rate(dt, *up) : dt;
    switch (state) {
    case 0:
        func_002587E0(this);
        m100 = 0;
        mFC = 1;
    case 1:
        mC0 += step;
        if (mC4 & 2) {
            if (mBC <= mC0) {
                m70 = m74;
                m80 = m90;
                m10 = m90;
                mFC = 4;
                return 1;
            }
        } else if (mBC - mB8 <= mC0) {
            if (mB8 == 0.0f) {
                m10 = m90;
                func_001A6BB8(func_00185578(m20, 0x0A015E17), m74);
                if (!func_00259480(this))
                    return 1;
                mFC = 0;
                return 0;
            }
            func_00258F18(this);
            func_00259480(this);
            mC4 |= 4;
            func_00259530(this);
            return 0;
        }
        func_00258F18(this);
        return 0;
    case 2:
        mC0 += step;
        if ((mC4 & 4) && mF4 * 0.5f <= mC0) {
            mC4 &= ~4;
            func_001A6BB8(func_00185578(m20, 0x0A015E17), m70);
        }
        if (mC0 > mF4) {
            mC8 = mC0 - mF4;
            func_00258FF0(this, step - mC8);
            mC8 = 0.0f;
            func_002587E0(this);
            func_00258F18(this);
            m100 = 0;
            mFC = 1;
            return 0;
        }
        func_00258FF0(this, step);
        return 0;
    case 3: {
        mC0 += step;
        float t = mC0 / mBC;
        if (mC0 < mBC) {
            m10 = mD0;
            Vec_00259660 v = m80 - mD0;
            v *= t;
            m10 += v;
        } else {
            m10 = m80;
            Vec_00259660 v = mE0 - m80;
            v *= t - 1.0f;
            m10 += v;
        }
        Row_00259660 a;
        Row_00259660 b;
        a = m80 - mD0;
        b = mE0 - m80;
        t *= 0.5f;
        if (0.5f <= t && (mC4 & 4)) {
            mC4 &= ~4;
            func_001A6BB8(func_00185578(m20, 0x0A015E17), m70);
        }
        if (1.0f <= t) {
            mC8 = 0.0f;
            func_002587E0(this);
            t = 1.0f;
            mFC = 1;
        }
        m50 = a * (1.0f - t);
        m50.Add(b * t);
        func_003233B8(&m50, &m50);
        return 0;
    }
    case 4:
        return 0;
    }
    return 0;
}
