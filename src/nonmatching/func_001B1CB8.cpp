/* fuzzy: 92.2 */
typedef int qword __attribute__((mode(TI)));

struct Vec_001B1CB8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_001B1CB8() {}
    Vec_001B1CB8(const Vec_001B1CB8& v) { q = v.q; }
    Vec_001B1CB8(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    float Length2() const { return x * x + y * y + z * z; }
    Vec_001B1CB8& Normalize();
};

static inline Vec_001B1CB8 operator-(const Vec_001B1CB8& a, const Vec_001B1CB8& b)
{
    return Vec_001B1CB8(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

static inline Vec_001B1CB8 operator+(const Vec_001B1CB8& a, const Vec_001B1CB8& b)
{
    return Vec_001B1CB8(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

static inline Vec_001B1CB8 operator*(const Vec_001B1CB8& a, float s)
{
    return Vec_001B1CB8(a.x * s, a.y * s, a.z * s, a.w * s);
}

struct Node_001B1CB8 {
    char pad0[0x50];
    Vec_001B1CB8 m_pos;
    Vec_001B1CB8 Sub(const Node_001B1CB8* n) const
    {
        return Vec_001B1CB8(m_pos.x - n->m_pos.x, m_pos.y - n->m_pos.y, m_pos.z - n->m_pos.z, m_pos.w - n->m_pos.w);
    }
};

struct Obj_001B1CB8 {
    char pad0[0x1C];
    int m1C;
    char pad1[0x30 - 0x20];
    float m30;
    float m34;
};

struct Comp_001B1CB8 {
    char pad0[0x84];
    int m84;
};

struct Thing_001B1CB8 {
    int m_pad[47];
    void* mBC;
};

struct C_001B1CB8;
extern "C" Obj_001B1CB8* func_00185578(Node_001B1CB8* node, unsigned int name);
extern "C" void func_001A7A78(Obj_001B1CB8* o);
extern "C" Node_001B1CB8* func_0022DD38(void* mgr);
extern void* D_0038FC78;
extern "C" float func_001E5318(unsigned int name, int flag);
extern "C" int func_001E53A0(unsigned int name, int flag);
extern "C" void func_001B6038(C_001B1CB8* self);
extern "C" void func_001B3538(C_001B1CB8* self);
extern "C" Thing_001B1CB8* func_001F0750(unsigned int name, void* params, int a, int b, int c,
                                          int d, int e, int f, int g, int h);
extern "C" void func_00183CB8(void* obj, void* ref);
extern "C" void func_00183C98(void* obj, void* ref);
extern "C" int func_001B4CE8(C_001B1CB8* self);
extern "C" int func_001B2968(C_001B1CB8* self);
extern "C" void func_001B2630(C_001B1CB8* self);
extern "C" void func_001B2C78(C_001B1CB8* self);
extern "C" void func_001B47F8(C_001B1CB8* self);
extern "C" void func_003233B8(Vec_001B1CB8* d, Vec_001B1CB8* s);
inline Vec_001B1CB8& Vec_001B1CB8::Normalize()
{
    func_003233B8(this, this);
    return *this;
}
extern "C" void func_001B4650(C_001B1CB8* self, Vec_001B1CB8 pos);
extern "C" void func_001B4A08(C_001B1CB8* self);
extern "C" void func_001B4228(C_001B1CB8* self);
extern "C" void func_001B2EA0(C_001B1CB8* self);
extern "C" void func_001B5BB8(C_001B1CB8* self);
extern "C" void func_001B4BE0(C_001B1CB8* self, int mode);
extern "C" void func_002708F8(Comp_001B1CB8* c, float v);

static inline void SetRef_001B1CB8(void** ref, void* obj)
{
    if (*ref) {
        func_00183CB8(*ref, ref);
        *ref = 0;
    }
    *ref = obj;
    if (obj) func_00183C98(obj, ref);
}

struct C_001B1CB8 {
    char pad0[0xC];
    Node_001B1CB8* mC;
    char pad1[0x20 - 0x10];
    unsigned int m20;
    char pad2[0x60 - 0x24];
    Vec_001B1CB8 m60;
    char pad3[0x8C - 0x70];
    float m8C;
    char pad4[0x1C0 - 0x90];
    float m1C0;
    void Update();
    Vec_001B1CB8 FromTarget() const
    {
        Node_001B1CB8* m = mC;
        return Vec_001B1CB8(m->m_pos.x - m60.x, m->m_pos.y - m60.y, m->m_pos.z - m60.z, m->m_pos.w - m60.w);
    }
    Vec_001B1CB8 ToTarget() const
    {
        Node_001B1CB8* m = mC;
        return Vec_001B1CB8(m60.x - m->m_pos.x, m60.y - m->m_pos.y, m60.z - m->m_pos.z, m60.w - m->m_pos.w);
    }
};

void C_001B1CB8::Update()
{
    Obj_001B1CB8* o = func_00185578(mC, 0x0A015E17);
    func_001A7A78(o);
    int b = (o->m1C & 0x100) != 0;
    float speed = m8C * o->m34;
    if (m20 & 4) {
        Node_001B1CB8* n = func_0022DD38(D_0038FC78);
        if (n) {
            Vec_001B1CB8 d = mC->Sub(n);
            float dist2 = d.x * d.x + d.y * d.y + d.z * d.z;
            if (dist2 < func_001E5318(0xBC2E678A, 1)) {
                func_001B6038(this);
                return;
            }
        }
    }
    if ((m20 & 2) || b) {
        Vec_001B1CB8 d;
        if ((m20 & 8) || b) {
            d = FromTarget();
        } else {
            Vec_001B1CB8 a = m60;
            a.y = 0.0f;
            Vec_001B1CB8 p = mC->m_pos;
            p.y = 0.0f;
            d = p - a;
        }
        float dist2 = d.Length2();
        int r = func_001E53A0(0xFB5D106F, 1);
        if (!(m20 & 0x800)) {
            if (dist2 < speed * speed)
                func_001B3538(this);
            else if (dist2 < (float)r)
                func_001B3538(this);
        }
        if (m20 & 0x100) {
            if (dist2 < (float)func_001E53A0(0x52EC432F, 1)) {
                m20 &= ~0x100u;
                Thing_001B1CB8* th = func_001F0750(0x9C7AB5F5, 0, 0, 0, -1, 0, 0, 0, 0, 0);
                SetRef_001B1CB8(&th->mBC, mC);
            }
        }
    }
    if ((m20 & 2) && speed != 0.0f) {
        int moved = 0;
        Vec_001B1CB8 saved;
        saved = mC->m_pos;
        if (func_001B4CE8(this)) {
            if (!func_001B2968(this))
                func_001B2630(this);
            func_001B2C78(this);
            if (b)
                func_001B47F8(this);
        } else {
            moved = 1;
            Vec_001B1CB8 np = saved + ToTarget().Normalize() * speed;
            func_001B2630(this);
            func_001B2C78(this);
            mC->m_pos = np;
            func_001B4650(this, saved);
        }
        if (!((m20 & 4) || (m20 & 0x80)) && !b) {
            func_001B4A08(this);
            if (!moved)
                func_001B4650(this, saved);
            func_001B4228(this);
        }
    } else {
        func_001B2EA0(this);
        func_001B47F8(this);
        if ((m20 & 0x200) || (m20 & 0x400))
            func_001B5BB8(this);
    }
    if (b)
        func_001B4BE0(this, 1);
    else if (m20 & 4)
        func_001B4BE0(this, 4);
    else if (m20 & 2)
        func_001B4BE0(this, 0);
    else if (m20 & 0x2000)
        func_001B4BE0(this, 3);
    if (m20 & 2)
        m1C0 = o->m34 / o->m30;
    else
        m1C0 = 0.0f;
    Comp_001B1CB8* c = (Comp_001B1CB8*)func_00185578(mC, 0xB5F1E9D2);
    if (c) {
        c->m84 = (m20 & 0x40) || (m20 & 0x80);
        func_002708F8(c, m1C0);
    }
}
