struct Scene_00131ED0 {
    char pad0[0x84];
    void* m_tex;
};

extern Scene_00131ED0* D_004653B0[4];
extern "C" bool func_00131CD8(Scene_00131ED0* s);
extern "C" void func_00139D10(void* tex);
extern "C" void func_00146558();

extern "C" bool func_00131ED0()
{
    for (int i = 0; i < 4; i++) {
        Scene_00131ED0* s = D_004653B0[i];
        if (s) {
            void* tex = s->m_tex;
            func_00131CD8(s);
            if (tex) {
                func_00139D10(tex);
            }
        }
    }
    func_00146558();
    return true;
}
