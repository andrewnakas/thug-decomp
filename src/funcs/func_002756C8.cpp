/* sym: _vt$11It_002756C8 = 0x00366B58 */
typedef int qword __attribute__((mode(TI)));

extern "C" float sqrtf(float);

struct Vec_002756C8 {
    union {
        qword q;
        float c[4];
    };
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    void operator*=(float k)
    {
        c[0] *= k;
        c[1] *= k;
        c[2] *= k;
        c[3] *= k;
    }
};
struct VecC_002756C8 : Vec_002756C8 {
    VecC_002756C8(float x, float y, float z, float w) { c[0] = x; c[1] = y; c[2] = z; c[3] = w; }
};
static inline VecC_002756C8 operator-(const Vec_002756C8& a, const Vec_002756C8& b) { return VecC_002756C8(a[0] - b[0], a[1] - b[1], a[2] - b[2], a[3] - b[3]); }

struct It_002756C8 {
    void* m_cur;
    int m_4;
    It_002756C8() { m_4 = 0; }
    virtual void Reset();
    virtual ~It_002756C8() {}
};

struct Conn_002756C8 {
    char pad0[0x20B4];
    unsigned int m20B4;
};

struct Player_002756C8 {
    char pad0[0x1C];
    Conn_002756C8* m1C;
};

struct Body_002756C8 {
    char pad0[0x18];
    unsigned short m18;
    char pad1A[0x50 - 0x1A];
    Vec_002756C8 m50;
};

struct Target_002756C8 {
    char pad0[0xB0];
    Vec_002756C8 mB0;
};

struct Peer_002756C8 {
    char pad0[0x18];
    Target_002756C8* m18;
};

struct Rail_002756C8 {
    char pad0[0x88];
    short m88;
    char pad8A[0x90 - 0x8A];
};

struct Holder_002756C8 {
    char pad0[0x20];
    Rail_002756C8 m20[1];
};

struct Global_002756C8 {
    char pad0[0x28];
    void* m28;
};

extern Global_002756C8* D_0038FC78;
extern void* D_00392068;
extern "C" void* func_002A39E0(void* net, int a);
extern "C" int func_002A1A38(void* net);
extern "C" Player_002756C8* func_002A52F0(void* net, unsigned short id);
extern "C" Conn_002756C8* func_00200EC0(void* self, It_002756C8* it);
extern "C" int func_00202768(Conn_002756C8* c);
extern "C" Peer_002756C8* func_002A56E0(void* net);
extern "C" void func_003233B8(Vec_002756C8* a, Vec_002756C8* b);
extern "C" void* func_0026B2F8(void* mgr, int id);
static inline void Norm_002756C8(Vec_002756C8& v) { func_003233B8(&v, &v); }
struct Obj_002756C8;
extern "C" void* func_00274DE8(Obj_002756C8* self, void* rail, float t);
extern "C" void func_00276338(Obj_002756C8* self);

struct Obj_002756C8 {
    char pad0[0xC];
    Body_002756C8* mC;
    char pad10[0x18];
    int m28;
    char pad2C[4];
    Vec_002756C8 m30;
    Vec_002756C8 m40;
    char pad50[0x20];
    float m70[20];
    float mC0[20];
    float m110[20];
    char pad160[0x2A0 - 0x160];
    int m2A0;
    float m2A4;
    char pad2A8[4];
    Holder_002756C8* m2AC;
    void Update();
};

void Obj_002756C8::Update()
{
    Vec_002756C8 d;
    void* mgr = D_0038FC78->m28;
    void* net = D_00392068;
    void* s = func_002A39E0(net, 0);
    /* the game computes and discards k / 20 and k % 20: see the divide-by-zero trap at 0x00275728 */
    int k = 20;
    int q = k / 20;
    int r = k % 20;
    Rail_002756C8* rails = m2AC->m20;
    unsigned int period = (int)(m2A4 * 1000.0f);
    unsigned int now;
    if (func_002A1A38(net)) {
        Conn_002756C8* c = func_002A52F0(net, mC->m18)->m1C;
        if (func_00202768(c))
            now = 0;
        else
            now = c->m20B4;
    } else {
        It_002756C8 it;
        Conn_002756C8* c = func_00200EC0(s, &it);
        if (func_00202768(c))
            now = 0;
        else
            now = c->m20B4;
    }
    float lag;
    if (period == 0) {
        lag = 0.0f;
    } else {
        lag = (float)(now - period) / (float)period;
        if (lag < 0.0f) lag = 0.0f;
    }
    int idx = m2A0 % 20;
    d = m30 - m40;
    float align = 0.0f;
    Peer_002756C8* p = func_002A56E0(net);
    if (p) {
        Vec_002756C8 a = p->m18->mB0;
        Vec_002756C8 b = d;
        Norm_002756C8(a);
        Norm_002756C8(b);
        align = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
        align += 1.0f;
        align *= 0.5f;
    }
    m70[idx] = sqrtf(d[0] * d[0] + d[1] * d[1] + d[2] * d[2]) / (float)period * 16.0f;
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
    float n = (float)i;
    float a70 = s70 / n;
    lag = sC0 / n;
    align = s110 / n;
    Norm_002756C8(d);
    d *= a70;
    lag *= align;
    float t = m2A4 * lag;
    if (t > 1.0f) t = 1.0f;
    void* rail = func_0026B2F8(mgr, rails[m28].m88);
    if (!rail) return;
    for (;; t -= m2A4) {
        if (t > 0.0f) {
            if (t > m2A4)
                rail = func_00274DE8(this, rail, m2A4);
            else
                rail = func_00274DE8(this, rail, t);
            if (!rail) break;
        } else
            return;
    }
    mC->m50 = m30;
    func_00276338(this);
}
