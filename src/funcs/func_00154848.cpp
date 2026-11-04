extern unsigned char* D_00394274;
extern unsigned char* D_00394278;
extern float D_003E1200[];

typedef int qword_00154848 __attribute__((mode(TI)));

struct Col_00154848 {
    unsigned char r, g, b, a;
    Col_00154848() {}
};

struct V3_00154848 {
    float x, y, z;
};

struct V4_00154848 {
    union {
        qword_00154848 q;
        struct {
            float x, y, z, w;
        };
    };
    V4_00154848() {}
    V4_00154848(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    V4_00154848(float ax, float ay, float az)
    {
        x = ax;
        y = ay;
        z = az;
        w = 1.0f;
    }
    V4_00154848& operator+=(const V4_00154848& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        w += v.w;
        return *this;
    }
};

static inline V4_00154848 operator*(const V4_00154848& a, float s)
{
    return V4_00154848(a.x * s, a.y * s, a.z * s, a.w * s);
}

static inline V4_00154848 Cross(const V4_00154848& a, const V4_00154848& b)
{
    return V4_00154848(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0.0f);
}

struct E_00154848 {
    char pad[0x18];
    float m18;
    float m1C;
    float m20;
    float m24;
    float m28;
    float m2C;
};

extern "C" void func_00168D98(int a, long b, int c, int d);
extern "C" void func_003233B8(V4_00154848* d, V4_00154848* s);
extern "C" float func_00341068(float a);
extern "C" float func_00340F60(float a);
extern "C" void func_0016A600(V4_00154848* c, V4_00154848* a, V4_00154848* b, V4_00154848* d, V4_00154848* e,
                              unsigned int c0, unsigned int c1, unsigned int c2);

struct C_00154848 {
    char pad0[0x50];
    float m50, m54, m58;
    char pad5C[0x10C];
    int m168;
    char pad16C[0x60];
    E_00154848* m1CC;
    char pad1D0[0x14];
    float m1E4;
    char pad1E8[0x18];
    V3_00154848* m200;
    char pad204[0x4];
    long m208;
    int m210;
    float m214;
    Col_00154848 m218[3];
    Col_00154848 m224[3];
    Col_00154848 m230[3];
    int m23C;
    void Draw();
};

void C_00154848::Draw()
{
    if (m168) {
        V4_00154848 yax(0.0f, 1.0f, 0.0f, 0.0f);
        V4_00154848 up(D_003E1200[8], D_003E1200[9], D_003E1200[10], 0.0f);
        V4_00154848 right = Cross(up, yax);
        V4_00154848 fwd = Cross(right, up);
        func_003233B8(&right, &right);
        func_003233B8(&fwd, &fwd);
        unsigned int* p = (unsigned int*)D_00394274;
        D_00394278 = (unsigned char*)p;
        p[0] = 0x10000000;
        p[1] = 0;
        D_00394274 = (unsigned char*)(p + 2);
        func_00168D98(m23C, m208, 0, 0);
        E_00154848* e = m1CC;
        V3_00154848* a = m200;
        for (int i = 0; i < m168; i++, e++, a++) {
            float t = e->m28 / e->m2C;
            float w = e->m18 + (e->m20 - e->m18) * t;
            float h = e->m1C + (e->m24 - e->m1C) * t;
            V4_00154848 c(a->x + m50, a->y + m54, a->z + m58);
            V4_00154848 R;
            V4_00154848 U;
            V4_00154848 q[4];
            R = right * w;
            U = fwd * h;
            Col_00154848 out[3];
            Col_00154848* c0;
            Col_00154848* c1;
            if (m1E4 >= 0.0f) {
                if (t < m1E4) {
                    t = t / m1E4;
                    c0 = m218;
                    c1 = m224;
                } else {
                    t = (t - m1E4) / (1.0f - m1E4);
                    c0 = m224;
                    c1 = m230;
                }
            } else {
                c0 = m218;
                c1 = m230;
            }
            for (int j = 0; j < 3; j++) {
                Col_00154848 x = *c0;
                Col_00154848 y = *c1;
                out[j].r = x.r + (int)((y.r - x.r) * t);
                out[j].g = x.g + (int)((y.g - x.g) * t);
                out[j].b = x.b + (int)((y.b - x.b) * t);
                out[j].a = x.a + (int)((y.a - x.a) * t);
                c0++;
                c1++;
            }
            q[0] = c;
            q[0] += R * func_00341068(0.0f) * m214;
            q[0] += U * func_00340F60(0.0f) * m214;
            q[2] = c;
            q[2] += R * func_00341068(0.0f);
            q[2] += U * func_00340F60(0.0f);
            for (int k = 0; k < m210; k++) {
                q[1] = c;
                q[1] += R * func_00341068(360.0f / m210 * (k + 1) * 0.0174532943f) * m214;
                q[1] += U * func_00340F60(360.0f / m210 * (k + 1) * 0.0174532943f) * m214;
                q[3] = c;
                q[3] += R * func_00341068(360.0f / m210 * (k + 1) * 0.0174532943f);
                q[3] += U * func_00340F60(360.0f / m210 * (k + 1) * 0.0174532943f);
                func_0016A600(&c, &q[0], &q[1], &q[2], &q[3], *(unsigned int*)&out[0], *(unsigned int*)&out[1],
                              *(unsigned int*)&out[2]);
                q[0] = q[1];
                q[2] = q[3];
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
