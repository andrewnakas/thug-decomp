typedef int qword __attribute__((mode(TI)));

struct Vec_0019F0A8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_0019F0A8() {}
    Vec_0019F0A8(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_0019F0A8& operator+=(const Vec_0019F0A8& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        w += o.w;
        return *this;
    }
};

static inline Vec_0019F0A8 operator*(const Vec_0019F0A8& v, float s)
{
    return Vec_0019F0A8(v.x * s, v.y * s, v.z * s, v.w * s);
}

static inline Vec_0019F0A8 operator-(const Vec_0019F0A8& a, const Vec_0019F0A8& b)
{
    return Vec_0019F0A8(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

struct Body_0019F0A8 {
    char pad0[0x70];
    Vec_0019F0A8 m70;
    Vec_0019F0A8 m80;
    Vec_0019F0A8 m90;
    Vec_0019F0A8 Side(float s) const { return Vec_0019F0A8(m70.x * s, m70.y * s, m70.z * s, m70.w * s); }
    Vec_0019F0A8 Fwd(float s) const { return Vec_0019F0A8(m80.x * s, m80.y * s, m80.z * s, m80.w * s); }
    Vec_0019F0A8 Up(float s) const { return Vec_0019F0A8(m90.x * s, m90.y * s, m90.z * s, m90.w * s); }
};

struct Obj_0019F0A8 {
    char pad0[0xC];
    Body_0019F0A8* mC;
    void Emit(const Vec_0019F0A8& pos, int bone, int type, int useBone, int up, float a, float spread, float b,
              float len);
};

extern "C" void func_0019EFF8(Obj_0019F0A8* o, int bone, Vec_0019F0A8* out);
extern "C" int func_00335048();
extern "C" void func_00143AA0(Vec_0019F0A8* p, Vec_0019F0A8* e, float a, float b, int type, int bone);

static inline float Rnd_0019F0A8(float lo, float range)
{
    return lo + range * (float)func_00335048() * 4.656612873e-10f;
}

void Obj_0019F0A8::Emit(const Vec_0019F0A8& pos, int bone, int type, int useBone, int up, float a, float spread,
                        float b, float len)
{
    Vec_0019F0A8 p;
    if (!bone) {
        p = pos;
    } else {
        func_0019EFF8(this, bone, &p);
    }
    len *= 12.0f;
    Vec_0019F0A8 e;
    if (up) {
        e = p - Vec_0019F0A8(0.0f, 1.0f, 0.0f, 1.0f) * len;
    } else {
        e = p - mC->Fwd(len);
    }
    p += mC->Fwd(12.0f);
    if (spread > 0.0f) {
        float range = spread + spread;
        float lo = -spread;
        float r1 = Rnd_0019F0A8(lo, range);
        float r2 = Rnd_0019F0A8(lo, range);
        e += mC->Side(r1);
        e += mC->Up(r2);
    }
    func_00143AA0(&p, &e, a, b, type, useBone ? bone : 0);
}
