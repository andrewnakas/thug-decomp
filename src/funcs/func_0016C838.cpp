struct Ent_0016C838 {
    int m_0;
    int m_4;
    int m_8;
    char pad[0x54];
};

extern unsigned D_0038BC14;
extern Ent_0016C838 D_003DDAA0[];

extern "C" void func_0016C838(int id, int v)
{
    unsigned i;
    for (i = 0; i < D_0038BC14; i++) {
        Ent_0016C838* e = &D_003DDAA0[i];
        if (e->m_8 == id) e->m_4 = v;
    }
}
