extern "C" float sqrtf(float);
extern "C" void func_00183CB8(void* obj, void* ref);
extern "C" void func_00183C98(void* obj, void* ref);
struct Comp_001B5A20 { char pad[0x1C]; int m_flags; };
extern "C" Comp_001B5A20* func_00185578(void* self, unsigned int id);
extern "C" void* func_001B4D00(void* self);
extern "C" void* func_001B5450(void* self);
extern "C" float func_001E5318(unsigned int id, int a);
extern "C" void func_001E6AE8(void* p, int a);
extern "C" void func_001E7200(void* p, unsigned int id, int v);
extern "C" void func_001E7360(void* p, int a, unsigned int id);
struct Ref_001B5A20 {
    void* m_p;
    void operator=(void* o)
    {
        if (m_p) { func_00183CB8(m_p, this); m_p = 0; }
        m_p = o;
        if (m_p) func_00183C98(m_p, this);
    }
};
struct Ev_001B5A20 { char pad[0xBC]; Ref_001B5A20 m_ref; };
extern "C" Ev_001B5A20* func_001F0750(unsigned int id, void* p, int a, int b, int c, int d, int e, int f, int g, int h);
struct Obj_001B5A20 { char pad[0xC]; void* m_C; char pad2[0x10]; unsigned int m_20; void Go(int unused, int flag); };
void Obj_001B5A20::Go(int unused, int flag)
{
    void* s;
    if (flag) {
        m_20 &= ~2;
        s = func_001B5450(this);
        func_001E7360(s, 0, 0x01615618);
    } else {
        s = func_001B4D00(this);
        if (func_00185578(m_C, 0x0A015E17)->m_flags & 0x100) {
            func_001E7200(s, 0x65B5788D, 1);
        } else {
            float a = func_001E5318(0xF1FF758A, 1);
            float b = func_001E5318(0xE224A5D3, 1);
            func_001E7200(s, 0x66CED87B, (int)(2.0f * sqrtf(a * a / (b * b))));
            func_001E7200(s, 0x65B5788D, 0);
        }
    }
    Ev_001B5A20* e = func_001F0750(0x10585CB3, s, 0, 0, -1, 0, 0, 0, 0, 0);
    e->m_ref = m_C;
    if (s) func_001E6AE8(s, 3);
}
