struct Scene_00131FB8 {
    char pad0[0x8C];
    int m_flag;
};

extern Scene_00131FB8* D_004653B0[4];
extern "C" void func_001464C0(void* a, void* b, Scene_00131FB8* s);

extern "C" void func_00131FB8(void* a, void* b, Scene_00131FB8* s)
{
    if (!s) {
        for (int i = 0; i < 4; i++) {
            if (D_004653B0[i] && !D_004653B0[i]->m_flag) {
                s = D_004653B0[i];
                break;
            }
        }
    }
    func_001464C0(a, b, s);
}
