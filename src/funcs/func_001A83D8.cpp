typedef int qword __attribute__((mode(TI)));

struct Vec_001A83D8 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_001A83D8() {}
    Vec_001A83D8(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_001A83D8& operator+=(const Vec_001A83D8& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        w += o.w;
        return *this;
    }
};

inline Vec_001A83D8 operator*(const Vec_001A83D8& a, float s)
{
    return Vec_001A83D8(a.x * s, a.y * s, a.z * s, a.w * s);
}

struct Obj_001A83D8 {
    char pad0[0x50];
    Vec_001A83D8 m_pos;
    char pad60[0x70 - 0x60];
    Vec_001A83D8 m_right;
    Vec_001A83D8 m_up;
    Vec_001A83D8 m_fwd;
    char padA0[0xB0 - 0xA0];
    Vec_001A83D8 m_vel;
    void OrthoRight()
    {
        m_right = Vec_001A83D8(m_up.y * m_fwd.z - m_up.z * m_fwd.y, m_up.z * m_fwd.x - m_up.x * m_fwd.z,
                               m_up.x * m_fwd.y - m_up.y * m_fwd.x, 0.0f);
    }
    void OrthoFwd()
    {
        m_fwd = Vec_001A83D8(m_right.y * m_up.z - m_right.z * m_up.y, m_right.z * m_up.x - m_right.x * m_up.z,
                             m_right.x * m_up.y - m_right.y * m_up.x, 0.0f);
    }
};

struct Path_001A83D8 {
    char pad0[0x10];
    Vec_001A83D8 m_pos;
};

struct C_001A83D8 {
    char pad0[0xC];
    Obj_001A83D8* m_obj;
    char pad10[0x1C - 0x10];
    int m_flags;
    int m_mode;
    char pad24[0x34 - 0x24];
    float m_speed;
    char pad38[0x210 - 0x38];
    float m_dt;
    void Update();
};

extern "C" void* func_00185578(Obj_001A83D8* o, unsigned int name);
extern "C" void func_001A7A78(C_001A83D8* self);
extern "C" Path_001A83D8* func_001A67A8(C_001A83D8* self);
extern "C" int func_00259660(Path_001A83D8* p, float dist, Vec_001A83D8* dir);
extern "C" void func_00259520(Path_001A83D8* p, Vec_001A83D8* out);
extern "C" void func_003233B8(Vec_001A83D8* d, Vec_001A83D8* s);
extern "C" void func_001A8BE0(C_001A83D8* self);

void C_001A83D8::Update()
{
    if (func_00185578(m_obj, 0x6EFDDFB8))
        return;
    Vec_001A83D8 delta(-m_obj->m_pos.x, -m_obj->m_pos.y, -m_obj->m_pos.z, -m_obj->m_pos.w);
    func_001A7A78(this);
    if (m_speed != 0.0f) {
        Path_001A83D8* p = func_001A67A8(this);
        if (func_00259660(p, m_speed * m_dt, (m_mode & 0x10) ? 0 : &m_obj->m_fwd)) {
            m_speed = 0.0f;
            m_flags &= ~0x10;
        }
        if (!(m_mode & 0x10)) {
            func_00259520(func_001A67A8(this), &m_obj->m_fwd);
            if ((m_mode & 0x400) && m_obj->m_fwd.y != 0.0f) {
                m_obj->m_fwd.y = 0.0f;
                func_003233B8(&m_obj->m_fwd, &m_obj->m_fwd);
            }
            if (!(m_mode & 4)) {
                m_obj->OrthoRight();
                func_003233B8(&m_obj->m_right, &m_obj->m_right);
                m_obj->OrthoFwd();
                func_003233B8(&m_obj->m_fwd, &m_obj->m_fwd);
            }
        }
        if (m_mode & 4) {
            Obj_001A83D8* o = m_obj;
            float y = o->m_pos.y;
            o->m_pos = func_001A67A8(this)->m_pos;
            m_obj->m_pos.y = y;
            func_001A8BE0(this);
        } else {
            Obj_001A83D8* o = m_obj;
            float y = o->m_pos.y;
            o->m_pos = func_001A67A8(this)->m_pos;
            if (m_mode & 0x100)
                m_obj->m_pos.y = y;
        }
    }
    Obj_001A83D8* o = m_obj;
    delta.x += o->m_pos.x;
    delta.y += o->m_pos.y;
    delta.z += o->m_pos.z;
    delta.w += o->m_pos.w;
    o->m_vel = delta * (1.0f / m_dt);
}
