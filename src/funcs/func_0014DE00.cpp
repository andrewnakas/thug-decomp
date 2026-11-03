typedef int qword __attribute__((mode(TI)));

extern "C" float sqrtf(float);

struct Vec_0014DE00 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    void Scale(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
    float Length() const { return sqrtf(x * x + y * y + z * z); }
};

struct Mat_0014DE00 {
    Vec_0014DE00 r[4];
    Mat_0014DE00() {}
    const Vec_0014DE00& operator[](int i) const { return r[i]; }
    Mat_0014DE00(const Mat_0014DE00& o)
    {
        r[0] = o[0];
        r[1] = o[1];
        r[2] = o[2];
        r[3] = o[3];
    }
};

extern "C" void func_001713E8(void* p, Vec_0014DE00* pos, Vec_0014DE00* scale, int one);

struct Obj_0014DE00 {
    char pad0[4];
    int m4;
    char pad8[0x20 - 8];
    void* m20;
    char pad24[0x30 - 0x24];
    Mat_0014DE00 m30;
    void Scale(const Vec_0014DE00& s);
};

extern "C" void func_0014E048(Obj_0014DE00* self);

void Obj_0014DE00::Scale(const Vec_0014DE00& s)
{
    Mat_0014DE00 old = m30;
    m30.r[0].Scale(s.x);
    m30.r[1].Scale(s.y);
    m30.r[2].Scale(s.z);
    if (m4 != 2) {
        func_0014E048(this);
    } else {
        Vec_0014DE00 v;
        v.x = s.x / old[0].Length();
        v.y = s.y / old[1].Length();
        v.z = s.z / old[2].Length();
        func_001713E8(m20, &m30.r[3], &v, 1);
    }
}
