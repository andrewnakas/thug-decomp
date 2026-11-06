typedef int qword __attribute__((mode(TI)));

struct Vec_001B2C78 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_001B2C78() {}
    Vec_001B2C78(const Vec_001B2C78& o) { q = o.q; }
    Vec_001B2C78(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_001B2C78 operator*(float s) const { return Vec_001B2C78(x * s, y * s, z * s, w * s); }
    Vec_001B2C78& operator+=(const Vec_001B2C78& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        w += o.w;
        return *this;
    }
    bool operator==(const Vec_001B2C78& o) const
    {
        if (x == o.x && y == o.y && z == o.z && w == o.w)
            return true;
        return false;
    }
    bool operator!=(const Vec_001B2C78& o) const { return !(*this == o); }
};

struct Mat_001B2C78 {
    Vec_001B2C78 r0, r1, r2, r3;
};

struct Obj_001B2C78 {
    char pad0[0x50];
    Vec_001B2C78 m_pos;
    char pad60[0xC0 - 0x60];
    Mat_001B2C78 m_matrix;
};

struct Comp_001B2C78 {
    char pad0[0x34];
    float m_scale;
};

struct C_001B2C78 {
    char pad0[0xC];
    Obj_001B2C78* m_obj;
    char pad10[0x20 - 0x10];
    unsigned int m_flag : 1;
    char pad24[0x8C - 0x24];
    float m_speed;
    bool Free() const { return !m_flag; }
    void Move();
};

extern "C" Comp_001B2C78* func_00185578(Obj_001B2C78* o, unsigned int name);
extern "C" float func_001B32B8(C_001B2C78* self);
extern "C" float func_001B33E0(C_001B2C78* self);
extern "C" void func_001B2EA0(C_001B2C78* self);
extern "C" void func_001B4650(C_001B2C78* self, Vec_001B2C78 v);

void C_001B2C78::Move()
{
    Comp_001B2C78* c = func_00185578(m_obj, 0x0A015E17);
    float a = func_001B32B8(this);
    float b = func_001B33E0(this);
    Vec_001B2C78 old = m_obj->m_pos;
    func_001B2EA0(this);
    float s = c->m_scale * m_speed;
    Mat_001B2C78 m = m_obj->m_matrix;
    float fa = s * a;
    float fb = s * b;
    Vec_001B2C78 side = m.r2 * fb;
    Vec_001B2C78 fwd = m.r0 * fa;
    m_obj->m_pos += fwd;
    m_obj->m_pos += side;
    Obj_001B2C78* o = m_obj;
    bool same = old.x == o->m_pos.x && old.y == o->m_pos.y && old.z == o->m_pos.z && old.w == o->m_pos.w;
    bool moved = !same;
    if (moved && Free()) {
        func_001B4650(this, old);
    }
}
