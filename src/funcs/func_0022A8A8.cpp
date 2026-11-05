struct Sub_0022A8A8 {
    char pad[0x54];
    int m_54;
};

struct Comp_0022A8A8 {
    char pad[0x1C];
    unsigned int m_flags;
    int m_20;
};

struct Obj_0022A8A8 {
    char pad0[0x1C];
    Comp_0022A8A8* m_1C;
    char pad20[0x2C - 0x20];
    Sub_0022A8A8* m_2C;
    void Update();
};

extern "C" bool func_001E5628(unsigned int name, int a);
extern "C" void func_001839E8(Comp_0022A8A8* c, int v);
extern "C" void func_00183A18(Comp_0022A8A8* c, int v);

void Obj_0022A8A8::Update()
{
    Sub_0022A8A8* s = m_2C;
    s->m_54 = 0;
    if (m_1C->m_flags & 0x100) {
        s->m_54 = m_1C->m_20;
        if (func_001E5628(0xF3E055E1, 1)) {
            func_001839E8(m_1C, 1);
            func_00183A18(m_1C, 1);
        }
    }
}
