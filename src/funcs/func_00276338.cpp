/* func_00276338: lag/align sampler + feeler; MATCH via const operator[] returning const float& and Vec ctor writing c[] directly */
/* sym: __15Feeler_00276338 = 0x00209240 */
extern "C" float sqrtf(float);
typedef int qword_00276338 __attribute__((mode(TI)));
struct Row_00276338 {
    union {
        qword_00276338 q;
        float c[4];
    };
    float& operator[](int i) { return c[i]; }
    const float& operator[](int i) const { return c[i]; }
    float Length() const { return sqrtf((*this)[0] * (*this)[0] + (*this)[1] * (*this)[1] + (*this)[2] * (*this)[2]); }
    void Normalize();
    void operator*=(float k)
    {
        c[0] *= k;
        c[1] *= k;
        c[2] *= k;
        c[3] *= k;
    }
};
struct Vec_00276338 : Row_00276338 {
    Vec_00276338() {}
    Vec_00276338(const Row_00276338& o) { q = o.q; }
    void operator=(const Row_00276338& o) { q = o.q; }
    Vec_00276338(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
};
extern "C" void func_003233B8(Row_00276338* dst, Row_00276338* src);
inline void Row_00276338::Normalize() { func_003233B8(this, this); }
inline Vec_00276338 operator*(const Row_00276338& a, float k) { return Vec_00276338(a[0] * k, a[1] * k, a[2] * k, a[3] * k); }
inline Vec_00276338 operator+(const Row_00276338& a, const Row_00276338& b)
{
    return Vec_00276338(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}
inline Vec_00276338 operator-(const Row_00276338& a, const Row_00276338& b)
{
    return Vec_00276338(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]);
}

extern "C" void func_00183CB8(void* obj, void* ref);
struct Ref_00276338 {
    void* m_obj;
    ~Ref_00276338()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
};
struct Feeler_00276338 {
    Vec_00276338 m_start;
    Vec_00276338 m_end;
    char pad20[0xA0 - 0x20];
    Vec_00276338 mA0;
    Vec_00276338 mB0;
    Ref_00276338 mC0;
    int mC4[7];
    Feeler_00276338();
};

extern char D_00366B58[];
struct It_00276338 {
    int m0;
    int m4;
    void* m8;
    It_00276338() { m8 = D_00366B58; m4 = 0; }
    ~It_00276338() { m8 = D_00366B58; }
};

struct Conn_00276338 {
    char pad0[0x20B4];
    unsigned int m20B4;
};
struct Player_00276338 {
    char pad0[0x1C];
    Conn_00276338* m1C;
};
struct Body_00276338 {
    char pad0[0xB0];
    Vec_00276338 mB0;
};
struct Elem_00276338 {
    char pad0[0x18];
    Body_00276338* m18;
};
struct Mat_00276338 {
    Row_00276338 r[4];
};
struct Skater_00276338 {
    char pad0[0x18];
    unsigned short m18;
    char pad1a[0x50 - 0x1A];
    Vec_00276338 m50;
    char pad60[0x70 - 0x60];
    Mat_00276338 m70;
};
struct Net_00276338;
extern Net_00276338* D_00392068;
extern "C" void* func_002A39E0(Net_00276338* net, int a);
extern "C" bool func_002A1A38(Net_00276338* net);
extern "C" Player_00276338* func_002A52F0(Net_00276338* net, unsigned short id);
extern "C" Conn_00276338* func_00200EC0(void* net, It_00276338* it);
extern "C" bool func_00202768(Conn_00276338* c);
extern "C" Elem_00276338* func_002A56E0(Net_00276338* net);
extern "C" float func_002032A0(unsigned int, int);
extern "C" void func_00209380(Feeler_00276338* f, Vec_00276338* s, Vec_00276338* e);
extern "C" void func_00209350(Feeler_00276338* f, int a, int b);
extern "C" int func_002093E8(Feeler_00276338* f, int a, int b);

struct Obj_00276338 {
    char pad0[0xC];
    Skater_00276338* mC;
    char pad10[0x30 - 0x10];
    Vec_00276338 m30;
    Vec_00276338 m40;
    char pad50[0x70 - 0x50];
    float m70[20];
    float mC0[20];
    float m110[20];
    char pad160[0x2A0 - 0x160];
    int m2A0;
    float m2A4;
    void Update();
};
extern "C" void func_00275D18(Obj_00276338* o, Vec_00276338* n, Vec_00276338* p);

void Obj_00276338::Update()
{
    Vec_00276338 pos;
    Vec_00276338 d;
    Net_00276338* net = D_00392068;
    void* base = func_002A39E0(net, 0);
    /* the game computes and discards size / 20 and size % 20: see the divide-by-zero trap at 0x00276388 */
    int size = 20;
    int q = size / 20;
    int r = size % 20;
    unsigned int ms = (int)(m2A4 * 1000.0f);
    unsigned int now;
    if (func_002A1A38(net)) {
        Conn_00276338* c = func_002A52F0(net, mC->m18)->m1C;
        now = func_00202768(c) ? 0 : c->m20B4;
    } else {
        It_00276338 it;
        Conn_00276338* c = func_00200EC0(base, &it);
        now = func_00202768(c) ? 0 : c->m20B4;
    }
    float lag;
    if (ms == 0) {
        lag = 0.0f;
    } else {
        lag = (float)(now - ms) / (float)ms;
        if (lag < 0.0f) lag = 0.0f;
    }
    int idx = m2A0 % 20;
    d = m30 - m40;
    Elem_00276338* e = func_002A56E0(net);
    float align;
    if (e && e->m18) {
        Vec_00276338 a = e->m18->mB0;
        Vec_00276338 b = d;
        a.Normalize();
        b.Normalize();
        align = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
        align += 1.0f;
        align *= 0.5f;
    } else {
        align = 0.0f;
    }
    m70[idx] = d.Length() / (float)ms * 16.0f;
    mC0[idx] = lag;
    m110[idx] = align;
    m2A0++;
    float s70 = 0.0f, sC0 = 0.0f, s110 = 0.0f;
    int i;
    for (i = 0; i < 20 && i < m2A0; i++) {
        s70 += m70[i];
        sC0 += mC0[i];
        s110 += m110[i];
    }
    float n = i;
    float a70 = s70 / n;
    lag = sC0 / n;
    align = s110 / n;
    lag *= align;
    d.Normalize();
    d *= a70;
    pos = mC->m50 + d * lag;
    pos[1] = mC->m50[1];
    mC->m50 = pos;
    Skater_00276338* o = mC;
    Vec_00276338 up = o->m70.r[1] * func_002032A0(0xD4205C9B, 0);
    Vec_00276338 start = m30 + up;
    Vec_00276338 end = mC->m50 + up;
    Feeler_00276338 f;
    if ((start - end).Length() > 120.0f) return;
    func_00209380(&f, &start, &end);
    func_00209350(&f, 0x10, 0);
    if (func_002093E8(&f, 1, 0)) {
        func_00275D18(this, &f.mB0, &f.mA0);
    }
}
