extern unsigned char* D_00394274;
extern unsigned char* D_00394278;

struct Col_001573B8 {
    unsigned char r, g, b, a;
    Col_001573B8() {}
};

struct V3_001573B8 {
    float x, y, z;
};

static inline V3_001573B8 operator+(const V3_001573B8& a, const V3_001573B8& b)
{
    V3_001573B8 r;
    r.x = a.x + b.x;
    r.y = a.y + b.y;
    r.z = a.z + b.z;
    return r;
}

struct V4_001573B8 {
    float x, y, z, w;
    V4_001573B8(float ax, float ay, float az)
    {
        x = ax;
        y = ay;
        z = az;
        w = 1.0f;
    }
};

struct E_001573B8 {
    char pad[0x28];
    float m28;
    float m2C;
};

extern "C" void func_00168D98(int a, long b, int c, int d);
extern "C" void func_0016B4F8(V4_001573B8* a, V4_001573B8* b, unsigned int c0, unsigned int c1);

struct C_001573B8 {
    char pad0[0x50];
    float m50, m54, m58;
    char pad5C[0x10C];
    int m168;
    char pad16C[0x60];
    E_001573B8* m1CC;
    char pad1D0[0x14];
    float m1E4;
    char pad1E8[0x18];
    int m200;
    V3_001573B8** m204;
    char pad208[0x8];
    long m210;
    Col_001573B8* m218;
    Col_001573B8* m21C;
    Col_001573B8* m220;
    int m224;
    void Draw();
};

void C_001573B8::Draw()
{
    if (m168) {
        unsigned int* p = (unsigned int*)D_00394274;
        D_00394278 = (unsigned char*)p;
        p[0] = 0x10000000;
        p[1] = 0;
        D_00394274 = (unsigned char*)(p + 2);
        func_00168D98(m224, m210, 0, 0);
        Col_001573B8 out[2];
        E_001573B8* e = m1CC;
        V3_001573B8* a = m204[0];
        V3_001573B8* b = m204[m200 - 1];
        int i = 0;
        while (i < m168) {
            float t = e->m28 / e->m2C;
            Col_001573B8* c0;
            Col_001573B8* c1;
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
            for (int j = 0; j < 2; j++) {
                Col_001573B8 x = *c0;
                Col_001573B8 y = *c1;
                out[j].r = x.r + (int)((y.r - x.r) * t);
                out[j].g = x.g + (int)((y.g - x.g) * t);
                out[j].b = x.b + (int)((y.b - x.b) * t);
                out[j].a = x.a + (int)((y.a - x.a) * t);
                c0++;
                c1++;
            }
            V4_001573B8 p0(a->x + m50, a->y + m54, a->z + m58);
            V4_001573B8 p1(b->x + m50, b->y + m54, b->z + m58);
            func_0016B4F8(&p0, &p1, *(unsigned int*)&out[0], *(unsigned int*)&out[1]);
            i++;
            e++;
            a++;
            b++;
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
