/* fuzzy: 93.7 */
typedef int qword_001B2630 __attribute__((mode(TI)));
extern "C" float sqrtf(float);

struct Vec_001B2630 {
    union {
        struct { float x, y, z, w; };
        qword_001B2630 q;
    };
    Vec_001B2630() {}
    Vec_001B2630(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Mat_001B2630 {
    Vec_001B2630 r[4];
};

static inline Vec_001B2630 Sub_001B2630(const Vec_001B2630& a, const Vec_001B2630& b)
{
    return Vec_001B2630(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

static inline float Dot_001B2630(const Vec_001B2630& a, const Vec_001B2630& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

static inline Vec_001B2630 Cross_001B2630(const Vec_001B2630& a, const Vec_001B2630& b)
{
    return Vec_001B2630(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 0.0f);
}

static inline float Length_001B2630(const Vec_001B2630& a)
{
    return sqrtf(Dot_001B2630(a, a));
}

struct Node_001B2630 {
    char pad0[0x50];
    Vec_001B2630 m50;
    char pad1[0xC0 - 0x60];
    Mat_001B2630 mC0;
};

extern "C" float func_001E5318(unsigned int name, int flag);
extern "C" float func_00101BC8(const Vec_001B2630* a, const Vec_001B2630* b);
extern "C" void func_001B3138(void* self, float ang, float k);

struct C_001B2630 {
    char pad0[0xC];
    Node_001B2630* mC;
    char pad1[0x50 - 0x10];
    Vec_001B2630 m50;
    Vec_001B2630 m60;
    void Track();
};

void C_001B2630::Track()
{
    Vec_001B2630 a = m50;
    Vec_001B2630 b = m60;
    a.y = 0.0f;
    b.y = 0.0f;
    Vec_001B2630 p = mC->m50;
    p.y = 0.0f;
    float k = func_001E5318(0xA876AA2C, 1);
    Vec_001B2630 ab = Sub_001B2630(b, a);
    Vec_001B2630 ap = Sub_001B2630(p, a);
    Vec_001B2630 c = Cross_001B2630(ab, ap);
    float t = Dot_001B2630(ap, ab) / Dot_001B2630(ab, ab);
    Vec_001B2630 q(ab.x * t + m50.x, ab.y * t + m50.y, ab.z * t + m50.z, ab.w * t + m50.w);
    q.y = 0.0f;
    Vec_001B2630 d = Sub_001B2630(q, p);
    Mat_001B2630 m = mC->mC0;
    float ang = func_00101BC8(&m.r[2], &d);
    if (ang > 360.0f) {
        ang -= (float)(int)(ang * 0.0027777778f) * 360.0f;
    }
    if (Cross_001B2630(m.r[2], d).y > 0.0f) {
        ang = 360.0f - ang;
    }
    Vec_001B2630 ba = Sub_001B2630(a, b);
    float dist = Length_001B2630(c) / Length_001B2630(ba);
    if (dist > k) {
        k = 1.0f;
    } else {
        k = 1.0f - (k - dist) / k;
    }
    if (dist > func_001E5318(0x81085734, 0)) {
        func_001B3138(this, ang * 0.017453294f, k);
    }
}
