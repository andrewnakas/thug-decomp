struct Net_001FA3B0 {
    char m_pad[0x134];
    int m134;
    char m_pad2[0x2D0 - 0x138];
    int m2D0;
};

extern "C" void func_001FA1A0(Net_001FA3B0*, int);

void func_001FA3B0(Net_001FA3B0* n, int state)
{
    if (n->m134 == state)
        return;
    if (n->m134 != 0)
        n->m2D0 = 1;
    n->m134 = state;
    switch (state) {
    case 1:
        func_001FA1A0(n, 0x1068);
        break;
    case 2:
        func_001FA1A0(n, 400000);
        break;
    case 3:
        func_001FA1A0(n, 300000);
        break;
    }
}
