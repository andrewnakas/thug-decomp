typedef int qword __attribute__((mode(TI)));

struct Vec_0015BB18 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Vec_0015BB18() {}
    void Zero()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
        w = 0.0f;
    }
    Vec_0015BB18(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

static inline Vec_0015BB18 operator-(const Vec_0015BB18& a, const Vec_0015BB18& b)
{
    return Vec_0015BB18(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

static inline Vec_0015BB18 operator*(const Vec_0015BB18& a, float s)
{
    return Vec_0015BB18(a.x * s, a.y * s, a.z * s, a.w * s);
}

struct Mat_0015BB18 {
    float m[4][4];
    void Ident()
    {
        m[0][0] = 1.0f;
        m[0][1] = 0.0f;
        m[0][2] = 0.0f;
        m[0][3] = 0.0f;
        m[1][0] = 0.0f;
        m[1][1] = 1.0f;
        m[1][2] = 0.0f;
        m[1][3] = 0.0f;
        m[2][0] = 0.0f;
        m[2][1] = 0.0f;
        m[2][2] = 1.0f;
        m[2][3] = 0.0f;
        m[3][0] = 0.0f;
        m[3][1] = 0.0f;
        m[3][2] = 0.0f;
        m[3][3] = 1.0f;
    }
};

struct Tex_0015BB18;

struct Info_0015BB18 {
    char pad0[0x1C];
    Tex_0015BB18* m1C;
    char pad20[0x2C - 0x20];
    Tex_0015BB18* m2C;
};

struct Elem_0015BB18 {
    char pad[0x20];
};

struct Sys_0015BB18 {
    char pad0[0x8];
    int m8;
    char padC[0x18 - 0xC];
    float m18;
    float m1C;
    float m20;
    char pad24[0x2C - 0x24];
    float m2C;
    float m30;
    char pad34[0xB0 - 0x34];
    Vec_0015BB18 mB0;
    Vec_0015BB18 mC0;
    Vec_0015BB18 mD0;
    char padE0[0x120 - 0xE0];
    int m120;
    float m124;
    unsigned char m128[4];
    unsigned char m12C[4];
    unsigned char m130[4];
    unsigned int m134;
    char pad138[0x13C - 0x138];
    int m13C;
    int m140;
    char pad144[0x1A0 - 0x144];
    int m1A0;
    int m1A4;
    int m1A8;
    Elem_0015BB18* m1AC;
    Elem_0015BB18* m1B0;
    Elem_0015BB18* m1B4;
    char pad1B8[0x1C0 - 0x1B8];
    Mat_0015BB18 m1C0;
    int m200;
    int m204;
    int m208;
    int m20C;
    long m210;
    int m218;
    char pad21C[0x228 - 0x21C];
    int m228;
    char pad22C[0x238 - 0x22C];
    int m238;
    char pad23C[0x240 - 0x23C];
    int m240;
    char pad244[0x248 - 0x244];
    int m248;
    char pad24C[0x258 - 0x24C];
    int m258;
    char pad25C[0x260 - 0x25C];
    int m260;
    int m264;
    int m268;
    int m26C;
    char pad270[0x2A0 - 0x270];
    Vec_0015BB18 m2A0;
    Vec_0015BB18 m2B0;
    Vec_0015BB18 m2C0;
    float m2D0[4];
    float m2E0[4];
    float m2F0[4];
    float m300;
    int m304;
    int m308;
    char pad30C[0x310 - 0x30C];
    Tex_0015BB18* m310;
    void Init();
};

extern void* D_00388A70;
extern void* D_00393EF8;
extern "C" void* func_0010A638(void* heap, int size, int a, int b);
extern "C" Info_0015BB18* func_00139468(void* mgr, int id);
extern "C" int func_0017EDA8(Tex_0015BB18* t);
extern "C" int func_0017ED88(Tex_0015BB18* t);
extern "C" void func_0015B780(Sys_0015BB18* self);

static inline void SetReg_0015BB18(long* r, long v)
{
    *r = v;
}

void Sys_0015BB18::Init()
{
    m1A8 = 0;
    m1A4 = 5;
    Elem_0015BB18* p = (Elem_0015BB18*)func_0010A638(D_00388A70, 0xA0, 1, 0);
    m1AC = p;
    m1B0 = p + m1A4 - 1;
    m1B4 = p;
    m1A0 = 0;
    m200 = 0x8005;
    m204 = 0x10000000;
    m208 = 0xE;
    m20C = 0;
    long a = 0;
    long fix = 0x40;
    switch (m134) {
    case 0x68E77F40:
        a = 0x49;
        break;
    case 0xDEA7E576:
        a = 0x42;
        break;
    case 0x54628ED7:
        a = 0x44;
        break;
    case 0x02E58C18:
        a = 0x48;
        break;
    case 0xA7FD7D23:
        a = 0x42;
        break;
    case 0x40F44B8A:
        a = 0x89;
        break;
    case 0x18B98905:
        a = 0x4000000064L;
        break;
    case 0xA86285A1:
        a = 0x4000000068L;
        break;
    case 0x0EEA99FF:
    case 0x0D7A749A:
        a = (fix << 32) | 0x62;
        break;
    case 0x90B93703:
        a = 0x40000000A9L;
        break;
    case 0xB8AA03C9:
        a = 0x4000000069L;
        break;
    case 0x806FFF30:
    case 0x515E298E:
        a = 0;
        break;
    }
    SetReg_0015BB18(&m210, a);
    m310 = 0;
    m218 = 0x42;
    Info_0015BB18* info = func_00139468(D_00393EF8, m140);
    if (info) {
        Tex_0015BB18* t = info->m2C;
        if (!t)
            t = info->m1C;
        m310 = t;
    }
    m228 = 6;
    m238 = 0x14;
    if (m310) {
        m260 = 8;
        m264 = func_0017EDA8(m310) * 16 - 8;
        m268 = func_0017ED88(m310) * 16 - 8;
        m26C = 8;
    }
    m248 = 0x47;
    m240 = (m13C << 4) | 0x5000B;
    m258 = 0xA;
    m304 = 0x60BB4000;
    m308 = 0x535312;
    m300 = m120 ? m2C * m124 * 0.01f : 0.0f;

    float t = m2C;
    float s = t * m30 * 0.01f;
    Vec_0015BB18 p0 = mB0;
    p0.w = m18;
    Vec_0015BB18 p1 = mC0;
    p1.w = m1C;
    Vec_0015BB18 p2 = mD0;
    p2.w = m20;
    Vec_0015BB18 va;
    Vec_0015BB18 vb;
    if (m8) {
        float inv = 1.0f / (s * t * (t - s));
        va = ((p1 - p0) * (t * t) - (p2 - p0) * (s * s)) * inv;
        vb = ((p2 - p0) * s - (p1 - p0) * t) * inv;
    } else {
        va = (p2 - p0) * (1.0f / t);
        vb.Zero();
    }
    m2A0 = p0;
    m2B0 = va;
    m2C0 = vb;
    func_0015B780(this);
    if (m120) {
        float r0 = 100.0f / (m2C * m124);
        float r1 = 100.0f / (m2C * (100.0f - m124));
        m2D0[0] = ((float)m12C[0] - (float)m128[0]) * r0;
        m2D0[1] = ((float)m12C[1] - (float)m128[1]) * r0;
        m2D0[2] = ((float)m12C[2] - (float)m128[2]) * r0;
        m2D0[3] = ((float)m12C[3] - (float)m128[3]) * r0;
        m2E0[0] = m12C[0];
        m2E0[1] = m12C[1];
        m2E0[2] = m12C[2];
        m2E0[3] = m12C[3];
        m2F0[0] = ((float)m130[0] - (float)m12C[0]) * r1;
        m2F0[1] = ((float)m130[1] - (float)m12C[1]) * r1;
        m2F0[2] = ((float)m130[2] - (float)m12C[2]) * r1;
        m2F0[3] = ((float)m130[3] - (float)m12C[3]) * r1;
    } else {
        float r = 1.0f / m2C;
        m2E0[0] = m128[0];
        m2E0[1] = m128[1];
        m2E0[2] = m128[2];
        m2E0[3] = m128[3];
        m2F0[0] = ((float)m130[0] - (float)m128[0]) * r;
        m2F0[1] = ((float)m130[1] - (float)m128[1]) * r;
        m2F0[2] = ((float)m130[2] - (float)m128[2]) * r;
        m2F0[3] = ((float)m130[3] - (float)m128[3]) * r;
    }
    m1C0.Ident();
}
