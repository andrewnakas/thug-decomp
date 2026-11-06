/* fuzzy: 86.6 */
typedef int qword __attribute__((mode(TI)));

struct Vec_001978D0 {
    union {
        qword q;
        struct { float x, y, z, w; };
    };
    Vec_001978D0() {}
    Vec_001978D0(float ax, float ay, float az, float aw) { x = ax; y = ay; z = az; w = aw; }
    Vec_001978D0 operator+(const Vec_001978D0& o) const
    {
        return Vec_001978D0(x + o.x, y + o.y, z + o.z, w + o.w);
    }
};

struct Box_001978D0 {
    Vec_001978D0 m_min;
    Vec_001978D0 m_max;
};

struct Wheel_001978D0 {
    char pad0[0x90];
    Vec_001978D0 m_top;
    Vec_001978D0 m_bottom;
    char padB0[0x220 - 0xB0];
};

struct Part_001978D0 {
    char pad0[0x30];
    Vec_001978D0 m_pos;
    Vec_001978D0 m_a;
    Vec_001978D0 m_b;
    char pad60[0x90 - 0x60];
    Vec_001978D0 PosA() const
    {
        return Vec_001978D0(m_pos.x + m_a.x, m_pos.y + m_a.y, m_pos.z + m_a.z, m_pos.w + m_a.w);
    }
    Vec_001978D0 PosB() const
    {
        return Vec_001978D0(m_pos.x + m_b.x, m_pos.y + m_b.y, m_pos.z + m_b.z, m_pos.w + m_b.w);
    }
    Vec_001978D0 PosAB() const
    {
        Vec_001978D0 t = PosA();
        return Vec_001978D0(t.x + m_b.x, t.y + m_b.y, t.z + m_b.z, t.w + m_b.w);
    }
};

extern "C" void func_001022D8(Box_001978D0* box);
extern "C" void func_00102358(Box_001978D0* box, Vec_001978D0* p);
extern "C" void func_001DA948(void* l, Box_001978D0* box);

struct Obj_001978D0 {
    char pad0[0x1C4];
    int m_numWheels;
    char pad1C8[0x1E0 - 0x1C8];
    Part_001978D0 m_parts[2];
    char pad300[0x318 - 0x300];
    Wheel_001978D0* m_wheels;
    char pad31C[0x360 - 0x31C];
    char m360[0x10];
    void CalcBox();
};

void Obj_001978D0::CalcBox()
{
    Box_001978D0 box;
    func_001022D8(&box);
    int i = m_numWheels;
    while (i-- != 0) {
        Wheel_001978D0* w = &m_wheels[i];
        func_00102358(&box, &w->m_top);
        func_00102358(&box, &w->m_bottom);
    }
    int k = 2;
    while (k-- != 0) {
        Part_001978D0* p = &m_parts[k];
        func_00102358(&box, &p->m_pos);
        {
            Vec_001978D0 pt = p->PosA();
            func_00102358(&box, &pt);
        }
        {
            Vec_001978D0 pt = p->PosB();
            func_00102358(&box, &pt);
        }
        {
            Vec_001978D0 pt = p->PosAB();
            func_00102358(&box, &pt);
        }
    }
    func_001DA948(m360, &box);
}
