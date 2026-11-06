/* fuzzy: 88.4 */
/* sym: __13Coll_001CAFC0 = 0x00209240 */
typedef int qword __attribute__((mode(TI)));

struct Vec_001CAFC0 {
    union {
        float col[4];
        qword q;
    };
    Vec_001CAFC0() {}
    Vec_001CAFC0(float ax, float ay, float az, float aw)
    {
        col[0] = ax;
        col[1] = ay;
        col[2] = az;
        col[3] = aw;
    }
    float& operator[](int i) { return col[i]; }
    const float& operator[](int i) const { return col[i]; }
};

static inline Vec_001CAFC0 operator+(const Vec_001CAFC0& a, const Vec_001CAFC0& b)
{
    return Vec_001CAFC0(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}
static inline Vec_001CAFC0 operator*(const Vec_001CAFC0& a, float s)
{
    return Vec_001CAFC0(a[0] * s, a[1] * s, a[2] * s, a[3] * s);
}
static inline void operator+=(Vec_001CAFC0& a, const Vec_001CAFC0& b)
{
    a[0] += b[0];
    a[1] += b[1];
    a[2] += b[2];
    a[3] += b[3];
}
static inline void operator-=(Vec_001CAFC0& a, const Vec_001CAFC0& b)
{
    a[0] -= b[0];
    a[1] -= b[1];
    a[2] -= b[2];
    a[3] -= b[3];
}

struct Link_001CAFC0;
extern "C" void func_00183CB8(void* list, Link_001CAFC0* node);

struct Link_001CAFC0 {
    void* m_list;
    ~Link_001CAFC0()
    {
        if (m_list) {
            func_00183CB8(m_list, this);
            m_list = 0;
        }
    }
};

class Coll_001CAFC0 {
public:
    Vec_001CAFC0 m0;
    Vec_001CAFC0 m10;
    char pad20[0xB0 - 0x20];
    Vec_001CAFC0 mB0;
    Link_001CAFC0 m_link;
    char padC4[0xE0 - 0xC4];
    Coll_001CAFC0();
};

struct Pmf_001CAFC0 {
    short delta;
    short index;
    void* func;
};

extern Pmf_001CAFC0 D_0038D7A0[];
extern Pmf_001CAFC0 D_0038D7A8[];

extern "C" void* func_001E5548(unsigned int crc, int a);
extern "C" int func_001E7EB0(void* s, unsigned int crc, float* out, int a);
static inline float Param_001CAFC0(unsigned int name)
{
    float v;
    func_001E7EB0(func_001E5548(0x6775E538, 0), name, &v, 1);
    return v;
}
extern "C" float func_00340F60(float a);
extern "C" float func_00341068(float a);
extern "C" int func_002093E8(Coll_001CAFC0* c, int a, int b);

struct Self_001CAFC0;
extern "C" int func_001C6458(Self_001CAFC0* self, Vec_001CAFC0* a, Vec_001CAFC0* b, Coll_001CAFC0* c);
extern "C" void func_0019C9D8(void* p, Coll_001CAFC0* c);
extern "C" void func_001C4210(Self_001CAFC0* self, Vec_001CAFC0* v, float f);
extern "C" void func_001BF130(Self_001CAFC0* self, int a);

struct Self_001CAFC0 {
    char pad0[0x30];
    Vec_001CAFC0 m_pos;
    char pad40[0x60 - 0x40];
    Vec_001CAFC0 m_vel;
    char pad70[0x90 - 0x70];
    unsigned int m_state;
    char pad94[0xC4 - 0x94];
    float mC4;
    char padC8[0x970 - 0xC8];
    Vec_001CAFC0 m970;
    char pad980[0xA50 - 0x980];
    Vec_001CAFC0 mA50;
    char padA60[0xA70 - 0xA60];
    char mA70[0xB50 - 0xA70];
    int mB50;
    char padB54[0xBD0 - 0xB54];
    Vec_001CAFC0 mBD0;
    char padBE0[0xBE4 - 0xBE0];
    float mBE4;
    char padBE8[0xBF4 - 0xBE8];
    float mBF4;
    char padBF8[0xC10 - 0xBF8];
    Vec_001CAFC0 mC10;
    char padC20[0xC30 - 0xC20];
    Vec_001CAFC0 mC30;
    float mC40;
    int mC44;
    char padC48[0xC80 - 0xC48];
    int mC80;
    Pmf_001CAFC0 mC84;

    int Start(Vec_001CAFC0* pos);
};

int Self_001CAFC0::Start(Vec_001CAFC0* pos)
{
    Vec_001CAFC0 p;
    Coll_001CAFC0 c1;
    int hit = func_001C6458(this, pos, &p, &c1);
    if (!hit) {
        Vec_001CAFC0 saved;
        Vec_001CAFC0 side(-m_vel[2], 0.0f, m_vel[0], 1.0f);
        *pos += side * 12.0f;
        saved = p;
        hit = func_001C6458(this, pos, &p, &c1);
        if (!hit) {
            *pos -= side * 24.0f;
            hit = func_001C6458(this, pos, &p, &c1);
            if (!hit) p = saved;
        }
    }
    Coll_001CAFC0 c2;
    float r = Param_001CAFC0(0xA20C43B7) * 0.5f;
    float up = Param_001CAFC0(0x6DA7F696);
    for (int i = 0; i < 7; i++) {
        float a = i * 0.8975979686f;
        float s = func_00340F60(a);
        float c = func_00341068(a);
        float w = 1.0f;
        Vec_001CAFC0 d = Vec_001CAFC0(s * m_vel[0] - c * m_vel[2], 0.0f, c * m_vel[0] + s * m_vel[2], w) * r;
        c2.m0 = p;
        c2.m0[1] += up;
        c2.m10 = p + d;
        c2.m10[1] += up;
        if (func_002093E8(&c2, 1, 0)) return 0;
    }
    c2.m0 = m_pos;
    c2.m0 += m_vel * -6.0f;
    float h = Param_001CAFC0(0xA8C13E74) + Param_001CAFC0(0x9B2818CF);
    c2.m10 = p;
    c2.m0[1] += h;
    c2.m10[1] += 1.0f;
    if (func_002093E8(&c2, 1, 0)) return 0;
    if (hit) {
        mC84 = D_0038D7A0[0];
        func_0019C9D8(mA70, &c1);
        mB50 = 1;
        mA50 = c1.mB0;
    } else {
        mC84 = D_0038D7A8[0];
    }
    mC10 = m_pos;
    mC30 = p;
    func_001C4210(this, &m_vel, 1.0f);
    mC44 = 0;
    mC40 = mC4;
    mC80 = 1;
    mBD0 = m_vel;
    m970 = m_vel * -(Param_001CAFC0(0x21DFBE77) + 6.0f);
    mBE4 = m_pos[1] - mBF4;
    m970[1] = 1.0f;
    func_001BF130(this, 4);
    m_state = 0x9EF9F8F1;
    return 1;
}
