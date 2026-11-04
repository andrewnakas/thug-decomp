extern "C" void* func_00185578(void* obj, unsigned int name);

struct Comp_001B4BE0 {
    int m_pad[21];
    int m54;
    int m58[9];
    bool m7C;
};

struct Comp2_001B4BE0 {
    int m_pad[7];
    int m1C;
};

struct C_001B4BE0 {
    int m_pad[3];
    void* mC;
    void SetMode(int v);
};

void C_001B4BE0::SetMode(int v)
{
    Comp_001B4BE0* c = (Comp_001B4BE0*)func_00185578(mC, 0xB5F1E9D2);
    if (c) {
        int old = c->m54;
        c->m54 = v;
        c->m7C |= old != v;
    }
    Comp2_001B4BE0* c2 = (Comp2_001B4BE0*)func_00185578(mC, 0x187574FA);
    if (c2) c2->m1C = v;
}
