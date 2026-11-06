/* fuzzy: 82.2 */
extern "C" float sqrtf(float);
typedef int qword __attribute__((mode(TI)));
union Vec_001C0030 {
    qword q;
    float c[4];
    float& operator[](int i) { return c[i]; }
    float operator[](int i) const { return c[i]; }
    Vec_001C0030() {}
    Vec_001C0030(float x, float y, float z, float w)
    {
        (*this)[0] = x;
        (*this)[1] = y;
        (*this)[2] = z;
        (*this)[3] = w;
    }
    void Set(float x, float y, float z, float w)
    {
        c[0] = x;
        c[1] = y;
        c[2] = z;
        c[3] = w;
    }
    float Dot3(const Vec_001C0030& o) const { return c[0] * o[0] + c[1] * o[1] + c[2] * o[2]; }
    float LengthSqr() const { return c[0] * c[0] + c[1] * c[1] + c[2] * c[2]; }
    void operator+=(const Vec_001C0030& o)
    {
        c[0] += o[0];
        c[1] += o[1];
        c[2] += o[2];
        c[3] += o[3];
    }
    void operator-=(const Vec_001C0030& o)
    {
        c[0] -= o[0];
        c[1] -= o[1];
        c[2] -= o[2];
        c[3] -= o[3];
    }
    void operator*=(float k)
    {
        c[0] *= k;
        c[1] *= k;
        c[2] *= k;
        c[3] *= k;
    }
};
inline Vec_001C0030 operator*(const Vec_001C0030& a, float k) { return Vec_001C0030(a[0] * k, a[1] * k, a[2] * k, a[3] * k); }
inline Vec_001C0030 operator+(const Vec_001C0030& a, const Vec_001C0030& b)
{
    return Vec_001C0030(a[0] + b[0], a[1] + b[1], a[2] + b[2], a[3] + b[3]);
}

extern "C" void func_00183CB8(void* p, void* pp);
struct Body_001C0030 {
    char pad0[0xB0];
    Vec_001C0030 mB0;
};
struct Coll_001C0030;
extern "C" Coll_001C0030* func_00209240(Coll_001C0030* c);
extern "C" int func_002093E8(Coll_001C0030* c, int a, int b);
extern "C" int func_00209A00(Coll_001C0030* c);
extern "C" Body_001C0030* func_00209A30(Coll_001C0030* c);
struct Coll_001C0030 {
    Vec_001C0030 start;
    Vec_001C0030 end;
    char pad20[0xA0 - 0x20];
    Vec_001C0030 hit;
    Vec_001C0030 normal;
    struct Ref {
        void* p;
        void Release()
        {
            if (p) {
                func_00183CB8(p, this);
                p = 0;
            }
        }
    } mC0;
    char padC4[0xE0 - 0xC4];
    Coll_001C0030() { func_00209240(this); }
    ~Coll_001C0030() { mC0.Release(); }
};

extern void* D_00388A70;
extern float D_00387A90;
extern "C" void func_0010A8D8(void* pool, void* p);
extern "C" unsigned int func_0010FC30();
struct Handle_001C0030 {
    Body_001C0030* m0;
};
struct Rec_001C0030 {
    char pad0[0x1C];
    Handle_001C0030* m1C;
    unsigned int m20;
    bool Valid()
    {
        Handle_001C0030* h = m1C;
        if (!h) return false;
        if (h->m0) return true;
        func_0010A8D8(D_00388A70, h);
        m1C = 0;
        m20 = func_0010FC30();
        return false;
    }
};
struct Flag_001C0030 {
    char pad0[0x2C];
    int m2C;
};
struct Info_001C0030 {
    char pad0[0x128];
    int m128;
};

/* one wall/ground probe result, 8 of them in the skater */
struct Probe_001C0030 {
    int m_valid;
    char pad4[0x10 - 0x4];
    Vec_001C0030 m_normal;
    char pad20[0x24 - 0x20];
    float m_dist;
    char pad28[0x30 - 0x28];
    char m_contact[0xC0 - 0x30];
    float m_C0;
    char padC4[0x110 - 0xC4];
};

struct Order_001C0030 {
    int idx[8];
};
extern Order_001C0030 D_00363470;

struct Obj_001C0030;
extern "C" void* func_001E5548(unsigned int key, int create);
extern "C" int func_001E7EB0(void* params, unsigned int name, float* out, int req);
extern "C" int func_0019C9D8(void* p, Coll_001C0030* c);
extern "C" float func_001C6B28(Obj_001C0030* o);
extern "C" Vec_001C0030 func_001C63B0(Obj_001C0030* o, int i);
extern "C" void func_003233B8(Vec_001C0030* d, Vec_001C0030* s);
extern "C" int func_001C37F0(Obj_001C0030* o);
extern "C" int func_001C3870(Obj_001C0030* o);
extern "C" int func_001CB7D0(Obj_001C0030* o, int a);

static inline float Param_001C0030(unsigned int key)
{
    float v;
    func_001E7EB0(func_001E5548(0x6775E538, 0), key, &v, 1);
    return v;
}

struct Obj_001C0030 {
    char pad0[0x1C];
    int m1C;
    char pad20[0x30 - 0x20];
    Vec_001C0030 m30;
    Vec_001C0030 m40;
    float m50;
    char pad54[0x98 - 0x54];
    float m98;
    char pad9C[0xBC - 0x9C];
    int mBC;
    char padC0[0xD0 - 0xC0];
    Probe_001C0030 m_probes[8];
    char pad950[0x954 - 0x950];
    float m954;
    char pad958[0x970 - 0x958];
    Vec_001C0030 m970;
    char pad980[0xA28 - 0x980];
    Info_001C0030* mA28;
    char padA2C[0xA38 - 0xA2C];
    Flag_001C0030* mA38;
    Rec_001C0030* mA3C;
    char padA40[0xA50 - 0xA40];
    Vec_001C0030 mA50;
    char padA60[0xA68 - 0xA60];
    unsigned int mA68;
    char padA6C[0xB58 - 0xA6C];
    int mB58;
    int Probe();
};

