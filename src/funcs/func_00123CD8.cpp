struct Tex_00123CD8 {
    char pad0[0x20];
    float m_u;
    float m_v;
    char pad28[0x34 - 0x28];
    float m_su;
    float m_sv;
    char pad3C[0x50 - 0x3C];
};

class Obj_00123CD8;
extern "C" void func_00125798(Obj_00123CD8* self, Tex_00123CD8* t);

class Obj_00123CD8 {
public:
    int m0[3];
    unsigned int m_flags;
    char pad10[0x80 - 0x10];
    Tex_00123CD8 m80;
    Tex_00123CD8 mD0;
    char pad120[0x180 - 0x120];
    float m_x;
    float m_y;
    float m_w;
    float m_h;
    void SetPos(float x, float y);
};

void Obj_00123CD8::SetPos(float x, float y)
{
    if (m_x == x && m_y == y) {
        return;
    }
    Tex_00123CD8* a = &m80;
    float dx = x - m_x;
    Tex_00123CD8* b = &mD0;
    float dy = y - m_y;
    float du = a->m_su * m_w * dx * 0.5f;
    float dv = a->m_sv * m_h * dy * 0.5f;
    a->m_u += du;
    a->m_v += dv;
    b->m_u += du;
    b->m_v += dv;
    m_x = x;
    m_y = y;
    m_flags |= 0x400;
    func_00125798(this, b);
}
