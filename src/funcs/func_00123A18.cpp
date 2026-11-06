struct Tex_00123A18 {
    char pad0[0x20];
    float m_u;
    float m_v;
};

class Obj_00123A18;
extern "C" void func_00125798(Obj_00123A18* self, Tex_00123A18* t);

class Obj_00123A18 {
public:
    int m0[3];
    unsigned int m_flags;
    char pad10[0x80 - 0x10];
    Tex_00123A18 m80;
    char padA8[0xD0 - 0xA8];
    Tex_00123A18 mD0;
    void SetUV(float u, float v, int both);
};

void Obj_00123A18::SetUV(float u, float v, int both)
{
    Tex_00123A18* t = &mD0;
    if (t->m_u != u || t->m_v != v) {
        t->m_u = u;
        t->m_v = v;
        m_flags |= 0x400;
        func_00125798(this, t);
    }
    if (both) {
        t = &m80;
        if (t->m_u != u || t->m_v != v) {
            t->m_u = u;
            t->m_v = v;
            m_flags |= 0x400;
        }
    }
}
