typedef int qword_0022B2E0 __attribute__((mode(TI)));

struct Vec_0022B2E0 {
    union {
        qword_0022B2E0 q;
        struct {
            float x, y, z, w;
        } f;
    };
};

struct Obj_0022B2E0 {
    char pad0[0x50];
    Vec_0022B2E0 m_pos;
    char pad60[0x10];
    Vec_0022B2E0 m_rot[4];

    void MoveLocal(const Vec_0022B2E0* v);
};

void Obj_0022B2E0::MoveLocal(const Vec_0022B2E0* v)
{
    Vec_0022B2E0 r0 = m_rot[0];
    Vec_0022B2E0 r1 = m_rot[1];
    Vec_0022B2E0 r2 = m_rot[2];
    Vec_0022B2E0 p = m_pos;
    p.f.x = p.f.x + (v->f.x * r0.f.x + v->f.y * r1.f.x + v->f.z * r2.f.x);
    p.f.y = p.f.y + (v->f.x * r0.f.y + v->f.y * r1.f.y + v->f.z * r2.f.y);
    p.f.z = p.f.z + (v->f.x * r0.f.z + v->f.y * r1.f.z + v->f.z * r2.f.z);
    m_pos = p;
}
