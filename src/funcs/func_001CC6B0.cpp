typedef int qword __attribute__((mode(TI)));

extern "C" float sqrtf(float);

struct Vec_001CC6B0 {
    union {
        struct { float x, y, z, w; };
        float c[4];
        qword q;
    };
    const float& operator[](int i) const { return c[i]; }
    Vec_001CC6B0() {}
    Vec_001CC6B0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

static inline Vec_001CC6B0 operator+(const Vec_001CC6B0& a, const Vec_001CC6B0& b)
{
    return Vec_001CC6B0(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}

static inline Vec_001CC6B0 operator-(const Vec_001CC6B0& a, const Vec_001CC6B0& b)
{
    return Vec_001CC6B0(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}

static inline Vec_001CC6B0 operator*(const Vec_001CC6B0& a, float s)
{
    return Vec_001CC6B0(a[0] * s, a[1] * s, a[2] * s, a[3] * s);
}

struct Node_001CC6B0 {
    char m_pad[0x50];
    Node_001CC6B0* m50;
    Node_001CC6B0* m54;
};

struct Board_001CC6B0 {
    char m_pad[0x290];
    float m290;
};

struct Obj_001CC6B0 {
    char m_pad0[0x30];
    Vec_001CC6B0 m30;
    char m_pad40[0x20];
    Vec_001CC6B0 m60;
    char m_pad70[0x90 - 0x70];
    unsigned int m90;
    char m_pad94[0x98 - 0x94];
    float m98;
    char m_pad9C[0xB0 - 0x9C];
    float mB0;
    char m_padB4[0x954 - 0xB4];
    float m954;
    char m_pad958[0xA1C - 0x958];
    Node_001CC6B0* mA1C;
    int m_padA20;
    void* mA24;
    Board_001CC6B0* mA28;
    char m_padA2C[0xBF0 - 0xA2C];
    float mBF0;
    void UpdateRail();
};

extern "C" Vec_001CC6B0 func_0026B1B0(void* rails, Node_001CC6B0* node);
extern "C" void* func_001E5548(unsigned int key, int create);
extern "C" bool func_001E7EB0(void* params, unsigned int name, float* out, int required);
extern "C" float func_00340F60(float a);
extern "C" void func_001CCA18(Obj_001CC6B0* self);
extern "C" void func_001CCC00(Obj_001CC6B0* self);

static inline float GetF_001CC6B0(unsigned int id)
{
    float v;
    func_001E7EB0(func_001E5548(0x6775E538, 0), id, &v, 1);
    return v;
}

void Obj_001CC6B0::UpdateRail()
{
    float step = GetF_001CC6B0(0x0AB2DB54);
    step *= mB0;
    step *= func_00340F60(mA28->m290);
    m954 = step;
    step *= m98;
    Node_001CC6B0* next = mA1C->m50;
    if (!next)
        next = mA1C->m54;
    Vec_001CC6B0 d = func_0026B1B0(mA24, next) - func_0026B1B0(mA24, mA1C);
    float len = sqrtf(d.x * d.x + d.y * d.y + d.z * d.z);
    step = step / len;
    int forward = 0.0f < step;
    mBF0 += step;
    if (mBF0 < GetF_001CC6B0(0x5296E3FD) / len) {
        func_001CCA18(this);
        return;
    }
    if ((len - GetF_001CC6B0(0x76BF49E0)) / len < mBF0) {
        func_001CCC00(this);
        return;
    }
    float m = mBF0;
    float t;
    if (1.0f < m)
        t = 1.0f;
    else
        t = m;
    if (t < 0.0f)
        t = 0.0f;
    mBF0 = t;
    if (t == 0.0f || t == 1.0f) {
        m954 = 0.0f;
        m90 = 0xC84243DA;
    } else {
        m90 = forward ? 0xAF5ABC82 : 0xFEC9DDED;
    }
    Vec_001CC6B0 res = func_0026B1B0(mA24, mA1C) + d * mBF0 - m60 * GetF_001CC6B0(0x35B3BBDA);
    m954 = __builtin_fabsf(m954);
    m30 = res;
}
