extern unsigned char* D_00394274;
extern unsigned char* D_00394278;
extern float D_003E1200[];

struct Col_001595F8 {
    unsigned char r, g, b, a;
    Col_001595F8() {}
};

struct V3_001595F8 {
    float x, y, z;
};

typedef int qword_001595F8 __attribute__((mode(TI)));

struct V4_001595F8 {
    union {
        qword_001595F8 q;
        struct {
            float x, y, z, w;
        };
    };
    V4_001595F8() {}
    V4_001595F8(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

static inline V4_001595F8 operator+(const V4_001595F8& a, const V4_001595F8& b)
{
    return V4_001595F8(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

static inline V4_001595F8 operator-(const V4_001595F8& a, const V4_001595F8& b)
{
    return V4_001595F8(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

static inline V4_001595F8 operator*(const V4_001595F8& a, float s)
{
    return V4_001595F8(a.x * s, a.y * s, a.z * s, a.w * s);
}

static inline V4_001595F8 Cross(const V4_001595F8& a, const V4_001595F8& b)
{
    return V4_001595F8(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0.0f);
}

struct E_001595F8 {
    char pad[0x18];
    float m18;
    float m1C;
    float m20;
    float m24;
    float m28;
    float m2C;
};

struct Row_001595F8 {
    V3_001595F8* p;
};

extern "C" void func_00168D98(int a, long b, int c, int d);
extern "C" void func_003233B8(V4_001595F8* d, V4_001595F8* s);
extern "C" void func_00168F58(int tex, V4_001595F8* a, V4_001595F8* b, V4_001595F8* c, V4_001595F8* d,
                              unsigned int c0, unsigned int c1, unsigned int c2, unsigned int c3);

struct C_001595F8 {
    char pad0[0x50];
    float m50, m54, m58;
    char pad5C[0x10C];
    int m168;
    char pad16C[0x60];
    E_001595F8* m1CC;
    char pad1D0[0x14];
    float m1E4;
    char pad1E8[0x18];
    int m200;
    Row_001595F8* m204;
    char pad208[0x8];
    long m210;
    Col_001595F8 m218[4];
    Col_001595F8 m228[4];
    Col_001595F8 m238[4];
    int m248;
    void Draw();
};

void C_001595F8::Draw()
{
    if (m168) {
        unsigned int* p = (unsigned int*)D_00394274;
        D_00394278 = (unsigned char*)p;
        p[0] = 0x10000000;
        p[1] = 0;
        D_00394274 = (unsigned char*)(p + 2);
        func_00168D98(m248, m210, 0, 0);
        Col_001595F8 out[4];
        V4_001595F8 up(D_003E1200[8], D_003E1200[9], D_003E1200[10], 0.0f);
        E_001595F8* e = m1CC;
        V3_001595F8* a = m204[0].p;
        V3_001595F8* b = m204[m200 - 1].p;
        for (int i = 0; i < m168; i++, a++, e++, b++) {
            float t = e->m28 / e->m2C;
            V4_001595F8 p0(a->x + m50, a->y + m54, a->z + m58, 1.0f);
            V4_001595F8 p1(b->x + m50, b->y + m54, b->z + m58, 1.0f);
            V4_001595F8 d = p1 - p0;
            V4_001595F8 n = Cross(d, up);
            func_003233B8(&n, &n);
            float w = e->m18 + (e->m20 - e->m18) * t;
            V4_001595F8 pts[4];
            pts[0] = p0 + n * w;
            pts[1] = p0 - n * w;
            pts[2] = p1 - n * w;
            pts[3] = p1 + n * w;
            Col_001595F8* c0;
            Col_001595F8* c1;
            if (m1E4 >= 0.0f) {
                if (t < m1E4) {
                    t = t / m1E4;
                    c0 = m218;
                    c1 = m228;
                } else {
                    t = (t - m1E4) / (1.0f - m1E4);
                    c0 = m228;
                    c1 = m238;
                }
            } else {
                c0 = m218;
                c1 = m238;
            }
            for (int j = 0; j < 4; j++) {
                Col_001595F8 x = *c0;
                Col_001595F8 y = *c1;
                out[j].r = x.r + (int)((y.r - x.r) * t);
                out[j].g = x.g + (int)((y.g - x.g) * t);
                out[j].b = x.b + (int)((y.b - x.b) * t);
                out[j].a = x.a + (int)((y.a - x.a) * t);
                c0++;
                c1++;
            }
            func_00168F58(m248, &p0, &pts[0], &pts[3], &p1, *(unsigned int*)&out[0], *(unsigned int*)&out[1],
                          *(unsigned int*)&out[2], *(unsigned int*)&out[3]);
            func_00168F58(m248, &p0, &pts[1], &pts[2], &p1, *(unsigned int*)&out[0], *(unsigned int*)&out[1],
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
