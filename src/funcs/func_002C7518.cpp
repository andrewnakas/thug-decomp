typedef int qword __attribute__((mode(TI)));

union Vec_002C7518 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
    Vec_002C7518() {}
    Vec_002C7518(float x, float y, float z, float w)
    {
        f.x = x;
        f.y = y;
        f.z = z;
        f.w = w;
    }
};


struct Box_002C7518 {
    unsigned char x;
    signed char y;
    unsigned char z;
    unsigned char w;
    unsigned char h;
    unsigned char d;
    void SetDims(unsigned char nw, unsigned char nh, unsigned char nd)
    {
        w = nw;
        h = nh;
        d = nd;
    }
    void Rotate() { SetDims(d, h, w); }
};


struct Obj_002C7518;
extern "C" void func_002C98B8(Obj_002C7518* o, int dx, int dz);
extern "C" Vec_002C7518 func_002C02B0(void* a, Box_002C7518* b, Vec_002C7518* out);
extern "C" void func_002CE390(void* p, const Vec_002C7518& v, float ang, int a);
extern "C" void func_002C74D8(Obj_002C7518* o);
extern "C" void func_002BB468(void* p, const Vec_002C7518& v, float ang);

struct Obj_002C7518 {
    int m0;
    int m4;
    void* m8;
    int mC;
    Box_002C7518 m10;
    float m18;
    int m1C;
    Vec_002C7518 m20;
    Vec_002C7518 m30;
    int m40;
    int m44;
    float m48;
    float m4C;
    void* m50;
    char pad54[0x6C - 0x54];
    void* m6C;
    int m70;
    int m74;
    int m78;
    int m7C;
    void Update(int dir, float dx, float dz);
    Vec_002C7518 Pos(const Vec_002C7518& b)
    {
        return Vec_002C7518(m30.f.x + b.f.x, m30.f.y + b.f.y, m30.f.z + b.f.z, m30.f.w + b.f.w);
    }
};

void Obj_002C7518::Update(int dir, float dx, float dz)
{
    if (dir > 0) {
        m44 = (m44 + 1) & 3;
        m48 += 90.0f;
        if (360.0f < m48) {
            m48 -= 360.0f;
            m4C -= 360.0f;
        }
        m10.Rotate();
    } else if (dir < 0) {
        m44 = (m44 - 1) & 3;
        m48 -= 90.0f;
        if (m48 < 0.0f) {
            m48 += 360.0f;
            m4C += 360.0f;
        }
        m10.Rotate();
    }
    float x2 = dx * dx;
    float z2 = dz * dz;
    bool moved = 9.999999e-9f < x2 || 9.999999e-9f < z2;
    if (moved && m18 <= 0.0f) {
        if (x2 * 5.8284f < z2) {
            if (dz < 0.0f) {
                func_002C98B8(this, 0, -1);
            } else {
                func_002C98B8(this, 0, 1);
            }
            m18 = 1.0f;
        } else if (z2 * 5.8284f < x2) {
            if (dx < 0.0f) {
                func_002C98B8(this, -1, 0);
            } else {
                func_002C98B8(this, 1, 0);
            }
            m18 = 1.0f;
        } else {
            if (dz < 0.0f) {
                func_002C98B8(this, 0, -1);
            } else {
                func_002C98B8(this, 0, 1);
            }
            if (dx < 0.0f) {
                func_002C98B8(this, -1, 0);
            } else {
                func_002C98B8(this, 1, 0);
            }
            m18 = 1.0f;
        }
    } else {
        func_002C98B8(this, 0, 0);
    }
    Vec_002C7518 size;
    m20 = func_002C02B0(m8, &m10, &size);
    m20.f.x += size.f.x * 0.5f;
    m20.f.z += size.f.z * 0.5f;
    float t = m18;
    if (0.0f < t) {
        m30.f.y = m20.f.y;
        m18 = t - 0.15f;
        m30.f.x += (m20.f.x - m30.f.x) * 0.15f / t;
        m30.f.z += (m20.f.z - m30.f.z) * 0.15f / t;
        if (m18 < 0.0f)
            m18 = 0.0f;
    } else {
        m18 = 0.0f;
        m30 = m20;
    }
    if (m4C < m48) {
        m4C += 15.0f;
        if (m48 < m4C)
            m4C = m48;
    } else if (m48 < m4C) {
        m4C -= 15.0f;
        if (m4C < m48)
            m4C = m48;
    }
    if (m7C == 5) {
        if (m6C)
            func_002CE390(m6C, Pos(Vec_002C7518(-1.5f, 1.5f, -1.5f, 1.0f)), m4C, m70);
    } else {
        func_002C74D8(this);
        if (m7C != 6)
            func_002BB468(m50, Pos(Vec_002C7518(-1.5f, 1.5f, -1.5f, 1.0f)), m4C);
    }
}
