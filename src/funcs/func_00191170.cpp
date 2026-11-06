typedef int qword_00191170 __attribute__((mode(TI)));

struct Vec_00191170 {
    union {
        struct { float x, y, z, w; };
        qword_00191170 q;
    };
    Vec_00191170() {}
    Vec_00191170(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_00191170& operator*=(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }
};

static inline Vec_00191170 Cross_00191170(const Vec_00191170& a, const Vec_00191170& b)
{
    return Vec_00191170(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0.0f);
}

static inline Vec_00191170 CrossW_00191170(const Vec_00191170& a, const Vec_00191170& b)
{
    return Vec_00191170(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, a.w);
}

static inline Vec_00191170 operator+(const Vec_00191170& a, const Vec_00191170& b)
{
    return Vec_00191170(a.x + b.x, a.y + b.y, a.z + b.z, a.w);
}

struct Obj_00191170 {
    char pad[0x1C];
    float m1C;
    float Method(Vec_00191170* a, Vec_00191170* b);
};

float Obj_00191170::Method(Vec_00191170* a, Vec_00191170* b)
{
    Vec_00191170 c = Cross_00191170(*b, *a);
    c *= m1C;
    Vec_00191170 e = *a + CrossW_00191170(c, *b);
    return 1.0f / (a->x * e.x + a->y * e.y + a->z * e.z);
}
