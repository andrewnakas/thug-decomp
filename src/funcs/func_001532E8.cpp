extern unsigned char* D_00394274;
extern unsigned char* D_00394278;
extern float D_003E1200[];

typedef int qword_001532E8 __attribute__((mode(TI)));

struct Col_001532E8 {
    unsigned char r, g, b, a;
    Col_001532E8() {}
};

struct V3_001532E8 {
    float x, y, z;
};

struct V4_001532E8 {
    union {
        qword_001532E8 q;
        struct {
            float x, y, z, w;
        };
        float c[4];
    };
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    V4_001532E8() {}
    V4_001532E8(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    V4_001532E8(float ax, float ay, float az)
    {
        x = ax;
        y = ay;
        z = az;
        w = 1.0f;
    }
};

static inline V4_001532E8 operator*(const V4_001532E8& a, float s)
{
    return V4_001532E8(a.x * s, a.y * s, a.z * s, a.w * s);
}

static inline V4_001532E8 operator+(const V4_001532E8& a, const V4_001532E8& b)
{
    return V4_001532E8(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

static inline V4_001532E8 operator-(const V4_001532E8& a, const V4_001532E8& b)
{
    return V4_001532E8(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

static inline V4_001532E8 Cross(const V4_001532E8& a, const V4_001532E8& b)
{
    return V4_001532E8(a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0], 0.0f);
}

struct E_001532E8 {
    char pad[0x18];
    float m18;
    float m1C;
    float m20;
    float m24;
    float m28;
    float m2C;
};

extern "C" void func_00168D98(int a, long b, int c, int d);
extern "C" void func_003233B8(V4_001532E8* d, V4_001532E8* s);
extern "C" void func_00168F58(int tex, V4_001532E8* a, V4_001532E8* b, V4_001532E8* c, V4_001532E8* d,
                              unsigned int c0, unsigned int c1, unsigned int c2, unsigned int c3);

struct C_001532E8 {
    char pad0[0x50];
    float m50, m54, m58;
    char pad5C[0x10C];
    int m168;
    char pad16C[0x60];
    E_001532E8* m1CC;
    char pad1D0[0x14];
    float m1E4;
    char pad1E8[0x18];
    V3_001532E8* m200;
    char pad204[0x4];
    long m208;
    Col_001532E8 m210[4];
    Col_001532E8 m220[4];
    Col_001532E8 m230[4];
    int m240;
    void Draw();
};

void C_001532E8::Draw()
{
    if (m168) {
        V4_001532E8 yax(0.0f, 1.0f, 0.0f, 0.0f);
        V4_001532E8 up(D_003E1200[8], D_003E1200[9], D_003E1200[10], 0.0f);
        V4_001532E8 right = Cross(up, yax);
        V4_001532E8 fwd = Cross(right, up);
        func_003233B8(&right, &right);
        func_003233B8(&fwd, &fwd);
        unsigned int* p = (unsigned int*)D_00394274;
        D_00394278 = (unsigned char*)p;
        p[0] = 0x10000000;
        p[1] = 0;
        D_00394274 = (unsigned char*)(p + 2);
        func_00168D98(m240, m208, 0, 0);
        E_001532E8* e = m1CC;
        V3_001532E8* a = m200;
        for (int i = 0; i < m168; i++, e++, a++) {
            float t = e->m28 / e->m2C;
            float w = e->m18 + (e->m20 - e->m18) * t;
            float h = e->m1C + (e->m24 - e->m1C) * t;
            V4_001532E8 c(a->x + m50, a->y + m54, a->z + m58);
            V4_001532E8 R;
            V4_001532E8 U;
            V4_001532E8 q[4];
            R = right * w;
            U = fwd * h;
            q[0] = c - R + U;
            q[1] = c + R + U;
            q[2] = c + R - U;
            q[3] = c - R - U;
            Col_001532E8 out[4];
            Col_001532E8* c0;
            Col_001532E8* c1;
            if (m1E4 >= 0.0f) {
                if (t < m1E4) {
                    t = t / m1E4;
                    c0 = m210;
                    c1 = m220;
                } else {
                    t = (t - m1E4) / (1.0f - m1E4);
                    c0 = m220;
                    c1 = m230;
                }
            } else {
                c0 = m210;
                c1 = m230;
            }
            for (int j = 0; j < 4; j++) {
                Col_001532E8 x = *c0;
                Col_001532E8 y = *c1;
                out[j].r = x.r + (int)((y.r - x.r) * t);
                out[j].g = x.g + (int)((y.g - x.g) * t);
                out[j].b = x.b + (int)((y.b - x.b) * t);
                out[j].a = x.a + (int)((y.a - x.a) * t);
                c0++;
                c1++;
            }
            func_00168F58(m240, &q[0], &q[1], &q[2], &q[3], *(unsigned int*)&out[0], *(unsigned int*)&out[1],
                          *(unsigned int*)&out[2], *(unsigned int*)&out[3]);
        }
        int kind = (*(unsigned int*)D_00394278 >> 28) & 7;
        while ((unsigned int)D_00394274 & 0xF) {
            *(unsigned int*)D_00394274 = 0;
            D_00394274 += 4;
        }
        if (kind != 3 && kind != 0 && kind != 4) {
            *(unsigned short*)D_00394278 = ((D_00394274 - D_00394278) - 8) >> 4;
        }
    }
}
