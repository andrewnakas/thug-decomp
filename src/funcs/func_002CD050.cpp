typedef int qword __attribute__((mode(TI)));

union Vec_002CD050 {
    qword q;
    struct {
        float x, y, z, w;
    } f;
};

struct Def_002CD050 {
    int m0;
    int m4;
    int m8;
    bool Flag8() { return (m8 & 8) != 0; }
};

struct Inst_002CD050 {
    int m0;
    int m4;
    int m8;
};

struct Park_002CD050;

extern const float D_00392610;
extern const float D_00392614;
extern const float D_00392618;
extern "C" float func_00341068(float);
extern "C" float func_00340F60(float);
extern "C" Park_002CD050* func_002C0368();
extern "C" Inst_002CD050* func_002BE6E0(Park_002CD050* b, Def_002CD050* p, int a);
extern "C" void func_002BB468(Inst_002CD050* g, Vec_002CD050 off, float ang);

struct Obj_002CD050 {
    int m0;
    Def_002CD050* m4;
    unsigned char m8;
    signed char m9;
    unsigned char mA;
    char padB;
    int mC;
    unsigned char m10;
    unsigned char m11;
    char pad12[2];
    Inst_002CD050* m14;
    void Place(unsigned char x, unsigned char y, unsigned char z, Vec_002CD050* base, float ang);
};

static inline Vec_002CD050 Get_002CD050(const Vec_002CD050& a)
{
    return a;
}

void Obj_002CD050::Place(unsigned char x, unsigned char y, unsigned char z, Vec_002CD050* base, float ang)
{
    if (!m4)
        return;
    Vec_002CD050 off;
    off.f.x = (m8 - x) * D_00392610 + (m10 - 1) * D_00392610 * 0.5f;
    off.f.y = 0.0f;
    off.f.z = (mA - z) * D_00392618 + (m11 - 1) * D_00392618 * 0.5f;
    off.f.w = 1.0f;
    float rad = ang * 0.01745329425f;
    float s = func_00341068(rad);
    float c = func_00340F60(rad);
    Vec_002CD050 r;
    r.f.x = c * off.f.x + s * off.f.z;
    r.f.y = 0.0f;
    r.f.z = c * off.f.z - s * off.f.x;
    Vec_002CD050 q;
    q.f.x = base->f.x + r.f.x;
    q.f.y = base->f.y + m9 * D_00392614;
    q.f.z = base->f.z + r.f.z;
    q.f.w = base->f.w + r.f.w;
    if (m4->Flag8())
        q.f.y -= D_00392614;
    if (!m14) {
        m14 = func_002BE6E0(func_002C0368(), m4, 1);
        m14->m8 |= 0x200;
    }
    func_002BB468(m14, Get_002CD050(q), ang + mC * 90.0f);
}
