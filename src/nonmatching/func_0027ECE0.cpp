/* fuzzy: 92.1 */
extern "C" float fabsf(float);

typedef int qword __attribute__((mode(TI)));

struct Row_0027ECE0 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    bool operator==(const Row_0027ECE0& o) const
    {
        return x == o.x && y == o.y && z == o.z && w == o.w;
    }
    Row_0027ECE0& operator+=(const Row_0027ECE0& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        w += o.w;
        return *this;
    }
};

struct Vec_0027ECE0 : Row_0027ECE0 {
    Vec_0027ECE0() {}
    Vec_0027ECE0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

static inline Vec_0027ECE0 operator*(const Row_0027ECE0& v, float s)
{
    return Vec_0027ECE0(v.x * s, v.y * s, v.z * s, v.w * s);
}

static inline Vec_0027ECE0 operator+(const Row_0027ECE0& a, const Row_0027ECE0& b)
{
    return Vec_0027ECE0(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

static inline Vec_0027ECE0 operator-(const Row_0027ECE0& a, const Row_0027ECE0& b)
{
    return Vec_0027ECE0(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

struct Body_0027ECE0 {
    char pad0[0x50];
    Vec_0027ECE0 m_pos;
    Vec_0027ECE0 m_old;
    char pad70[0x80 - 0x70];
    Vec_0027ECE0 m_vel;
};

struct Flags_0027ECE0 {
    char pad[0x2C];
    int m2C;
};

extern "C" void func_003233B8(Vec_0027ECE0* d, Vec_0027ECE0* s);
extern "C" float func_002032A0(unsigned int crc, int a);
extern "C" void func_001BB080(void* o, int a, void* b);

struct Obj_0027ECE0 {
    char pad0[0xC];
    Body_0027ECE0* m_body;
    char pad10[0x70 - 0x10];
    Vec_0027ECE0 m70;
    char pad80[0xB0 - 0x80];
    char mB0[0x150 - 0xB0];
    Vec_0027ECE0 m150;
    Vec_0027ECE0 m160;
    char pad170[0x270 - 0x170];
    Vec_0027ECE0 m_start;
    Vec_0027ECE0 m_end;
    int m290;
    char pad294[0x598 - 0x294];
    void* m598;
    char pad59C[0x5B8 - 0x59C];
    Flags_0027ECE0* m5B8;
    void Update();
};

extern "C" int func_0028E1C0(Obj_0027ECE0* self, int flags, int a);
extern "C" void func_0027F008(Obj_0027ECE0* self, Vec_0027ECE0* n);

void Obj_0027ECE0::Update()
{
    if (m_body->m_pos == m_body->m_old)
        return;
    Vec_0027ECE0 dir(m_body->m_pos.x - m_body->m_old.x, m_body->m_pos.y - m_body->m_old.y,
                     m_body->m_pos.z - m_body->m_old.z, m_body->m_pos.w - m_body->m_old.w);
    func_003233B8(&dir, &dir);
    Body_0027ECE0* b = m_body;
    float t = func_002032A0(0xD4205C9B, 0);
    Vec_0027ECE0 v(b->m_vel.x * t, b->m_vel.y * t, b->m_vel.z * t, b->m_vel.w * t);
    m_start = Vec_0027ECE0(m_body->m_old.x + v.x, m_body->m_old.y + v.y, m_body->m_old.z + v.z, m_body->m_old.w + v.w);
    m_end = Vec_0027ECE0(m_body->m_pos.x + v.x, m_body->m_pos.y + v.y, m_body->m_pos.z + v.z, m_body->m_pos.w + v.w) +
            dir * func_002032A0(0x20102726, 0);
    if (func_0028E1C0(this, 0x10, 0)) {
        Vec_0027ECE0 n = m160;
        float d = n.x * m70.x + n.y * m70.y + n.z * m70.z;
        if (!m290 || fabsf(d) < 0.01f) {
            func_001BB080(m598, 6, mB0);
            if (!m5B8->m2C)
                func_0027F008(this, &n);
        } else {
            m_body->m_pos = m150;
            m_body->m_pos += n * 0.1f;
        }
    }
}
