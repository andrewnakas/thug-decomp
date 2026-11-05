struct E_001E13A0 {
    int m0;
    char m_pad[0x100C];
};

extern E_001E13A0 D_003ED8D0[];

extern "C" E_001E13A0* func_001E13A0(int id)
{
    for (int i = 0; i < 1; i++) {
        if (D_003ED8D0[i].m0 == id) return &D_003ED8D0[i];
    }
    return 0;
}
