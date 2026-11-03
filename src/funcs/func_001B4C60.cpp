extern "C" void* func_00185578(void* obj, unsigned int name);

struct Comp_001B4C60 {
    int m_pad[20];
    int m50;
    int m54[10];
    bool m7C;
};

struct Comp2_001B4C60 {
    int m_pad[8];
    int m20;
    int m24;
};

struct C_001B4C60 {
    int m_pad[3];
    void* mC;
    void SetMode(int v);
};

void C_001B4C60::SetMode(int v)
{
    Comp_001B4C60* c = (Comp_001B4C60*)func_00185578(mC, 0xB5F1E9D2);
    if (c) {
        int old = c->m50;
        c->m50 = v;
        c->m7C |= old != v;
    }
    Comp2_001B4C60* c2 = (Comp2_001B4C60*)func_00185578(mC, 0x187574FA);
    if (c2) {
        c2->m20 = v;
        c2->m24 = v;
    }
}
