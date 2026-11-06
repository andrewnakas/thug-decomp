extern unsigned char* D_00394274;
extern unsigned char* D_00394278;
extern float D_003E1200[];

typedef int qword_00153DA8 __attribute__((mode(TI)));

struct Col_00153DA8 {
    unsigned char r, g, b, a;
    Col_00153DA8() {}
};

struct V3_00153DA8 {
    float x, y, z;
};

struct V4_00153DA8 {
    union {
        qword_00153DA8 q;
        struct {
            float x, y, z, w;
        };
    };
    V4_00153DA8() {}
    V4_00153DA8(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    V4_00153DA8(float ax, float ay, float az)
    {
        x = ax;
        y = ay;
        z = az;
        w = 1.0f;
    }
};

static inline V4_00153DA8 operator*(const V4_00153DA8& a, float s)
{
    return V4_00153DA8(a.x * s, a.y * s, a.z * s, a.w * s);
}

static inline V4_00153DA8 operator+(const V4_00153DA8& a, const V4_00153DA8& b)
{
    return V4_00153DA8(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

static inline V4_00153DA8 operator-(const V4_00153DA8& a, const V4_00153DA8& b)
{
    return V4_00153DA8(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

static inline V4_00153DA8 Cross(const V4_00153DA8& a, const V4_00153DA8& b)
{
    return V4_00153DA8(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0.0f);
}

struct E_00153DA8 {
    char pad[0x18];
    float m18;
    float m1C;
    float m20;
    float m24;
    float m28;
    float m2C;
};

extern "C" void func_00168D98(int a, long b, int c, int d);
extern "C" void func_003233B8(V4_00153DA8* d, V4_00153DA8* s);
extern "C" void func_00169E68(int a, V4_00153DA8* c, V4_00153DA8* q0, V4_00153DA8* q1, V4_00153DA8* q2,
                              V4_00153DA8* q3, unsigned int c0, unsigned int c1);

struct C_00153DA8 {
    char pad0[0x50];
    float m50, m54, m58;
    char pad5C[0x10C];
    int m168;
    char pad16C[0x60];
    E_00153DA8* m1CC;
    char pad1D0[0x14];
    float m1E4;
    char pad1E8[0x18];
    V3_00153DA8* m200;
    char pad204[0x4];
    long m208;
    Col_00153DA8 m210[2];
    Col_00153DA8 m218[2];
    Col_00153DA8 m220[2];
    int m228;
    void Draw();
};

void C_00153DA8::Draw()
{
    if (m168) {
        V4_00153DA8 yax(0.0f, 1.0f, 0.0f, 0.0f);
        V4_00153DA8 up(D_003E1200[8], D_003E1200[9], D_003E1200[10], 0.0f);
        V4_00153DA8 right = Cross(up, yax);
        V4_00153DA8 fwd = Cross(right, up);
        func_003233B8(&right, &right);
        func_003233B8(&fwd, &fwd);
        unsigned int* p = (unsigned int*)D_00394274;
        D_00394278 = (unsigned char*)p;
        p[0] = 0x10000000;
        p[1] = 0;
        D_00394274 = (unsigned char*)(p + 2);
        func_00168D98(m228, m208, 0, 0);
        E_00153DA8* e = m1CC;
        V3_00153DA8* a = m200;
        for (int i = 0; i < m168; i++, e++, a++) {
            float t = e->m28 / e->m2C;
            float w = e->m18 + (e->m20 - e->m18) * t;
            float h = e->m1C + (e->m24 - e->m1C) * t;
            V4_00153DA8 c(a->x + m50, a->y + m54, a->z + m58);
            V4_00153DA8 R;
            V4_00153DA8 U;
            V4_00153DA8 q[4];
            R = right * w;
            U = fwd * h;
            q[0] = c - R + U;
            q[1] = c + R + U;
            q[2] = c + R - U;
            q[3] = c - R - U;
            Col_00153DA8 out[2];
            Col_00153DA8* c0;
            Col_00153DA8* c1;
            if (m1E4 >= 0.0f) {
                if (t < m1E4) {
                    t = t / m1E4;
                    c0 = m210;
                    c1 = m218;
                } else {
                    t = (t - m1E4) / (1.0f - m1E4);
                    c0 = m218;
                    c1 = m220;
                }
            } else {
                c0 = m210;
                c1 = m220;
            }
            for (int j = 0; j < 2; j++) {
                Col_00153DA8 x = *c0;
                Col_00153DA8 y = *c1;
                out[j].r = x.r + (int)((y.r - x.r) * t);
                out[j].g = x.g + (int)((y.g - x.g) * t);
                out[j].b = x.b + (int)((y.b - x.b) * t);
                out[j].a = x.a + (int)((y.a - x.a) * t);
                c0++;
                c1++;
            }
            func_00169E68(m228, &c, &q[0], &q[1], &q[2], &q[3], *(unsigned int*)&out[0], *(unsigned int*)&out[1]);
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
