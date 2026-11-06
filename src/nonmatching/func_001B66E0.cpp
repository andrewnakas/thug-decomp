/* fuzzy: 87.1 */
typedef int qword_001B66E0 __attribute__((mode(TI)));

struct Vec_001B66E0 {
    union {
        qword_001B66E0 q;
        struct {
            float x, y, z, w;
        };
    };
    Vec_001B66E0() {}
    Vec_001B66E0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    float operator[](int i) const { return (&x)[i]; }
};

static inline Vec_001B66E0 operator*(const Vec_001B66E0& a, float s)
{
    return Vec_001B66E0(a[0] * s, a[1] * s, a[2] * s, a[3] * s);
}

static inline Vec_001B66E0 operator+(const Vec_001B66E0& a, const Vec_001B66E0& b)
{
    return Vec_001B66E0(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}

class Base_001B66E0 {
public:
    int m0;
    int m_type;
    virtual void V0();
    virtual void Move(Vec_001B66E0* pos);
    virtual void Place(void* where, void* mat, Vec_001B66E0* pos);
    virtual void V3();
    virtual void Disable();
    virtual void Enable();
};

class Shape_001B66E0 : public Base_001B66E0 {
public:
    int mC;
    float m10;
};

struct Skel_001B66E0 {
    char pad[0xF0];
    Vec_001B66E0 mF0;
    char pad100[0xB0];
    unsigned long m_flags;
};

struct Model_001B66E0 {
    char pad[0x260];
    Skel_001B66E0* m260;
};

struct Owner_001B66E0 {
    char pad[0x50];
    Vec_001B66E0 m_pos;
    char pad60[0x10];
    char m70[0x10];
    Vec_001B66E0 m_dir;
};

struct C_001B66E0 {
    char pad[0xC];
    Owner_001B66E0* mC;
    char pad10[0xC];
    Shape_001B66E0* m1C;
    char m20[0x10];
    Vec_001B66E0 m30;
    char pad40[0x4];
    Model_001B66E0* m44;
    void Update();
};

void C_001B66E0::Update()
{
    Shape_001B66E0* s = m1C;
    if (!s)
        return;
    Skel_001B66E0* k = m44 ? m44->m260 : 0;
    if (!k)
        return;
    int on = 0;
    if ((int)(k->m_flags >> 1) & 1)
        on = ((int)(k->m_flags >> 2) & 1) ^ 1;
    if (on) {
    switch (s->m_type) {
    case 1: {
        Vec_001B66E0 v = mC->m_dir * 36.0f;
        v = mC->m_pos + v;
        s->Move(&v);
        break;
    }
    case 2: {
        Vec_001B66E0 r = k->mF0;
        s->m10 = r.x;
        Vec_001B66E0 p = m30;
        m1C->Place(m20, mC->m70, &p);
        break;
    }
    }
    m1C->Enable();
    } else {
        s->Disable();
    }
}
