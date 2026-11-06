struct Scene_00132098 {
    char pad0[0x8C];
    int m_flag;
};

extern Scene_00132098* D_004653B0[4];
extern "C" int func_0010FC30();
extern "C" void func_00133CC0(Scene_00132098* s);

extern "C" void func_00132098()
{
    func_0010FC30();
    for (int i = 0; i < 4; i++) {
        Scene_00132098* s = D_004653B0[i];
        if (s && !s->m_flag) {
            func_00133CC0(s);
        }
    }
    func_0010FC30();
}
