/* fuzzy: 83.3 */
typedef int qword_001A7108 __attribute__((mode(TI)));

struct Vec_001A7108 {
    union {
        struct { float x, y, z, w; };
        qword_001A7108 q;
    };
    Vec_001A7108() {}
    Vec_001A7108(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

static inline Vec_001A7108 operator-(const Vec_001A7108& a, const Vec_001A7108& b)
{
    return Vec_001A7108(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

extern "C" float fabsf(float);
extern "C" float func_00101A10(void* mat, Vec_001A7108* v, int axis, int i);

struct Model_001A7108 {
    char pad[0x70];
    char m70[0x40];
};

struct Obj_001A7108 {
    char pad[0xC];
    Model_001A7108* mC;
    char pad10[0xC];
    int m1C;
    char pad20[0x160 - 0x20];
    float m160[4];
    int m170[4];
    int Method(Vec_001A7108* a, Vec_001A7108* b, int axis, int i, float limit);
};

int Obj_001A7108::Method(Vec_001A7108* a, Vec_001A7108* b, int axis, int i, float limit)
{
    Vec_001A7108 d = *a - *b;
    m170[i] = 0;
    float* base = m160;
    float* out = base + i;
    float r = func_00101A10(mC->m70, &d, axis, i);
    *out = r;
    if (fabsf(r) > limit) {
        m1C |= 1 << i;
        return 1;
    }
    return 0;
}
