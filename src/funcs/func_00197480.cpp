extern "C" float sqrtf(float);

typedef int qword __attribute__((mode(TI)));

struct Vec_00197480 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Vec_00197480() {}
    Vec_00197480(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_00197480(float ax, float ay, float az) { x = ax; y = ay; z = az; w = 1.0f; }
    float Length() const { return sqrtf(x * x + y * y + z * z); }
    Vec_00197480& operator-=(const Vec_00197480& o)
    {
        x -= o.x;
        y -= o.y;
        z -= o.z;
        w -= o.w;
        return *this;
    }
};

static inline Vec_00197480 operator*(const Vec_00197480& v, float s)
{
    return Vec_00197480(v.x * s, v.y * s, v.z * s, v.w * s);
}

struct Mat_00197480 {
    Vec_00197480 r[3];
    Vec_00197480 Rotate(const Vec_00197480& p) const
    {
        Vec_00197480 o;
        o.x = p.x * r[0].x + p.y * r[1].x + p.z * r[2].x;
        o.y = p.x * r[0].y + p.y * r[1].y + p.z * r[2].y;
        o.z = p.x * r[0].z + p.y * r[1].z + p.z * r[2].z;
        o.w = p.w;
        return o;
    }
};

struct Wheel_00197480 {
    float m0;
    int m_state;
    float m8;
    float mC;
    float m_angle;
    char pad14[0x30 - 0x14];
    Vec_00197480 m_axis;
    char pad40[0x70 - 0x40];
    Vec_00197480 m_normal;
    float m80;
    char pad84[0xE0 - 0x84];
    float mE0;
    char padE4[0x120 - 0xE4];
    Vec_00197480 m120;
    Vec_00197480 m130;
    char pad140[0x220 - 0x140];
};

struct Obj_00197480 {
    char pad0[0x70];
    Mat_00197480 m_mat;
    char padA0[0x1C4 - 0xA0];
    int m_numWheels;
    char pad1C8[0x318 - 0x1C8];
    Wheel_00197480* m_wheels;
};

extern "C" Vec_00197480* func_001016A8(Vec_00197480* v, const Vec_00197480* n);
extern "C" float func_00341068(float a);
extern "C" float func_00340F60(float a);
extern "C" void func_003233B8(Vec_00197480* d, Vec_00197480* s);
extern "C" float func_00197378(Obj_00197480* o, Wheel_00197480* w, float len);

extern "C" void func_00197480(Obj_00197480* o)
{
    int i = o->m_numWheels;
    while (i-- != 0) {
        Wheel_00197480* w = &o->m_wheels[i];
        if (w->m_state != 1) {
            Vec_00197480 axis = w->m_axis;
            func_001016A8(&axis, &w->m_normal);
            Vec_00197480 dir(func_00341068(w->m_angle), 0.0f, func_00340F60(w->m_angle));
            dir = o->m_mat.Rotate(dir);
            func_001016A8(&dir, &w->m_normal);
            func_003233B8(&dir, &dir);
            w->m120 = dir;
            w->m130 = axis;
            axis -= dir * (w->m8 * w->mE0);
            w->m80 = func_00197378(o, w, axis.Length());
        }
    }
}
