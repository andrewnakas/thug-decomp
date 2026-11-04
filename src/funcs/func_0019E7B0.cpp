extern "C" float sqrtf(float);

typedef int qword __attribute__((mode(TI)));

struct Vec_0019E7B0 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Vec_0019E7B0() {}
    Vec_0019E7B0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    float Length() const { return sqrtf(x * x + y * y + z * z); }
    void SetLength(float n)
    {
        float l = Length();
        if (l > 0.0f) {
            float s = n / l;
            x *= s;
            y *= s;
            z *= s;
        }
    }
    Vec_0019E7B0& operator+=(const Vec_0019E7B0& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        w += o.w;
        return *this;
    }
};

static inline Vec_0019E7B0 operator*(const Vec_0019E7B0& v, float s)
{
    return Vec_0019E7B0(v.x * s, v.y * s, v.z * s, v.w * s);
}

extern "C" int func_00100030(int n);

struct Obj_0019E7B0 {
    char pad0[0x44];
    float m44;
    char pad48[0x5C - 0x48];
    float m5C;
    char pad60[0x90 - 0x60];
    Vec_0019E7B0 m90;
    Vec_0019E7B0 Dir(const Vec_0019E7B0& p) const
    {
        return Vec_0019E7B0(m90.x - p.x, m90.y - p.y, m90.z - p.z, m90.w - p.w);
    }
    void Throw(const Vec_0019E7B0& vel, const Vec_0019E7B0& pos);
};

extern "C" void func_0019E748(Obj_0019E7B0* o, Vec_0019E7B0* v);

void Obj_0019E7B0::Throw(const Vec_0019E7B0& vel, const Vec_0019E7B0& pos)
{
    Vec_0019E7B0 v = vel;
    float speed = v.Length();
    if (speed < m5C) {
        speed = m5C;
        v.SetLength(speed);
    }
    Vec_0019E7B0 d = Dir(pos);
    d.SetLength(speed);
    v += d * ((float)(func_00100030(100) + 50) * 0.01f);
    v.SetLength(speed);
    v.y = m44 * (speed + 1000.0f) * 0.0005f;
    func_0019E748(this, &v);
}
