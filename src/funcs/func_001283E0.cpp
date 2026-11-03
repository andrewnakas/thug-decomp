struct Obj_001283E0;

extern "C" void func_00183C98(Obj_001283E0* o, void* h);
extern "C" void func_00183CB8(Obj_001283E0* o, void* h);

struct Handle_001283E0 {
    Obj_001283E0* m_obj;
    Handle_001283E0* m_prev;
    Handle_001283E0* m_next;
    Handle_001283E0(Obj_001283E0* o)
    {
        m_prev = 0;
        m_next = 0;
        m_obj = o;
        if (o)
            func_00183C98(o, this);
    }
    ~Handle_001283E0()
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
    }
    Handle_001283E0& operator=(Obj_001283E0* o)
    {
        if (m_obj) {
            func_00183CB8(m_obj, this);
            m_obj = 0;
        }
        m_obj = o;
        if (o)
            func_00183C98(o, this);
        return *this;
    }
};

struct Color_001283E0 {
    unsigned char r, g, b, a;
};

struct Obj_001283E0 {
    char pad0[0x60];
    Obj_001283E0* m60;
    char pad64[0x1C8 - 0x64];
    Color_001283E0 m_color;
    int m1CC;
};

struct C_001283E0 {
    char pad0[0x54];
    Obj_001283E0* m54;
    char pad58[0x1D4 - 0x58];
    int m1D4;
    int m1D8;
    char pad1DC[0x1E0 - 0x1DC];
    float m1E0;
    float m1E4;
    Color_001283E0 m_color;
    int m1EC;
    void Apply();
};

extern "C" void func_001265E0(Obj_001283E0* o);
extern "C" void func_00126678(Obj_001283E0* o);
extern "C" void func_001266D8(Obj_001283E0* o, int on);
extern "C" void func_00126738(Obj_001283E0* o, float a, float b);

void C_001283E0::Apply()
{
    Handle_001283E0 h(Handle_001283E0(m54).m_obj);
    while (h.m_obj) {
        if (m1D4)
            func_001265E0(h.m_obj);
        else
            func_00126678(h.m_obj);
        if (m1D8)
            func_001266D8(h.m_obj, 1);
        else
            func_001266D8(h.m_obj, 0);
        func_00126738(h.m_obj, m1E0, m1E4);
        h.m_obj->m_color = Color_001283E0(m_color);
        h.m_obj->m1CC = m1EC;
        h = h.m_obj->m60;
    }
}
