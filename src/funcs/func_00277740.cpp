typedef int qword_00277740 __attribute__((mode(TI)));

struct Vec_00277740 {
    union {
        struct {
            float x, y, z, w;
        } f;
        qword_00277740 q;
    } u;
    Vec_00277740() {}
    Vec_00277740(float x, float y, float z, float w)
    {
        u.f.x = x;
        u.f.y = y;
        u.f.z = z;
        u.f.w = w;
    }
    Vec_00277740& operator+=(const Vec_00277740& o)
    {
        u.f.x += o.u.f.x;
        u.f.y += o.u.f.y;
        u.f.z += o.u.f.z;
        u.f.w += o.u.f.w;
        return *this;
    }
};

extern "C" void func_00183CB8(void* p, void* pp);

struct Feeler_00277740 {
    Vec_00277740 m_start;
    Vec_00277740 m_end;
    char m_pad20[0xA0 - 0x20];
    Vec_00277740 m_point;
    Vec_00277740 m_normal;
    struct Ref {
        void* p;
        ~Ref()
        {
            if (p) {
                func_00183CB8(p, this);
                p = 0;
            }
        }
    } m_ref;
    char m_padC4[0xE0 - 0xC4];
};

struct Body_00277740 {
    char m_pad[0x50];
    Vec_00277740 m_pos;
    char m_pad60[0x80 - 0x60];
    Vec_00277740 m_vel;
};

struct Info_00277740 {
    char m_pad[0x1C];
    int m_type;
};

struct Owner_00277740 {
    char m_pad[0x260];
    void* m260;
};

extern "C" Feeler_00277740* func_00209240(Feeler_00277740* f);
extern "C" bool func_002093E8(Feeler_00277740* f, int a, int b);
extern "C" bool func_002095C8(Feeler_00277740* f);
extern "C" float func_00209608(Feeler_00277740* f);
extern "C" void* func_0013D8A8(void* p);
extern "C" void func_00137BE8(void* p, float h);
extern "C" void func_00136178(float h);
extern "C" void func_001B6BC0(void* p, Vec_00277740* v);
extern "C" void func_001B6BD0(void* p, Vec_00277740* v);

struct Skater_00277740 {
    char m_pad[0xC];
    Body_00277740* mC;
    char m_pad10[0x2B4 - 0x10];
    Owner_00277740* m2B4;
    Info_00277740* m2B8;
    char m_pad2BC[0x2C4 - 0x2BC];
    void* m2C4;
    void Shadow();
};

void Skater_00277740::Shadow()
{
    Feeler_00277740 f;
    func_00209240(&f);
    Body_00277740* b = mC;
    f.m_start = b->m_pos;
    f.m_end = b->m_pos;
    Vec_00277740 v(b->m_vel.u.f.x * 0.001f, b->m_vel.u.f.y * 0.001f, b->m_vel.u.f.z * 0.001f,
                   b->m_vel.u.f.w * 0.001f);
    f.m_start += v;
    f.m_start.u.f.y += 8.0f;
    f.m_end.u.f.y -= 4800.0f;
    if (func_002093E8(&f, 1, 0)) {
        if (m2B8->m_type != 4 && func_002095C8(&f)) {
            void* p = func_0013D8A8(m2B4->m260);
            if (p)
                func_00137BE8(p, func_00209608(&f));
            else
                func_00136178(func_00209608(&f));
        }
        func_001B6BC0(m2C4, &f.m_point);
        func_001B6BD0(m2C4, &f.m_normal);
    }
}