int Obj_001C0030::Probe()
{
    float reach = Param_001C0030(0x99978D2B);
    float up = Param_001C0030(0x6DA7F696);
    Coll_001C0030 c;
    bool touching = false;
    for (int i = 0; i < 8; i++) {
        if (i == 7) {
            if (m1C != 1) {
                m_probes[7].m_valid = 0;
                continue;
            }
            c.start = m30 + m970;
            c.end = c.start + m40 * m98;
            float g = func_001C6B28(this);
            float dt = m98;
            c.end[1] += m50 * dt + -g * (dt * dt * 0.5f);
        } else {
            c.start = m30;
            c.start[1] += up;
            Vec_001C0030 d = func_001C63B0(this, i) * reach;
            c.end = m30 + d;
            c.end[1] += up;
        }
        m_probes[i].m_valid = func_002093E8(&c, 1, 0);
        if (!m_probes[i].m_valid) {
            continue;
        }
        if (i == 7 && c.normal[1] > D_00387A90) {
            m_probes[7].m_valid = 0;
            continue;
        }
        func_0019C9D8(m_probes[i].m_contact, &c);
        touching = true;
        m_probes[i].m_normal = c.normal;
        m_probes[i].m_normal[1] = 0.0f;
        func_003233B8(&m_probes[i].m_normal, &m_probes[i].m_normal);
        if (!func_00209A00(&c)) {
            m_probes[i].m_dist = 0.0f;
            continue;
        }
        if (mA3C->Valid()) {
            Body_001C0030* ground = mA3C->m1C->m0;
            if (func_00209A30(&c) == ground) {
                m_probes[i].m_dist = 0.0f;
                continue;
            }
        }
        m_probes[i].m_dist = func_00209A30(&c)->mB0.Dot3(m_probes[i].m_normal);
    }

    if (m1C == 0) {
        if (func_001C37F0(this)) {
            float t = func_0010FC30() - mA68;
            if (Param_001C0030(0x38D36700) < t) {
                if (func_001CB7D0(this, 0) || func_001C3870(this)) {
                    return 0;
                }
            }
        }
        if (mA28->m128 && !mBC && func_001CB7D0(this, 1)) {
            return 0;
        }
        if (mA38->m2C) {
            return 0;
        }
        if (m1C == 0 && mA50[1] < 0.5f) {
            Vec_001C0030 n = mA50;
            n[1] = 0.0f;
            func_003233B8(&n, &n);
            Vec_001C0030 d = n * (Param_001C0030(0x4D16F37D) * m98);
            m30 += d;
        }
    }

    if (!touching) {
        return 0;
    }
    for (int i = 0; i < 8; i++) {
        if (m_probes[i].m_valid) {
            float depth = m_probes[i].m_C0;
            if (depth < Param_001C0030(0xA20C43B7) / reach) {
                Vec_001C0030 d = m_probes[i].m_normal * (Param_001C0030(0x4D16F37D) * m98);
                m30 += d;
            }
        }
    }
    touching = false;
    for (int i = 0; i < 8; i++) {
        if (m_probes[i].m_valid) {
            if (m_probes[i].m_dist <= m_probes[i].m_normal.Dot3(m40)) {
                m_probes[i].m_valid = 0;
            } else {
                touching = true;
            }
        }
    }
    if (!touching) {
        return 0;
    }

    for (int i = 0; i < 8; i++) {
        if (!m_probes[i].m_valid) {
            continue;
        }
        for (int j = i + 1; j < 8; j++) {
            if (m_probes[j].m_valid && m_probes[i].m_normal.Dot3(m_probes[j].m_normal) <= 0.0f) {
                m40.Set(0.0f, 0.0f, 0.0f, 1.0f);
                float cap = Param_001C0030(0x0BD6A05D);
                m954 = m954 < cap ? m954 : cap;
                mB58 = 1;
                return 1;
            }
        }
    }

    /* the binary normalizes a copy of the velocity here and never reads it back */
    Vec_001C0030 dir = m40;
    func_003233B8(&dir, &dir);
    Vec_001C0030 v = m40;
    Order_001C0030 order = D_00363470;
    for (int k = 0; k < 8; k++) {
        Probe_001C0030* p = &m_probes[order.idx[k]];
        if (!p->m_valid) {
            continue;
        }
        float dot = v.Dot3(p->m_normal);
        if (p->m_dist <= dot) {
            continue;
        }
        Vec_001C0030 push = p->m_normal * (dot - p->m_dist);
        v -= push;
        if (v.Dot3(m40) <= 0.0f) {
            m40.Set(0.0f, 0.0f, 0.0f, 1.0f);
            float cap = Param_001C0030(0x0BD6A05D);
            m954 = m954 < cap ? m954 : cap;
            mB58 = 1;
            return 1;
        }
    }

    float len = sqrtf(v.LengthSqr());
    Vec_001C0030 u = v;
    u *= 1.0f / len;
    float proj = m40.Dot3(u);
    if (proj < len) {
        v = u * proj;
    }
    mB58 = v.LengthSqr() / m40.LengthSqr() < 0.25f;
    m40 = v;
    float speed = sqrtf(m40.LengthSqr());
    if (Param_001C0030(0x0BD6A05D) < m954) {
        m954 = speed;
        float cap = Param_001C0030(0x0BD6A05D);
        m954 = m954 > cap ? m954 : cap;
    }
    return 1;
}
