struct Scene_00131DD8 {
    char pad0[0x80];
    unsigned int m_name;
};

extern Scene_00131DD8* D_004653B0[4];

extern "C" Scene_00131DD8* func_00131DD8(unsigned int name)
{
    for (int i = 0; i < 4; i++) {
        Scene_00131DD8* s = D_004653B0[i];
        if (s && s->m_name == name) {
            return s;
        }
    }
    return 0;
}
