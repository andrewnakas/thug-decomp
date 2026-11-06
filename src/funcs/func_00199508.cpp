typedef int qword __attribute__((mode(TI)));

struct Vec_00199508 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Vec_00199508() {}
    Vec_00199508(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
};

struct Plane_00199508 {
    Vec_00199508 m_point;
    Vec_00199508 m_normal;
};

extern "C" void func_001235E8(Plane_00199508* a, Vec_00199508* b, unsigned int c0, unsigned int c1, int n);

class Obj_00199508 {
public:
    char pad0[0x20];
    Vec_00199508 m_pos;
    char pad30[0x1380 - 0x30];
    int m_debug;
    bool InFront(Plane_00199508* p);
};

bool Obj_00199508::InFront(Plane_00199508* p)
{
    Vec_00199508 d(p->m_point.x - m_pos.x, p->m_point.y - m_pos.y, p->m_point.z - m_pos.z, p->m_point.w - m_pos.w);
    bool front = d.x * p->m_normal.x + d.y * p->m_normal.y + d.z * p->m_normal.z >= 0.0f;
    if (m_debug && front) {
        Vec_00199508 e;
        Vec_00199508 s(p->m_normal.x * 48.0f, p->m_normal.y * 48.0f, p->m_normal.z * 48.0f, p->m_normal.w * 48.0f);
        e.x = p->m_point.x + s.x;
        e.y = p->m_point.y + s.y;
        e.z = p->m_point.z + s.z;
        e.w = p->m_point.w + s.w;
        func_001235E8(p, &e, 0xFF000000, 0xFF000000, 1);
    }
    return front;
}
