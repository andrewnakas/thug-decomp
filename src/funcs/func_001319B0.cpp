struct Scene_001319B0 {
    char pad0[0x80];
    unsigned int m_name;
    int m_flags;
};

extern Scene_001319B0* D_004653B0[4];
extern "C" Scene_001319B0* func_00145FE8();
extern "C" unsigned int func_001F0D78(const char* s);

extern "C" Scene_001319B0* func_001319B0(const char* name, int flags)
{
    Scene_001319B0* s = func_00145FE8();
    s->m_name = func_001F0D78(name);
    s->m_flags = flags;
    for (int i = 0; i < 4; i++) {
        if (!D_004653B0[i]) {
            D_004653B0[i] = s;
            break;
        }
    }
    return s;
}
