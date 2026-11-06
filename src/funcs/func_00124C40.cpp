typedef int qword __attribute__((mode(TI)));

struct Vec_00124C40 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Vec_00124C40& operator=(const Vec_00124C40& o)
    {
        q = o.q;
        return *this;
    }
};

struct Rgba_00124C40 {
    struct Bytes { unsigned char r, g, b, a; } v;
    Rgba_00124C40(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
    {
        v.r = r;
        v.g = g;
        v.b = b;
        v.a = a;
    }
    Rgba_00124C40(const Rgba_00124C40& o) { v = o.v; }
};

struct Tex_00124C40 {
    float m0;
    Vec_00124C40 m10;
    float m20;
    float m24;
    int m28;
    float m2C;
    float m30;
    float m34;
    float m38;
    float m3C;
    float m40;
    float m44;
    Rgba_00124C40 m48;
    void Blend(Tex_00124C40* g, float k, float k2)
    {
        float px = m20 + (g->m20 - m20) * k;
        float py = m24 + (g->m24 - m24) * k;
        m20 = px;
        m24 = py;
        float sx = m34 + (g->m34 - m34) * k2;
        float sy = m38 + (g->m38 - m38) * k2;
        m34 = sx;
        m38 = sy;
        m44 += (g->m44 - m44) * k2;
    }
    void SetColor(Rgba_00124C40 c)
    {
        m48.v.r = c.v.r;
        m48.v.g = c.v.g;
        m48.v.b = c.v.b;
        m48.v.a = c.v.a;
    }
};

class Elem_00124C40;

static inline float ToParent_00124C40(float origin, float v, float scale)
{
    return origin + v * scale;
}

extern "C" int func_0010FC30();
extern "C" void func_00124118(Elem_00124C40* self, int on);
extern "C" void* func_0013AF50(int n);
extern "C" float func_00114BE0(void* cam, Vec_00124C40* pos, float* x, float* y, int* z);
extern "C" void func_00123DB0(Elem_00124C40* self, float x, float y, int relative, int f);
extern "C" void func_00125798(Elem_00124C40* self, Tex_00124C40* t);

class Base_00124C40 {
public:
    int m0;
    int m4;
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
};

class Elem_00124C40 : public Base_00124C40 {
public:
    unsigned int m_flags;
    char pad10[0x44 - 0x10];
    int m_busy;
    Elem_00124C40* m_parent;
    char pad4C[0x54 - 0x4C];
    Elem_00124C40* m_child;
    char pad58[0x60 - 0x58];
    Elem_00124C40* m_next;
    char pad64[0x80 - 0x64];
    Tex_00124C40 m80;
    Tex_00124C40 mD0;
    unsigned int m_start;
    unsigned int m_dur;
    float m_ease;
    float m_time;
    Tex_00124C40 m130;
    Tex_00124C40* World() { return &m130; }
    void Update();
};

void Elem_00124C40::Update()
{
    int now = func_0010FC30();
    int changed = 0;
    m_busy++;
    func_00124118(this, 1);
    if (m_flags & 0x80000) {
        Tex_00124C40* d = &mD0;
        float x;
        float y;
        int z;
        float s = func_00114BE0(func_0013AF50(0), &mD0.m10, &x, &y, &z);
        if (0.0f <= s) {
            d->m28 = z;
            d->m20 = x;
            d->m24 = y;
            func_00123DB0(this, s, s, 1, 0);
            m_flags &= ~0x100000;
        } else {
            d->m20 = -320.0f;
            d->m24 = -224.0f;
            m_flags |= 0x100000;
        }
        func_00125798(this, d);
        m_flags |= 0x400;
    }
    if ((m_flags & 0x400) && !(m_flags & 0x40000)) {
        if (m_dur) {
            float t = (float)(now - m_start) / (float)m_dur;
            if (!(now - m_start < m_dur)) {
                t = 1.0f;
                m_dur = 0;
            }
            float e;
            int mode = (m_flags >> 8) & 3;
            switch (mode) {
            case 1:
                e = t + t - t * t;
                break;
            case 2:
                e = t * t;
                break;
            case 3:
                e = (3.0f - (t + t)) * t * t;
                break;
            default:
                e = t;
                break;
            }
            float k = (e - m_ease) / (1.0f - m_ease);
            float k2 = (t - m_time) / (1.0f - m_time);
            m80.Blend(&mD0, k, k2);
            m80.m0 += (mD0.m0 - m80.m0) * k2;
            func_00125798(this, &m80);
            Rgba_00124C40 ca = m80.m48;
            Rgba_00124C40 cb = mD0.m48;
            Rgba_00124C40 cr((unsigned char)(ca.v.r + (cb.v.r - ca.v.r) * k2),
                             (unsigned char)(ca.v.g + (cb.v.g - ca.v.g) * k2),
                             (unsigned char)(ca.v.b + (cb.v.b - ca.v.b) * k2),
                             (unsigned char)(ca.v.a + (cb.v.a - ca.v.a) * k2));
            m80.SetColor(cr);
            m_ease = e;
            m_time = t;
        } else {
            m80 = mD0;
            m_flags &= ~0x400;
        }
        changed = 1;
    }
    Elem_00124C40* p = m_parent;
    if (p && (p->m_flags & 0x800)) {
        changed = 1;
    }
    m_flags &= ~0x800;
    if (changed) {
        if (p && !(m_flags & 0x80000)) {
            Tex_00124C40* w = &m130;
            Tex_00124C40* l = &m80;
            float sx = l->m34 * m_parent->World()->m34;
            float sy = l->m38 * m_parent->World()->m38;
            w->m34 = sx;
            w->m38 = sy;
            float px = ToParent_00124C40(m_parent->World()->m2C, l->m20, m_parent->World()->m34);
            float py = ToParent_00124C40(m_parent->World()->m30, l->m24, m_parent->World()->m38);
            w->m20 = px;
            w->m24 = py;
            m130.m0 = m80.m0 * m_parent->m130.m0;
            float ox = ToParent_00124C40(m_parent->World()->m2C, l->m2C, m_parent->World()->m34);
            float oy = ToParent_00124C40(m_parent->World()->m30, l->m30, m_parent->World()->m38);
            w->m2C = ox;
            w->m30 = oy;
        } else {
            m130 = m80;
        }
        m_flags |= 0x800;
    }
    V10();
    m_flags &= ~0x1000;
    if (m_flags & 0x20000) {
        m_flags |= 0x40000;
    }
    for (Elem_00124C40* ch = m_child; ch; ch = ch->m_next) {
        ch->Update();
    }
    if (m_busy > 0) {
        m_busy--;
    }
}
