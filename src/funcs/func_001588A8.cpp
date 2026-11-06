extern unsigned char* D_00394274;
extern unsigned char* D_00394278;
extern float D_003E1200[];

struct Col_001588A8 {
    unsigned char r, g, b, a;
    Col_001588A8() {}
};

struct V3_001588A8 {
    float x, y, z;
};

typedef int qword_001588A8 __attribute__((mode(TI)));

struct V4_001588A8 {
    union {
        qword_001588A8 q;
        struct {
            float x, y, z, w;
        };
    };
    V4_001588A8() {}
    void Set(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    V4_001588A8(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

static inline V4_001588A8 operator+(const V4_001588A8& a, const V4_001588A8& b)
{
    return V4_001588A8(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

static inline V4_001588A8 operator-(const V4_001588A8& a, const V4_001588A8& b)
{
    return V4_001588A8(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

static inline V4_001588A8 operator*(const V4_001588A8& a, float s)
{
    return V4_001588A8(a.x * s, a.y * s, a.z * s, a.w * s);
}

static inline V4_001588A8 Cross(const V4_001588A8& a, const V4_001588A8& b)
{
    return V4_001588A8(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0.0f);
}

struct E_001588A8 {
    char pad[0x18];
    float m18;
    float m1C;
    float m20;
    float m24;
    float m28;
    float m2C;
};

struct Row_001588A8 {
    V3_001588A8* p;
};

extern "C" void func_00168D98(int a, long b, int c, int d);
extern "C" void func_003233B8(V4_001588A8* d, V4_001588A8* s);
extern "C" void func_00168F58(int tex, V4_001588A8* a, V4_001588A8* b, V4_001588A8* c, V4_001588A8* d,
                              unsigned int c0, unsigned int c1, unsigned int c2, unsigned int c3);

struct C_001588A8 {
    char pad0[0x50];
    float m50, m54, m58;
    char pad5C[0x10C];
    int m168;
    char pad16C[0x60];
    E_001588A8* m1CC;
    char pad1D0[0x14];
    float m1E4;
    char pad1E8[0x18];
    int m200;
    Row_001588A8* m204;
    char pad208[0x8];
    long m210;
    Col_001588A8* m218;
    Col_001588A8* m21C;
    Col_001588A8* m220;
    int m224;
    void Draw();
};

static inline void Norm(V4_001588A8* v)
{
    func_003233B8(v, v);
}

static inline void Lerp(Col_001588A8& o, Col_001588A8* c0, Col_001588A8* c1, float t)
{
    Col_001588A8 x = *c0;
    Col_001588A8 y = *c1;
    o.r = x.r + (int)((y.r - x.r) * t);
    o.g = x.g + (int)((y.g - x.g) * t);
    o.b = x.b + (int)((y.b - x.b) * t);
    o.a = x.a + (int)((y.a - x.a) * t);
}

void C_001588A8::Draw()
{
    if (m168) {
        unsigned int* p = (unsigned int*)D_00394274;
        D_00394278 = (unsigned char*)p;
        p[0] = 0x10000000;
        p[1] = 0;
        D_00394274 = (unsigned char*)(p + 2);
        func_00168D98(m224, m210, 0, 0);
        Col_001588A8 out[2];
        V4_001588A8 up(D_003E1200[8], D_003E1200[9], D_003E1200[10], 0.0f);
        E_001588A8* e = m1CC;
        for (int i = 0; i < m168; i++, e++) {
            float t = e->m28 / e->m2C;
            V4_001588A8 pt[2];
            V3_001588A8* r = &m204[0].p[i];
            pt[0].Set(r->x + m50, r->y + m54, r->z + m58, 1.0f);
            r = &m204[1].p[i];
            pt[1].Set(r->x + m50, r->y + m54, r->z + m58, 1.0f);
            V4_001588A8 d = pt[1] - pt[0];
            V4_001588A8 n = Cross(d, up);
            Norm(&n);
            float w = e->m18 + (e->m20 - e->m18) * t;
            V4_001588A8 q[4];
            Col_001588A8* c0;
            Col_001588A8* c1;
            Col_001588A8 x;
            Col_001588A8 y;
            if (m1E4 >= 0.0f) {
                if (t < m1E4) {
                    t = t / m1E4;
                    c0 = m218;
                    c1 = m21C;
                } else {
                    t = (t - m1E4) / (1.0f - m1E4);
                    c0 = m21C;
                    c1 = m220;
                }
            } else {
                c0 = m218;
                c1 = m220;
            }
            {
                x = *c0;
                y = *c1;
                out[0].r = x.r + (int)((y.r - x.r) * t);
                out[0].g = x.g + (int)((y.g - x.g) * t);
                out[0].b = x.b + (int)((y.b - x.b) * t);
                out[0].a = x.a + (int)((y.a - x.a) * t);
            }
            c0++;
            c1++;
            q[0] = pt[0] + n * w;
            q[1] = pt[0] - n * w;
            for (int j = 1; j < m200; j++) {
                {
                x = *c0;
                y = *c1;
                out[1].r = x.r + (int)((y.r - x.r) * t);
                out[1].g = x.g + (int)((y.g - x.g) * t);
                out[1].b = x.b + (int)((y.b - x.b) * t);
                out[1].a = x.a + (int)((y.a - x.a) * t);
            }
                c0++;
                c1++;
                if (j > 1) {
                    r = &m204[j].p[i];
                    pt[1].Set(r->x + m50, r->y + m54, r->z + m58, 1.0f);
                    d = pt[1] - pt[0];
                    n = Cross(d, up);
                    Norm(&n);
                }
                q[2] = pt[1] - n * w;
                q[3] = pt[1] + n * w;
                func_00168F58(m224, &q[0], &q[1], &q[2], &q[3], *(unsigned int*)&out[0], *(unsigned int*)&out[0],
                              *(unsigned int*)&out[1], *(unsigned int*)&out[1]);
                out[0] = out[1];
                pt[0] = pt[1];
                q[0] = q[3];
                q[1] = q[2];
            }
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
