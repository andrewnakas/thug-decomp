struct Scene_00131D68 {
    char pad0[0x84];
    int m_tex;
    int m88;
    bool m_flag;
};

extern "C" Scene_00131D68* func_00131E20(unsigned int name);
extern "C" bool func_00131CD8(Scene_00131D68* s);
extern "C" void* func_00131A48(unsigned int name, int tex, bool a, bool b, int c, int d);

extern "C" bool func_00131D68(unsigned int name)
{
    Scene_00131D68* s = func_00131E20(name);
    if (s) {
        bool flag = s->m_flag;
        int tex = s->m_tex;
        func_00131CD8(s);
        func_00131A48(name, tex, !flag, flag, 0, 0);
        return true;
    }
    return false;
}
