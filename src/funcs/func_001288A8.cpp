struct Tex_001288A8 {
    char pad0[0x44];
    float m_rot;
    char pad48[0x50 - 0x48];
};

extern "C" void func_0013BA40(void* sprite, float rot);

class Elem_001288A8 {
public:
    int m0[3];
    unsigned int m_flags;
    char pad10[0x80 - 0x10];
    Tex_001288A8 m80;
    Tex_001288A8 mD0;
    char pad120[0x1A4 - 0x120];
    void* m_sprite;
    void SetRotation(int now, float deg);
};

void Elem_001288A8::SetRotation(int now, float deg)
{
    float a = deg * 0.01745329425f;
    a += 0.001f;
    Tex_001288A8* t = &mD0;
    if (t->m_rot != a) {
        t->m_rot = a;
        m_flags |= 0x400;
    }
    Tex_001288A8* c = &m80;
    if (now && c->m_rot != a) {
        func_0013BA40(m_sprite, a);
        c->m_rot = a;
        m_flags |= 0x400;
    }
}
