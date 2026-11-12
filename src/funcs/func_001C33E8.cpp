typedef int qword_001C33E8 __attribute__((mode(TI)));

struct Vec_001C33E8 {
    union {
        struct {
            float x, y, z, w;
        };
        qword_001C33E8 q;
    };
    Vec_001C33E8() {}
    Vec_001C33E8(float ax, float ay, float az, float aw)
    {
        x = ax;
        y = ay;
        z = az;
        w = aw;
    }
    void Set(float ax, float ay, float az)
    {
        x = ax;
        y = ay;
        z = az;
        w = 1.0f;
    }
};


extern "C" void func_00183CB8(int obj, int* ref);

static inline void Release_001C33E8(int* ref)
{
    if (*ref) {
        func_00183CB8(*ref, ref);
        *ref = 0;
    }
}

struct Feeler_001C33E8 {
    Vec_001C33E8 m_start;
    Vec_001C33E8 m_end;
    char pad20[0xA0 - 0x20];
    Vec_001C33E8 m_normal;
    Vec_001C33E8 m_point;
    int m_ref;
    char padC4[0xE0 - 0xC4];
    ~Feeler_001C33E8()
    {
        Release_001C33E8(&m_ref);
    }
};

struct Body_001C33E8 {
    char pad[0x184];
    float m_height;
};

struct Walk_001C33E8 {
    char pad0[0xC];
    void* m_obj;
    char pad10[0x30 - 0x10];
    Vec_001C33E8 m_pos;
    Vec_001C33E8 m_vel;
    int m_50;
    char pad54[0x80 - 0x54];
    Vec_001C33E8 m_lastPos;
    int m_state;
    char pad94[0x970 - 0x94];
    Vec_001C33E8 m_offset;
    char pad980[0xA30 - 0x980];
    void* m_A30;
    char padA34[0xA40 - 0xA34];
    Body_001C33E8* m_body;
    char padA44[0xA50 - 0xA44];
    Vec_001C33E8 m_up;
    char padA60[0xB50 - 0xA60];
    int m_B50;
    void Snap();
};

extern char D_00363408[];
extern char D_003634F0[];
extern char D_00363427[];

extern "C" void func_00209240(Feeler_001C33E8* f);
extern "C" bool func_002093E8(Feeler_001C33E8* f, bool getHit, bool all);
extern "C" void func_0018DF70(void* p, Feeler_001C33E8* f);
extern "C" void* func_00185578(void* obj, unsigned int name);
extern "C" void func_001B6BC0(void* p, Vec_001C33E8* v);
extern "C" void func_001B6BD0(void* p, Vec_001C33E8* v);
extern "C" void func_00103F28(const char* fmt, ...);
extern "C" void func_001BF130(Walk_001C33E8* self, int state);

void Walk_001C33E8::Snap()
{
    Feeler_001C33E8 f;
    func_00209240(&f);
    Vec_001C33E8 p(m_pos.x + m_offset.x, m_pos.y + m_offset.y, m_pos.z + m_offset.z, m_pos.w + m_offset.w);
    f.m_start.q = p.q;
    f.m_end.q = p.q;
    f.m_end.y -= 4800.0f;
    f.m_start.y += 1.0f;
    if (func_002093E8(&f, true, false)) {
        Vec_001C33E8* n = &f.m_normal;
        m_body->m_height = m_pos.y - f.m_normal.y;
        func_0018DF70(m_A30, &f);
        void* o = func_00185578(m_obj, 0x8A897DD2);
        func_001B6BC0(o, n);
        func_001B6BD0(o, &f.m_point);
        return;
    }
    func_00103F28(D_00363408, D_00363427, 0x898, D_003634F0);
    m_pos.q = m_lastPos.q;
    m_vel.Set(0.0f, 0.0f, 0.0f);
    m_50 = 0;
    func_001BF130(this, 0);
    m_B50 = 0;
    m_up.Set(0.0f, 1.0f, 0.0f);
    m_state = 0x57FF2A27;
}
