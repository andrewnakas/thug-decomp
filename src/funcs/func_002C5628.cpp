typedef int qword __attribute__((mode(TI)));
union Vec_002C5628 {
    qword q;
    float c[4];
    Vec_002C5628() {}
    Vec_002C5628(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    void operator+=(const Vec_002C5628& o)
    {
        c[0] += o.c[0];
        c[1] += o.c[1];
        c[2] += o.c[2];
        c[3] += o.c[3];
    }
};

struct Mat_002C5628;
extern "C" void func_00323318(Mat_002C5628* d, const Mat_002C5628* a, Mat_002C5628* b);
struct Mat_002C5628 {
    Vec_002C5628 r0;
    Vec_002C5628 r1;
    Vec_002C5628 r2;
    Vec_002C5628 r3;
    void Ident()
    {
        r0.c[0] = 1.0f;
        r0.c[1] = 0.0f;
        r0.c[2] = 0.0f;
        r0.c[3] = 0.0f;
        r1.c[0] = 0.0f;
        r1.c[1] = 1.0f;
        r1.c[2] = 0.0f;
        r1.c[3] = 0.0f;
        r2.c[0] = 0.0f;
        r2.c[1] = 0.0f;
        r2.c[2] = 1.0f;
        r2.c[3] = 0.0f;
        r3.c[0] = 0.0f;
        r3.c[1] = 0.0f;
        r3.c[2] = 0.0f;
        r3.c[3] = 1.0f;
    }
    Mat_002C5628& operator=(const Mat_002C5628& o)
    {
        r0.q = o.r0.q;
        r1.q = o.r1.q;
        r2.q = o.r2.q;
        r3.q = o.r3.q;
        return *this;
    }
    void RotateX(float a);
    void RotateY(float a);
};

extern "C" Mat_002C5628* func_00100890(Mat_002C5628* out, float a);
extern "C" Mat_002C5628* func_00100928(Mat_002C5628* out, float a);
inline void Mat_002C5628::RotateX(float a)
{
    Mat_002C5628 t;
    func_00323318(this, func_00100890(&t, a), this);
}
inline void Mat_002C5628::RotateY(float a)
{
    Mat_002C5628 t;
    func_00323318(this, func_00100928(&t, a), this);
}

struct Cam_002C5628 {
    char pad0[0x50];
    Vec_002C5628 m50;
    char pad60[0x70 - 0x60];
    Mat_002C5628 m70;
};
struct Ctl_002C5628 {
    char pad0[0x30];
    float m30;
    float m34;
    float m38;
    char pad3C[0x7C - 0x3C];
    int m7C;
    char pad80[0xC8 - 0x80];
    int mC8;
    bool Is(int v) const { return m7C == v; }
    bool Mode(int v) const { return mC8 == v; }
    bool Locked() const { return m7C == 2 || m7C == 3; }
};

extern void* D_0038C608;
extern char D_0037A918[];
extern char D_0037A930[];
extern char D_0037A948[];
extern char D_0037A960[];
extern char D_0037A970[];
extern char D_0037A990[];
extern char D_0037A9A8[];
extern char D_0037A9C0[];

extern "C" Cam_002C5628* func_00187B48(void* p, unsigned int name);
extern "C" int func_0010FC30();
extern "C" float func_00340F60(float);
extern "C" float func_00341068(float);
extern "C" void func_001F0370(char* name, int a, int b, int c);
extern "C" void func_002C7F88(Ctl_002C5628* c, int a, int b, int d);
extern "C" void func_002C8EA0(Ctl_002C5628* c, int a);
extern "C" int func_002C7BF8(Ctl_002C5628* c);
extern "C" int func_002C95B0(Ctl_002C5628* c);
extern "C" int func_002C8618(Ctl_002C5628* c);
extern "C" void func_002C8C70(Ctl_002C5628* c);
extern "C" int func_002C79A0(Ctl_002C5628* c);
extern "C" int func_002C7EE0(Ctl_002C5628* c);
extern "C" void func_002C86F0(Ctl_002C5628* c);
extern "C" int func_002C7AC8(Ctl_002C5628* c);
extern "C" void* func_002CC830();
extern "C" void func_002CC178(void* p);
extern "C" int func_002C93B8(Ctl_002C5628* c, int d);
extern "C" void* func_0029C320();
extern "C" void func_0029A500(void* p);
extern "C" void func_0029A598(void* p);
extern "C" void func_0029A608(void* p);
extern "C" void* func_002977B0();
extern "C" void func_00296968(void* p);
extern "C" void func_002C7518(Ctl_002C5628* c, float x, float z, int d);
extern "C" void func_002C8D08(Ctl_002C5628* c);
extern "C" void func_002C7488(Ctl_002C5628* c);

static inline float Dead_002C5628(float v)
{
    float r;
    if (50.0f < v)
        r = (v - 50.0f) * 0.01282051299f;
    else if (v < -50.0f)
        r = (v + 50.0f) * 0.01282051299f;
    else
        r = 0.0f;
    return r;
}

struct Top_002C5628 {
    bool x0 : 7;
    bool b7 : 1;
};

struct Game_002C5628 {
    char pad0[0x38];
    int m38;
    char pad3C[0x48 - 0x3C];
    float m48;
    float m4C;
    float m50;
    float m54;
    float m58;
    float m5C;
    union {
        unsigned int m60;
        unsigned char m60c[4];
        struct {
            bool x0 : 7;
            bool b7 : 1;
        } m60b;
    };
    int pad64;
    float m68;
    float m6C;
    float m70;
    char pad74[0xA0 - 0x74];
    Ctl_002C5628* mA0;
    int padA4;
    int mA8;
    int padAC;
    int mB0;
    bool Flag(unsigned int f) const { return (m60 & f) && !mA0->Locked(); }
    bool B(unsigned int f) const { return (m60 & f) != 0; }
    bool AnyPress() const { return B(0x20) || B(0x40) || B(0x80) || B(0x100); }
    void Control();
    void Camera();
};
extern "C" void func_002C5468(Game_002C5628* g);

void Game_002C5628::Control()
{
    float k = 0.01745329425f;
    Mat_002C5628 m;
    m.Ident();
    Vec_002C5628& t = m.r3;
    t = Vec_002C5628(0.0f, 0.0f, m70, 1.0f);
    m.RotateX(-m6C * k);
    m.RotateY(m68 * k);
    t += Vec_002C5628(mA0->m30, 300.0f, mA0->m38, 0.0f);
    Cam_002C5628* cam = func_00187B48(D_0038C608, 0x64716BEE);
    if (cam) {
        cam->m50 = m.r3;
        cam->m70 = m;
    }
    if (mB0)
        return;
    if (!mA0->Is(4))
        func_002C8EA0(mA0, 0);
    int now = func_0010FC30();
    float dt = (float)(now - mA8) * 0.001000000047f;
    mA8 = now;
    m5C = Dead_002C5628(m5C);
    m58 = Dead_002C5628(m58);
    float fwd = m58 * dt * m48;
    float side = m5C * dt * m48;
    float a = m68 * 0.01745329425f;
    float cx = func_00340F60(a) * fwd;
    float x = cx + func_00341068(a) * side;
    float cz = func_00340F60(a) * side;
    float z = cz - func_00341068(a) * fwd;
    m54 = Dead_002C5628(m54);
    m50 = Dead_002C5628(m50);
    m68 += m50 * dt * m4C;
    if (m68 < 0.0f)
        m68 += 360.0f;
    else if (360.0f <= m68)
        m68 -= 360.0f;
    m6C -= m54 * dt * m4C;
    if (m6C < 10.0f)
        m6C = 10.0f;
    else if (90.0f < m6C)
        m6C = 90.0f;
    int dir = 0;
    if (m60 & 2) {
        func_001F0370(D_0037A918, 0, 0, 0);
        if (mA0->Locked())
            func_002C7F88(mA0, -1, 0, 0);
        else
            dir = -1;
    }
    if (m60 & 4) {
        func_001F0370(D_0037A918, 0, 0, 0);
        if (mA0->Locked())
            func_002C7F88(mA0, -1, 0, 0);
        else
            dir = 1;
    }
    if (m60 & 0x20) {
        if (mA0->Locked()) {
            if ((func_002C7BF8(mA0) || func_002C95B0(mA0)) && !mA0->Mode(1)) {
                func_001F0370(D_0037A930, 0, 0, 0);
                func_001F0370(D_0037A948, 0, 0, 0);
            } else {
                func_001F0370(D_0037A960, 0, 0, 0);
            }
            m38 = 1;
        } else if (mA0->Is(4)) {
            switch (func_002C8618(mA0)) {
            case 1:
                func_001F0370(D_0037A930, 0, 0, 0);
                break;
            case 2:
                func_001F0370(D_0037A930, 0, 0, 0);
                func_001F0370(D_0037A970, 0, 0, 0);
                break;
            default:
                func_001F0370(D_0037A960, 0, 0, 0);
                break;
            }
        } else if (mA0->Is(5)) {
            func_002C8C70(mA0);
            m38 = 1;
        } else {
            if (func_002C79A0(mA0))
                func_001F0370(D_0037A930, 0, 0, 0);
            else
                func_001F0370(D_0037A960, 0, 0, 0);
            m38 = 1;
        }
    }
    if (m60 & 0x40) {
        if (mA0->Locked()) {
            if (func_002C7EE0(mA0))
                func_001F0370(D_0037A990, 0, 0, 0);
            else
                func_001F0370(D_0037A960, 0, 0, 0);
        } else if (mA0->Is(4)) {
            func_002C86F0(mA0);
            m38 = 1;
        } else {
            if (func_002C7AC8(mA0))
                func_001F0370(D_0037A990, 0, 0, 0);
            else
                func_001F0370(D_0037A960, 0, 0, 0);
            m38 = 1;
        }
        func_002CC178(func_002CC830());
    }
    func_002C5468(this);
    if (m60b.b7) {
        if (!mA0->Locked()) {
            if (func_002C93B8(mA0, 1))
                func_001F0370(D_0037A9A8, 0, 0, 0);
            else
                func_001F0370(D_0037A960, 0, 0, 0);
        }
        m38 = 1;
    }
    if (m60c[1] & 1) {
        if (!mA0->Locked()) {
            if (func_002C93B8(mA0, -1))
                func_001F0370(D_0037A9C0, 0, 0, 0);
            else
                func_001F0370(D_0037A960, 0, 0, 0);
        }
        m38 = 1;
    }
    if (Flag(0x2000)) {
        m70 += 16.0f;
        if (1500.0f < m70)
            m70 = 1500.0f;
    }
    if (Flag(0x4000)) {
        m70 -= 16.0f;
        if (m70 < 500.0f)
            m70 = 500.0f;
    }
    if (((const Top_002C5628*)&m60c[1])->b7 && mA0->Locked())
        func_002C7F88(mA0, 0, 1, 0);
    if ((m60 & 0x800) && mA0->Locked())
        func_002C7F88(mA0, 0, 0, 1);
    if ((m60 & 0x10000) && mA0->Locked())
        func_002C7F88(mA0, 0, -1, 0);
    if ((m60 & 0x1000) && mA0->Locked())
        func_002C7F88(mA0, 0, 0, -1);
    if (AnyPress()) {
        void* p = func_0029C320();
        func_0029A500(p);
        func_0029A598(p);
        func_0029A608(p);
        func_00296968(func_002977B0());
    }
    func_002C7518(mA0, x, z, dir);
    if (mA0->Is(4))
        func_002C8D08(mA0);
    else if (mA0->Is(6))
        func_002C7488(mA0);
    else
        func_002C8EA0(mA0, 1);
}
