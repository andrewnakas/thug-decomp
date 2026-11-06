typedef int qword __attribute__((mode(TI)));

struct Vec_00143208 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_00143208() {}
    Vec_00143208(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    void Set(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Mat_00143208 {
    Vec_00143208 r[4];
    Mat_00143208(const Vec_00143208& axis, float angle);
    Vec_00143208 Transform(const Vec_00143208& v) const
    {
        Vec_00143208 o;
        o.x = v.x * r[0].x + v.y * r[1].x + v.z * r[2].x;
        o.y = v.x * r[0].y + v.y * r[1].y + v.z * r[2].y;
        o.z = v.x * r[0].z + v.y * r[1].z + v.z * r[2].z;
        o.w = v.w;
        return o;
    }
};

static inline Vec_00143208 Xf(const Mat_00143208& m, const Vec_00143208& v)
{
    Vec_00143208 o;
    o.x = v.x * m.r[0].x + v.y * m.r[1].x + v.z * m.r[2].x;
    o.y = v.x * m.r[0].y + v.y * m.r[1].y + v.z * m.r[2].y;
    o.z = v.x * m.r[0].z + v.y * m.r[1].z + v.z * m.r[2].z;
    o.w = v.w;
    return o;
}

extern "C" void func_001235E8(Vec_00143208* a, Vec_00143208* b, unsigned int c0, unsigned int c1, int a4);
extern "C" void func_001235F8(Vec_00143208* a, unsigned int c, int a2, float size);

struct Wheel_0019C110 {
    float m0;
    int m4;
    char pad8[0xC - 0x8];
    float mC;
    float m10;
    char pad14[0xC0 - 0x14];
    Vec_00143208 mC0;
    char padD0[0xE0 - 0xD0];
    float mE0;
    char padE4[0x220 - 0xE4];
    Mat_00143208 Rot() const { return Mat_00143208(Vec_00143208(0.0f, 1.0f, 0.0f, 1.0f), m10); }
    void Apply(Vec_00143208& p) const
    {
        p.x += mC0.x;
        p.y += mC0.y;
        p.z += mC0.z;
        p.w += mC0.w;
    }
};

struct Obj_0019C110 {
    char pad0[0x20];
    Vec_00143208 m20;
    char pad30[0x70 - 0x30];
    Mat_00143208 m_mat;
    char padB0[0x110 - 0xB0];
    Vec_00143208 m110;
    char pad120[0x1C4 - 0x120];
    int m1C4;
    char pad1C8[0x318 - 0x1C8];
    Wheel_0019C110* m318;
    char pad31C[0x1380 - 0x31C];
    int m1380;
    Vec_00143208 Add(const Vec_00143208& p) const
    {
        return Vec_00143208(m20.x + p.x, m20.y + p.y, m20.z + p.z, m20.w + p.w);
    }
    Vec_00143208 WheelPos(Wheel_0019C110* w, int i, bool flip);
    void Draw_0019C380();
};

/* sym: __12Mat_00143208RC12Vec_00143208f = 0x00100700 */
/* sym: WheelPos__12Obj_0019C110P14Wheel_0019C110ib = 0x0019C110 */

void Obj_0019C110::Draw_0019C380()
{
    if (m1380) {
        int i = m1C4;
        while (i--) {
            Wheel_0019C110* w = &m318[i];
            int c;
            switch (w->m4) {
            case 2:
                c = 0xFF00FF00;
                break;
            case 3:
                c = 0xFF000000;
                break;
            case 4:
                c = 0xFF00C8FF;
                break;
            case 5:
                c = 0xFF0000FF;
                break;
            case 6:
                c = 0xFF960096;
                break;
            case 7:
                c = 0xFF969600;
                break;
            case 0:
            case 1:
            default:
                c = -1;
                break;
            }
            int j = 12;
            while (j--) {
                Vec_00143208 a = WheelPos(w, j, true);
                Vec_00143208 b = WheelPos(w, j + 1, true);
                func_001235E8(&a, &b, c, c, 1);
                a = WheelPos(w, j, false);
                b = WheelPos(w, j + 1, false);
                func_001235E8(&a, &b, c, c, 1);
                a = WheelPos(w, j, true);
                b = WheelPos(w, j, false);
                func_001235E8(&a, &b, c, c, 1);
                Mat_00143208 m = w->Rot();
                a.Set(-240.0f, 0.0f, 0.0f, 1.0f);
                a = Xf(m, a);
                w->Apply(a);
                a.y += w->m0;
                a = Add(m_mat.Transform(a));
                b.Set(240.0f, 0.0f, 0.0f, 1.0f);
                b = Xf(m, b);
                w->Apply(b);
                b.y += w->m0;
                b = Add(m_mat.Transform(b));
                func_001235E8(&a, &b, 0xFF000000, 0xFF000000, 1);
            }
        }
    }
    if (m1380) {
        Vec_00143208 a(m20.x + m110.x, m20.y + m110.y, m20.z + m110.z, m20.w + m110.w);
        func_001235F8(&a, 0xFF640064, 1, 12.0f);
        a = m20;
        func_001235F8(&a, 0xFF646400, 1, 12.0f);
    }
}
