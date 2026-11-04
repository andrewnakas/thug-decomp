typedef int qword __attribute__((mode(TI)));

struct Vec_00143208 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_00143208() {}
    Vec_00143208(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
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

extern "C" float func_00340F60(float a);
extern "C" float func_00341068(float a);

struct Wheel_0019C110 {
    float m0;
    char pad4[0xC - 0x4];
    float mC;
    float m10;
    char pad14[0xC0 - 0x14];
    Vec_00143208 mC0;
    char padD0[0xE0 - 0xD0];
    float mE0;
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
    Vec_00143208 Add(const Vec_00143208& p) const
    {
        return Vec_00143208(m20.x + p.x, m20.y + p.y, m20.z + p.z, m20.w + p.w);
    }
    Vec_00143208 WheelPos(Wheel_0019C110* w, int i, bool flip);
};

Vec_00143208 Obj_0019C110::WheelPos(Wheel_0019C110* w, int i, bool flip)
{
    float x = -3.849999905f;
    if (flip) {
        x = 3.849999905f;
    }
    float a = (float)i * 0.523598671f;
    Vec_00143208 p(x, w->mE0 * func_00340F60(a + w->mC), w->mE0 * func_00341068(a + w->mC), 1.0f);
    Mat_00143208 m(Vec_00143208(0.0f, 1.0f, 0.0f, 1.0f), w->m10);
    p = m.Transform(p);
    p.y += w->m0;
    w->Apply(p);
    p = Add(m_mat.Transform(p));
    return p;
}
