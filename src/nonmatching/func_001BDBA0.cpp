/* fuzzy: 88.3 */
/* blocked: game copies mB0 to the stack (sq 0x20) but multiplies the fields read from mC->mB0, w first; by-value operator*, const& vel, temp ctor and member operator* all worse. */
typedef int qword_001BDBA0 __attribute__((mode(TI)));

struct Vec_001BDBA0 {
    union {
        struct { float x, y, z, w; };
        qword_001BDBA0 q;
    };
    Vec_001BDBA0() {}
    Vec_001BDBA0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

static inline Vec_001BDBA0 operator+(const Vec_001BDBA0& a, const Vec_001BDBA0& b)
{
    return Vec_001BDBA0(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

static inline Vec_001BDBA0 operator*(const Vec_001BDBA0& v, float s)
{
    return Vec_001BDBA0(v.x * s, v.y * s, v.z * s, v.w * s);
}

extern void* D_00392068;
extern "C" int func_002A19A8(void* net);
extern "C" int func_001A9E60(void* p);
extern "C" float func_0010FAB8();

struct Model_001BDBA0 {
    char pad[0x50];
    Vec_001BDBA0 m50;
    char pad60[0xB0 - 0x60];
    Vec_001BDBA0 mB0;
};

struct Obj_001BDBA0 {
    char pad[0xC];
    Model_001BDBA0* mC;
    char pad10[0xC];
    void* m1C;
    void Method();
};

void Obj_001BDBA0::Method()
{
    if (func_002A19A8(D_00392068) || !func_001A9E60(m1C)) {
        Vec_001BDBA0 p;
        Vec_001BDBA0 pos = mC->m50;
        Vec_001BDBA0 vel = mC->mB0;
        p = pos + vel * 0.5f * func_0010FAB8();
        mC->m50 = p;
    }
}
