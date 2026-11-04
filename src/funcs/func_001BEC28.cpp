typedef int qword __attribute__((mode(TI)));
extern "C" float sqrtf(float);

struct Vec_001BEC28 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_001BEC28() {}
    void Set(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    float Length() const { return sqrtf(x * x + y * y + z * z); }
    void Add(const Vec_001BEC28& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        w += o.w;
    }
    void Scale(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
    }
};

struct Body_001BEC28 {
    char pad0[0x50];
    Vec_001BEC28 m_pos;
    char pad1[0x70 - 0x60];
    Vec_001BEC28 m_70;
    Vec_001BEC28 m_normal;
    Vec_001BEC28 m_90;
    char pad2[0xB0 - 0xA0];
    Vec_001BEC28 m_vel;
};

struct Info_001BEC28 {
    char pad0[0x40];
    int m_40;
    char pad1[0x100 - 0x44];
    int m_100;
};

struct Owner_001BEC28 {
    char pad0[0x5B0];
    Info_001BEC28* m_info;
};

struct Quat_001BEC28;
extern "C" void func_001BA4F0(Quat_001BEC28* out, Vec_001BEC28* axis, float angle);
extern "C" void func_001BA5D0(Vec_001BEC28* out, Quat_001BEC28* q, Vec_001BEC28* v);
struct Quat_001BEC28 {
    float v[4];
    Quat_001BEC28(Vec_001BEC28* axis, float angle) { func_001BA4F0(this, axis, angle); }
};

extern "C" int func_0010FC30();
extern "C" void* func_001E5548(unsigned int key, int a);
extern "C" int func_001E7EB0(void* s, unsigned int key, float* out, int flag);
extern "C" float func_003412F0(float x);
static inline float Param_001BEC28(unsigned int key)
{
    float f;
    func_001E7EB0(func_001E5548(0x6775E538, 0), key, &f, 1);
    return f;
}

static inline float Clamp_001BEC28(float c, float lo, float hi)
{
    if (c > hi) c = hi;
    if (c < lo) c = lo;
    return c;
}

struct C_001BEC28 {
    char pad0[0xC];
    Body_001BEC28* m_body;
    char pad1[0x20 - 0x10];
    int m_time;
    char pad2[0x94 - 0x24];
    int m_94;
    char pad3[0xBC - 0x98];
    int m_BC;
    int m_C0;
    int m_C4;
    char pad4[0x960 - 0xC8];
    int m_960;
    char pad5[0x970 - 0x964];
    Vec_001BEC28 m_970;
    float m_980;
    float m_984;
    char pad6[0x990 - 0x988];
    Vec_001BEC28 m_axis;
    char pad7[0x9B0 - 0x9A0];
    int m_9B0;
    char pad8[0xA44 - 0x9B4];
    Owner_001BEC28* m_owner;
    char pad9[0xA50 - 0xA48];
    Vec_001BEC28 m_A50;
    char pad10[0xB50 - 0xA60];
    int m_B50;
    char pad11[0xB70 - 0xB54];
    Vec_001BEC28 m_dir;
    char pad12[0xB90 - 0xB80];
    int m_B90;
    char pad13[0xBC0 - 0xB94];
    int m_BC0;
    void Land(int snap);
};

extern "C" void func_001BF130(C_001BEC28* self, int a);
extern "C" void func_001C4030(C_001BEC28* self, Vec_001BEC28* vel, float* vy);

void C_001BEC28::Land(int snap)
{
    m_time = func_0010FC30();
    Body_001BEC28* b = m_body;
    if (b->m_normal.y > 0.999000013f) {
        m_980 = 0.0f;
    } else {
        if (b->m_normal.y > -0.999000013f) {
            m_axis.Set(-b->m_normal.z, 0.0f, b->m_normal.x, 1.0f);
            float c = m_body->m_normal.y;
            c = Clamp_001BEC28(c, -1.0f, 1.0f);
            m_984 = func_003412F0(c);
        } else {
            m_axis = b->m_70;
            m_984 = 3.14159274f;
        }
        m_980 = Param_001BEC28(0xB0675803);
        Body_001BEC28* b2 = m_body;
        if (b2->m_normal.y < 0.0f) {
            snap = 0;
            Vec_001BEC28 p;
            Vec_001BEC28 t;
            t.Set(b2->m_normal.x * 6.0f, b2->m_normal.y * 6.0f, b2->m_normal.z * 6.0f, b2->m_normal.w * 6.0f);
            p.Set(b2->m_pos.x + t.x, b2->m_pos.y + t.y, b2->m_pos.z + t.z, b2->m_pos.w + t.w);
            b2->m_pos = p;
        }
    }
    if (snap) {
        func_001BF130(this, 0);
        m_A50.Set(0.0f, 1.0f, 0.0f, 1.0f);
        m_B50 = 0;
        m_body->m_vel.y = 0.0f;
        m_C0 = 0;
    } else {
        func_001BF130(this, 1);
        if (m_owner->m_info->m_40 && m_980 != 0.0f) {
            Vec_001BEC28 v = m_body->m_90;
            Vec_001BEC28 t;
            Quat_001BEC28 q(&m_axis, m_984);
            Vec_001BEC28 r;
            func_001BA5D0(&r, &q, &v);
            v = r;
            Vec_001BEC28* vel = &m_body->m_vel;
            float k = Param_001BEC28(0x17B37748);
            t.Set(v.x * k, v.y * k, v.z * k, v.w * k);
            vel->Add(t);
        }
        Body_001BEC28* b4 = m_body;
        m_dir = b4->m_vel;
        m_dir.y = 0.0f;
        float len = m_dir.Length();
        if (len < 0.001f) {
            m_dir = b4->m_90;
            m_dir.y = 0.0f;
            len = m_dir.Length();
            if (len < 0.001f) {
                Vec_001BEC28 n;
                n.Set(-b4->m_normal.x, -b4->m_normal.y, -b4->m_normal.z, -b4->m_normal.w);
                m_dir = n;
                m_dir.y = 0.0f;
                len = m_dir.Length();
            }
        }
        m_dir.Scale(1.0f / len);
        func_001C4030(this, &m_body->m_vel, &m_body->m_vel.y);
        m_B90 = 0;
        m_BC0 = 0;
        Info_001BEC28* info = m_owner->m_info;
        m_C0 = info->m_40 != 0 || info->m_100 != 0;
    }
    m_BC = 1;
    m_960 = 0;
    m_9B0 = 0;
    m_94 = 0;
    m_970.Set(0.0f, 0.0f, 0.0f, 1.0f);
    m_C4 = 0;
}
