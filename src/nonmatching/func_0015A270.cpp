/* fuzzy: 96.4 */
extern unsigned char* D_00394274;
extern unsigned char* D_00394278;
extern float D_003E1200[];

struct Col_0015A270 {
    unsigned char r, g, b, a;
    Col_0015A270() {}
};

struct V3_0015A270 {
    float x, y, z;
};

typedef int qword_0015A270 __attribute__((mode(TI)));

struct V4_0015A270 {
    union {
        qword_0015A270 q;
        struct {
            float x, y, z, w;
        };
    };
    V4_0015A270() {}
    void Set(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    V4_0015A270& operator+=(const V4_0015A270& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        w += v.w;
        return *this;
    }
    V4_0015A270(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
};

static inline V4_0015A270 operator+(const V4_0015A270& a, const V4_0015A270& b)
{
    return V4_0015A270(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

static inline V4_0015A270 operator-(const V4_0015A270& a, const V4_0015A270& b)
{
    return V4_0015A270(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

static inline V4_0015A270 operator*(const V4_0015A270& a, float s)
{
    return V4_0015A270(a.x * s, a.y * s, a.z * s, a.w * s);
}

static inline V4_0015A270 Cross(const V4_0015A270& a, const V4_0015A270& b)
{
    return V4_0015A270(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0.0f);
}

struct E_0015A270 {
    char pad[0x18];
    float m18;
    float m1C;
    float m20;
    float m24;
    float m28;
    float m2C;
};

struct Row_0015A270 {
    V3_0015A270* p;
};

extern "C" float func_00341068(float a);
extern "C" float func_00340F60(float a);
extern "C" void func_0016A600(V4_0015A270* c, V4_0015A270* a, V4_0015A270* b, V4_0015A270* d, V4_0015A270* e,
                              unsigned int c0, unsigned int c1, unsigned int c2);
extern "C" void func_00168D98(int a, long b, int c, int d);
extern "C" void func_003233B8(V4_0015A270* d, V4_0015A270* s);
extern "C" void func_00168F58(int tex, V4_0015A270* a, V4_0015A270* b, V4_0015A270* c, V4_0015A270* d,
                              unsigned int c0, unsigned int c1, unsigned int c2, unsigned int c3);

static inline void Norm(V4_0015A270* v)
{
    func_003233B8(v, v);
}

struct C_0015A270 {
    char pad0[0x50];
    float m50, m54, m58;
    char pad5C[0x10C];
    int m168;
    char pad16C[0x60];
    E_0015A270* m1CC;
    char pad1D0[0x14];
    float m1E4;
    char pad1E8[0x18];
    int m200;
    Row_0015A270* m204;
    char pad208[0x8];
    long m210;
    int m218;
    float m21C;
    Col_0015A270* m220;
    Col_0015A270* m224;
    Col_0015A270* m228;
    int m22C;
    void Draw();
};

void C_0015A270::Draw()
{
    if (m168) {
        V4_0015A270 yax(0.0f, 1.0f, 0.0f, 0.0f);
        V4_0015A270 up(D_003E1200[8], D_003E1200[9], D_003E1200[10], 0.0f);
        V4_0015A270 right = Cross(up, yax);
        V4_0015A270 fwd = Cross(right, up);
        func_003233B8(&right, &right);
        func_003233B8(&fwd, &fwd);
        unsigned int* p = (unsigned int*)D_00394274;
        D_00394278 = (unsigned char*)p;
        p[0] = 0x10000000;
        p[1] = 0;
        D_00394274 = (unsigned char*)(p + 2);
        func_00168D98(m22C, m210, 0, 0);
        Col_0015A270 out[3];
        E_0015A270* e = m1CC;
        for (int i = 0; i < m168; i++, e++) {
            float t = e->m28 / e->m2C;
            V4_0015A270 pt[2];
            V3_0015A270* a = &m204[0].p[i];
            pt[0].Set(a->x + m50, a->y + m54, a->z + m58, 1.0f);
            V3_0015A270* b = &m204[1].p[i];
            pt[1].Set(b->x + m50, b->y + m54, b->z + m58, 1.0f);
            V4_0015A270 d = pt[1] - pt[0];
            V4_0015A270 n = Cross(d, up);
            Norm(&n);
            float w = e->m18 + (e->m20 - e->m18) * t;
            float h = e->m1C + (e->m24 - e->m1C) * t;
            V4_0015A270 q[4];
            Col_0015A270* c0;
            Col_0015A270* c1;
            Col_0015A270 x;
            Col_0015A270 y;
            if (m1E4 >= 0.0f) {
                if (t < m1E4) {
                    t = t / m1E4;
                    c0 = m220 + 3;
                    c1 = m224 + 3;
                } else {
                    t = (t - m1E4) / (1.0f - m1E4);
                    c0 = m224 + 3;
                    c1 = m228 + 3;
                }
            } else {
                c0 = m220 + 3;
                c1 = m228 + 3;
            }
            x = *c0;
            y = *c1;
            out[0].r = x.r + (int)((y.r - x.r) * t);
            out[0].g = x.g + (int)((y.g - x.g) * t);
            out[0].b = x.b + (int)((y.b - x.b) * t);
            out[0].a = x.a + (int)((y.a - x.a) * t);
            c0++;
            c1++;
            q[0] = pt[0] + n * w * m21C;
            q[1] = pt[0] - n * w * m21C;
            for (int j = 1; j < m200; j++) {
                x = *c0;
                y = *c1;
                out[1].r = x.r + (int)((y.r - x.r) * t);
                out[1].g = x.g + (int)((y.g - x.g) * t);
                out[1].b = x.b + (int)((y.b - x.b) * t);
                out[1].a = x.a + (int)((y.a - x.a) * t);
                c0++;
                c1++;
                if (j > 1) {
                    Row_0015A270* rr = m204;
                    rr += j;
                    V3_0015A270* r = &rr->p[i];
                    pt[1].Set(r->x + m50, r->y + m54, r->z + m58, 1.0f);
                    d = pt[1] - pt[0];
                    n = Cross(d, up);
                    Norm(&n);
                }
                q[2] = pt[1] - n * w * m21C;
                q[3] = pt[1] + n * w * m21C;
                func_00168F58(m22C, &q[0], &q[1], &q[2], &q[3], *(unsigned int*)&out[0], *(unsigned int*)&out[0],
                              *(unsigned int*)&out[1], *(unsigned int*)&out[1]);
                out[0] = out[1];
                pt[0] = pt[1];
                q[0] = q[3];
                q[1] = q[2];
            }
            V3_0015A270* a2 = &m204[0].p[i];
            pt[0].Set(a2->x + m50, a2->y + m54, a2->z + m58, 1.0f);
            V4_0015A270 R;
            V4_0015A270 U;
            R = right * w;
            U = fwd * h;
            if (m1E4 >= 0.0f) {
                if (t < m1E4) {
                    t = t / m1E4;
                    c0 = m220;
                    c1 = m224;
                } else {
                    t = (t - m1E4) / (1.0f - m1E4);
                    c0 = m224;
                    c1 = m228;
                }
            } else {
                c0 = m220;
                c1 = m228;
            }
            for (int j = 0; j < 3; j++) {
                Col_0015A270 cx = *c0;
                Col_0015A270 cy = *c1;
                out[j].r = cx.r + (int)((cy.r - cx.r) * t);
                out[j].g = cx.g + (int)((cy.g - cx.g) * t);
                out[j].b = cx.b + (int)((cy.b - cx.b) * t);
                out[j].a = cx.a + (int)((cy.a - cx.a) * t);
                c0++;
                c1++;
            }
            q[0] = pt[0];
            q[0] += R * func_00341068(0.0f) * m21C;
            q[0] += U * func_00340F60(0.0f) * m21C;
            q[2] = pt[0];
            q[2] += R * func_00341068(0.0f);
            q[2] += U * func_00340F60(0.0f);
            for (int k = 0; k < m218; k++) {
                q[1] = pt[0];
                q[1] += R * func_00341068(360.0f / m218 * (k + 1) * 0.0174532943f) * m21C;
                q[1] += U * func_00340F60(360.0f / m218 * (k + 1) * 0.0174532943f) * m21C;
                q[3] = pt[0];
                q[3] += R * func_00341068(360.0f / m218 * (k + 1) * 0.0174532943f);
                q[3] += U * func_00340F60(360.0f / m218 * (k + 1) * 0.0174532943f);
                func_0016A600(&pt[0], &q[0], &q[1], &q[2], &q[3], *(unsigned int*)&out[0], *(unsigned int*)&out[1],
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
