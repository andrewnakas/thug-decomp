typedef int qword __attribute__((mode(TI)));

struct Vec_00197AD0 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Vec_00197AD0() {}
    Vec_00197AD0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

extern "C" void func_00183CB8(int obj, int* ref);

static inline void Release_00197AD0(int* ref)
{
    if (*ref) {
        func_00183CB8(*ref, ref);
        *ref = 0;
    }
}

struct Feeler_00197AD0 {
    Vec_00197AD0 m_start;
    Vec_00197AD0 m_end;
    char pad20[0x70 - 0x20];
    int m_surface;
    char pad74[0x90 - 0x74];
    float m_dist;
    char pad94[0xA0 - 0x94];
    Vec_00197AD0 m_point;
    Vec_00197AD0 m_normal;
    int m_ref;
    char padC4[0xD4 - 0xC4];
    void* m_ignore;
    char padD8[0xE0 - 0xD8];
    ~Feeler_00197AD0()
    {
        Release_00197AD0(&m_ref);
    }
};

struct Contact_00197AD0 {
    char pad0[0x70];
    int m_surface;
};

struct Mat_00197AD0 {
    Vec_00197AD0 r[3];
};

struct Wheel_00197AD0 {
    float m_len;
    int m_state;
    char pad8[0x20 - 0x8];
    Vec_00197AD0 m_pos;
    Vec_00197AD0 m_vel;
    char pad40[0x70 - 0x40];
    Vec_00197AD0 m_normal;
    char pad80[0x90 - 0x80];
    Vec_00197AD0 m_top;
    Vec_00197AD0 m_bottom;
    char padB0[0xC0 - 0xB0];
    Vec_00197AD0 m_local;
    char padD0[0xD8 - 0xD0];
    float m_rest;
    char padDC[0xE0 - 0xDC];
    float m_min;
    char padE4[0x140 - 0xE4];
    Contact_00197AD0 m_contact;
    char pad1B4[0x220 - 0x1B4];
    Vec_00197AD0 WorldPos(const Mat_00197AD0& m) const
    {
        Vec_00197AD0 r;
        r.x = m_pos.x * m.r[0].x + m_pos.y * m.r[1].x + m_pos.z * m.r[2].x;
        r.y = m_pos.x * m.r[0].y + m_pos.y * m.r[1].y + m_pos.z * m.r[2].y;
        r.z = m_pos.x * m.r[0].z + m_pos.y * m.r[1].z + m_pos.z * m.r[2].z;
        r.w = m_pos.w;
        return r;
    }
};



struct Global_00197AD0 {
    char pad0[0xAC];
    unsigned int m_mode;
};



static inline bool SameSurface_00197AD0(const Feeler_00197AD0& f, const Contact_00197AD0& c)
{
    return f.m_surface == c.m_surface;
}

extern "C" void func_00209240(Feeler_00197AD0* f);
extern "C" void func_00209350(Feeler_00197AD0* f, int a, int b);
extern "C" int func_002093E8(Feeler_00197AD0* f, int a, int b);
extern "C" void func_001BB080(int obj, int type, void* data);
extern "C" void func_0019C9D8(Contact_00197AD0* c, Feeler_00197AD0* f);
extern Global_00197AD0* D_00392808;

struct Node_00197AD0 {
    char pad0[0xC];
    unsigned int m_flags;
};

struct Obj_00197AD0 {
    char pad0[0xC];
    Node_00197AD0* m_node;
    char pad10[0x70 - 0x10];
    Mat_00197AD0 m_mat;
    char padA0[0xB0 - 0xA0];
    Vec_00197AD0 m_vel;
    Vec_00197AD0 m_angVel;
    char padD0[0x120 - 0xD0];
    int m_numContacts;
    char pad124[0x128 - 0x124];
    int m128;
    char pad12C[0x1C4 - 0x12C];
    int m_numWheels;
    char pad1C8[0x318 - 0x1C8];
    Wheel_00197AD0* m_wheels;
    char pad31C[0x360 - 0x31C];
    char m360[0x1394 - 0x360];
    int m1394;
    bool Aborted()
    {
        bool r = false;
        if (m128 || (m_node->m_flags & 1)) r = true;
        return r;
    }
    Vec_00197AD0 PointVel(const Wheel_00197AD0* w) const
    {
        Vec_00197AD0 c(m_angVel.y * w->m_pos.z - m_angVel.z * w->m_pos.y,
                       m_angVel.z * w->m_pos.x - m_angVel.x * w->m_pos.z,
                       m_angVel.x * w->m_pos.y - m_angVel.y * w->m_pos.x, 0.0f);
        return Vec_00197AD0(m_vel.x + c.x, m_vel.y + c.y, m_vel.z + c.z, m_vel.w);
    }
    void UpdateWheels();
};

void Obj_00197AD0::UpdateWheels()
{
    Feeler_00197AD0 f;
    func_00209240(&f);
    m_numContacts = 0;
    f.m_ignore = m360;
    int i = m_numWheels;
    while (i-- != 0) {
        Wheel_00197AD0* w = &m_wheels[i];
        f.m_start = w->m_top;
        f.m_end = w->m_bottom;
        func_00209350(&f, 0x10, 0);
        if (func_002093E8(&f, 0, 0)) {
            if (w->m_state != 1) {
                if (SameSurface_00197AD0(f, w->m_contact)) goto contact;
                func_001BB080(m1394, 4, &w->m_contact);
                if (Aborted()) return;
            }
            func_001BB080(m1394, 5, &f);
            if (Aborted()) return;
        contact:
            func_0019C9D8(&w->m_contact, &f);
            w->m_state = 0;
            w->m_normal = f.m_normal;
            w->m_len = f.m_dist * (w->m_rest - w->m_min) + w->m_min;
            m_numContacts++;
            f.m_end = f.m_point;
        } else {
            if (w->m_state != 1) {
                func_001BB080(m1394, 4, &w->m_contact);
                if (Aborted()) return;
            }
            w->m_state = 1;
            w->m_len = w->m_rest;
        }
        if (D_00392808->m_mode != 0xD443A2BC) {
            func_00209350(&f, 0, 0x50);
            if (func_002093E8(&f, 0, 0)) {
                func_001BB080(m1394, 6, &f);
                if (Aborted()) return;
            }
        }
    }
    int j = m_numWheels;
    while (j-- != 0) {
        Wheel_00197AD0* w = &m_wheels[j];
        w->m_pos = w->m_local;
        w->m_pos.y += w->m_len - w->m_min;
        w->m_pos = w->WorldPos(m_mat);
        w->m_vel = PointVel(w);
    }
}
