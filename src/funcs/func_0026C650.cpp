typedef int qword __attribute__((mode(TI)));

struct Vec_0026C650 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_0026C650() {}
    Vec_0026C650(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_0026C650& operator*=(float s) { x *= s; y *= s; z *= s; w *= s; return *this; }
};

extern "C" void func_003233B8(Vec_0026C650* dst, Vec_0026C650* src);
extern "C" void func_00102E58(void* m, const Vec_0026C650* p, Vec_0026C650* out);

struct Obj_0026C650 {
    char m_pad0[0x10];
    Vec_0026C650 m10;
    char m_pad20[0x14];
    int m34;
    float m38;
    char m_pad3C[0x14];
    char m50[0x40];
    Vec_0026C650 Project(const Vec_0026C650& p);
};

extern "C" int func_0026C538(Obj_0026C650* self, const Vec_0026C650* p);

Vec_0026C650 Obj_0026C650::Project(const Vec_0026C650& p)
{
    if (func_0026C538(this, &p)) {
        return p;
    }
    Vec_0026C650 r;
    if (m34 != 0) {
        if (m34 == 2) {
            Vec_0026C650 d(p.x - m10.x, p.y - m10.y, p.z - m10.z, p.w - m10.w);
            func_003233B8(&d, &d);
            d *= m38;
            r = Vec_0026C650(m10.x + d.x, m10.y + d.y, m10.z + d.z, m10.w + d.w);
        }
    } else {
        func_00102E58(m50, &p, &r);
    }
    return r;
}
