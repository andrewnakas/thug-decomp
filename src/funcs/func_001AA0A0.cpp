typedef int qword_001AA0A0 __attribute__((mode(TI)));

struct Vec_001AA0A0 {
    union {
        struct { float x, y, z, w; };
        qword_001AA0A0 q;
    };
    Vec_001AA0A0() {}
    Vec_001AA0A0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

static inline Vec_001AA0A0 operator-(const Vec_001AA0A0& a, const Vec_001AA0A0& b)
{
    return Vec_001AA0A0(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

extern char D_00362758[];
extern "C" void* func_0013B0E8(int i);
extern "C" Vec_001AA0A0* func_00114E18(void* p);
extern "C" int func_00103F28(const char* fmt, ...);

struct Model_001AA0A0 {
    char pad[0x50];
    Vec_001AA0A0 m50;
};

struct Obj_001AA0A0 {
    char pad[0xC];
    Model_001AA0A0* mC;
    float Method();
};

float Obj_001AA0A0::Method()
{
    void* p = func_0013B0E8(0);
    if (p) {
        Vec_001AA0A0* a = func_00114E18(p);
        Model_001AA0A0* m = mC;
        Vec_001AA0A0 d(a->x - m->m50.x, a->y - m->m50.y, a->z - m->m50.z, a->w - m->m50.w);
        return d.x * d.x + d.y * d.y + d.z * d.z;
    }
    func_00103F28(D_00362758);
    return 0.0f;
}
