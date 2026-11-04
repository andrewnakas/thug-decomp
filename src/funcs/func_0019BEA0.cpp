typedef int qword __attribute__((mode(TI)));

struct Vec_0019BEA0 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_0019BEA0() {}
    Vec_0019BEA0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Mat_0019BEA0 {
    Vec_0019BEA0 r[4];
    const Vec_0019BEA0& operator[](int i) const { return r[i]; }
    Mat_0019BEA0& operator=(const Mat_0019BEA0& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
        return *this;
    }
};

struct Body_0019BEA0 {
    char pad0[0x50];
    Vec_0019BEA0 m50;
    char pad60[0x70 - 0x60];
    Mat_0019BEA0 m_mat;
    Vec_0019BEA0 mB0;
    Vec_0019BEA0 At(const Vec_0019BEA0& r) const
    {
        return Vec_0019BEA0(m50.x + r.x, m50.y + r.y, m50.z + r.z, m50.w + r.w);
    }
};

struct Flags_0019BEA0 {
    char pad0[0x34];
    int m34;
};

struct Holder_0019BEA0 {
    char pad0[0xC];
    Body_0019BEA0* m0C;
    char pad10[0x20 - 0x10];
    Mat_0019BEA0 m_mat;
    char pad60[0x5B0 - 0x60];
    Flags_0019BEA0* m5B0;
};

extern void* D_00392068;
extern int D_0038CA30;

extern "C" float func_001A0AB0(void* comp, unsigned int anim);
extern "C" bool func_002A19A8(void* net);
extern "C" void func_001A0F78(void* comp, unsigned int anim, int a, int b, float c, float d, float e, float f);

static inline float Unit_0019BEA0(float v, float lo, float hi)
{
    return (v - lo) / (hi - lo);
}

struct Obj_0019BEA0 {
    char pad0[0xC];
    Body_0019BEA0* m0C;
    char pad10[0x1330 - 0x10];
    int m1330;
    char pad1334[0x1340 - 0x1334];
    Vec_0019BEA0 m1340;
    unsigned int m1350;
    float m1354;
    char pad1358[0x1388 - 0x1358];
    Body_0019BEA0* m1388;
    void* m138C;
    Holder_0019BEA0* m1390;
    Vec_0019BEA0 Local(const Mat_0019BEA0& m) const
    {
        Vec_0019BEA0 v;
        v.x = m1340.x * m.r[0].x + m1340.y * m.r[1].x + m1340.z * m.r[2].x;
        v.y = m1340.x * m.r[0].y + m1340.y * m.r[1].y + m1340.z * m.r[2].y;
        v.z = m1340.x * m.r[0].z + m1340.y * m.r[1].z + m1340.z * m.r[2].z;
        v.w = m1340.w;
        return v;
    }
    void Update();
};

void Obj_0019BEA0::Update()
{
    m1388->m50 = m0C->At(Local(m0C->m_mat));
    m1388->m_mat = m0C->m_mat;
    m1390->m_mat = m1390->m0C->m_mat;
    m1388->mB0 = m0C->mB0;
    if (!m1330) {
        return;
    }
    float f = func_001A0AB0(m138C, m1350);
    float s;
    if (m1390->m5B0->m34) {
        s = m1354;
    } else {
        s = -m1354;
    }
    float g = f * Unit_0019BEA0(s, -1.0f, 1.0f);
    if (!func_002A19A8(D_00392068)) {
        func_001A0F78(m138C, m1350, 0, 1, g, 1000.0f, 0.0f, 0.0f);
        return;
    }
    D_0038CA30++;
    if (D_0038CA30 == 15) {
        D_0038CA30 = 0;
        func_001A0F78(m138C, m1350, 1, 1, g, 1000.0f, 0.0f, 0.0f);
    } else {
        func_001A0F78(m138C, m1350, 0, 1, g, 1000.0f, 0.0f, 0.0f);
    }
}
