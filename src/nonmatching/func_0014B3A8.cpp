/* fuzzy: 63.4 */
typedef int qword __attribute__((mode(TI)));

struct Vec_0014B3A8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_0014B3A8() {}
    Vec_0014B3A8(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

static inline Vec_0014B3A8 operator*(float s, const Vec_0014B3A8& v)
{
    return Vec_0014B3A8(v.x * s, v.y * s, v.z * s, v.w * s);
}

extern Vec_0014B3A8 D_003DDA50;
extern Vec_0014B3A8 D_003DDA20[];

struct Model_0014B3A8 {
    unsigned int m_flags;
    char pad4[0x3C];
    Vec_0014B3A8 m_srcDir[2];
    char pad60[0x10];
    Vec_0014B3A8 m_srcAmb;
    Vec_0014B3A8 m_dirCol[2];
    char padA0[0x10];
    Vec_0014B3A8 m_ambCol;
    const Vec_0014B3A8* GetAmb()
    {
        if (m_flags & 1) {
            return &m_srcAmb;
        }
        return &D_003DDA50;
    }
    const Vec_0014B3A8* GetDir(int i)
    {
        return (m_flags & (2 << i)) ? &m_srcDir[i] : &D_003DDA20[i];
    }
    void SetAmb(const Vec_0014B3A8& v)
    {
        m_ambCol = v;
        m_flags |= 0x10;
    }
    void SetDir(int i, const Vec_0014B3A8& v)
    {
        m_dirCol[i] = v;
        m_flags |= 0x20 << i;
    }
};


class Comp_0014B3A8 {
public:
    int m0;
    int m4;
    float m_amb;
    float m_dir[2];
    char pad14[0x8];
    Model_0014B3A8* m1C;
    void Apply();
};

void Comp_0014B3A8::Apply()
{
    Model_0014B3A8* m = m1C;
    m->SetAmb(m_amb * *m->GetAmb());
    for (int i = 0; i < 2; i++) {
        Model_0014B3A8* d = m1C;
        d->SetDir(i, m_dir[i] * *d->GetDir(i));
    }
}
