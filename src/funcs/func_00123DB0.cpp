struct Sub_00123DB0 {
    char pad[0x34];
    float m_x;
    float m_y;
    float m_sx;
    float m_sy;
    char pad44[0xC];
};

struct C_00123DB0 {
    char pad0[0xC];
    unsigned int m_flags;
    char pad10[0x80 - 0x10];
    Sub_00123DB0 m80;
    Sub_00123DB0 mD0;
    Sub_00123DB0* D0() { return &mD0; }
    void SetScale(float x, float y, int relative, int f);
};

extern "C" void func_00125798(C_00123DB0* self, Sub_00123DB0* s);

void C_00123DB0::SetScale(float x, float y, int relative, int f)
{
    if (D0()->m_x != x || D0()->m_y != y || relative) {
        if (!relative) {
            D0()->m_sx = x;
            D0()->m_sy = y;
        } else {
            x *= D0()->m_sx;
            y *= D0()->m_sy;
        }
        D0()->m_x = x;
        D0()->m_y = y;
        func_00125798(this, D0());
        m_flags |= 0x400;
    }
    if (f) {
        Sub_00123DB0* d = &m80;
        if (d->m_x != x || d->m_y != y) {
            d->m_x = x;
            d->m_y = y;
            m_flags |= 0x400;
        }
    }
}
