struct Scene_00131E88 {
    char pad0[0x8C];
    int m_flag;
};

extern Scene_00131E88* D_004653B0[4];

extern "C" Scene_00131E88* func_00131E88()
{
    for (int i = 0; i < 4; i++) {
        Scene_00131E88* s = D_004653B0[i];
        if (s && s->m_flag) {
            return s;
        }
    }
    return 0;
}
