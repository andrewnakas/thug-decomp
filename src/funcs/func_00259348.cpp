typedef int qword_00259348 __attribute__((mode(TI)));

extern "C" float sqrtf(float);

struct Vec_00259348 {
    union {
        float col[4];
        qword_00259348 q;
    };
    Vec_00259348() {}
    Vec_00259348(float ax, float ay, float az, float aw)
    {
        col[0] = ax;
        col[1] = ay;
        col[2] = az;
        col[3] = aw;
    }
    float& operator[](int i) { return col[i]; }
    const float& operator[](int i) const { return col[i]; }
    float Length() const { return sqrtf(col[0] * col[0] + col[1] * col[1] + col[2] * col[2]); }
};

static inline Vec_00259348 operator-(const Vec_00259348& a, const Vec_00259348& b)
{
    return Vec_00259348(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}

struct Mover_00259348;
extern "C" void func_00259428(Mover_00259348* self);
extern "C" int func_00259480(Mover_00259348* self);
extern "C" void func_00259160(Mover_00259348* self);

struct Mover_00259348 {
    char pad0[0x10];
    Vec_00259348 m_pos;
    char pad20[0x74 - 0x20];
    int m_74;
    char pad78[0x8];
    Vec_00259348 m_start;
    Vec_00259348 m_target;
    char padA0[0x20];
    float m_C0;
    int m_C4;
    float m_C8;
    char padCC[0xFC - 0xCC];
    int m_FC;

    void Start(int a, const Vec_00259348& p);
};

void Mover_00259348::Start(int a, const Vec_00259348& p)
{
    m_74 = a;
    float zero = 0.0f;
    m_FC = 0;
    m_C4 = 0;
    m_C8 = zero;
    m_C0 = zero;
    m_start.q = p.q;
    m_pos.q = m_start.q;
    func_00259428(this);
    while ((m_pos - m_target).Length() < 1.0f) {
        if (!func_00259480(this)) return;
    }
    func_00259160(this);
}
