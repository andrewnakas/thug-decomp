typedef int qword __attribute__((mode(TI)));

struct Vec_001A8940 {
    union {
        struct { float x, y, z, w; };
        qword q;
    };
    Vec_001A8940() {}
    Vec_001A8940(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_001A8940(float ax, float ay, float az)
    {
        x = ax;
        y = ay;
        z = az;
        w = 1.0f;
    }
    Vec_001A8940& operator+=(const Vec_001A8940& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        w += o.w;
        return *this;
    }
};

inline Vec_001A8940 operator+(const Vec_001A8940& a, const Vec_001A8940& b)
{
    return Vec_001A8940(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

inline Vec_001A8940 operator*(const Vec_001A8940& a, float s)
{
    return Vec_001A8940(a.x * s, a.y * s, a.z * s, a.w * s);
}

extern "C" void func_00183CB8(void* obj, void* ref);

struct Ref_001A8940 {
    void* m_obj;
    ~Ref_001A8940()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
};

struct Feeler_001A8940 {
    Vec_001A8940 m_start;
    Vec_001A8940 m_end;
    int m20[40];
    Ref_001A8940 mC0;
    int mC4[7];
    Feeler_001A8940();
};

extern "C" int func_002093E8(Feeler_001A8940* f, int a, int b);

struct Obj_001A9858 {
    char pad0[0x50];
    Vec_001A8940 m_pos;
};

struct C_001A9858 {
    char pad0[0xC];
    Obj_001A9858* m_obj;
    char pad10[0x1C - 0x10];
    int m_flags;
    char pad20[0x210 - 0x20];
    float m_dt;
    char pad214[0x228 - 0x214];
    float m_vy;
    float m_ay;
    Vec_001A8940 m_vel;
    int m240;
    char pad244[0x250 - 0x244];
    Vec_001A8940 m_newPos;
    float m_velScale;
    float m_up;
    float m_down;
    char pad26C[0x270 - 0x26C];
    int m_useFloor;
    float m_floor;
    void Update();
};

void C_001A9858::Update()
{
    float dt = m_dt;
    float half = dt * 0.5f;
    float dy = m_vy * dt + m_ay * half * dt;
    Vec_001A8940 pos = m_obj->m_pos;
    if (m240) {
        float s = m_velScale;
        pos += Vec_001A8940(m_vel.x * s, m_vel.y * s, m_vel.z * s, m_vel.w * s) * dt;
        pos.y = m_obj->m_pos.y;
    }
    pos.y += dy;
    m_vy += m_ay * m_dt;
    if (dy < 0.0f) {
        if (m_useFloor) {
            if (pos.y < m_floor) {
                pos.y = m_floor;
                m_flags &= ~0x100;
            }
        } else {
            Feeler_001A8940 f;
            f.m_start = pos + Vec_001A8940(0.0f, m_up, 0.0f);
            f.m_end = pos + Vec_001A8940(0.0f, -m_down, 0.0f);
            if (func_002093E8(&f, 1, 0))
                m_flags &= ~0x100;
        }
    }
    m_newPos = pos;
}
