struct Scene_00131E48 {
    char pad0[0x8C];
    int m_flag;
};

extern Scene_00131E48* D_004653B0[4];

extern "C" Scene_00131E48* func_00131E48()
{
    for (int i = 3; i >= 0; i--) {
        Scene_00131E48* s = D_004653B0[i];
        if (s && !s->m_flag) {
            return s;
        }
    }
    return 0;
}
