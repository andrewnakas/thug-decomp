struct Obj_00123C40;
extern "C" void func_00125798(Obj_00123C40* self, void* p);

struct Obj_00123C40 {
    char pad[0xC];
    unsigned int m_flags;
    char pad10[0xD0 - 0x10];
    char mD0[0x188 - 0xD0];
    float m_w;
    float m_h;
    void SetSize(float w, float h, int flag);
};

void Obj_00123C40::SetSize(float w, float h, int flag)
{
    if (m_w != w || m_h != h) {
        m_w = w;
        m_h = h;
        m_flags |= 0x400;
        func_00125798(this, mD0);
    }
    if (flag) {
        m_flags |= 0x2000;
    } else {
        m_flags &= ~0x2000;
    }
}
